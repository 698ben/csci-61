//implementation of set.h
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
        set( ){ //0 arg constructor
          //Postcondition: the set is empty
          data_count=0;
          child_count=0;
        }
        set(const set& source){//copy constructor
          data_count=0;
          child_count=0;
          for (int i=0; i<source.data_count; i++){
            data[i]=source.data[i];
            data_count++;
          }
          for (int i=0; i<source.child_count; i++){
            //create set
            subset[i]=new set(*source.subset[i]);
            child_count++;
          }
        }
        ~set( ) { clear( );}//destructor
        // MODIFICATION MEMBER FUNCTIONS
        void operator =(const set& source{
          data_count=0;
          child_count=0;
          for (int i=0; i<source.data_count; i++){
            data[i]=source.data[i];
            data_count++;
          }
          for (int i=0; i<source.child_count; i++){
            //create set
            subset[i]=new set(*source.subset[i]);
            child_count++;
          }
        }

        void clear( ){
          //Postcondition: the set is empty
          for (int i=0; i<child_count; i++){
            subset[i]->clear();
          }
          child_count=0;
          data_count=0;
        }

        bool insert(const Item& entry){

          if (!loose_insert(entry))
            return false;
          if (data_count>MAXIMUM){
            set<Item> * s=new set<Item>();
            for(int i=0; i<data_count; i++){
              s->data[i]=data[i];
            }
            for(int i=0; i<child_count; i++){
              s->subset[i]=subset[i];
            }
            s->data_count=data_count;
            s->child_count=child_count;
            data_count=0;
            child_count=1;
            subset[0]=s;
            fix_excess(0);
          }
          return true;
            //Fix the root of the entire tree so that it no longer has too many entries.
          //Return true.

        }
        std::size_t erase(const Item& target){
          /*PSEUDOCODE
            if (!loose_erase(target))
              Return false since loose_erase did not remove an entry from the set.
            if ((data_count==0)&&(child_count ==1))
              Fix the root of the entire tree so that it no longer has zero entries.
            Return true since an entry was removed from the set.
          */
        }
        // CONSTANT MEMBER FUNCTIONS
        std::size_t count(const Item& target) const{
          //Postcondition:
          //     Returns the number of items equal to the target
          //     (either 0 or 1 for a set).
        }
        //bool empty( ) const { return (data_count == 0); }//returns true if the set it empty, otherwise returns false
        // SUGGESTED FUNCTION FOR DEBUGGING
        void print(int indent) const{
          //print tree
        }
    private:
        // MEMBER CONSTANTS
        static const std::size_t MINIMUM = 200;
        static const std::size_t MAXIMUM = 2 * MINIMUM;
        // MEMBER VARIABLES
        std::size_t data_count;
        Item data[MAXIMUM+1];
        std::size_t child_count;
        set *subset[MAXIMUM+2];
        // HELPER MEMBER FUNCTIONS
        bool is_leaf( ) const { return (child_count == 0); }

        bool loose_insert(const Item& entry){
          /*PSEUDOCODE
          //finds the first location in the root's entries that is not less than the new entry
          1. Make a local variable, i, equal to the first index such that data[i]
          is not less than the entry. If there is no such index, then set i equal to data_count,
          indicating that all entries are less than the target.

          2.
          if (we found the new entry at data[i])
            2a. Return false with no further work (since the new entry is already in the set)
          else if (root has no children)
            2b. Add the new entry to the root at data[i]. (The original entries at data[i] and
            afterwards must be shifted right to make room for the new entry.) Return true to
            indicate that we added the entry.
          else
            2c. Save the value from this recursive call:
            subset[i]->loose_insert(entry);
            Then check whether the root of subset[i] now has an excess entry; if so, then fix that problem
            Return the saved value from the recursive call.
          */
        }

        bool loose_erase(const Item& target){
        /*PSEUDOCODE
          1. Make a local variable, i, equal to the first index such that data[i]
          is not less than the target. If there is no such index, then set i equal to data_count,
          indicating that all entries are less than the target.

          2.
          (a)The root has no children, and we did not find the target. In this case, there is no work to do,
          since the target is not in the set (return false).
          (b)The root has no children, and we found the target: In this case, remove the target from the
          data array, and return true,
          (c)The root has children, and we did not find the target (see following)
            subset[i]->loose_erase(target);
            if (subset[i]->data_count<MINIMUM)
              fix_shortage(i);
            return true;
          (d)The root has children, and we found the target (see following)
            subset[i]->remove_biggest(data[i]);
            if (subset[i]->data_count<MINIMUM)
              fix_shortage(i);
            return true;
        */
        }

        void remove_biggest(Item& removed_entry){
        /*PSEUDOCODE
          if (root has no children)
            copy the last item of data into the reference parameter, removed_entry.
            subtract one from data_count
          else
            subset[child_count-1]->remove_biggest(removed_entry;)
          if (number of entries in the root of subset[child_count-1]<MINIMUM)
            fix_shortage(child_count-1);
        */
        }

        void fix_excess(std::size_t i){
          /*PSEUDOCODE
          the child node is split into 2 nodes which each contain MINIMUM entries
          This leaves the extra entry which is passed up to the parent*/
          int ct;
          //copy middle entry of subset to root
          for(ct=data_count; ct>i;ct--)
            data[ct]=data[m-1];
          data[i]=subset[i].data[MINIMUM];
          data_count++;
          //split child into 2 subsets:
          set leftChild = new set();
          set rightChild = new set();
          leftChild.data_count = MINIMUM;
          rightChile.data_count = MINIMUM;
          //copy data from original subset into 2 splits:
          for(ct=0;ct<MINIMUM; ct++){
            leftChild.data[ct] = subset[i].data[ct];
            rightChild.data[ct] = subset[i].data[ct+MINIMUM+1];
          }
          //copy subsets of child if they exist:
          int subChildCount = (subset[i].child_count)/2;
          for(ct = 0; ct<subChildCount;ct++){
            leftChild.subset[ct] = subset[i].subset[ct];
            rightChild.subset[ct] = subset[i].subset[ct+subChildCount];
          }
          if(subChildCount>0){
            leftChild.child_count=MINIMUM+1;
            rightChild.child_count=MINIMUM+1;
          }

          //make room in root's subset array for new children
          subset[child_count]=new set();
          for(ct=child_count; ct>i; ct--){
            subset[ct]=subset[ct-1];
          }
          child_count++;
          //add new subsets to root's subset array
          subset[i]=leftChild;
          subset[i+1]=rightChild;
        }

        void fix_shortage(std::size_t i){

        // NOTE: The implementor may want to have additional helper functions
        /*PSEUDOCODE
        page 567
        */
        }
      };
}
#include "set.template" // Include the implementation.

#endif
