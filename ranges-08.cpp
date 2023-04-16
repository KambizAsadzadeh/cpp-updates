#include <iostream>
#include <ranges>
#include <map>

int main()
{
    std::map<std::string, std::string> data
        {
         {"name", "C++"},
         {"informal_name", "C++2a"},
         {"standard", "ISO/IEC 14882:2020"},
         };

    //!Get keys
    for (auto const& key : std::views::keys(data))
        std::cout << key << '\n';

    //!Get values
    for (auto const& value : std::views::values(data))
        std::cout << value << '\n';
}

#include <iostream>
#include <ranges>
#include <map>

int main()
{
    std::map<std::string, std::string> data
        {
         {"name", "C++"},
         {"informal_name", "C++2a"},
         {"standard", "ISO/IEC 14882:2020"},
         };

    for (auto const& get : std::views::all(data))
        std::cout << get.first << ":" << get.second << '\n';
}
