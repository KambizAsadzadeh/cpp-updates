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

template <typename T>
concept IsStandard = requires(T t) {
    { t.get() } -> std::convertible_to<FactorStruct>;
};

class NewFactor : public BaseFactor {
public:
    NewFactor(){}
    NewFactor(const FactorStruct& factor) : m_factor(factor){}
    FactorStruct get() const { return m_factor; }
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
    MyFactorTmp(const FactorStruct& factor){}
private:
    std::string fakeName() { return "I'm Fake!"; }
};

template <IsStandard T>
FactorStruct getFactor(const T& obj) {
    return obj.get();
}

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
    factorData.invoiceNumber = 2023;
    factorData.totalAmount = 2'000;
                             factorData.terms = pt;

    auto myFactor = MyFactor(factorData); //!My new factor

    auto newFactor = NewFactor(factorData); //! New factor (Original)

    auto tmpFactor = MyFactorTmp(factorData); //! Fake factor

    if constexpr (std::constructible_from<decltype(myFactor), decltype(newFactor)>)
    {
        std::cout << " It's Standard factor.\n";
    }
    else
    {
        std::cout << " It's not Standard factor, please choose another one!\n";
    }

    auto printableData = FactorStruct();
    printableData = getFactor(newFactor);

    //!Print Factor
    {
        std::cout << "Unique ID:" << printableData.uniqueId << std::endl;
        std::cout << "Title:" << printableData.title << std::endl;
        std::cout << "Buyer Name:" << printableData.buyerName.name << std::endl;
        std::cout << "Invoice Number:" << printableData.invoiceNumber << std::endl;
        std::cout << "Total Amount:" << printableData.totalAmount << "$" << std::endl;
        //ToDo...[printableData]
    }

    getFactor(tmpFactor); //Error fake factor! [Compile time]

    static_assert(std::constructible_from<MyFactor, NewFactor> == true ); //OK
    static_assert(std::constructible_from<decltype(myFactor), decltype(newFactor)> == true ); //OK
    static_assert(std::constructible_from<decltype(myFactor), decltype(tmpFactor)> == true ); //[Compile time]

    return 0;
}
