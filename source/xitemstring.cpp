#include <sstream>
#include <boost/algorithm/string.hpp>
#include <xitemlist.h>
#include <xitemstring.h>
#include <xitemvisitor.h>

std::shared_ptr<XItemString> XItemString::createXItemString(const std::wstring& string, uint32_t count) {
    std::wstringstream stream;
    for (uint32_t i = 0; i < count; i++)
        stream << string;
    return std::make_shared<XItemString>(stream.str());
}

std::tuple<std::wstring, XCallError> XItemString::at(size_t position) {
    if (position >= 0 && position < value.size())
        return std::make_tuple<std::wstring, XCallError>(std::wstring(value[position], 1), XCallError(XCallError::XCallError_EnumNoError, L""));
    return std::make_tuple<std::wstring, XCallError>(std::wstring(), XCallError(XCallError::XCallError_EnumOutOfRangeError, L""));
}

bool XItemString::startsWith(const std::wstring& string) {
    return boost::algorithm::starts_with(value, string);
}

bool XItemString::endsWith(const std::wstring& string) {
    return boost::algorithm::ends_with(value, string);
}

std::shared_ptr<XItem> XItemString::split(const std::wstring& tag, bool keepEmpty) {
    std::list<std::wstring> strings;
    boost::algorithm::split(strings, getValue(), boost::is_any_of(tag), keepEmpty ? boost::token_compress_off : boost::token_compress_on);

    std::shared_ptr<XItemList> list = std::make_shared<XItemList>();
    for (auto string : strings)
        list->addItem(std::make_shared<XItemString>(string));

    return list->asItem();
}

std::wstring XItemString::getItemInfo() {
    std::wstringstream stream;
    stream << "'" << value << "'";
    return stream.str();
}

void XItemString::accept(std::shared_ptr<XItemVisitor> visitor) {
    if (visitor)
        visitor->visit(asString());
}
