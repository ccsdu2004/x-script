#ifndef XOPERATORDIV_H
#define XOPERATORDIV_H
#include <cmath>
#include <xoperator.h>
#include <xitemfloat.h>
#include <xitemdouble.h>
#include <xitemint32.h>
#include <xitemint64.h>

class XOperatorDiv : public XOperator {
  public:
    XOperatorDiv() {
        symbol = L"/";
    }
    virtual ~XOperatorDiv() = default;
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments)override;
  protected:
    template<class Value, class Type>
    XOperatorResult processNumber(Value value, const std::shared_ptr<XItem> argument, const std::wstring& error) {
        auto type = argument->getValueType();
        if (type == XItem::XItemValueType_EnumFloat) {
            auto k = argument->asFloat()->getValue();
            if (std::fabs(k) < 0.00001f)
                return XCallError::makeDivZeroError();
            else
                value /= k;
        } else if (type == XItem::XItemValueType_EnumDouble) {
            auto k = argument->asDouble()->getValue();
            if (std::fabs(k) < 0.00000001f)
                return XCallError::makeDivZeroError();
            else
                value /= k;
        } else if (type == XItem::XItemValueType_EnumInt32) {
            auto k = argument->asInt32()->getValue();
            if (k == 0)
                return XCallError::makeDivZeroError();
            else
                value /= k;
        } else if (type == XItem::XItemValueType_EnumInt64) {
            auto k = argument->asInt64()->getValue();
            if (k == 0)
                return XCallError::makeDivZeroError();
            else
                value /= k;
        } else
            return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError, error);

        return makeItemNoError<Type>(value);
    }
};

#endif // XOPERATORDIV_H
