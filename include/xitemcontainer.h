#ifndef XITEMCONTAINER_H
#define XITEMCONTAINER_H
#include <list>
#include <boost/noncopyable.hpp>
#include <xitem.h>
#include <xitemvisitor.h>

class XItemContainer : public XItem, public XItemVisitor {
  public:
    XItemContainer();
    virtual ~XItemContainer();
  public:
    void addItem(std::shared_ptr<XItem> item);
    void removeItem(std::shared_ptr<XItem> item);

    virtual void accept(std::shared_ptr<XItemVisitor> visitor)override;
  protected:
    std::shared_ptr<XItemVisitor> itemVisitor;
    std::list<std::shared_ptr<XItem>> children;
};

#endif // XITEMCONTAINER_H
