#include "xitemfunctionproxy.h"

XItemFunctionProxy::XItemFunctionProxy()
{
}

XItemFunctionProxy::~XItemFunctionProxy()
{
}

void XItemFunctionProxy::setExecuteCallback(XItemFunctionProxy::ExecuteCallback callback)
{
    if(callback)
        executeCallbacks.push_back(callback);
}

void XItemFunctionProxy::setMainExecuteCallback(XItemFunctionProxy::ExecuteCallback callback)
{
    if(callback)
        mainExecuteCallback = callback;
}

std::tuple<std::shared_ptr<XItem>, XCallError> XItemFunctionProxy::execute()
{
    std::tuple<std::shared_ptr<XItem>, XCallError> ret;
    for(auto callback : executeCallbacks) {
        ret = callback(arguments);
        if(std::get<1>(ret).getError() == XCallError::XCallError_EnumNoError)
            return ret;
    }

    if(mainExecuteCallback)
        return mainExecuteCallback(arguments);
    return std::make_tuple(std::shared_ptr<XItem>(nullptr), XCallError(XCallError::XCallError_EnumOperatorError, L"XItemFunctionProxy::execute()"));
}
