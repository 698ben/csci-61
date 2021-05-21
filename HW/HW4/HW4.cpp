#include <iostream>
#include "bintree.h"
#include <stdlib.h>

using namespace std;

main_savitch_10::binary_tree_node<int>* heapisfication( main_savitch_10::binary_tree_node<int>* root);

void swap(main_savitch_10::binary_tree_node<int>* a, main_savitch_10::binary_tree_node<int>* b);

int tree_max(main_savitch_10::binary_tree_node<int>* root);

struct student
{
  int length;
  int time;
  int priority;
};

class averager
{
  public:
    void sum(int a)
    {
      total = total + a;
      quantity++;
    }
    double answer()
    {
      return total/quantity;
    }
  private:
    int total = 0;
    double quantity = 0;

};

class pQueue
{
  private:
    student* data;
    int used;
    int max = 100;
  public:
    pQueue(student init_data)
    {
      data = new student[max];
      data[0] = init_data;
      used = 1;
    }
    pQueue()
    {
      data = new student[max];
      used = 0;
    }
    ~pQueue()
    {
      delete data;
    }
    void insert(student new_data)
    {
      student temp[used];
      if(used < max)
      {
        data[used] = new_data;
        //data++;
      }else
      {
        for(int i = 0; i < used; i++)
        {
          temp[i] = data[i];
        }
        delete data;
        max = max * 2;
        data = new student[max];
        for(int i = 0; i < used; i++)
        {
          data[i] = temp[i];
        }
        data[used] = new_data;
      }
      int i = used;
      used++;
      while ( i > 0 && (data[i].priority > data[(i - 1) / 2].priority))
      {
        student temp2 = data[i];
        data[i] = data[(i - 1) / 2];
        data[(i - 1) / 2] = temp2;
        i = (i - 1) / 2; 
      }
      
    }
    student front()
    {
      return data[0];
    }
    void remove()
    {
      student ans;
      
      data[0] = data[used - 1];
      used--;
      int i = 0;
      student temp;
      while(((i * 2) + 2 < used - 1) || (data[i].priority < data[(i * 2) + 1].priority  || data[i].priority < data[(i * 2) + 2].priority))
      {
        if(data[(i * 2) + 1].priority > data[(i * 2) + 2].priority )
        {
          temp = data[(i * 2) + 1];
          data[(i * 2) + 1] = data[i];
          data[i] = temp;
          i = (i * 2) + 1;
        }else
        {
          temp = data[(i * 2) + 2];
          data[(i * 2) + 2] = data[i];
          data[i] = temp;
          i = (i * 2) + 2;
        }
      }
    }
    bool empty()
    {
      return used > 0;
    }
    void print()
    {
      for(int i = 0; i < used; i++)
      {
        cout << data[i].priority << ", ";
      }
      cout << endl;
    }
};

void officeHours(averager& a, averager& b, averager& c, int prob, int min, int max);
void insert(main_savitch_10::binary_tree_node<int>* root, int entry);
int depth( main_savitch_10::binary_tree_node<int>* root);
main_savitch_10::binary_tree_node<int>* transfer(main_savitch_10::binary_tree_node<int>* root);
main_savitch_10::binary_tree_node<int>* find_next(main_savitch_10::binary_tree_node<int>* root, int depth);
void heapification_upward(main_savitch_10::binary_tree_node<int>* root);


int main()
{
  // main_savitch_10::binary_tree_node<int>* root;
  // main_savitch_10::binary_tree_node<int>* child;

  // root = new main_savitch_10::binary_tree_node<int>((40));
  // child = new main_savitch_10::binary_tree_node<int>(50);
  // root -> set_left(child);
  // child = new main_savitch_10::binary_tree_node<int>(30);
  // root -> left() -> set_left(child);
  // child = new main_savitch_10::binary_tree_node<int>(60);
  // root -> left() -> set_right(child);
  // child = new main_savitch_10::binary_tree_node<int>(20);
  // root -> set_right(child);
  // heapisfication(root);
  // main_savitch_10::print(root, depth(root));
  averager a;
  averager b;
  averager c;
  int prob = 0;
  int min = 0;
  int max = 0;
  cout << "enter the probility of a stduent arrving every second(a number between 0 and 100)" << endl;
  cin >> prob;
  cout << "enter the minimum then the maximum question length in seconds sperated by a space" << endl;
  cin >> min;
  cin >> max;
  max++;
  for(int i = 0; i< 100; i++)
  {
    officeHours(a,b,c,prob,min,max);
  }
  cout << "average time a student spends is line is: " << a.answer() << endl
       << "average time a student spends with the professor is: " << b.answer() << endl
       << "average time a professor spends after the intended time is: " << c.answer() << endl;
  return 0;
}

