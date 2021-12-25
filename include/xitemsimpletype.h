#ifndef XITEMSIMPLETYPE_H
#define XITEMSIMPLETYPE_H
#include <sstream>
#include <xitem.h>

template<class T>
class XItemSimpleType : public XItem
{
public:
    XItemSimpleType() = default;
    XItemSimpleType(const T &newValue):
        value(newValue)
    {
    }

    virtual ~XItemSimpleType() = default;
public:
    void setValue(const T &newValue)
    {
        if (value != newValue) {
            value = newValue;
            onValueChanged(newValue);
        }
    }

    T getValue()const
    {
        return value;
    }

    virtual std::wstring getItemInfo()override
    {
        std::wstringstream stream;
        stream << value;
        return stream.str();
    }
protected:
    virtual void onValueChanged(const T &newValue)
    {
        (void)newValue;
    }
protected:
    T value;
};

#endif // XITEMTYPE_H
