#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
#include <cmath>
#include <algorithm> // std::sort

using namespace std;

int minimum_total(std::vector<std::vector<int>> triangle)
{
    vector<vector<int>> tab(2);
    tab[0] = vector<int>(triangle.size());
    tab[1] = vector<int>(triangle.size());
    tab[0][0] = triangle[0][0];
    int i = 1;
    for (; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            tab[i % 2][j] = triangle[i][j] + min(tab[(i - 1) % 2][max(0, j - 1)], tab[(i - 1) % 2][j]);
            std::cout << tab[i % 2][j] << ' \n';
        }
        std::cout << '\n';
    }
    auto last_row = tab[(i - 1) % 2];
    std::sort(last_row.begin(), last_row.end());
    return last_row[0];
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
