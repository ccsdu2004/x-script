#ifndef XITEMFLOAT_H
#define XITEMFLOAT_H
#include <xitemsimpletype.h>

class XItemFloat : public XItemSimpleType<float> {
  public:
    XItemFloat(float newValue = 0.0f):
        XItemSimpleType(newValue) {
        setValueType(XItemValueType_EnumFloat);
    }
  public:
    std::shared_ptr<XItemFloat> asFloat() override {
        return std::dynamic_pointer_cast<XItemFloat>(shared_from_this());
    }
  public:
    void accept(std::shared_ptr<XItemVisitor> visitor)override;
};

#endif // XITEMINT_H
