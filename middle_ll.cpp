#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout
#include <iterator>  // back_inserter, istream_iterator
#include <sstream>   // istringstream
#include <string>    // getline, stoi, string
#include <vector>    // vector
using namespace std;

template <typename T>
struct Node
{
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr)
        : val{val}, next{next} {}

    ~Node()
    {
        delete next;
    }
};

int middle_of_linked_list(Node<int> *head)
{
    auto sp = head;
    auto qp = head->next;

    while (qp != nullptr)
    {
        sp = sp->next;
        if (qp->next != nullptr)
        {
            qp = qp->next->next;
        }else{
            break;
        }
    }

    // WRITE YOUR BRILLIANT CODE HERE
    return sp->val;
}

template <typename T, typename Iter, typename F>
Node<T> *build_list(Iter &it, Iter &end, F f)
{
    if (it == end)
        return nullptr;
    std::string val = *it;
    ++it;
    Node<T> *next = build_list<T>(it, end, f);
    return new Node<T>{f(val), next};
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
    std::vector<std::string> head_vec = get_words<std::string>();
    auto head_it = head_vec.begin();
    auto head_end = head_vec.end();
    Node<int> *head = build_list<int>(head_it, head_end, [](auto s)
                                      { return std::stoi(s); });
    int res = middle_of_linked_list(head);
    std::cout << res << '\n';
}
