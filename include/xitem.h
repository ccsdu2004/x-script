#ifndef XITEM_H
#define XITEM_H
#include <string>
#include <list>
#include <vector>
#include <boost/noncopyable.hpp>
#include <xdefs.h>
#include <xitemtype.h>
#include <xitemconvertor.h>

class XItem : public XItemConvertor, public XItemType, public std::enable_shared_from_this<XItem>, public boost::noncopyable {
    friend class XItemFactory;
  public:
    XItem();
    XItem(const std::wstring& name);
    virtual ~XItem() = default;
  public:
    virtual std::shared_ptr<XItem> asItem()override {
        return shared_from_this();
    }

    std::wstring getName()const {
        return itemName;
    }

    virtual void accept(std::shared_ptr<XItemVisitor> visitor);
  public:
    std::wstring getItemTypeInfo();
    virtual std::wstring getItemInfo();
  protected:
    void setName(const std::wstring& name);
    virtual void onItemNameChanged(const std::wstring& newName);

    virtual void onDestroyed();
  protected:
    std::wstring itemName;
};

using XItemVectorType = std::vector<std::shared_ptr<XItem>>;

#endif // XITEM_H
