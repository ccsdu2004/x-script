#include <xitemstring.h>
#include <xfactory.h>
#include <operator/xoperatordiv.h>

XOperatorResult XOperatorDiv::execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments) {
    if (arguments.empty() || arguments.size() > 1)
        return XCallError::makeError(XCallError::XCallError_EnumArgumentCountError);

    if (item->asFloat())
        return processNumber<float, XItemFloat>(item->asFloat()->getValue(), arguments[0], L"XOperatorDiv arguments must be float,double,int32 or int64");

    if (item->asDouble())
        return processNumber<double, XItemDouble>(item->asDouble()->getValue(), arguments[0], L"XOperatorDiv arguments must be float,double,int32 or int64");

    if (item->asInt32())
        return processNumber<int32_t, XItemInt32>(item->asInt32()->getValue(), arguments[0], L"XOperatorDiv arguments must be float,double,int32 or int64");

    if (item->asInt64())
        return processNumber<int64_t, XItemInt64>(item->asInt64()->getValue(), arguments[0], L"XOperatorDiv arguments must be float,double,int32 or int64");

    return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError);
}

