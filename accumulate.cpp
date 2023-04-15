#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    std::cout << "Sum = " << sum << std::endl;
    return 0;
}

#include <iostream>
#include <numeric>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int sum = std::accumulate(arr, arr + 5, 0);
    std::cout << "Sum = " << sum << std::endl;
    return 0;
}
