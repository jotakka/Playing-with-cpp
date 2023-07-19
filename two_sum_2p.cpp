#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
using namespace std;

std::vector<int> two_sum_sorted(std::vector<int> arr, int target)
{
    int p1 = 0;
    int p2 = arr.size() - 1;

    while (p1 < p2)
    {
        auto curr_sum = arr[p1] + arr[p2];
        if (curr_sum == target)
        {
            return {p1, p2};
        }
        else if (curr_sum < target)
        {
            p1++;
        }
        else
        {
            p2--;
        }
    }

    return {p1, p2};
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
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    std::vector<int> res = two_sum_sorted(arr, target);
    put_words(res);
}
