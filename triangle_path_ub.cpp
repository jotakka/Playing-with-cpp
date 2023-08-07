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
class s_map
{
    unordered_map<int, int> _map;
    int _max_c;

    int get_idx(int r, int c)
    {
        return r * _max_c + c;
    }

public:
    s_map(int max_column) : _max_c(max_column)
    {
    }

    void insert(int r, int c, int val)
    {
        auto idx = get_idx(r, c);
        _map[idx] = val;
    }

    bool contains(int r, int c)
    {
        return _map.find(get_idx(r, c)) != _map.end();
    }

    int get(int r, int c)
    {
        return _map[get_idx(r, c)];
    }
};

int dfs(std::vector<std::vector<int>> &triangle, s_map &memo, int r, int c)
{
    if (r >= triangle.size())
    {
        return 0;
    }

    if (memo.contains(r, c))
    {
        return memo.get(r, c);
    }

    auto p1 = dfs(triangle, memo, r + 1, c);
    auto p2 = dfs(triangle, memo, r + 1, c + 1);

    auto min_p = triangle[r][c] + min(p1, p2);
    memo.insert(r, c, min_p);

    return min_p;
}

int minimum_total(std::vector<std::vector<int>> triangle)
{
    auto memo = s_map(triangle.size());
    return dfs(triangle, memo, 0, 0);
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
    int triangle_length;
    std::cin >> triangle_length;
    ignore_line();
    std::vector<std::vector<int>> triangle;
    for (int i = 0; i < triangle_length; i++)
    {
        triangle.emplace_back(get_words<int>());
    }
    int res = minimum_total(triangle);
    std::cout << res << '\n';
}
