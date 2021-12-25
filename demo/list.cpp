#include <iostream>
#include <cassert>
#include <xitemlist.h>
#include <xitemundefined.h>
#include <xitemint32.h>
#include <xitemint64.h>
#include <xitemstring.h>
#include <xitemboolean.h>
#include <xitemfloat.h>
#include <xitemfunction.h>
#include <xitemdict.h>
#include <xitemdouble.h>

class OutputItemVisitor : public XItemVisitor
{
public:
    virtual ~OutputItemVisitor(){}
    virtual void visit(std::shared_ptr<XItemUndefined> item)
    {
        if(item)
            std::wcout<<item->getItemInfo()<<std::endl;
    }
    virtual void visit(std::shared_ptr<XItemBoolean> item)
    {
        if(item)
            std::wcout<<item->getItemInfo()<<std::endl;
    }
    virtual void visit(std::shared_ptr<XItemString> item)
    {
        if(item)
            std::wcout<<item->getItemInfo()<<std::endl;
    }
    virtual void visit(std::shared_ptr<XItemFloat> item)
    {
        if(item)
            std::wcout<<item->getItemInfo()<<std::endl;
    }
    virtual void visit(std::shared_ptr<XItemDouble> item)
    {
        if(item)
            std::wcout<<item->getItemInfo()<<std::endl;
    }
    virtual void visit(std::shared_ptr<XItemInt32> item)
    {
        std::wcout<<"visit32:"<<item<<std::endl;
        if(item)
            std::wcout<<item->getItemInfo()<<std::endl;
    }
    virtual void visit(std::shared_ptr<XItemInt64> item)
    {
        if(item)
            std::wcout<<item->getItemInfo()<<std::endl;
    }
    virtual void visit(std::shared_ptr<XItemList> item)
    {
        if(item)
            std::wcout<<item->getItemInfo()<<std::endl;
    }
    virtual void visit(std::shared_ptr<XItemDict> item)
    {
        if(item)
            std::wcout<<item->getItemInfo()<<std::endl;
    }
};

int main()
{
    {
        auto list = std::make_shared<XItemList>();
        {
            auto value = std::make_shared<XItemFloat>();
            value->setValue(1.2f);
            list->addItem(value);
        }
        {
            auto value = std::make_shared<XItemDouble>();
            value->setValue(23.4);
            list->addItem(value);
        }
        {
            auto value = std::make_shared<XItemInt32>();
            value->setValue(3);
            list->addItem(value);
        }
        {
            auto value = std::make_shared<XItemInt64>();
            value->setValue(3);
            list->addItem(value);
        }
        {
            auto value = std::make_shared<XItemString>();
            value->setValue(L"Hello World");
            list->addItem(value);
        }

        std::wcout<<list->getItemTypeInfo()<<std::endl;
        std::wcout<<list->getItemInfo()<<std::endl;

        auto visitor = std::make_shared<OutputItemVisitor>();
        list->accept(visitor);
    }


    return 0;
}
