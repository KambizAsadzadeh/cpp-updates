//!C++98
#include <algorithm>
#include <iostream>

int main() {
    int numbers[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof (numbers) /sizeof (numbers [0]);
    std:: sort (numbers, numbers + size);
    for (int i = 0; i < size; ++i) {
        std:: cout << numbers[i] << "";
    }
    std:: cout << std::endl;
    return 0;
}

//!C++20
#include <iostream>
#include <algorithm>
#include <array>
#include <ranges>

int main() {
    std::array<int, 11> numbers {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::ranges:: sort (numbers);
    for (auto element : numbers)
    {
        std:: cout << element << std:: endl;
    }
    return 0;
}
