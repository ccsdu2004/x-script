#include <iostream>
#include <cassert>
#include <xitemboolean.h>

int main()
{
    {
        auto boolean = std::shared_ptr<XItemBoolean>();
        assert(boolean);
        boolean->setValue(true);

        std::wcout<<boolean->getItemInfo()<<std::endl;
        std::wcout<<boolean->getItemTypeInfo()<<std::endl;
    }

    {
        auto boolean = std::shared_ptr<XItemBoolean>();
        assert(boolean);
        boolean->setValue(false);

        std::wcout<<boolean->getItemInfo()<<std::endl;

        auto b1 = boolean->clone();

        assert(b1);
        std::wcout<<b1->getItemInfo()<<std::endl;
        assert(boolean->getValue() == b1->asBoolean()->getValue());

        std::wcout<<boolean->getItemInfo()<<std::endl;
        std::wcout<<boolean->getItemTypeInfo()<<std::endl;
    }

    return 0;
}
