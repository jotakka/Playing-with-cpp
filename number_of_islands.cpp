#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <tuple>
using namespace std;

struct Coordinate
{
    const int i;
    const int j;
    const int val;
    Coordinate(int i, int j, int val = -1) : i(i), j(j), val(val) {}
};

int count_number_of_islands(std::vector<std::vector<int>> grid)
{
    auto get_neighbors = [&grid](const Coordinate &point) -> vector<Coordinate>
    {
        vector<Coordinate> neighbors;
        const vector<vector<int>> mask = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (const auto &m : mask)
        {
            auto i = point.i + m[0];
            auto j = point.j + m[1];
            auto i_is_valid = i >= 0 && i < (grid[0].size() - 1);
            auto j_is_valid = j >= 0 && j < (grid.size() - 1);

            if (i_is_valid && j_is_valid)
            {
                neighbors.push_back(Coordinate(i, j, grid[j][i]));
            }
        }
        return neighbors;
    };

    auto island_val = 1;
    queue<Coordinate> points;
    for (int i_idx = 0; i_idx < grid[0].size(); i_idx++)
    {
        for (int j_idx = 0; j_idx < grid.size(); j_idx++)
        {
            if (grid[j_idx][i_idx] == 1)
            {
                island_val++;
                points.push(Coordinate(i_idx, j_idx));
                while (!points.empty())
                {
                    auto point = points.front();
                    points.pop();
                    grid[point.j][point.i] = island_val;

                    for (const auto &neighbor : get_neighbors(point))
                    {
                        if (neighbor.val == 1)
                        {
                            points.push(neighbor);
                        }
                    }
                }
            }
        }
    }
    return island_val - 1;
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
    int res = count_number_of_islands(grid);
    std::cout << res << '\n';
}
