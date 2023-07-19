#include <algorithm> // sort
#include <iostream>  // cin, cout
#include <string>    // getline, string
#include <vector>    // vector
#include <list>
#include <map>
#include <set>
using namespace std;

list<char> get_edges(string str)
{
    list<char> list(str.begin(), str.end());
    return list;
}

void get_perm(std::string letters, list<char> path, set<string> &res)
{
    if (letters.length() == 0)
    {
        res.emplace(string(path.begin(), path.end()));
        return;
    }

    for (auto edge : get_edges(letters))
    {
        size_t pos = letters.find(edge);
        if (pos != std::string::npos)
        {
            path.push_back(edge);
            auto letters_copy = letters;
            letters_copy.erase(pos, 1);
            get_perm(letters_copy, path, res);
            path.pop_back();
        }
    }
}

std::vector<std::string> permutations(std::string letters)
{
    set<string> res;
    get_perm(letters, {}, res);

    return vector(res.begin(),res.end());
}

int main()
{
    std::string letters;
    std::getline(std::cin, letters);
    std::vector<std::string> res = permutations(letters);
    std::sort(res.begin(), res.end());
    for (const std::string &line : res)
    {
        std::cout << line << '\n';
    }
}
