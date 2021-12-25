#ifndef XITEMUNDEFINED_H
#define XITEMUNDEFINED_H
#include <memory>
#include <xitem.h>

class XItemUndefined : public XItem {
  public:
    XItemUndefined();
    virtual ~XItemUndefined();
  public:
    std::shared_ptr<XItemUndefined> asUndefined()override;
  public:
    void accept(std::shared_ptr<XItemVisitor> visitor)override;
    std::wstring getItemInfo()override;
};

#endif // XITEMUNDEFINED_H
