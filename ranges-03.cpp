#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> numbers {5, 1, 9, 3, 7, 4, 6, 8, 2};
    auto numbers_range = numbers | std::views::all;
    auto min_element = std::ranges::min_element(numbers_range);
    std::cout << "Minimum element: " << *min_element << "/n";

    return 0;
}
