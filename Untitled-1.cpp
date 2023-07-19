#include <algorithm>  // copy
#include <iostream>   // boolalpha, cin, cout
#include <iterator>   // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream>    // istringstream
#include <string>     // getline, string
#include <vector>     // vector
#include <map>
#include <queue>
#include <set>
#include <list>
using namespace std;

map<char, set<char>> &initialize_graph(const vector<string>& words)
{
   map<char, set<char>> graph;

   for (auto word : words)
   {
      for (auto c : word)
      {
         if (graph.find(c) == graph.end())
         {
            graph[c] = set<char>();
         }
      }
   }
   return graph;
}

void compare_words(const string w1, const string w2, map<char, set<char>> &graph)
{
   auto min_length = min(w1.length(), w2.length());
   for (auto i = 0; i < min_length; i++)
   {
      if (w1[i] != w2[i])
      {
         graph[w1[i]].emplace(w2[i]);
         break;
      }
   }
}

std::string alien_order(std::vector<std::string> words)
{
   auto graph = initialize_graph(words);
   ostringstream ss;

   for (int i = 1; i < words.size(); i++)
   {
      compare_words(words[i - 1], words[i], graph);
   }

   priority_queue<char, vector<char>, greater<char>> pq;
   for (auto edge : graph)
   {
      if (edge.second.empty())
      {
         pq.push(edge.first);
      }
   }

   while (!pq.empty())
   {
      priority_queue<char, vector<char>, greater<char>> cpq;

      while (!pq.empty())
      {
         auto key = pq.top();
         pq.pop();
         ss << key;
         for (auto &edge : graph)
         {
            if (edge.second.find(key) != edge.second.end())
            {
               edge.second.erase(key);
            }

            if (edge.second.empty())
            {
               cpq.emplace(edge.first);
            }
         }
      }
      pq = cpq;
   };

   return ss.str();
}


template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
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

int main() {
    std::vector<std::string> words = get_words<std::string>();
    std::string res = alien_order(words);
    std::cout << res << '\n';
}
