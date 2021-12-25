#ifndef XITEMVISITOR_H
#define XITEMVISITOR_H
#include <xitem.h>

class XItemVisitor
{
public:
    virtual ~XItemVisitor() = default;
public:
    virtual void visit(std::shared_ptr<XItemUndefined> item);
    virtual void visit(std::shared_ptr<XItemBoolean> item);
    virtual void visit(std::shared_ptr<XItemString> item);
    virtual void visit(std::shared_ptr<XItemFloat> item);
    virtual void visit(std::shared_ptr<XItemDouble> item);
    virtual void visit(std::shared_ptr<XItemInt32> item);
    virtual void visit(std::shared_ptr<XItemInt64> item);
    virtual void visit(std::shared_ptr<XItemList> item);
    virtual void visit(std::shared_ptr<XItemDict> item);
    virtual void visit(std::shared_ptr<XItemFunction> item);
    virtual void visit(std::shared_ptr<XItemClass> item);
    virtual void visit(std::shared_ptr<XItemModule> item);
};

#endif // XITEMVISITOR_H
