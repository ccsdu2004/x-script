#include <sstream>
#include <xitemboolean.h>
#include <xitemvisitor.h>
#include <xfactory.h>

REGISTER_OBJECT(XItem,XItemBoolean)

std::wstring XItemBoolean::getItemInfo()
{
    std::wstringstream stream;
    if(getValue() == true)
        stream << L"True";
    else
        stream << L"False";
    return stream.str();
}

void XItemBoolean::accept(std::shared_ptr<XItemVisitor> visitor)
{
    if (visitor)
        visitor->visit(asBoolean());
}
