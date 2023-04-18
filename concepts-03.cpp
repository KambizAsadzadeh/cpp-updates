//!- ---> C++20
#include <iostream>
#include <concepts>

class Person {};
class Developer: public Person {};
class Designer: private Person {};

int main() {

    if(std::derived_from<Developer, Person>)
    {
        std::cout << "Developer is dericed from Person class!\n";
    }

    static_assert( std::derived_from<Developer, Developer> == true );   // same class: true
    static_assert( std::derived_from<int, int> == false );              // same primitive type: false
    static_assert( std::derived_from<Developer, Person> == true );      // public inheritance: true
    static_assert( std::derived_from<Designer, Developer> == false );   // private inheritance: false

}
