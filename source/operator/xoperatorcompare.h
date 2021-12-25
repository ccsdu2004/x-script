#ifndef XOPERATORCOMPRE_H
#define XOPERATORCOMPRE_H
#include <xoperator.h>
#include <xcallerror.h>
#include <xitemstring.h>
#include <xitemboolean.h>
#include <xitemfloat.h>
#include <xitemdouble.h>
#include <xitemint32.h>
#include <xitemint64.h>

class XOperatorCompare : public XOperator {
  public:
    XOperatorCompare();
    virtual ~XOperatorCompare() = default;
  public:
    XOperatorResult execute(std::shared_ptr<XItem> item, const XItemVectorType& arguments);
  protected:
    virtual XOperatorResult executeImpl(double left, double right) = 0;
  private:
    std::tuple<double, XCallError> getValue(std::shared_ptr<XItem> item);
};

class XOperatorGreater : public XOperatorCompare {
  public:
    XOperatorGreater();
  protected:
    virtual XOperatorResult executeImpl(double left, double right);
};

class XOperatorGreaterOrEqual : public XOperatorCompare {
  public:
    XOperatorGreaterOrEqual();
  protected:
    virtual XOperatorResult executeImpl(double left, double right);
};

class XOperatorLess : public XOperatorCompare {
  public:
    XOperatorLess();
  protected:
    virtual XOperatorResult executeImpl(double left, double right);
};

class XOperatorLessOrEqual : public XOperatorCompare {
  public:
    XOperatorLessOrEqual();
  protected:
    virtual XOperatorResult executeImpl(double left, double right);
};

#endif // XOPERATORCOMPRE_H














