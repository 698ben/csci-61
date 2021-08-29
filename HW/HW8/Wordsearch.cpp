#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void wordsearch();

int main()
{

  wordsearch();
  return 0;
}
void wordsearch()
{
   ifstream fin("puzzle.txt");
  string test;
  vector<string> board;
  char next = fin.get();
  int g = 0;
  while(!(fin.eof()))
  {
    while(next != '\n')
    {
      if(next != ' ')
        test.push_back(next);
      next = fin.get();
    }
    board.push_back(test);
    test = "";
    next = fin.get();
  }
  fin.close();
  fin.open("words.txt");
  unordered_set<string> words;
  while(!(fin.eof()))
  {
    fin >> test;
    words.insert(test);
  }
  fin.close();
  int l = board[0].length();
  int h = board.size();
  int max = 0;

  for(auto i = words.begin(); i != words.end(); i++)
  {
    if((*i).length() > max)
    {
      max = (*i).length();
    }
  }
  ofstream fout("test.txt");
  fout << "vertical words" << endl;
  test = "";
  int k = 0;
  string reverse = "";
  for(int i = 0; i < l; i++)
  {
    unordered_set<string>::iterator check = words.end();
    for(int j = 0; j < h; j++)
    {
      for(k = 6; k < max; k++)
      {
        if(j + k <= h)
        {
          for(int z = 0; z < k; z++)
          {
            test = test + board[z + j][i];
          }
          check = words.find(test);
          if(check != words.end())
          {
            fout << *check << " from (" << j << "," << i << ")to " << "(" << j + test.length() << "," << i  << ")" << endl;
          }
          for(int y = test.length() - 1; y >= 0; y--)
          { 
            reverse.push_back(test[y]);
          }
          //cout << "test: " << test << endl << "reverse: " << reverse << endl;
          check = words.find(reverse);
          if(check != words.end())
          {
            fout << *check << " from (" << j << "," << i << ")to " << "(" << j + test.length() - 1 << "," << i << ")" << endl;
          }
          test = "";
          reverse = "";
          check = words.end();
        }
      }
    }
  }
  fout << "________________________________________" << endl
       << "horizontal words" << endl;
  test = "";
  k = 0;
  reverse = "";
  for(int j = 0; j < h; j++)
  {
    unordered_set<string>::iterator check = words.end();
    for(int i = 0; i < l; i++)
    {
      for(k = 6; k < max; k++)
      {
        if(i + k <= l)
        {
          for(int z = 0; z < k; z++)
          {
            test = test + board[j][z + i];
          }
          // cout << "test: " << test << endl;
          check = words.find(test);
          if(check != words.end())
          {
            fout << *check << " from (" << j << "," << i << ")to " << "(" << j  << "," << i + test.length() - 1  << ")" << endl;
          }
          for(int y = test.length() - 1; y >= 0; y--)
          { 
            reverse.push_back(test[y]);
          }
          check = words.find(reverse);
          if(check != words.end())
          {
            fout << *check << " from (" << j << "," << i << ")to " << "(" << j << "," << i + test.length() - 1 << ")" << endl;
          }
          test = "";
          reverse = "";
          check = words.end();
        }
      }
    }
  }
  fout << "________________________________________" << endl
       << "left-right diagonal words" << endl;
  test = "";
  k = 0;
  reverse = "";
    for(int i = 0; i < l; i++)
    {
      unordered_set<string>::iterator check = words.end();
      for(k = 6; k < max; k++)
      {
        if(i + k <= l - i)
        {
          for(int z = 0; z < k; z++)
          {
            test = test + board[z + i][z + i];
          }
          // cout << "test: " << test << endl;
          check = words.find(test);
          if(check != words.end())
          {
           fout << *check << " from (" << i << "," << i << ")to " << "(" << i + test.length()  << "," << i + test.length() - 1  << ")" << endl;
          }
          for(int y = test.length() - 1; y >= 0; y--)
          { 
            reverse.push_back(test[y]);
          }
          check = words.find(reverse);
          if(check != words.end())
          {
            fout << *check << " from (" << i << "," << i << ")to " << "(" << i + test.length() << "," << i + test.length() - 1 << ")" << endl;
          }
          test = "";
          reverse = "";
          check = words.end();
        }
      }
    }
    for(int j = 1; j < h; j++)
    {
      unordered_set<string>::iterator check = words.end();
      for(k = 6; k < max; k++)
      {
        if(j + k <= h - j)
        {
          for(int z = 0; z < k; z++)
          {
            test = test + board[z + j][z + j];
          }
          // cout << "test: " << test << endl;
          check = words.find(test);
          if(check != words.end())
          {
            fout << *check << " from (" << j << "," << j << ")to " << "(" << j + test.length()  << "," << j + test.length() - 1  << ")" << endl;
          }
          for(int y = test.length() - 1; y >= 0; y--)
          { 
            reverse.push_back(test[y]);
          }
          check = words.find(reverse);
          if(check != words.end())
          {
            std::cout << *check << " from (" << j << "," << j << ")to " << "(" << j + test.length() << "," << j + test.length() - 1 << ")" << endl;
          }
          test = "";
          reverse = "";
          check = words.end();
        }
      }
    }
    fout << "________________________________________" << endl
       << "right-left diagonal words" << endl;
  test = "";
  k = 0;
  reverse = "";
    for(int i = l - 1; i >= 0; i--)
    {
      unordered_set<string>::iterator check = words.end();
      for(k = 6; k < max; k++)
      {
        if(i + k <= l - i)
        {
          for(int z = 0; z < k; z++)
          {
            test = test + board[i - z][i - z];
          }
          // cout << "test: " << test << endl;
          check = words.find(test);
          if(check != words.end())
          {
            fout << *check << " from (" << i << "," << i << ")to " << "(" << i + test.length()  << "," << i + test.length() - 1  << ")" << endl;
          }
          for(int y = test.length() - 1; y >= 0; y--)
          { 
            reverse.push_back(test[y]);
          }
          check = words.find(reverse);
          if(check != words.end())
          {
            fout << *check << " from (" << i << "," << i << ")to " << "(" << i + test.length() << "," << i + test.length() - 1 << ")" << endl;
          }
          test = "";
          reverse = "";
          check = words.end();
        }
      }
    }
    for(int j = h - 1; j > 0; j--)
    {
      unordered_set<string>::iterator check = words.end();
      for(k = 6; k < max; k++)
      {
        if(j + k <= h - j)
        {
          for(int z = 0; z < k; z++)
          {
            test = test + board[j - z][j - z];
          }
          // cout << "test: " << test << endl;
          check = words.find(test);
          if(check != words.end())
          {
            fout << *check << " from (" << j << "," << j << ")to " << "(" << j + test.length()  << "," << j + test.length() - 1  << ")" << endl;
          }
          for(int y = test.length() - 1; y >= 0; y--)
          { 
            reverse.push_back(test[y]);
          }
          check = words.find(reverse);
          if(check != words.end())
          {
            fout << *check << " from (" << j << "," << j << ")to " << "(" << j + test.length() << "," << j + test.length() - 1 << ")" << endl;
          }
          test = "";
          reverse = "";
          check = words.end();
        }
      }
    }
    fout.close();
}