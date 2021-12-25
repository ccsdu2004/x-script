#include <iostream>
#include <xitemstring.h>
#include <operator/xoperatorplus.h>
#include <xprint.h>

class XOperatorPlusString : public XOperatorPlus {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto string = item->asString()->getValue();
        return processString<std::wstring, XItemString>(string, arguments, L"XOperatorPlus arguments must be float,double,int32,int64 or string");
    }
  private:
    template<class Value, class Type>
    XOperatorResult processString(Value value, const XItemVectorType& arguments, const std::wstring& error) {
        for (auto& argument : arguments) {
            auto type = argument->getValueType();
            if (type == XItem::XItemValueType_EnumFloat)
                value += std::to_wstring(argument->asFloat()->getValue());
            else if (type == XItem::XItemValueType_EnumDouble)
                value += std::to_wstring(argument->asDouble()->getValue());
            else if (type == XItem::XItemValueType_EnumInt32)
                value += std::to_wstring(argument->asInt32()->getValue());
            else if (type == XItem::XItemValueType_EnumInt64)
                value += std::to_wstring(argument->asInt64()->getValue());
            else if (type == XItem::XItemValueType_EnumString)
                value += argument->asString()->getValue();
            else
                return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError, error);
        }
        return std::make_tuple(std::make_shared<Type>(value), XCallError(XCallError::XCallError_EnumNoError));
    }
};

class XOperatorPlusFloat : public XOperatorPlus {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asFloat()->getValue();
        return processNumber<float, XItemFloat>(value, arguments, L"XOperatorPlus arguments must be float,double,int32 or int64");
    }
};

class XOperatorPlusDouble : public XOperatorPlus {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asDouble()->getValue();
        return processNumber<double, XItemDouble>(value, arguments, L"XOperatorPlus arguments must be float,double,int32 or int64");
    }
};

class XOperatorPlusInt32 : public XOperatorPlus {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asInt32()->getValue();
        return processNumber<int32_t, XItemInt32>(value, arguments, L"XOperatorPlus arguments must be float,double,int32 or int64");
    }
};

class XOperatorPlusInt64 : public XOperatorPlus {
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override {
        auto value = item->asInt64()->getValue();
        return processNumber<int64_t, XItemInt64>(value, arguments, L"XOperatorPlus arguments must be float,double,int32 or int64");
    }
};

XOperatorResult XOperatorPlus::execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments) {
    if (item->asString()) {
        XOperatorPlusString plus;
        return plus.execute(item, arguments);
    }

    if (item->asFloat()) {
        XOperatorPlusFloat plus;
        return plus.execute(item, arguments);
    }

    if (item->asDouble()) {
        XOperatorPlusDouble plus;
        return plus.execute(item, arguments);
    }

    if (item->asInt32()) {
        XOperatorPlusInt32 plus;
        return plus.execute(item, arguments);
    }

    if (item->asInt64()) {
        XOperatorPlusInt64 plus;
        return plus.execute(item, arguments);
    }

    return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError);
}



