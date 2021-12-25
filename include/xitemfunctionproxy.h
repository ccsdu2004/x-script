#ifndef XITEMFUNCTIONPROXY_H
#define XITEMFUNCTIONPROXY_H
#include <functional>
#include <vector>
#include <xitemfunction.h>

class XItemFunctionProxy : public XItemFunction {
  public:
    XItemFunctionProxy();
    virtual ~XItemFunctionProxy();
  public:
    using ExecuteCallback = std::function<FunctionReturn(const std::vector<std::shared_ptr<XItem>>&)>;
    void setExecuteCallback(ExecuteCallback callback);
    void setMainExecuteCallback(ExecuteCallback callback);

    virtual FunctionReturn execute()override;
  private:
    std::vector<ExecuteCallback> executeCallbacks;
    ExecuteCallback mainExecuteCallback;
};

#endif // XITEMFUNCTIONPROXY_H


