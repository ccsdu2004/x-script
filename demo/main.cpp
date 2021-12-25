#include <iostream>
#include <xitemboolean.h>
#include <xitemint32.h>
#include <xitemlist.h>
#include <xitemfunctionproxy.h>
#include <xcallerror.h>
#include "xfactory.h"

using namespace std;

class XItemFunctionNot : public XItemFunction
{
public:    
    FunctionReturn execute()override
    {
        if(arguments.size() != 1)
            return XCallError::makeError(XCallError::XCallError_EnumArgumentCountError, L"");
        if(!arguments[0]->asBoolean())
            return XCallError::makeError(XCallError::XCallError_EnumArgumentTypeError, L"");
        return std::make_tuple(std::make_shared<XItemBoolean>(!arguments[0]->asBoolean()->getValue()), XCallError(XCallError::XCallError_EnumNoError, L""));
    }
};

int main()
{

    /*cout << "Hello World!" << endl;
    std::shared_ptr<XItemBoolean> ptr = std::make_shared<XItemBoolean>();
    ptr->setValue(true);
    std::cout << "ptr value:" << ptr->getValue() << std::endl;
    auto other = ptr->clone();
    std::cout << "other ptr:" << other << std::endl;
    std::cout << "other value:" << other->asBoolean()->getValue() << std::endl;
    auto function = std::make_shared<XItemFunctionNot>();
    function->addArgument(other);
    auto [value, error] = function->execute();
    std::wcout << error.getError() << " " << error.getErrorString() << std::endl;
    std::wcout << value->asBoolean()->getValue() << std::endl;*/

    {
    }

    return 0;
}
