#include <iostream>
#include <stack>
#include <string>
#include "bintree.h"
#include "bag6.h"

using namespace std;

int numOfTrees(int n);
void PrefixToBTree();

int main()
{
  int num;
  string ans;
  main_savitch_10::bag<int> nums;
  cout << "enter a number of nodes and I will tell you how many binary trees there are" << endl;
  cin >> num;
  cout << numOfTrees(num) << endl;
  cout << "_____________________________________________________________________________" << endl;
  std::cout << "enter an equation in prefix notation and i will convert it to a binary tree" << std::endl;
  PrefixToBTree();
  cout << "___________________________________________________________________________________" << endl;
  while(ans != "no")
  {
    cout << "give me a number to put into a binary search tree" << endl;
    cin >> num;
    nums.insert(num);
    cout << "do you want to add another number? type yes or no." << endl;
    cin >> ans;
  }
  cout << "tell me anumber and i will tell you how many times it appeares in your tree" << endl;
  cin >> num;
  cout << "Number of times " <<  num <<  " appeared in the tree : " << nums.count(num) << endl;
  // cout << "Now tell me a number to get rid of in the tree: " << endl;
  // cin >> num;
  // cout << "I removed " << nums.erase(num) << "intances of " << num << " in the tree" << endl;
  return 0;
}


//This works becasue you have a certain number of possible nodes to create the next level 
//and some of those will be dupicates so it accounts for how many are dupicates.
int numOfTrees(int n)
{
  if(n == 0 || n == 1)
  {
    return 1;
  }else
  {
    return numOfTrees(n- 1) * numOfTrees(n - 2) + numOfTrees(n-1);
  }

}

void PrefixToBTree()
{
  char leftoperand;
  char rightoperand;
  char operation;
  char temp2;
  std::stack<main_savitch_10::binary_tree_node<char>*> input;
  main_savitch_10::binary_tree_node<char>* temp;
  main_savitch_10::binary_tree_node<char>* root;
  main_savitch_10::binary_tree_node<char>* LeftChild;
  main_savitch_10::binary_tree_node<char>* RightChild;
  cin.get(temp2);
  while(std::cin.peek() != '\n')
  {
    if(std::cin.peek() == ')')
    {
     
      std::cin.get(temp2);
      root = new main_savitch_10::binary_tree_node<char>();
      LeftChild = new main_savitch_10::binary_tree_node<char>();
      RightChild = new main_savitch_10::binary_tree_node<char>();
      RightChild = main_savitch_10::tree_copy(input.top());
      input.pop();
      LeftChild = main_savitch_10::tree_copy(input.top());
      input.pop();
      root = main_savitch_10::tree_copy(input.top());
      input.pop();

      root -> set_left(LeftChild);
      root -> set_right(RightChild);
      
      input.push(root);
    }
    else if(std::cin.peek() != '(')
    {
      std::cin.get(temp2);
      temp = new main_savitch_10::binary_tree_node<char>(temp2);
      input.push(temp);
    }else
    {
      std::cin.get(temp2);
    }
  }
  main_savitch_10::print(input.top(),main_savitch_10::tree_size(input.top()));
}
