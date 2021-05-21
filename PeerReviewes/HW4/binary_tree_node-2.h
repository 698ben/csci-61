#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

template <class Item>
class binary_tree_node{
public:
//constructor
  binary_tree_node(const Item& idata = Item(),binary_tree_node* ileft = nullptr,binary_tree_node* iright = nullptr)
    : data_field(idata),left_field(ileft),right_field(iright) {}
//accessor (and mutator) functins
  Item& data() {return data_field;}
  binary_tree_node*& left() {return left_field;}
  binary_tree_node*& right() {return right_field;}
//accessor functions
  const Item& data() const {return data_field;}
  const binary_tree_node* left() const {return left_field;}
  const binary_tree_node* right() const {return right_field;}
//mutator functions
  void set_data(const Item& val) {data_field=val;}
  void set_left(binary_tree_node* new_left) {left_field=new_left;}
  void set_right(binary_tree_node* new_right) {right_field=new_right;}
private:
  Item data_field;
  binary_tree_node* left_field;
  binary_tree_node* right_field;
};

template <class Item>
void inorder_print(const binary_tree_node<Item>* node_ptr);

template <class Item>
int size(const binary_tree_node<Item>* node_ptr);

//Precondition:start>=0
//Postcondition: the entries in the binary tree pointed by the root_ptr have been inserted into the array arr
//from largest to smallest, thus forming a heap structure
template <class Item>
void fillArray(Item arr[],int& start,const binary_tree_node<Item>* root_ptr);

//This function will call the fillArray function and converts the binary tree structure into a heap in the form
//of an array and cout the result
template <class Item>
void convert_to_heap(const binary_tree_node<Item>* root_ptr);

#endif //BINARY_TREE_NODE_H
