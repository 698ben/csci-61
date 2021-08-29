#include <iostream>
#include "table2.h"

using namespace std;
// Driver program
int main()
{
// array that contains keys to be mapped
int a[] = {15, 11, 27, 8, 12};
int n = sizeof(a)/sizeof(a[0]);
//insert the keys into the hash table
main_savitch_12B::table<int> h;
// hash table
//h.insert(a[0]);
for (int i = 0; i < n; i++)
  h.insert(a[i]);

//find 11
bool found = false;
int result;
h.find(13,found,result);
if(found)
  std::cout << result << " was found in the hashtable" << std::endl;
else
  std::cout << 13 << " was not found in the hashtable" << std::endl;
cout << "--------------------------------" << endl;
if(h.is_present(11))
  std::cout << 11 << " was found in the hashtable" << std::endl;
else
  std::cout << 11 << " was not found in the hashtable" << std::endl;
// delete 12 from hash table
cout << "--------------------------------" << endl;
h.displayHash();
h.remove(12);
// display the Hash table
cout << "--------------------------------" << endl;
h.displayHash();
h.remove(8);
cout << "--------------------------------" << endl;
h.displayHash();
return 0;
}