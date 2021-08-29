#include <iostream>
#include <string>
#include "graph.h"
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cstdlib>

using namespace std;

struct doubletsVals
{
  string key;
  int distance;
  int indexOfprev;
};

void solveDoubletsPuzzle(string start, string end);

int main()
{
  main_savitch_15::graph<int> a;
  a.add_vertex(6);
  a.add_vertex(4);
  a.add_vertex(3);
  a.add_vertex(20);
  a.add_edge(0,1);
  a.add_edge(0,2);
  a.add_edge(2,3);
  //a.longestdist();
  cout << a.longestdist() << endl;
  std::cout << "________________________________________" << endl;
  string c;
  string b;
  std::cout << "any two five letter words speaerated by a space and I will find a path between them if one exist" << endl;
  cin >> c;
  cin >> b;
  std::cout << "doublets puzzle of " << c << " and " <<  b << " is solved like this: " << endl;
  solveDoubletsPuzzle(c, b);
  return 0;
}

void solveDoubletsPuzzle(string start, string end)
{
  main_savitch_15::graph<doubletsVals> data;
  ifstream fin("knuth.txt");
  string curr;
  vector<doubletsVals> copy;
  int count = 0;
  int indexOfStart = 0;
  while(fin >> curr)
  {
    doubletsVals temp = {curr, 1000000000, 0};
    copy.push_back(temp);
  }
  for(int i = 0; i < copy.size(); i++)
  {
    data.add_vertex(copy[i]);
    if(copy[i].key == start)
    {
      indexOfStart = i;
    }
  }
  for(int i = 0; i < copy.size(); i++)
  {
    for(int j = 0; j < copy.size(); j++)
    {
      for(int k = 0; k < copy[i].key.length(); k++)
      {
        if(copy[i].key[k] == copy[j].key[k])
        {
          count++;
        }
      }
      if(count == copy[i].key.length() - 1)
      {
        data.add_edge(i,j);
      }
      count = 0;
    }
  }
  bool marked[copy.size()];
  for(int i = 0; i < copy.size(); i++)
  {
    marked[i] = false;
  }
  //cout << marked.size()<< endl;
  data[indexOfStart].distance = 0;
  int index = indexOfStart;
  bool AllVisited = false;
  bool found = false;
  count = 0;
  int endindex = -1;
  set<size_t> nehibors;
  // nehibors = data.neighbors(3161);
  // for(auto it = nehibors.begin(); it != nehibors.end(); it++)
  // {
  //   cout << data[*it] << endl;
  // }
  queue<int> next;
  while(!(AllVisited) && !(found) && index != -1)
  {
    if(data[index].key == end)
    {
      found = true;
      endindex = index;
    }else
    {
      nehibors = data.neighbors(index);
      for(auto it = nehibors.begin(); it != nehibors.end(); it++)
      {
        if(data[*it].distance > data[index].distance + 1)
        {
          data[*it].distance = data[index].distance + 1;
          data[*it].indexOfprev = index;
        }
        next.push(*(it));
      }
    }
    for(int i = 0; i < copy.size(); i++)
    { 
      if(marked[i])
      {
        count++;
      }
    }
    if(count == copy.size() - 1)
    {
      AllVisited = true;
    }
    count = 0;
    if(found == false)
    {
      index = -1;
      while(marked[next.front()])
      {
        next.pop();
      }
      if(!next.empty())
      {
        index = next.front();
        next.pop();
        marked[index] = true;
      }
    }
  }
  //cout << data[57].indexOfprev << endl;
  stack<doubletsVals> reverse;
  if(endindex != -1)
  {
    std::cout << data[indexOfStart].key << endl;
    for(int i = endindex; i != indexOfStart; i = data[i].indexOfprev)
    {
      reverse.push(data[i]);
    }
    while(!reverse.empty())
    {
      std::cout << reverse.top().key << endl;
      reverse.pop();
    }
  }else
  {
    std::cout << "no path exist from " << start << " to " << end << endl;
  }
}