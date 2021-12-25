#include <sstream>
#include <boost/algorithm/string/join.hpp>
#include <xitemlist.h>
#include <xitemvisitor.h>

XItemList::XItemList()
{
    setValueType(XItemValueType_EnumList);
}

XItemList::~XItemList()
{
}

std::wstring XItemList::getItemInfo()
{
    std::wstringstream stream;
    std::list<std::wstring> items;
    stream << L"[";
    for(auto item : children)
        items.push_back(item->getItemInfo());
    stream << boost::algorithm::join(items,L",");
    stream <<"]";
    return stream.str();
}

