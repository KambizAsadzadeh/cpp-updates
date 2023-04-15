//!----> Pre-C++20
#include <iostream>

void foo(int *arr, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    foo(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}

//!----> C++20
#include <iostream>
#include <span>

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    std::span<int> span_arr(arr, 5);
    for(auto i : span_arr)
    {
        std::cout << i << " ";
    }
    return 0;
}
