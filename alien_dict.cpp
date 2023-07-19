#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout
#include <iterator>  // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
#include <map>
#include <queue>
#include <set>
#include <list>
using namespace std;

map<char, int> find_indegree(map<char, set<char>> &graph)
{
   map<char, int> indegree;
   for (auto edge : graph)
   {
      indegree[edge.first] = 0;
   }

   for (auto edge : graph)
   {
      for (auto neighbor : edge.second)
      {
         indegree[neighbor]++;
      }
   }

   return indegree;
}

map<char, set<char>> initialize_graph(const vector<string> &words)
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

string alien_order(vector<string> words)
{
   auto graph = initialize_graph(words);
   ostringstream ss;

   for (int i = 1; i < words.size(); i++)
   {
      compare_words(words[i - 1], words[i], graph);
   }

   priority_queue<char, vector<char>, greater<char>> pq;
   auto indegree = find_indegree(graph);

   for (auto edge : indegree)
   {
      if (edge.second == 0)
      {
         pq.push(edge.first);
      }
   }
   while (!pq.empty())
   {
      auto key = pq.top();
      pq.pop();
      ss << key;
      cout << key;

      for (char edge : graph[key])
      {
         indegree[edge]--;
         if (indegree[edge] == 0)
         {
            pq.push(edge);
         }
      }
   }

   for (auto edge : indegree)
   {
      if (edge.second != 0)
      {
         return "";
      }
   }

   return ss.str();
}

template <typename T>
void put_words(const vector<T> &v)
{
   if (!v.empty())
   {
      copy(v.begin(), prev(v.end()), ostream_iterator<T>{cout, " "});
      cout << v.back();
   }
   cout << '\n';
}

template <typename T>
vector<T> get_words()
{
   string line;
   getline(cin, line);
   istringstream ss{line};
   ss >> boolalpha;
   vector<T> v;
   copy(istream_iterator<T>{ss}, istream_iterator<T>{}, back_inserter(v));
   return v;
}

int main()
{
   vector<string> words = get_words<string>();
   string res = alien_order(words);
   cout << res << '\n';
}
