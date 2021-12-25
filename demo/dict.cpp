#include <iostream>
#include <cassert>
#include <xitemlist.h>
#include <xitemundefined.h>
#include <xitemint32.h>
#include <xitemint64.h>
#include <xitemstring.h>
#include <xitemboolean.h>
#include <xitemfloat.h>
#include <xitemfunction.h>
#include <xitemdict.h>
#include <xitemdouble.h>
#include <xprint.h>

class OutputItemVisitor : public XItemVisitor {
  public:
    ~OutputItemVisitor() {
    }

    void visit(std::shared_ptr<XItemUndefined> item) {
        print(item);
    }
    void visit(std::shared_ptr<XItemBoolean> item) {
        print(item);
    }
    void visit(std::shared_ptr<XItemString> item) {
        print(item);
    }
    void visit(std::shared_ptr<XItemFloat> item) {
        print(item);
    }
    void visit(std::shared_ptr<XItemDouble> item) {
        print(item);
    }
    void visit(std::shared_ptr<XItemInt32> item) {
        print(item);
    }
    void visit(std::shared_ptr<XItemInt64> item) {
        print(item);
    }
    void visit(std::shared_ptr<XItemList> item) {
        print(item);
    }
    void visit(std::shared_ptr<XItemDict> item) {
        print(item);
    }
  private:
    template<class T>
    void print(T item) {
        if (item)
            std::wcout << L"type:" << item->getItemTypeInfo() << L" key:" << item->getItemInfo() << std::endl;
    }
};

int main() {

    auto dict = std::make_shared<XItemDict>();

    dict->addItem(true, std::make_shared<XItemBoolean>());
    dict->addItem(1, std::make_shared<XItemInt32>(1234));
    dict->addItem(std::numeric_limits<int32_t>::max(), std::make_shared<XItemInt32>(std::numeric_limits<int32_t>::min()));
    dict->addItem(std::wstring(L"hello"), std::make_shared<XItemString>(L"world"));

    print(std::wcout, L"dict", dict->getItemInfo());

    auto visitor = std::make_shared<OutputItemVisitor>();
    dict->accept(visitor);

    return 0;
}
