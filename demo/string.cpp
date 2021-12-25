#include <iostream>
#include <cassert>
#include <xitemlist.h>
#include <xitemint32.h>
#include <xitemint64.h>
#include <xitemstring.h>
#include <xitemfloat.h>
#include <xitemdouble.h>
#include <xoperator.h>
#include <xcallerror.h>
#include <xprint.h>

int main() {

    auto hello = std::make_shared<XItemString>(L"Hello");
    auto world = std::make_shared<XItemString>(L" World ");
    auto value = std::make_shared<XItemInt32>(123);
    auto end = std::make_shared<XItemString>(L"!");

    XItemVectorType list = {hello, world, value->asItem(), end};
    auto plus = XOperator::makeOperator(L"+");
    auto [result, error] = plus->execute(std::make_shared<XItemString>(L"Hi "), list);

    if (error.getError() == XCallError::XCallError_EnumNoError)
        print(std::wcout, result->getItemInfo());
    else
        print(std::wcout, L"error:", error.getErrorString());

    return 0;
}
