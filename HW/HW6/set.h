// FILE: set.h (part of the namespace main_savitch_11)
// TEMPLATE CLASS PROVIDED: set<Item>
//   (a container template class for a set of items)
//
// TYPEDEFS for the set<Item> class:
//   set<Item>::value_type
//     set<Item>::value_type is the data type of the items in the set. It may be
//     any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
// CONSTRUCTOR for the set<Item> class:
//   set( )
//     Postcondition: The set is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the set<Item> class:
//   void clear( )
//     Postcondition: The set is empty.
//
//   bool insert(const Item& entry)
//     Postcondition: If an equal entry was already in the set, the set is
//     unchanged and the return value is false. Otherwise, entry was added
//     to the set and the return value is true. This is slightly different than
//     the C++ Standard Library set (see Appendix H).
//
//   size_t erase(const Item& target)
//     Postcondition: If target was in the set, then it has been removed from
//     the set and the return value is 1. Otherwise the set is unchanged and the
//     return value is zero.
//
// CONSTANT MEMBER FUNCTIONS for the Set<Item> class:
//   size_t count(const Item& target) const
//     Postcondition: Returns the number of items equal to the target
//     (either 0 or 1 for a set).
//
//  bool empty( ) const 
//     Postcondition: Returns true if the set is empty; otherwise returns false.
//
// VALUE SEMANTICS for the set<Item> class:
//   Assignments and the copy constructor may be used with set<Item> objects.
//
// DYNAMIC MEMORY USAGE by the set<Item> class:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: 
//   The constructors, insert, and the assignment operator.

#ifndef MAIN_SAVITCH_SET_H
#define MAIN_SAVITCH_SET_H
#include <cstdlib>   // Provides size_t

namespace main_savitch_11
{
    template <class Item>
    class set
    {
    public:
        // TYPEDEFS
        typedef Item value_type;
        // CONSTRUCTORS and DESTRUCTOR
        set( )
        { 
          data_count = 0; 
          child_count = 0;
          for(int i = 0; i < MAXIMUM + 2; i++)
          {
            subset[i] = nullptr;
          }
        }
        set(const set& source)
        {
          for(int i = 0; i< source.data_count; i++)
          {
            data[i] = source.data[i];
          }
          for(int i = 0; i< source.child_count; i++)
          {
            subset[i] = source.subset[i];
          }
          data_count = source.data_count;
          child_count = source.child_count;
        }
        ~set( ) { //clear( ); 
        }
        // MODIFICATION MEMBER FUNCTIONS
        void operator =(const set& source);
        void clear( );
        bool insert(const Item& entry);
        std::size_t erase(const Item& target);
        // CONSTANT MEMBER FUNCTIONS
        std::size_t count(const Item& target) const;
        bool empty( ) const { return (data_count == 0); }
        // SUGGESTED FUNCTION FOR DEBUGGING
        void print(int indent) const;
    private:
        // MEMBER CONSTANTS
        static const std::size_t MINIMUM = 1;
        static const std::size_t MAXIMUM = 2 * MINIMUM;
        // MEMBER VARIABLES
        std::size_t data_count;
        Item data[MAXIMUM+1];
        std::size_t child_count;
        set *subset[MAXIMUM+2];
        // HELPER MEMBER FUNCTIONS
        bool is_leaf( ) const { return (child_count == 0); }
        bool loose_insert(const Item& entry);
        bool loose_erase(const Item& target);
        void remove_biggest(Item& removed_entry);
        void fix_excess(std::size_t i);
        void fix_excess();
        void fix_shortage(std::size_t i);
        void fix_shortage();
        void moveup(size_t index, const Item& entry)
        {
          Item temp[data_count + 1];
          for(int i = 0; i < data_count; i++)
          {
            temp[i] = data[i];
          }
          if(index == data_count)
          {
            temp[data_count] = entry;
          }
          else
          {
            for(int i = 0; i < data_count + 1; i++)
            { 
              if(i == index)
              {
                temp[i] = entry;
              }else if(i > index)
              {
                temp[i] = data[i - 1];
              }
            }
          }
          for(int i = 0; i < data_count + 1; i++)
          {
            data[i] = temp[i];
          }
        }
        void moveup(size_t index, set<Item>* entry)
        {
          set<Item>* temp[child_count + 1];
          for(int i = 0; i < child_count; i++)
          {
            temp[i] = subset[i];
          }
          for(int i = 0; i < child_count; i++)
          { 
            if(i == index)
            {
              temp[i] = entry;
            }else if(i > index)
            {
              temp[i] = subset[i - 1];
            }
          }
          for(int i = 0; i < child_count; i++)
          {
            subset[i] = temp[i];
          }
        }
        void movedown(size_t index, char d)
        {
          int temp[data_count];
          for(int i = 0; i < data_count; i++)
          {
            temp[i] = data[i];
          }
          for(int i = 0; i < data_count; i++)
          { 
            if(index < i)
            {
              temp[i - 1] = data[i];
            }
          }
          for(int i = 0; i < data_count; i++)
          {
            data[i] = temp[i];
          }
        }
        void movedown(size_t index)
        {
          set<Item>* temp[child_count];
          for(int i = 0; i < child_count; i++)
          {
            temp[i] = subset[i];
          }
          for(int i = 0; i < child_count; i++)
          { 
            if(index < i)
            {
              temp[i - 1] = subset[i];
            }
          }
          for(int i = 0; i < child_count; i++)
          {
            subset[i] = temp[i];
          }
        }
        void comination(size_t i);
        void comination(size_t i, char a);
        void trasfer(size_t i);
        void trasfer(size_t i,char a);
        // NOTE: The implementor may want to have additional helper functions
      };
}
#include "set.template" // Include the implementation.

#endif
