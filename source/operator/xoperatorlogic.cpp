#include <xitemboolean.h>
#include "xoperatorlogic.h"

XOperatorLogic::XOperatorLogic(const std::wstring& tag) {
    symbol = tag;
}

std::tuple<bool, XCallError> XOperatorLogic::getValue(std::shared_ptr<XItem> item) {
    if (item->asBoolean())
        return makeValueNoError<bool>(item->asBoolean()->getValue());
    return std::make_tuple(false, XCallError(XCallError::XCallError_EnumArgumentTypeError));
}

XOperatorLogicAnd::XOperatorLogicAnd():
    XOperatorLogic(L"and") {
}

XOperatorResult XOperatorLogicAnd::execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments) {
    auto [value, error] = getValue(item);
    if (error.getError() != XCallError::XCallError_EnumNoError)
        return XCallError::makeError(error.getError());

    if (arguments.empty())
        return XCallError::makeError(XCallError::XCallError_EnumArgumentCountError);

    for (auto& argument : arguments) {
        auto [v, error] = getValue(argument);
        if (error.getError() != XCallError::XCallError_EnumNoError)
            return XCallError::makeError(error.getError());
        value = value && v;
    }

    return makeItemNoError<XItemBoolean>(value);
}

XOperatorLogicNot::XOperatorLogicNot():
    XOperatorLogic(L"not") {
}

XOperatorResult XOperatorLogicNot::execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments) {
    auto [value, error] = getValue(item);
    if (error.getError() != XCallError::XCallError_EnumNoError)
        return XCallError::makeError(error.getError());

    if (!arguments.empty())
        return XCallError::makeError(XCallError::XCallError_EnumArgumentCountError);

    return makeItemNoError<XItemBoolean>(!value);
}

XOperatorLogicOr::XOperatorLogicOr():
    XOperatorLogic(L"or") {
}

XOperatorResult XOperatorLogicOr::execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments) {
    auto [value, error] = getValue(item);
    if (error.getError() != XCallError::XCallError_EnumNoError)
        return XCallError::makeError(error.getError());

    if (arguments.empty())
        return XCallError::makeError(XCallError::XCallError_EnumArgumentCountError);

    for (auto& argument : arguments) {
        auto [v, error] = getValue(argument);
        if (error.getError() != XCallError::XCallError_EnumNoError)
            return XCallError::makeError(error.getError());
        value = value || v;
    }

    return makeItemNoError<XItemBoolean>(value);
}
