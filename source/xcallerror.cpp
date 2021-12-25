#include <xcallerror.h>

std::tuple<std::shared_ptr<XItem>, XCallError> XCallError::makeDivZeroError() {
    return makeError(XCallError_EnumDivZreo);
}

std::tuple<std::shared_ptr<XItem>, XCallError> XCallError::makeError(XCallError::XCallError_Enum type, const std::wstring& error) {
    return std::make_tuple<std::shared_ptr<XItem>, XCallError>(nullptr, {type, error});
}

XCallError::XCallError(XCallError::XCallError_Enum type, const std::wstring& error) {
    errorType = type;
    errorString = error;
}

XCallError::XCallError(XCallError::XCallError_Enum type, const std::wstring& error, std::weak_ptr<XItem> pointer) {
    errorType = type;
    errorString = error;
    source = pointer;
}

XCallError::XCallError(const XCallError& other) {
    source = other.source;
    errorType = other.errorType;
    errorString = other.errorString;
}

XCallError::XCallError_Enum XCallError::getError() const {
    return errorType;
}

std::wstring XCallError::getErrorString() const {
    return errorString;
}

std::weak_ptr<XItem> XCallError::getSource() const {
    return source;
}
