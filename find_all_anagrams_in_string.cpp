#include <algorithm> // copy
#include <iostream>  // cin, cout
#include <iterator>  // ostream_iterator, prev
#include <string>    // getline, string
#include <vector>    // vector
using namespace std;

std::vector<int> find_all_anagrams(std::string original, std::string check)
{
    auto check_cp = check;
    auto length = original.length();
    auto check_len = check.length();
    auto p1 = 0;
    auto count = 0;
    sort(check_cp.begin(), check_cp.end());
    vector<int> result;

    for (; p1 <= length - check_len; p1++)
    {
        auto sub = original.substr(p1, check_len);
        sort(sub.begin(), sub.end());
        if (sub == check_cp)
        {
            result.push_back(p1);
        }
    }

    return result;
}

template <typename T>
void put_words(const std::vector<T> &v)
{
    if (!v.empty())
    {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main()
{
    std::string original;
    std::getline(std::cin, original);
    std::string check;
    std::getline(std::cin, check);
    std::vector<int> res = find_all_anagrams(original, check);
    put_words(res);
}
