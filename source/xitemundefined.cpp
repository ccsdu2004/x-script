#include <sstream>
#include <xitemundefined.h>
#include <xitemvisitor.h>
#include <xfactory.h>

REGISTER_OBJECT(XItem,XItemUndefined)

XItemUndefined::XItemUndefined()
{
    setValueType(XItemValueType_EnumUndefined);
}

XItemUndefined::~XItemUndefined()
{
}

std::shared_ptr<XItemUndefined> XItemUndefined::asUndefined()
{
    return std::dynamic_pointer_cast<XItemUndefined>(shared_from_this());
}

void XItemUndefined::accept(std::shared_ptr<XItemVisitor> visitor)
{
    if (visitor)
        visitor->visit(asUndefined());
}

std::wstring XItemUndefined::getItemInfo()
{
    std::wstringstream stream;
    stream << L"XItemUndefined";
    return stream.str();
}
