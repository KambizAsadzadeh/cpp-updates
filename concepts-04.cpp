//!- ---> C++20
#include <iostream>
#include <concepts>

/*!
 * \brief The Person class
 */
struct Person final
{
    std::string name    {};
    std::string family  {};
};

/*!
 * \brief The Date class
 */
class Date {
public:
    std::string date {};
};

/*!
 * \brief The PaymentTerms class
 */
struct PaymentTerms {
    bool warranty;
};

/*!
 * \brief The FactorStruct class
 */
struct FactorStruct final
{
    unsigned int    uniqueId            {};

    std::string     title               {};
    std::string     description         {};

    unsigned int    invoiceNumber       {};
    unsigned int    totalAmount         {};

    Date            invoiceIssuanceDate {};
    Person          buyerName           {};
    PaymentTerms    terms               {};

};

class BaseFactor {
public:
    BaseFactor(){}
    BaseFactor(const FactorStruct& factor) {}
    virtual ~BaseFactor(){}
    virtual void print() = 0;
};

class NewFactor : public BaseFactor {
public:
    NewFactor(){}
    NewFactor(const FactorStruct& factor){}
    void print() override
    {
        std::cout << m_factor.title << std::endl;
    }
private:
    FactorStruct m_factor;
};

class MyFactor {
public:
    MyFactor(){}
    MyFactor(const NewFactor& factor){}
private:
    NewFactor m_factor;
};

class MyFactorTmp {
public:
    MyFactorTmp(){}
    MyFactorTmp(const NewFactor& factor){}
private:
    std::string fakeName() { return "I'm Fake!"; }
};

int main() {

    auto factorData = FactorStruct(); //!My factor information

    Person          p   {   .name = "Kambiz", .family = "Asadzadeh" };
    Date            d   {   .date = "2023-04-18" };
    PaymentTerms    pt  {   .warranty = true };

    //!Factor data initializing...
    factorData.uniqueId = 1;
    factorData.title = "Apple Service";
    factorData.buyerName = p;
    factorData.description = "Apple iMac 21 arm64 (M1)";
    factorData.invoiceIssuanceDate = d;
    factorData.totalAmount = 2'000;
                             factorData.terms = pt;

    auto myFactor = MyFactor(factorData); //!My new factor

    auto newFactor = NewFactor(factorData);

    auto tmpFactor = MyFactorTmp(factorData);

    if constexpr (std::constructible_from<decltype(myFactor), decltype(newFactor)>)
    {
        std::cout << " It's Standard factor.\n";
    }
    else
    {
        std::cout << " It's not Standard factor, please choose another one!\n";
    }

    static_assert(std::constructible_from<MyFactor, NewFactor> == true );
    static_assert(std::constructible_from<decltype(myFactor), decltype(newFactor)> == true );
    static_assert(std::constructible_from<decltype(myFactor), decltype(tmpFactor)> == true );

    return 0;
}
