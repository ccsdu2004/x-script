#include <iostream>
#include <cassert>
#include <xitemint32.h>
#include <xitemint64.h>
#include <xitemstring.h>
#include <xitemfloat.h>
#include <xitemdouble.h>
#include <xoperator.h>
#include <xcallerror.h>
#include <xprint.h>

int main() {
    {
        auto hello = std::make_shared<XItemString>(L"Hello");
        auto count = std::make_shared<XItemInt32>(3);
        auto result = XOperator::makeOperator(L"*")->execute(hello, {count});
        printXResult(result);
    }

    {
        auto x = std::make_shared<XItemFloat>(3.3f);
        auto y = std::make_shared<XItemDouble>(3.6);
        auto z = std::make_shared<XItemInt32>(2.5);
        auto result = XOperator::makeOperator(L"*")->execute(x, {y, z});
        printXResult(result);
    }

    {
        auto x = std::make_shared<XItemFloat>(3.3f);
        auto y = std::make_shared<XItemDouble>(3.6);
        auto result = XOperator::makeOperator(L">")->execute(x, {y});
        printXResult(result);
    }

    {
        auto x = std::make_shared<XItemString>(L"Hello");
        auto y = std::make_shared<XItemString>(L"World");
        auto result = XOperator::makeOperator(L">")->execute(x, {y});
        printXResult(result);
    }

    {
        auto x = std::make_shared<XItemFloat>(3.3f);
        auto y = std::make_shared<XItemDouble>(3.6);
        auto [greate, error] = XOperator::makeOperator(L">")->execute(x, {y});
        if (error.getError() == XCallError::XCallError_EnumNoError) {
            auto result = XOperator::makeOperator(L"not")->execute(greate, {});
            printXResult(result);
        }
    }
    return 0;
}

