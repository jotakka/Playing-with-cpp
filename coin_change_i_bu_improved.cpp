#include <algorithm>     // copy
#include <iostream>      // boolalpha, cin, cout, streamsize
#include <iterator>      // back_inserter, istream_iterator
#include <limits>        // numeric_limits
#include <sstream>       // istringstream
#include <string>        // getline, string
#include <vector>        // vector
#include <unordered_map> // vector
#include <cmath>
using namespace std;
constexpr int int_max = numeric_limits<int>::max();

int coin_change(std::vector<int> coins, int amount)
{
    vector<int> amounts(amount + 1, int_max);
    amounts[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin > i)
            {
                continue;
            }
            amounts[i] = min(
                amounts[i - coin] == int_max ? int_max : amounts[i - coin] + 1,
                amounts[i]);
        }
    }

    return amounts[amount] == int_max ? -1 : amounts[amount];
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

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    std::vector<int> coins = get_words<int>();
    int amount;
    std::cin >> amount;
    ignore_line();
    int res = coin_change(coins, amount);
    std::cout << res << '\n';
}
