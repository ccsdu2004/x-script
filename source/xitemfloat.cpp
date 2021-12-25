#include <xitemfloat.h>
#include <xitemvisitor.h>

void XItemFloat::accept(std::shared_ptr<XItemVisitor> visitor)
{
    if (visitor)
        visitor->visit(asFloat());
}
