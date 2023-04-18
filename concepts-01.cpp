//!- --->C++20

#include <iostream>
#include <concepts>

template<typename T>
concept Integer = std:: is_integral<T>:: value;

template <Integer T>
T add (T a, T b) {
    return a + b;
}

int main()
{
    int a = 5;
    int b = 2;
    double c = 3.14; //! is double!? it's not as integral!
    std:: cout << add (a, b) << std:: endl; //!Prints std::
}
