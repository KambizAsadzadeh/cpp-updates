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
class Date {};

/*!
 * \brief The PaymentTerms class
 */
struct PaymentTerms {};

/*!
 * \brief The FactorStruct class
 */
class FactorStruct final
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
    BaseFactor(const FactorStruct& factor): m_factor(factor) {}
private:
    FactorStruct m_factor;
};

class MyFactor {
public:
    MyFactor(const std::string& str): m_str(str) {}
    std::string m_str;
};

int main() {
    if constexpr (std::constructible_from<MyFactor, BaseFactor>) {
        std::cout << "MyFactor is constructible from BaseFactor.\n";
    } else {
        std::cout << "MyFactor is not constructible from BaseFactor.\n";
    }
    return 0;
}
