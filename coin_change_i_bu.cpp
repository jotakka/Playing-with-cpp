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
    vector<vector<int>> tab(2);
    tab[1] = vector<int>(amount + 1, -1);
    tab[1][0] = 0;
    int i = 0;
    for (; i < coins.size(); i++)
    {
        auto curr_coin = coins[i];

        auto curr_i = (i) % 2;
        auto prev_i = (i + 1) % 2;
        tab[curr_i] = tab[prev_i];

        for (int j = curr_coin; j <= amount; j++)
        {
            auto min_above = tab[prev_i][j] == -1 ? int_max : tab[prev_i][j];
            auto min_row = tab[curr_i][max(0, j - curr_coin)] == -1 ? int_max : tab[curr_i][max(0, j - curr_coin)] + 1;

            auto min_c = curr_coin ? min(min_above, min_row) : min_above;
            min_c = min_c == int_max ? -1 : min_c;
            tab[curr_i][j] = min_c;
        }
    }

    return tab[(i + 1) % 2][amount];
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
