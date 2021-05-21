The files binary_tree_node.h,binary_tree_node.cpp,and Question1.cpp are for Question 1.
Three new functions have been added to binary_tree_node.h and implemented in binary_tree_node.cpp:
template <class Item>
int size(const binary_tree_node<Item>* node_ptr);

template <class Item>
void fillArray(Item arr[],int& start,const binary_tree_node<Item>* root_ptr);

template <class Item>
void convert_to_heap(const binary_tree_node<Item>* root_ptr);

The first two functions both serve as helper functions for the third function.
The implementation of these functions are tested in the application file Question1.cpp.

To run the program for question 1, enter the following command:
g++ Question1.cpp binary_tree_node.cpp
./a.exe

The files queue.h,queue.cpp,and main.cpp are for Question2.
No changes have been made to the first two files; changes have only been made to main.cpp.

To run the program for question 2, enter the following command:
g++ main.cpp queue.cpp
.a/.exe

Terminal results for the two questions can be found in the file terminal.png.
