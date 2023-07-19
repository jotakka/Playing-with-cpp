#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
#include <unordered_set>
#include <queue>
#include <forward_list>

using namespace std;

struct Coordinate
{
    const int i;
    const int j;
    const int val;
    Coordinate(int i, int j, int val) : i(i), j(j), val(val) {}
};

std::vector<std::vector<int>>
flood_fill(int r, int c, int replacement, std::vector<std::vector<int>> image)
{
    unordered_set<int> visited;
    auto try_set_visited = [&visited, &image](Coordinate pix) -> bool
    {
        auto idx = image[0].size() * pix.j + pix.i;
        auto is_visited = visited.find(idx) != visited.end();
        if (!is_visited)
        {
            visited.emplace(idx);
        }
        return is_visited;
    };

    auto get_neighbors = [&image](const Coordinate &pix) -> forward_list<Coordinate>
    {
        forward_list<Coordinate> neighbors;
        auto is_in_range = [&image](const int i, const int j) -> bool
        {
            auto i_in_range = (i >= 0 && i < image[0].size());
            auto j_in_range = (j >= 0 && j < image.size());
            return i_in_range && j_in_range;
        };

        vector<vector<int>> mask = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        for (const auto val : mask)
        {
            auto i = pix.i + val[0];
            auto j = pix.j + val[1];
            if (is_in_range(i, j))
            {
                cout << i << " " << j << "->" << image[j][i] << endl;
                neighbors.push_front(Coordinate(i, j, image[j][i]));
            }
        }

        return neighbors;
    };

    queue<Coordinate> pix_queue;
    pix_queue.push(Coordinate(c, r, image[r][c]));
    while (!pix_queue.empty())
    {
        auto pix = pix_queue.front();
        pix_queue.pop();
        image[pix.j][pix.i] = replacement;
        for (auto neighbor : get_neighbors(pix))
        {
            if (neighbor.val == pix.val)
            {
                if (!try_set_visited(neighbor))
                {
                    pix_queue.push(neighbor);
                }
            }
        }
    }

    return image;
}

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

int main()
{
    int r;
    std::cin >> r;
    ignore_line();
    int c;
    std::cin >> c;
    ignore_line();
    int replacement;
    std::cin >> replacement;
    ignore_line();
    int image_length;
    std::cin >> image_length;
    ignore_line();
    std::vector<std::vector<int>> image;
    for (int i = 0; i < image_length; i++)
    {
        image.emplace_back(get_words<int>());
    }
    std::vector<std::vector<int>> res = flood_fill(r, c, replacement, image);
    for (const std::vector<int> &row : res)
    {
        put_words(row);
    }
}
