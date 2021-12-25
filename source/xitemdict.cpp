#include <sstream>
#include <boost/algorithm/string/join.hpp>
#include <xitemdict.h>
#include <xitemvisitor.h>

XItemAbstractDict::XItemAbstractDict()
{
    setValueType(XItemValueType_EnumDict);
}

void XItemDict::accept(std::shared_ptr<XItemVisitor> visitor)
{
    for(auto& child : childrenBoolean)
        child.second->accept(visitor);

    for(auto& child : childrenInt32)
        child.second->accept(visitor);

    for(auto& child : childrenInt64)
        child.second->accept(visitor);

    for(auto& child : childrenWString)
        child.second->accept(visitor);
}

std::wstring XItemDict::getItemInfo()
{
    std::wstringstream stream;
    std::list<std::wstring> items;
    stream << L"{";
    for(auto item : childrenBoolean)
        items.push_back(getPairInfo(item.first,item.second));
    for(auto item : childrenInt32)
        items.push_back(getPairInfo(item.first,item.second));
    for(auto item : childrenInt64)
        items.push_back(getPairInfo(item.first,item.second));
    for(auto item : childrenWString)
        items.push_back(getPairInfo(item.first,item.second));
    stream << boost::algorithm::join(items,L",");
    stream <<"}";
    return stream.str();
}

void XItemDict::insertItem(bool key, std::shared_ptr<XItem> value)
{
    childrenBoolean.insert_or_assign(key,value);
}

void XItemDict::insertItem(int32_t key, std::shared_ptr<XItem> value)
{
    childrenInt32.insert_or_assign(key,value);
}

void XItemDict::insertItem(int64_t key, std::shared_ptr<XItem> value)
{
    childrenInt64.insert_or_assign(key,value);
}

void XItemDict::insertItem(const std::wstring &key, std::shared_ptr<XItem> value)
{
    childrenWString.insert_or_assign(key,value);
}

void XItemDict::removeItem(bool key)
{
    childrenBoolean.erase(key);
}

void XItemDict::removeItem(int32_t key)
{
    childrenInt32.erase(key);
}

void XItemDict::removeItem(int64_t key)
{
    childrenInt64.erase(key);
}

void XItemDict::removeItem(const std::wstring &key)
{
    childrenWString.erase(key);
}

