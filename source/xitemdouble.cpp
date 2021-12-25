#include <xitemdouble.h>
#include <xitemvisitor.h>
#include <xfactory.h>

REGISTER_OBJECT(XItem,XItemDouble)

void XItemDouble::accept(std::shared_ptr<XItemVisitor> visitor)
{
    if (visitor)
        visitor->visit(asDouble());
}
