#ifndef XITEMDOUBLE_H
#define XITEMDOUBLE_H
#include "xitemsimpletype.h"

class XItemDouble : public XItemSimpleType<double> {
  public:
    XItemDouble(double newValue = false):
        XItemSimpleType(newValue) {
        setValueType(XItemValueType_EnumDouble);
    }
  public:
    std::shared_ptr<XItemDouble> asDouble() override {
        return std::dynamic_pointer_cast<XItemDouble>(shared_from_this());
    }
  public:
    void accept(std::shared_ptr<XItemVisitor> visitor)override;
};

#endif // XITEMINT_H
