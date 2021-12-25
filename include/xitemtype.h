#ifndef XITEMTYPE_H
#define XITEMTYPE_H
#include <string>
#include <xdefs.h>

class XItemType {
    friend class XItem;
    friend class XItemFunction;
  public:
    enum XItemValueType {
        XItemValueType_EnumUndefined = 0,
        XItemValueType_EnumString,
        XItemValueType_EnumBoolean,
        XItemValueType_EnumInt32,
        XItemValueType_EnumInt64,
        XItemValueType_EnumFloat,
        XItemValueType_EnumDouble,
        XItemValueType_EnumList,
        XItemValueType_EnumDict,
        XItemValueType_EnumFunction,
        XItemValueType_EnumClass,
        XItemValueType_EnumModule,
        XItemValueType_EnumCustom,
        XItemValueType_EnumMax
    };

    enum XItemPositionType {
        XItemPositionType_EnumNormal = 0,
        XItemPositionType_EnumArgument,
        XItemPositionType_EnumReturn,
        XItemPositionType_EnumMax
    };

    virtual ~XItemType() {}
  public:
    XItemValueType getValueType()const {
        return valueType;
    }

    std::wstring getStringFromType()const;

    XItemPositionType getPositionType()const {
        return positionType;
    }
  protected:
    void setValueType(XItemValueType type) {
        if (valueType != type) {
            valueType = type;
            onValueTypeChanged(valueType);
        }
    }

    void setPositionType(XItemPositionType type) {
        if (positionType != type) {
            positionType = type;
            onPositionTypeChanged(positionType);
        }
    }
  protected:
    virtual void onValueTypeChanged(XItemValueType type) {
        (void)type;
    }
    virtual void onPositionTypeChanged(XItemPositionType type) {
        (void)type;
    }
  private:
    XItemValueType valueType;
    XItemPositionType positionType;
};

#endif // XITEMTYPE_H
