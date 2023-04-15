#include <iostream>

using namespace std;

class Person {
public:
    void print()
    {
        //!ToDo..
    }
};

std::optional<Person> optionalPerson()
{
    return std::make_optional(Person());
}

int main()
{
    auto p = optionalPerson();
    if(p.has_value())
    {
        p->print();
    }
    return 0;
}
