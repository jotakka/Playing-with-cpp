#include <iostream> // cin, cout, streamsize
#include <limits>   // numeric_limits
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point
{
    const int x;
    const int y;
    Point(int x, int y) : x(x), y(y) {}
};

struct PointHash
{
    std::size_t operator()(const Point &point) const
    {
        return std::hash<int>{}(point.x) ^ std::hash<int>{}(point.y);
    }
};

// Equality operator for Person struct
bool operator==(const Point &lhs, const Point &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

vector<Point> get_moves(const int curr_x, const int curr_y)
{
    const vector<vector<int>> vals = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    vector<Point> moves;

    for (const auto &val : vals)
    {
        moves.push_back(Point(curr_x + val[0], curr_y + val[1]));
    }
    return moves;
}

int get_knight_shortest_path(int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 0;
    }

    queue<Point> q;
    auto path = 0;
    unordered_map<Point, int, PointHash> visited;

    q.push(Point(0, 0));
    visited[Point(0, 0)] = 0;

    while (!q.empty())
    {
        auto position = q.front();
        q.pop();

        for (const auto &move : get_moves(position.x, position.y))
        {
            auto is_visited = visited.find(move) != visited.end();
            if (!is_visited)
            {
                visited[move] = visited[position] + 1;
                if (move.x == x && move.y == y)
                {
                    return visited[move];
                }
                q.push(move);
            }
        }
    }
    return -1;
}

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    int x;
    std::cin >> x;
    ignore_line();
    int y;
    std::cin >> y;
    ignore_line();
    int res = get_knight_shortest_path(x, y);
    std::cout << res << '\n';
}
