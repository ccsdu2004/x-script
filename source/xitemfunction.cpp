#include <sstream>
#include <iostream>
#include <xitemfunction.h>
#include <xitemvisitor.h>

XItemFunction::XItemFunction()
{
    setValueType(XItemValueType_EnumFunction);
}

XItemFunction::~XItemFunction()
{
}

void XItemFunction::addArgument(std::shared_ptr<XItem> item)
{
    item->setPositionType(XItemPositionType_EnumArgument);
    arguments.push_back(item);
}

std::tuple<std::shared_ptr<XItem>, XCallError> XItemFunction::execute()
{
    return std::make_tuple<std::shared_ptr<XItem>, XCallError>(
                nullptr, XCallError(XCallError::XCallError_EnumUnreachedError, L"XItemFunction::execute"));
}

std::shared_ptr<XItemFunction> XItemFunction::asFunction()
{
    return std::dynamic_pointer_cast<XItemFunction>(shared_from_this());
}

void XItemFunction::accept(std::shared_ptr<XItemVisitor> visitor)
{
    if (visitor) {
        for (auto argument : arguments) {
            argument->accept(visitor);
        }
    }
}

std::wstring XItemFunction::getItemInfo()
{
    std::wstringstream stream;
    stream <<L"XItemFunction";
    return stream.str();
}
