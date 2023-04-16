//!----> Pre-C++20
#include <iostream>

int main() {
    const int arr[] = {1, 2, 3, 4, 5, 6, 7};
    const int n = 4;
    for (const int *ptr = arr; ptr != arr + n; ++ptr) {
        std::cout << *ptr << std::endl;
    }

    return 0;
}

//!----> C++20
#include <iostream>
#include <ranges>

int main()
{
    const int arr[] = {1, 2, 3, 4, 5, 6, 7};
    for(int i : std::views::counted(arr, 4))
    {
        std::cout << i << std::endl;
    }
}
