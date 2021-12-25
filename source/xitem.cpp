#include <sstream>
#include <xitem.h>
#include <xitemlist.h>
#include <xitemdict.h>
#include <xitemfunction.h>
#include <xitemmodule.h>
#include <xitemvisitor.h>

XItem::XItem()
{
}

XItem::XItem(const std::wstring &name):
    itemName(name)
{
}

void XItem::accept(std::shared_ptr<XItemVisitor> visitor)
{
    (void)visitor;
}

std::wstring XItem::getItemTypeInfo()
{
    std::wstringstream stream;
    stream<<L"<"<<getStringFromType()<<">";
    return stream.str();
}

std::wstring XItem::getItemInfo()
{
    std::wstringstream stream;
    stream<<L"pointer:"<<std::hex<<this;
    return stream.str();
}

void XItem::setName(const std::wstring &name)
{
    if (name != getName()) {
        itemName = name;
        onItemNameChanged(itemName);
    }
}

void XItem::onItemNameChanged(const std::wstring &newName)
{
}

void XItem::onDestroyed()
{

}