void officeHours(averager& a, averager& b, averager& c, int prob, int min, int max)
{
  const int totalLength = 60;
  const int interations = 100;
  pQueue waiting;
  int length = 0;
  int chance = 0;
  int current = 0;
  srand(time(0));
    while(length <= 60 || waiting.empty() || current > 0)
    {
      chance = (rand() % 101) + 1;
      if(chance <= prob & length <= 60)
      {
        //cout << "1" << endl;
        student t = {(rand() % (max - min)) + min, length, (rand() % (11)) + 1 };
        waiting.insert(t);
      }
      //cout << current << " " << waiting.empty() << endl;
      if(current == 0 && waiting.empty())
      {
        //cout << "2" << endl;
        current = waiting.front().length;
        a.sum(length - waiting.front().time );
        b.sum(current);
        waiting.remove();
      }
      if(current > 0)
        current--;
        length++;
    }
    c.sum(length - totalLength);
}
main_savitch_10::binary_tree_node<int>* heapisfication( main_savitch_10::binary_tree_node<int>* root)
{
  return transfer(root);
  
}
//creates a new binary tree node use the inster functions for heaps using the supplied binary tree data.
main_savitch_10::binary_tree_node<int>* transfer(main_savitch_10::binary_tree_node<int>* root)
{
  main_savitch_10::binary_tree_node<int>* temp;
  if(root == nullptr)
  {
    return new main_savitch_10::binary_tree_node<int>(root -> data());
  }else
  {
    temp = transfer(root);
    insert(temp, root -> data());
  }
  return temp;
}


void swap(main_savitch_10::binary_tree_node<int>* a, main_savitch_10::binary_tree_node<int>* b)
{
  main_savitch_10::binary_tree_node<int>* oldroot;
  oldroot = new main_savitch_10::binary_tree_node<int>(a -> data());
  //oldroot = a;
  a -> set_data(b-> data());
  if(a -> left() == b)
    a -> set_left(oldroot);
  else
    a -> set_right(oldroot);
  oldroot -> set_left(b -> left());
  oldroot -> set_right(b -> right());
}

int tree_max(main_savitch_10::binary_tree_node<int>* root)
{
  if(root == nullptr)
  {
    return 0;
  }else
  {
    if(tree_max(root -> left()) > root -> data() && (tree_max(root -> left()) > tree_max(root -> right()) ))
    {
      return root -> left() -> data();
    }else if (tree_max(root -> right()) > root -> data() && (tree_max(root -> right()) > tree_max(root -> left()) ))
    {
      return root -> right() -> data();
    }else if(root -> left() == nullptr || root -> right() == nullptr)
    {
      return root -> data();
    }
  }
}

int depth( main_savitch_10::binary_tree_node<int>* root)
{
  int height = 0;

  main_savitch_10::binary_tree_node<int>* cursor = root;

  while(cursor != nullptr)

    if(cursor -> left() == nullptr && cursor -> right() != nullptr)

    {

      height++;

      cursor = cursor -> right();

    }else if(cursor -> right() == nullptr && cursor -> left() != nullptr)

    {

      height++;

      cursor = cursor -> left();

    }else

    {

      height++;

      cursor = cursor -> left();

  }
  return height;
}
//looks for the next avalible spot in the tree then insters it there and does the heapification upward algorithim.
void insert(main_savitch_10::binary_tree_node<int>* root, int enrty)
{
  main_savitch_10::binary_tree_node<int>* next;
  next = find_next(root, depth(root));
  main_savitch_10::binary_tree_node<int>* new_data;
  new_data = new main_savitch_10::binary_tree_node<int>();
  new_data -> set_data(enrty);
  if(next -> left() == nullptr )
  {
    next -> set_left(new_data);
  }else
  {
    next -> set_right(new_data);
  }
  heapification_upward(root);

}
//attemps to find the next availible spot in the provided binary tree
main_savitch_10::binary_tree_node<int>* find_next(main_savitch_10::binary_tree_node<int>* root, int depth)
{
  if(root -> left() == nullptr && root -> right() == nullptr && depth == 1)
  {
    return root;
  }else if(root -> left() == nullptr && root -> right() == nullptr)
  {
    //return find_next(root -> right(), --depth - 1);

  }
  if(root -> right() != nullptr)
  {
    return find_next(root -> right(), --depth - 1);
  }
  if(root -> left() != nullptr)
  {
    return find_next(root -> right(), --depth - 1);
  }
}
//this is the heapiification upward alg. that looks at the kids of the node and swaps them if they are larger than the parent
void heapification_upward(main_savitch_10::binary_tree_node<int>* root)
{
  if(root -> left() == nullptr && root -> right() == nullptr)
  {
    return;
  }else
  {
    if(root -> left() -> data() > root -> data())
    {
      swap(root, root -> left());
    }
    if(root -> right() -> data() > root -> data())
    {
      swap(root, root -> right());
    }
    heapification_upward(root -> left());
    heapification_upward(root -> right());
    heapification_upward(root);
  }
}