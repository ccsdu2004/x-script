#ifndef XOPERATORPLUS_H
#define XOPERATORPLUS_H
#include <xoperator.h>
#include <xitemfloat.h>
#include <xitemdouble.h>
#include <xitemint32.h>
#include <xitemint64.h>

class XOperatorPlus : public XOperator {
  public:
    XOperatorPlus() {
        symbol = L"+";
    }
    virtual ~XOperatorPlus() = default;

    virtual XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments);
  protected:
    template<class Value, class Type>
    XOperatorResult processNumber(Value value, const XItemVectorType& arguments, const std::wstring& error) {
        for (auto& argument : arguments) {
            auto type = argument->getValueType();
            if (type == XItem::XItemValueType_EnumFloat)
                value += argument->asFloat()->getValue();
            else if (type == XItem::XItemValueType_EnumDouble)
                value += argument->asDouble()->getValue();
            else if (type == XItem::XItemValueType_EnumInt32)
                value += argument->asInt32()->getValue();
            else if (type == XItem::XItemValueType_EnumInt64)
                value += argument->asInt64()->getValue();
            else
                return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError, error);
        }
        return makeItemNoError<Type>(value);
    }
};


#endif // XOPERATORPLUS_H
