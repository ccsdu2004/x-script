#ifndef XITEMSTRING_H
#define XITEMSTRING_H
#include <xcallerror.h>
#include <xitemsimpletype.h>

class XItemString : public XItemSimpleType<std::wstring> {
  public:
    static std::shared_ptr<XItemString> createXItemString(const std::wstring& string, uint32_t count);
  public:
    XItemString() {
        setValueType(XItemValueType_EnumString);
    }
    XItemString(const std::wstring& newValue):
        XItemSimpleType(newValue) {
        setValueType(XItemValueType_EnumString);
    }
  public:
    size_t length()const {return value.size();}
    std::tuple<std::wstring, XCallError> at(size_t position);
    bool startsWith(const std::wstring& string);
    bool endsWith(const std::wstring& string);

    std::shared_ptr<XItem> split(const std::wstring& tag, bool keepEmpty = true);

    void appendString(const std::wstring& item) {
        value += item;
    }

    std::shared_ptr<XItemString> asString()override {
        return std::dynamic_pointer_cast<XItemString>(shared_from_this());
    }

    virtual std::wstring getItemInfo()override;
  public:
    void accept(std::shared_ptr<XItemVisitor> visitor)override;
};

#endif // XITEMSTRING_H
