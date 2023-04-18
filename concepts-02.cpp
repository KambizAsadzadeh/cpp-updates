//!- --->C++20

#include <iostream>
#include <concepts>

/*!
 * \brief The CustomerType enum
 */
enum class CustomerType
{
    Standard, Exclusive
};

template <typename T>
concept IsPerson = requires(T t) {
    { t.getName() } -> std::convertible_to<std::string>;
};

template <typename T>
concept IsCustomer = requires(T t) {
    { t.getName() } -> std::convertible_to<std::string>;
    { t.getType() } -> std::convertible_to<CustomerType>;
};

class Person {
public:
    Person(const std::string& name) : m_name(name) {}
    std::string getName() const { return m_name; }
private:
    std::string m_name;
};

class Customer : public Person{
public:
    Customer(const std::string& name, const CustomerType type)
        : Person(name), m_type(type) {}
    CustomerType getType() const { return m_type; }
private:
    CustomerType m_type;
};

template <IsPerson T>
void getPerson(const T& obj)
{
    std::cout << obj.getName() << " as a Person" <<'\n';
}

template <IsCustomer T>
void getCustomer(const T& obj) {
    switch (obj.getType()) {
    case CustomerType::Standard:
        std::cout << obj.getName() << "->" << "Standard" << '\n';
        break;
    case CustomerType::Exclusive:
        std::cout << obj.getName() << "->" << "Exclusive" << '\n';
        break;
    default:
        break;
    }}

int main()
{
    auto p = Person("Kambiz");
    auto c = Customer("Kambiz Asadzadeh", CustomerType::Exclusive);
    getPerson(p);
    getCustomer(c);
}
