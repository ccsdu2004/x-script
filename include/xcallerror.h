#ifndef XCALLERROR_H
#define XCALLERROR_H
#include <memory>
#include <string>
#include <tuple>
#include <xitem.h>

class XCallError {
  public:
    enum XCallError_Enum {
        XCallError_EnumNoError = 0,
        XCallError_EnumUnreachedError,
        XCallError_EnumArgumentCountError,
        XCallError_EnumArgumentTypeError,
        XCallError_EnumOutOfRangeError,
        XCallError_EnumOperatorError,
        XCallError_EnumDivZreo
    };

    using XResult = std::tuple<std::shared_ptr<XItem>, XCallError>;

    static XResult makeDivZeroError();
    static XResult makeError(XCallError_Enum type, const std::wstring& error = L"");
  public:
    XCallError() = default;
    XCallError(XCallError_Enum type, const std::wstring& error = L"");
    XCallError(XCallError_Enum type, const std::wstring& error, std::weak_ptr<XItem> pointer);
    XCallError(const XCallError& other);
  public:
    XCallError_Enum getError()const;
    std::wstring getErrorString()const;
    std::weak_ptr<XItem> getSource()const;
  private:
    XCallError_Enum errorType;
    std::wstring errorString;
    std::weak_ptr<XItem> source;
};

template<class Item, class Value>
inline std::tuple<std::shared_ptr<Item>, XCallError> makeItemNoError(Value value) {
    return std::make_tuple(std::make_shared<Item>(value), XCallError(XCallError::XCallError_EnumNoError));
}

template<class Item, class Value>
inline std::tuple<Item, XCallError> makeValueNoError(Value value) {
    return std::make_tuple(value, XCallError(XCallError::XCallError_EnumNoError));
}

#endif // XCALLERROR_H
