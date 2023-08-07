#include <algorithm>     // copy
#include <iostream>      // boolalpha, cin, cout, streamsize
#include <iterator>      // back_inserter, istream_iterator
#include <limits>        // numeric_limits
#include <sstream>       // istringstream
#include <string>        // getline, string
#include <vector>        // vector
#include <unordered_map> // vector
using namespace std;
constexpr int int_max = numeric_limits<int>::max();

int dfs(int c_idx, vector<int> &coins, int amount, vector<unordered_map<int, int>> &memo)
{
    if (amount == 0)
    {
        return 0;
    }

    if (c_idx >= coins.size())
    {
        return -1;
    }

    if (memo[c_idx].find(amount) != memo[c_idx].end())
    {
        return memo[c_idx][amount];
    }

    int max_n = amount / coins[c_idx];
    auto prev = int_max;
    for (int n = 0; n <= max_n; n++)
    {
        auto count = dfs(c_idx + 1, coins, amount - n * coins[c_idx], memo);
        if (count != -1)
        {
            prev = min(prev, n + count);
        }
    }

    auto val = prev == int_max ? -1 : prev;
    memo[c_idx][amount] = val;
    return val;
}

int coin_change(std::vector<int> coins, int amount)
{
    vector<unordered_map<int, int>> memo(coins.size());
    return dfs(0, coins, amount, memo);
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
