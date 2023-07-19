#include <algorithm>     // copy
#include <iostream>      // boolalpha, cin, cout, streamsize
#include <iterator>      // back_inserter, istream_iterator
#include <limits>        // numeric_limits
#include <sstream>       // istringstream
#include <string>        // getline, string
#include <vector>        // vector
#include <unordered_map> // vector
#include <stack>         // vector
using namespace std;

enum class NodeState
{
    NotVisited,
    Visiting,
    Visited,
};

struct Node
{
    vector<int> neighbors;
    NodeState state;
};

bool is_valid(int node, unordered_map<int, Node> &graph)
{
    graph[node].state = NodeState::Visiting;

    for (auto const n : graph[node].neighbors)
    {
        if (graph[n].state == NodeState::Visiting)
        {
            return false;
        }
        if (graph[n].state == NodeState::Visited)
        {
            continue;
        }
        if (!is_valid(n, graph))
        {
            return false;
        }
    }
    graph[node].state = NodeState::Visited;
    return true;
}

bool is_valid_course_schedule(int n, std::vector<std::vector<int>> prerequisites)
{
    unordered_map<int, Node> graph;
    stack<int> s;

    for (auto i = 0; i < n; i++)
    {
        graph[i] = Node();
    }

    for (auto val : prerequisites)
    {
        graph[val[0]].neighbors.push_back(val[1]);
    }

    return is_valid(0, graph);
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

int main()
{
    int n;
    std::cin >> n;
    ignore_line();
    int prerequisites_length;
    std::cin >> prerequisites_length;
    ignore_line();
    std::vector<std::vector<int>> prerequisites;
    for (int i = 0; i < prerequisites_length; i++)
    {
        prerequisites.emplace_back(get_words<int>());
    }
    bool res = is_valid_course_schedule(n, prerequisites);
    std::cout << std::boolalpha << res << '\n';
}
