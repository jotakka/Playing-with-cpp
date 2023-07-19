#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector

int binary_search(std::vector<int> arr, int target)
{
    if (arr.empty())
    {
        return -1;
    }

    auto max = arr.size();
    auto min = 0;

    do
    {
        auto idx = (max + min) / 2;
        auto val = arr[idx];

        if (val == target)
        {
            return idx;
        }
        else if (target < val)
        {
            max = idx;
        }
        else
        {
            min = idx + 1;
        }
    } while (min < max);

    return -1;
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
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = binary_search(arr, target);
    std::cout << res << '\n';
}
