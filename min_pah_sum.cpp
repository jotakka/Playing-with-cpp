#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
using namespace std;

int min_path_sum(const std::vector<std::vector<int>> &grid)
{
    auto rows = grid.size();
    auto cols = grid[0].size();
    vector<vector<int>> paths(rows + 1, vector<int>(cols + 1, 0));
    paths[1][1] = grid[0][0];

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (i == 1)
            {
                paths[i][j] = paths[i][j - 1] + grid[i - 1][j - 1];
            }
            else if (j == 1)
            {
                paths[i][j] = paths[i - 1][j] + grid[i - 1][j - 1];
            }
            else
            {
                paths[i][j] = min(paths[i - 1][j], paths[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
    }
    return paths[rows][cols];
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
    int grid_length;
    std::cin >> grid_length;
    ignore_line();
    std::vector<std::vector<int>> grid;
    for (int i = 0; i < grid_length; i++)
    {
        grid.emplace_back(get_words<int>());
    }
    int res = min_path_sum(grid);
    std::cout << res << '\n';
}
