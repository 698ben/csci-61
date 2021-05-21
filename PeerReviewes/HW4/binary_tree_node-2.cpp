#include "binary_tree_node-2.h"
#include <iostream>
using namespace std;

template <class Item>
void inorder_print(const binary_tree_node<Item>* node_ptr){
  if (node_ptr!=nullptr){
    inorder_print(node_ptr->left());
    cout<<node_ptr->data()<<" ";
    inorder_print(node_ptr->right());
  }
}

template <class Item>
int size(const binary_tree_node<Item>* node_ptr){
  if (node_ptr==nullptr)
    return 0;
  else{
    return 1 + size(node_ptr->left()) + size(node_ptr->right());
  }
}

template <class Item>
void fillArray(Item arr[],int& start,const binary_tree_node<Item>* root_ptr){
  if (root_ptr!=nullptr){
    fillArray(arr,start,root_ptr->right());
    arr[start++]=root_ptr->data();
    fillArray(arr,start,root_ptr->left());
  }
}

template <class Item>
void convert_to_heap(const binary_tree_node<Item>* root_ptr){
  int n = size(root_ptr);
  int start = 0;
  Item heap[n];
  fillArray(heap,start,root_ptr);
  for (int i=0;i<n;i++)
    cout<<heap[i]<<" ";
}
