#ifndef XOPERATOR_H
#define XOPERATOR_H
#include <tuple>
#include <xitem.h>
#include <xcallerror.h>

using XOperatorResult = std::tuple<std::shared_ptr<XItem>,XCallError>;

class XOperator
{
public:
    static std::shared_ptr<XOperator> makeOperator(const std::wstring& tag);
public:
    virtual ~XOperator() = default;
public:
    std::wstring getOperator()const{return symbol;}
    virtual XOperatorResult execute(std::shared_ptr<XItem> item,const XItemVectorType& arguments) = 0;
protected:
    std::wstring symbol;
};

#endif // XOPERATOR_H
