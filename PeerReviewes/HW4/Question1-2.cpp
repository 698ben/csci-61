#include "binary_tree_node-2.h"
#include "binary_tree_node-2.cpp"

int main(){
  binary_tree_node<int> *root,*child1,*child2;
  root = new binary_tree_node<int>(21);
  root->set_left(new binary_tree_node<int>(19));
  root->set_right(new binary_tree_node<int>(45));
  child1 = root->left();
  child2 = root->right();
  child1->set_left(new binary_tree_node<int>(16));
  child1->set_right(new binary_tree_node<int>(20));
  child2->set_left(new binary_tree_node<int>(36));
  child2->set_right(new binary_tree_node<int>(50));

  convert_to_heap(root);

  return 0;
}
