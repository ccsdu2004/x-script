#include <xitemint64.h>
#include <xitemvisitor.h>
#include <xfactory.h>

void XItemInt64::accept(std::shared_ptr<XItemVisitor> visitor)
{
    if (visitor)
        visitor->visit(asInt32());
}
