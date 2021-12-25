#include <xitemstring.h>
#include <xfactory.h>
#include <operator/xoperatorminus.h>

class XOperatorMinusFloat : public XOperatorMinus {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asFloat()->getValue();
        return processNumber<float, XItemFloat>(value, arguments, L"XOperatorMinus arguments must be float,double,int32 or int64");
    }
};

class XOperatorMinusDouble : public XOperatorMinus {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asDouble()->getValue();
        return processNumber<double, XItemDouble>(value, arguments, L"XOperatorMinus arguments must be float,double,int32 or int64");
    }
};

class XOperatorMinusInt32 : public XOperatorMinus {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asInt32()->getValue();
        return processNumber<int32_t, XItemInt32>(value, arguments, L"XOperatorMinus arguments must be float,double,int32 or int64");
    }
};

class XOperatorMinusInt64 : public XOperatorMinus {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asInt64()->getValue();
        return processNumber<int64_t, XItemInt64>(value, arguments, L"XOperatorMinus arguments must be float,double,int32 or int64");
    }
};

XOperatorResult XOperatorMinus::execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments) {
    if (item->asFloat()) {
        XOperatorMinusFloat call;
        return call.execute(item, arguments);
    }

    if (item->asDouble()) {
        XOperatorMinusDouble call;
        return call.execute(item, arguments);
    }

    if (item->asInt32()) {
        XOperatorMinusInt32 call;
        return call.execute(item, arguments);
    }

    if (item->asInt64()) {
        XOperatorMinusInt64 call;
        return call.execute(item, arguments);
    }

    return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError);
}

