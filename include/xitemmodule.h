#ifndef XITEMMODULE_H
#define XITEMMODULE_H
#include <xitemcontainer.h>

class XItemModule : public XItemContainer
{
public:
    XItemModule();
    ~XItemModule();
public:
    void setModuleFileName(const std::wstring &fileName);
    std::wstring getModuleFileName()const;
public:
    std::shared_ptr<XItemModule> asModule() override
    {
        return std::dynamic_pointer_cast<XItemModule>(shared_from_this());
    }
    void accept(std::shared_ptr<XItemVisitor> visitor)override;
    std::wstring getItemInfo()override;
private:
    std::wstring moduleFileName;
};

#endif // XITEMMODULE_H
