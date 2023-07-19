#include <algorithm> // copy, sort
#include <iostream>  // boolalpha, cin
#include <iterator>  // back_inserter, istream_iterator
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
#include <unordered_map>
#include <unordered_set>

using namespace std;
std::vector<int> knapsack_weight_only(std::vector<int> weights)
{
    unordered_set<int> unique_weights;
    unordered_map<int, int> map;
    // WRITE YOUR BRILLIANT CODE HERE
    for (const auto &i : weights)
    {
        map[i]++;
    }

    auto sum = 0;
    for (auto weight : weights)
    {
        sum
            unique_weights.emplace()
    }

    return {};
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
    std::vector<int> weights = get_words<int>();
    std::vector<int> res = knapsack_weight_only(weights);
    std::sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
        {
            cout << " ";
        }
    }
    cout << "\n";
}
