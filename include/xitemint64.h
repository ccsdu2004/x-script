#ifndef XITEMINT64_H
#define XITEMINT64_H
#include <xitemtype.h>
#include <xitemsimpletype.h>

class XItemInt64 : public XItemSimpleType<int64_t>
{
public:
    XItemInt64(bool newValue = false):
        XItemSimpleType(newValue)
    {
        setValueType(XItemValueType_EnumInt64);
    }
public:
    std::shared_ptr<XItemInt64> asInt64() override
    {
        return std::dynamic_pointer_cast<XItemInt64>(shared_from_this());
    }
public:
    void accept(std::shared_ptr<XItemVisitor> visitor) override;
};

#endif // XITEMINT_H
