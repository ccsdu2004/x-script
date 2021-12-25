#include <xitemstring.h>
#include <xfactory.h>
#include <operator/xoperatormulti.h>

class XOperatorMultiFloat : public XOperatorMulti {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asFloat()->getValue();
        return processNumber<float, XItemFloat>(value, arguments, L"XOperatorMulti arguments must be float,double,int32 or int64");
    }
};

class XOperatorMultiDouble : public XOperatorMulti {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asDouble()->getValue();
        return processNumber<double, XItemDouble>(value, arguments, L"XOperatorMulti arguments must be float,double,int32 or int64");
    }
};

class XOperatorMultiInt32 : public XOperatorMulti {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asInt32()->getValue();
        return processNumber<int32_t, XItemInt32>(value, arguments, L"XOperatorMulti arguments must be float,double,int32 or int64");
    }
};

class XOperatorMultiInt64 : public XOperatorMulti {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asInt64()->getValue();
        return processNumber<int64_t, XItemInt64>(value, arguments, L"XOperatorMulti arguments must be float,double,int32 or int64");
    }
};

XOperatorResult XOperatorMulti::execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments) {
    if (item->asString()) {
        if (arguments.size() > 1 || arguments.empty())
            return XCallError::makeError(XCallError::XCallError_EnumArgumentCountError);

        int32_t count = 0;
        if (arguments[0]->asInt32())
            count = arguments[0]->asInt32()->getValue();
        else if (arguments[0]->asInt64())
            count = arguments[0]->asInt64()->getValue();
        else
            return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError);

        if (count == 0)
            return std::make_tuple(std::make_shared<XItemString>(L""), XCallError(XCallError::XCallError_EnumNoError));

        std::wstring retValue;
        auto value = item->asString()->getValue();
        for (int32_t i = 0; i < count; i++)
            retValue.append(value);

        return std::make_tuple(std::make_shared<XItemString>(retValue), XCallError(XCallError::XCallError_EnumNoError));
    }

    if (item->asFloat()) {
        XOperatorMultiFloat call;
        return call.execute(item, arguments);
    }

    if (item->asDouble()) {
        XOperatorMultiDouble call;
        return call.execute(item, arguments);
    }

    if (item->asInt32()) {
        XOperatorMultiInt32 call;
        return call.execute(item, arguments);
    }

    if (item->asInt64()) {
        XOperatorMultiInt64 call;
        return call.execute(item, arguments);
    }

    return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError);
}

