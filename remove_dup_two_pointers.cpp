#include <algorithm> // sort
#include <iostream>  // cin, cout, streamsize
#include <limits>    // numeric_limits
#include <string>    // string
#include <vector>    // vector
#include <list>
#include <sstream>
using namespace std;

int remove_duplicates(std::vector<int>& arr) {
    int sp =0;
    int qp = 0;

    while(qp < arr.size()){
        while(arr[sp] == arr[qp])
        {
            qp++;
        }
        if(qp < arr.size()){
            sp++;
            arr[sp] = arr[qp];
        }
    }

    return sp+1;
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> arr = get_words<int>();
    int res = remove_duplicates(arr);
    arr.resize(res);
    put_words(arr);
}
