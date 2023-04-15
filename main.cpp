consteval int factorial(int n) {
    if (n < 2) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    constexpr int result = factorial(5);
    static_assert(result == 120);
    return 0;
}
