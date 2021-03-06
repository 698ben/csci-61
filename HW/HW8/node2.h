#ifndef MAIN_SAVITCH_NODE2_H
#define MAIN_SAVITCH_NODE2_H
#include <cstdlib>
#include <iterator>
#include <cassert>
namespace main_savitch_6B
{
  template <class Item>
  class node
  {
    public:
      typedef Item Value_type;
      node(const Item& init_data = Item(), node* init_link = NULL)
      {data_field = init_data; link_field = init_link;}
      Item& data(){return data_field;}
      node* link(){return link_field;}
      void set_data(const Item& new_data){data_field = new_data;}
      void set_link(node* new_link){link_field = new_link;}
      const Item& data() const {return data_field;}
      const node* link() const {return link_field;}
    private:
      Item data_field;
      node *link_field;
  };
  template <class Item>
  void list_clear(node<Item>*& head_ptr)
  {
    while(head_ptr != NULL)
    {
      list_head_remove(head_ptr);
    }
  }
  template <class Item>
  void list_copy(node<Item>*& source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr)
  {
    head_ptr = NULL;
    tail_ptr = NULL;
    if(source_ptr == NULL)
    {
      return;
    }
    list_head_insert(head_ptr,source_ptr -> data());
    tail_ptr = head_ptr;
    source_ptr = source_ptr -> link();
    while(source_ptr != NULL)
    {
      list_insert(tail_ptr,source_ptr -> data());
      tail_ptr = tail_ptr -> link();
      source_ptr = source_ptr -> link();
    }
  }
  template <class Item>
  void list_head_insert(node<Item>*& head_ptr, const Item& entry)
  {
    head_ptr = new node<Item>(entry,head_ptr);
  }
  template <class Item>
   void list_head_remove(node<Item>*& head_ptr)
  {
    node<Item> *remove_ptr;

    remove_ptr = head_ptr;
    head_ptr = head_ptr -> link();
    delete remove_ptr;
  }
  template <class Item>
  void list_insert(node<Item>*& pervious_ptr, const Item& entry)
  {
    node<Item> *insert_ptr;
    insert_ptr = new node<Item>(entry,pervious_ptr -> link());
    pervious_ptr -> set_link(insert_ptr);
  }
  template <class Item>
  std::size_t list_length(const node<Item>* head_ptr)
  {
    const node<Item> *cursor;
    std::size_t answer;

    answer = 0;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link())
    {
      answer++;
    }
    return answer;
  }
  template<class Nodeptr,class SizeType>
  Nodeptr linst_locate(Nodeptr head_ptr,SizeType position)
  {
    Nodeptr cursor;
    std::size_t i;

    assert(0 < position);
    cursor = head_ptr;
    for(i = 1; (i < position) && (cursor != NULL); i++)
      cursor = cursor -> link();
    return cursor;
  }

  template <class Item>
  void list_remove(node<Item>*& pervious_ptr)
  {
    node<Item> *remove_ptr;
    remove_ptr = pervious_ptr -> link();
    pervious_ptr -> set_link(remove_ptr -> link());
    delete remove_ptr;
  }
  template<class NodePtr, class Item>
  NodePtr list_search(NodePtr head_ptr, const Item& target)
  { 
    NodePtr cursor;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link())
    {
      if(target == cursor -> data())
      {
        return cursor;
      }
    }
    return NULL;
  }
}
#endif