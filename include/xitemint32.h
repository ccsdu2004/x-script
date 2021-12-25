#ifndef XITEMINT32_H
#define XITEMINT32_H
#include <xitemsimpletype.h>

class XItemInt32 : public XItemSimpleType<int32_t> {
  public:
    XItemInt32(int32_t newValue = false):
        XItemSimpleType(newValue) {
        setValueType(XItemValueType_EnumInt32);
    }
  public:
    std::shared_ptr<XItemInt32> asInt32()override {
        return std::dynamic_pointer_cast<XItemInt32>(shared_from_this());
    }
  public:
    void accept(std::shared_ptr<XItemVisitor> visitor) override;
};

#endif // XITEMINT_H
