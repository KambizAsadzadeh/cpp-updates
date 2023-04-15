#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto odd_numbers = numbers | std::views::filter([](int number){ return number % 2 != 0; });
    for (int number : odd_numbers) {
        std::cout << number << " ";
    }
    return 0;
}
