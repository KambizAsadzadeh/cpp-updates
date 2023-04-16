//!----> Pre-C++20
#include <iostream>
#include <string>

int main()
{
    const std::string words = "Com<!/pez<!/'s Wor<!/ld!";
    const std::string delim = "<!/";

    auto it = words.begin();
    for (auto end = words.end(); it != end; ) {
        const auto tokenEnd = std::search(it, end, delim.begin(), delim.end());
        std::cout << std::string(it, tokenEnd);
        if (tokenEnd == end) {
            break;
        }
        it = tokenEnd + delim.size();
    }
    return 0;
}

//!----> C++20
#include <iostream>
#include <ranges>
#include <string_view>

int main()
{
    constexpr std::string_view words{"Com<!/pez<!/'s Wor<!/ld!"};
    constexpr std::string_view delim{"<!/"};
    for (const auto word : std::views::split(words, delim))
        std::cout << std::string_view{word.begin(), word.end()};
}
