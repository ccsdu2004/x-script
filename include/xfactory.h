#ifndef XFACTORY_H
#define XFACTORY_H
#include <map>
#include <list>
#include <memory>
#include <functional>

#define STR(str) #str
#define A_JOIN_B(a,b) a##b

template<class Product, class ID>
class XObjectFactory {
  public:
    using Creator = std::function<std::shared_ptr<Product>()>;

    inline static std::shared_ptr<std::map<ID, Creator>> creator = nullptr;
    static void initialize() {
        if (!creator)
            creator = std::make_shared<std::map<ID, Creator>>();
    }

    static std::shared_ptr<Product> create(const ID& id) {
        auto itr = creator->find(id);
        if (itr != creator->end())
            return itr->second();
        return nullptr;
    }
};

template<class Product, class Target, class ID>
class XObjectRegister : public XObjectFactory<Product, ID> {
  public:
    XObjectRegister(const ID& id) {
        XObjectFactory<Product, ID>::initialize();

        (*XObjectFactory<Product, ID>::creator)[id] = []()->std::shared_ptr<Product> {
            return std::make_shared<Target>();
        };
    }
};

#define REGISTER_OBJECT(base,product)\
    XObjectRegister<base,product,std::string> A_JOIN_B(base,product)(STR(product));

#endif
