#ifndef XITEMBOOLEAN_H
#define XITEMBOOLEAN_H
#include <xitemsimpletype.h>

class XItemBoolean : public XItemSimpleType<bool> {
  public:
    XItemBoolean(bool newValue = false):
        XItemSimpleType(newValue) {
        setValueType(XItemValueType_EnumBoolean);
    }

    ~XItemBoolean() = default;
  public:
    std::shared_ptr<XItemBoolean> asBoolean()override {
        return std::dynamic_pointer_cast<XItemBoolean>(shared_from_this());
    }
    std::wstring getItemInfo()override;
  public:
    void accept(std::shared_ptr<XItemVisitor> vistor)override;
};

#endif // XITEMBOOLEAN_H
