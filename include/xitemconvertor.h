#ifndef XITEMCONVERTOR_H
#define XITEMCONVERTOR_H
#include <memory>
#include <xdefs.h>

class XItemConvertor
{
public:
    virtual ~XItemConvertor() = default;
public:
    virtual std::shared_ptr<XItem> asItem()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemUndefined> asUndefined()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemInt32> asInt32()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemInt64> asInt64()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemBoolean> asBoolean()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemString> asString()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemFloat> asFloat()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemDouble> asDouble()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemList> asList()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemDict> asDict()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemFunction> asFunction()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemClass> asClass()
    {
        return nullptr;
    }
    virtual std::shared_ptr<XItemModule> asModule()
    {
        return nullptr;
    }
};

#endif // XITEMCONVERTOR_H
