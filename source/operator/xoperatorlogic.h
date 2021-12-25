#ifndef XOPERATORLOGIC_H
#define XOPERATORLOGIC_H
#include <xoperator.h>

class XOperatorLogic : public XOperator {
  public:
    XOperatorLogic() = delete;
    XOperatorLogic(const std::wstring& tag);
    virtual ~XOperatorLogic() = default;
  protected:
    std::tuple<bool, XCallError> getValue(std::shared_ptr<XItem> item);
};

class XOperatorLogicAnd : public XOperatorLogic {
  public:
    XOperatorLogicAnd();
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments);
};

class XOperatorLogicNot : public XOperatorLogic {
  public:
    XOperatorLogicNot();
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments);
};

class XOperatorLogicOr : public XOperatorLogic {
  public:
    XOperatorLogicOr();
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments);
};
#endif // XOPERATORLOGIC_H
