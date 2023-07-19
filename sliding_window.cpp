#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <limits>

int subarray_sum_fixed(std::vector<int> nums, int k) {
    auto p1 =0;
    auto p2 = 0;
    auto max= std::numeric_limits<int>::min();
    auto sum = 0;
    for(int i = 0 ; i < k; i++){
        sum+= nums[i];
    }
    max = sum;

    while(p2<nums.size()){
        auto next_sum = sum - nums[p1++] +nums[++p2];
        max = std::max(sum, next_sum);
        sum = next_sum;
    }
    return sum;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> nums = get_words<int>();
    int k;
    std::cin >> k;
    ignore_line();
    int res = subarray_sum_fixed(nums, k);
    std::cout << res << '\n';
}
