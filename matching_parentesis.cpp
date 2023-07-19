#include <algorithm> // sort
#include <iostream>  // cin, cout, streamsize
#include <limits>    // numeric_limits
#include <string>    // string
#include <vector>    // vector
#include <list>
#include <sstream>
using namespace std;

vector<string> get_edges()
{
    return {"(", ")"};
}

void get_combinations(int n, int open, int closed, list<string> path, vector<string>& res)
{
    if (open == n && closed == n)
    {
        ostringstream ss; 
        for(auto p : path){
            ss<<p;
        }
        res.push_back(ss.str());
        return;
    }

    if(open < n){
        path.push_back("(");
        get_combinations(n, open+1, closed, path, res);
        path.pop_back();
    }
    if(closed <n && closed < open){
        path.push_back(")");
        get_combinations(n, open, closed+1, path, res);
        path.pop_back();
    }
}

std::vector<std::string> generate_parentheses(int n)
{
    vector<string> res;
    get_combinations(n, 0, 0, {}, res);
    return res;
}

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    int n;
    std::cin >> n;
    ignore_line();
    std::vector<std::string> res = generate_parentheses(n);
    std::sort(res.begin(), res.end());
    for (const std::string &line : res)
    {
        std::cout << line << '\n';
    }
}
