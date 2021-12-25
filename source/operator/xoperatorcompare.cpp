#include <xcallerror.h>
#include <xitemstring.h>
#include <xitemboolean.h>
#include <xitemfloat.h>
#include <xitemdouble.h>
#include <xitemint32.h>
#include <xitemint64.h>
#include <operator/xoperatorcompare.h>

XOperatorCompare::XOperatorCompare() {
    symbol = L">";
}

XOperatorResult XOperatorCompare::execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments) {
    if (arguments.empty() || arguments.size() > 1)
        return XCallError::makeError(XCallError::XCallError_EnumArgumentCountError);

    auto [left, error1] = getValue(item);
    if (error1.getError() != XCallError::XCallError_EnumNoError)
        return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError);
    auto [right, error2] = getValue(item);
    if (error2.getError() != XCallError::XCallError_EnumNoError)
        return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError);
    return executeImpl(left, right);
}

std::tuple<double, XCallError> XOperatorCompare::getValue(std::shared_ptr<XItem> item) {
    double value = 0.0;
    if (item->asFloat())
        value = item->asFloat()->getValue();
    else if (item->asDouble())
        value = item->asDouble()->getValue();
    else if (item->asInt32())
        value = item->asInt32()->getValue();
    else if (item->asInt64())
        value = item->asInt64()->getValue();
    else
        return std::make_tuple(value, XCallError::XCallError_EnumArgumentTypeError);
    return std::make_tuple(value, XCallError::XCallError_EnumNoError);
}

XOperatorGreater::XOperatorGreater() {
    symbol = L">";
}

XOperatorResult XOperatorGreater::executeImpl(double left, double right) {
    return makeItemNoError<XItemBoolean>(left > right);
}

XOperatorGreaterOrEqual::XOperatorGreaterOrEqual() {
    symbol = L">=";
}

XOperatorResult XOperatorGreaterOrEqual::executeImpl(double left, double right) {
    return makeItemNoError<XItemBoolean>(left >= right);
}

XOperatorLess::XOperatorLess() {
    symbol = L"<";
}

XOperatorResult XOperatorLess::executeImpl(double left, double right) {
    return makeItemNoError<XItemBoolean>(left < right);
}

XOperatorLessOrEqual::XOperatorLessOrEqual() {
    symbol = L"<=";
}

XOperatorResult XOperatorLessOrEqual::executeImpl(double left, double right) {
    return makeItemNoError<XItemBoolean>(left <= right);
}
