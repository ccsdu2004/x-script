#include <xprint.h>

void printXResult(XCallError::XResult result) {
    auto [value, error] = result;
    if (error.getError() == XCallError::XCallError_EnumNoError)
        print(std::wcout, value->getItemInfo());
    else
        print(std::wcout, L"error:", error.getErrorString());
}
