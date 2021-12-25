#include <xitemcontainer.h>
#include <xitemvisitor.h>

XItemContainer::XItemContainer()
{
}

XItemContainer::~XItemContainer()
{
}

void XItemContainer::addItem(std::shared_ptr<XItem> item)
{
    if(item)
        children.push_back(item);
}

void XItemContainer::removeItem(std::shared_ptr<XItem> item)
{
    if (item)
        children.remove(item);
}

void XItemContainer::accept(std::shared_ptr<XItemVisitor> visitor)
{
    if (!visitor)
        return;

    itemVisitor = visitor;
    auto itr = children.begin();
    while (itr != children.end()) {
        auto item = *itr;
        visitor->visit(item->asUndefined());
        visitor->visit(item->asBoolean());
        visitor->visit(item->asString());
        visitor->visit(item->asInt64());
        visitor->visit(item->asFloat());
        visitor->visit(item->asDouble());
        visitor->visit(item->asList());
        visitor->visit(item->asDict());
        visitor->visit(item->asFunction());
        visitor->visit(item->asClass());
        visitor->visit(item->asModule());
        itr ++;
    }
}
