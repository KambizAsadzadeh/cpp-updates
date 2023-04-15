#include <iostream>
#include <ranges>

int main() {
    std::string s = "Compez's, World!";
    auto reversed_view = std::views::reverse(s);
    std::cout << std::string(reversed_view.begin(), reversed_view.end()) << "\n";
    return 0;
}
