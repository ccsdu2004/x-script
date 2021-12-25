#ifndef XITEMLIST_H
#define XITEMLIST_H
#include <xitemcontainer.h>
#include <iostream>

class XItemList : public XItemContainer
{
public:
    XItemList();
    ~XItemList();
public:
    std::shared_ptr<XItemList> asList() override
    {
        return std::dynamic_pointer_cast<XItemList>(shared_from_this());
    }
public:
    std::wstring getItemInfo()override;
};



#endif // XITEMINT_H
