#include <iostream> // cin, cout, streamsize
#include <limits>   // numeric_limits
#include <vector>   // numeric_limits

using namespace std;

int unique_paths(int m, int n)
{
    vector<vector<int>> paths(m + 1, vector<int>(n + 1, 0));

    paths[1][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            paths[i][j] = paths[i][j - 1] + paths[i - 1][j] + paths[i][j];
        }
    }

    return paths[m][n];
}

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    int m;
    std::cin >> m;
    ignore_line();
    int n;
    std::cin >> n;
    ignore_line();
    int res = unique_paths(m, n);
    std::cout << res << '\n';
}
