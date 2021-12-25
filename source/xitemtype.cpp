#include <xitemtype.h>

/*
bool XItem::canBySetAsKeyValue(XItemEnum type)
{
    switch (type) {
        case XItem_EnumString:
        case XItem_EnumBoolean:
        case XItem_EnumInt32:
        case XItem_EnumInt64:
            return true;
        default:
            return false;
    }
}*/

std::wstring XItemType::getStringFromType() const
{
    switch (getValueType()) {
        case XItemValueType_EnumUndefined:
            return L"XItemUndefined";
        case XItemValueType_EnumString:
            return L"XItemString";
        case XItemValueType_EnumBoolean:
            return L"XItemBoolean";
        case XItemValueType_EnumInt32:
            return L"XItemInt32";
        case XItemValueType_EnumInt64:
            return L"XItemInt64";
        case XItemValueType_EnumFloat:
            return L"XItemFloat";
        case XItemValueType_EnumDouble:
            return L"XItemDouble";
        case XItemValueType_EnumList:
            return L"XItemList";
        case XItemValueType_EnumDict:
            return L"XItemDict";
        case XItemValueType_EnumFunction:
            return L"XItemFunction";
        case XItemValueType_EnumClass:
            return L"XItemClass";
        case XItemValueType_EnumModule:
            return L"XItemModule";
        case XItemValueType_EnumCustom:
            return L"XItemCustom";
        case XItemValueType_EnumMax:
            return L"XItemMax";
        default:
            return L"XItemTypeUnkhown";
    }
}
