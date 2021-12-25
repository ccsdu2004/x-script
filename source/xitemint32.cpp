#include <xitemint32.h>
#include <xitemvisitor.h>

void XItemInt32::accept(std::shared_ptr<XItemVisitor> visitor) {
    if (visitor)
        visitor->visit(asInt32());
}
