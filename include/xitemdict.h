#ifndef XITEMDICT_H
#define XITEMDICT_H
#include <map>
#include <sstream>
#include <xitem.h>
#include <xitemvisitor.h>

class XItemAbstractDict : public XItem, public XItemVisitor {
  public:
    XItemAbstractDict();
    virtual ~XItemAbstractDict() = default;
  public:
    template<class T>
    void addItem(const T& key, std::shared_ptr<XItem> value) {
        static_assert(std::is_same<T, bool>::value ||
                      std::is_same<T, int32_t>::value ||
                      std::is_same<T, int64_t>::value ||
                      std::is_same<T, std::wstring>::value,
                      "XItemDict key must be boolean,int32_t,int64_r or std::wstring");
        insertItem(key, value);
    }

    template<class T>
    void removeItem(const T& key) {
        static_assert(std::is_same<T, bool>::value ||
                      std::is_same<T, int32_t>::value ||
                      std::is_same<T, bool>::value ||
                      std::is_same<T, std::wstring>::value,
                      "XItemDict key must be boolean,int32_t,int64_r or std::wstring");
        removeItem(key);
    }

  protected:
    virtual void insertItem(bool key, std::shared_ptr<XItem> value) = 0;
    virtual void insertItem(int32_t key, std::shared_ptr<XItem> value) = 0;
    virtual void insertItem(int64_t key, std::shared_ptr<XItem> value) = 0;
    virtual void insertItem(const std::wstring& key, std::shared_ptr<XItem> value) = 0;

    virtual void removeItem(bool key) = 0;
    virtual void removeItem(int32_t key) = 0;
    virtual void removeItem(int64_t key) = 0;
    virtual void removeItem(const std::wstring& key) = 0;
};

class XItemDict : public XItemAbstractDict {
  public:
    void accept(std::shared_ptr<XItemVisitor> visitor)override;
    std::wstring getItemInfo()override;
  protected:
    void insertItem(bool key, std::shared_ptr<XItem> value)override;
    void insertItem(int32_t key, std::shared_ptr<XItem> value)override;
    void insertItem(int64_t key, std::shared_ptr<XItem> value)override;
    void insertItem(const std::wstring& key, std::shared_ptr<XItem> value)override;

    void removeItem(bool key)override;
    void removeItem(int32_t key)override;
    void removeItem(int64_t key)override;
    void removeItem(const std::wstring& key)override;
  protected:
    template<class T>
    std::wstring getPairInfo(const T& key, std::shared_ptr<XItem>& value) {
        std::wstringstream stream;
        stream << key << L":" << value->getItemInfo();
        return stream.str();
    }

    std::wstring getPairInfo(const bool& key, std::shared_ptr<XItem>& value) {
        std::wstringstream stream;
        stream << (key ? L"True" : L"False") << L":" << value->getItemInfo();
        return stream.str();
    }
  protected:
    std::map<bool, std::shared_ptr<XItem>> childrenBoolean;
    std::map<int32_t, std::shared_ptr<XItem>> childrenInt32;
    std::map<int64_t, std::shared_ptr<XItem>> childrenInt64;
    std::map<std::wstring, std::shared_ptr<XItem>> childrenWString;
};



#endif // XITEMINT_H
