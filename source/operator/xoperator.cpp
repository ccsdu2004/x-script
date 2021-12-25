#include <xoperator.h>
#include <operator/xoperatorminus.h>
#include <operator/xoperatorplus.h>
#include <operator/xoperatormulti.h>
#include <operator/xoperatordiv.h>
#include <operator/xoperatorcompare.h>
#include <operator/xoperatorlogic.h>

std::shared_ptr<XOperator> XOperator::makeOperator(const std::wstring& tag) {
    if (tag == L"+")
        return std::make_shared<XOperatorPlus>();
    else if (tag == L"-")
        return std::make_shared<XOperatorMinus>();
    else if (tag == L"*")
        return std::make_shared<XOperatorMulti>();
    else if (tag == L"/")
        return std::make_shared<XOperatorDiv>();
    else if (tag == L">")
        return std::make_shared<XOperatorGreater>();
    else if (tag == L">=")
        return std::make_shared<XOperatorGreaterOrEqual>();
    else if (tag == L"<")
        return std::make_shared<XOperatorLess>();
    else if (tag == L"<=")
        return std::make_shared<XOperatorLessOrEqual>();
    else if (tag == L"and")
        return std::make_shared<XOperatorLogicAnd>();
    else if (tag == L"or")
        return std::make_shared<XOperatorLogicOr>();
    else if (tag == L"not")
        return std::make_shared<XOperatorLogicNot>();
    return nullptr;
}
