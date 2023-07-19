#include <iostream> // cin, cout
#include <string>   // getline, string
#include <map>
#include <list>
using namespace std;

map<string, int> memo;

list<string> get_substrs(string str)
{
    list<string> strs;
    strs.push_front(str.substr(0, 1));
    if (str.length() >= 2)
    {
        strs.push_front(str.substr(0, 2));
    }

    return strs;
}

int decode_ways(std::string digits)
{
    if (digits[0] == '0')
    {
        return 0;
    }
    if (digits.empty())
    {
        return 1;
    }

    auto sum = 0;

    for (auto substr : get_substrs(digits))
    {
        auto sub_digits = digits.substr(substr.length());

        auto memo_val = memo.find(sub_digits);
        if (memo_val != memo.end())
        {
            sum += memo_val->second;
        }
        else if (stoi(substr) <= (int)('z' - 'a'))
        {
            auto val = decode_ways(sub_digits);
            memo[sub_digits] = val;
            sum += val;
        }
    }
    return sum;
}

int main()
{
    std::string digits;
    std::getline(std::cin, digits);
    int res = decode_ways(digits);
    std::cout << res << '\n';
}
