#ifndef XITEMFUNCTION_H
#define XITEMFUNCTION_H
#include <vector>
#include <tuple>
#include <xitem.h>
#include <xcallerror.h>

class XItemFunction : public XItem {
  public:
    XItemFunction();
    virtual ~XItemFunction();
  public:
    void addArgument(std::shared_ptr<XItem> item);

    using FunctionReturn = std::tuple<std::shared_ptr<XItem>, XCallError>;
    virtual FunctionReturn execute();
  public:
    std::shared_ptr<XItemFunction> asFunction() override;
    void accept(std::shared_ptr<XItemVisitor> visitor) override;
    std::wstring getItemInfo()override;
  protected:
    std::vector<std::shared_ptr<XItem>> arguments;
};

#endif // XITEMINT_H
