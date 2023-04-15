#include <iostream>
#include <ranges>

int main() {
    std::string str { "Compez's, World!"} ;
    int count = std::ranges::distance(str);
    std::cout << count << '\n'; // prints 16
    return 0;
}
