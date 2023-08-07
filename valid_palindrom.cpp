#include <iostream> // boolalpha, cin, cout
#include <string>   // getline, string
#include <algorithm>
#include <cctype>

using namespace std;
bool is_palindrome(std::string str)
{
    str.erase(remove_if(str.begin(), str.end(), [](char c)
                        { return !isalnum(c); }),
              str.end());

    transform(str.begin(), str.end(), str.begin(), [](char c)
              { return tolower(c); });

    auto cp = str;
    reverse(cp.begin(), cp.end());

    return str.compare(cp) == 0;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);
    bool res = is_palindrome(s);
    std::cout << std::boolalpha << res << '\n';
}
