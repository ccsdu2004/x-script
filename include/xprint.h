#ifndef XPRINT_H
#define XPRINT_H
#include <iostream>
#include <xcallerror.h>

template <class Output, class FirstType, class... Args>
void print(Output& output, FirstType first, Args... args) {
    output << first;
    auto printWhiteSpace = [&](const auto arg) {
        output << L" " << arg;
    };
    (..., printWhiteSpace(args));

    output << "\n";
}

void printXResult(XCallError::XResult result);

#endif // XPRINTER_H
