#include <sstream>
#include <iostream>
#include <xitemmodule.h>
#include <xitemvisitor.h>

XItemModule::XItemModule()
{
    setValueType(XItemValueType_EnumModule);
}

XItemModule::~XItemModule()
{
}

void XItemModule::accept(std::shared_ptr<XItemVisitor> visitor)
{
    visitor->visit(asModule());
}

std::wstring XItemModule::getItemInfo()
{
    std::wstringstream stream;
    stream <<"XItemModule:"<<getName()<<",fileName:"<<getModuleFileName();
    return stream.str();
}

