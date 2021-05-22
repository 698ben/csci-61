#include <iostream>
#include "set.h"

using namespace std;

int main()
{
  main_savitch_11::set<int> nums;
  nums.insert(1);
  nums.insert(2);
  nums.insert(3);
  nums.insert(4);
  nums.insert(5);
  nums.insert(6);
  nums.insert(7);
  nums.insert(8);
  nums.insert(9);
  nums.insert(10);
  nums.insert(11);
  nums.print(1);

  return 0;
}