#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector

int first_not_smaller(std::vector<int> arr, int target)
{
    auto smaller_than_target = [target](int a) -> bool
    { a < target; };
    auto max = arr.size();
    auto min = 0;
    do
    {
        auto idx = (max + min) / 2;
        if ((!smaller_than_target(arr[idx])) && (idx == 0 || smaller_than_target(arr[idx - 1])))
        {
            return idx;
        }
        if (smaller_than_target(arr[idx]))
        {
            min = idx;
        }
        else
        {
            max = idx + 1;
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
    int res = first_not_smaller(arr, target);
    std::cout << res << '\n';
}
