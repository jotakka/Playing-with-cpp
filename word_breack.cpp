#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout
#include <iterator>  // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
#include <map>
#include <queue>
#include <set>
#include <list>
using namespace std;

bool startsWith(const std::string &str, const std::string &prefix)
{
    return str.compare(0, prefix.length(), prefix) == 0;
}

bool verify(std::string s, std::vector<std::string>& words, string res)
{
    if (res == s)
    {
        return true;
    }

    for (auto word : words)
    {
        auto cp = res + word;
        if (cp.length() <= word.length() && startsWith(s, cp))
        {
            if (verify(s, words, cp))
            {
                return true;
            }
        }
    }
}

bool word_break(std::string s, std::vector<std::string> words)
{
    return verify(s, words, "");
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

template <typename T>
std::vector<T> get_words()
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::string> words = get_words<std::string>();
    bool res = word_break(s, words);
    std::cout << std::boolalpha << res << '\n';
}