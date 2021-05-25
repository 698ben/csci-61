#include <iostream>
#include <fstream>
#include <map>
#include <time.h>
using namespace std;

struct student
{
  int length;
  int time;
  int priority;
};
struct questions
{
    string name;
    string subject;
};
template<class item>
void insertionSort(item arr[], int size);
void insertionSort(questions arr[], int size);
void insertionSortr(questions arr[], int size);
template<class item>
bool swap(item arr[], int a, int b);
template<class item>
bool swapo(item arr[], int a, int b);
template<class item>
bool swapr(item arr[], int a, int b);
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
class record
{
  public:
    record()
    {
      //data;
    }
    record(const record& copy)
    {
      data = copy.data;
    }
    void insert(string namme, string subject)
    {
      data.insert(make_pair(namme, subject));
    }
    void print_master(string name2)
    {
        int count = 0;
        fout.open(name2 + ".txt");
         string name = "";
      multimap<string,string> temp = data;
      name = temp.begin() -> first;
      //fout << name << endl << endl;
      for(auto i = temp.begin()++; i != temp.end(); i++)
      {
        if(i -> first != name)
        {
          fout << name << " " << count << endl << endl;
          count = 0;
          name = i -> first;
        }else
        {
          count++;
          fout << i -> second << endl;
        }      
      }
      count = 0;
      fout.close();
    }
    void print_records()
    {
      fout.open("master.txt");
      //fout << "test" << endl;
      int count = 0;
      string name = "";
      multimap<string,string> temp = data;
      name = temp.begin() -> first;
      //fout << name << endl << endl;
      for(auto i = temp.begin()++; i != temp.end(); i++)
      {
        if(i -> first != name)
        {
          fout << name << " " << count << endl << endl;
          count = 0;
          name = i -> first;
        }else
        {
          count++;
          fout << i -> second << endl;
        }      
      }
      count = 0;
      fout.close();
      name = temp.begin() -> first;
      fout.open(name + ".txt");
      for(auto i = temp.begin()++; i != temp.end(); i++)
      {
        if(i -> first != name)
        {
          fout << name << " " << count << endl << endl;
          count = 0;
          name = i -> first;
          fout.close();
          fout.open(name + ".txt");
        }else
        {
          count++;
          fout << i -> second << endl;
        }      
      }
      //fout.close();
    }
    void SortMaster( int col, int dir)
    {
        fout.open("sortedMaster.txt");
        if(col == 1 && dir == 1)
        {   
            print_master("SortMaster");
        }else if(col == 1 && dir == 2)
        {
            int count = 0;
            string name = "";
            multimap<string,string> temp = data;
            name = temp.begin() -> first;
            for(auto i = data.rbegin(); i != data.rend(); i++)
            {
                 if(i -> first != name)
                {
                    fout << name << " " << count << endl << endl;
                    count = 0;
                    name = i -> first;
                }else
                {
                    count++;
                    fout << i -> second << endl;
                }   
            }
        }else if(col = 2 && dir == 1)
        {
            questions q[500];
            int used = 0;
            fout.open("sortedMaster.txt");
            for(auto i = data.begin(); i != data.end(); i++)
            {
                q[used].name = i -> first;
                q[used].subject = i -> second;
                used++;
            }
            insertionSort(q, used);
            for(int i = 1; i < used; i++)
            {
               fout << q[i].name << " " << q[i].subject << endl;
            }
        }else if(col = 2 && dir == 2)
        {
            questions q[500];
            int used = 0;
            fout.open("sortedMaster.txt");
            for(auto i = data.begin(); i != data.end(); i++)
            {
                q[used].name = i -> first;
                q[used].subject = i -> second;
                used++;
            }
            insertionSortr(q, used);
            for(int i = 1; i < used; i++)
            {
               fout << q[i].name << " " << q[i].subject << endl;
            }
        }
}
  private:
    multimap<string,string> data;
    ofstream fout;
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

void officeHours(averager& a, averager& b, averager& c, record& d, int prob, int min, int max);
void SortMaster(record& d, int col, int dir);
void remove(string a[], int& used, int target)
{
  for(int i  = 0; i < used; i++)
  {
    if(i > target)
    {
      a[i-1] = a[i];
    }
  }
  used--;
}

int main()
{
    cout << "Insertion sort: " << endl;
    int num = 0;
    cout << "How many numbers do you want to sort" << endl;
    cin >> num;
    int arr[num];
    cout << "enter the numbers you want to sort separted by a space" << endl;
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i]; 
    }
    insertionSort(arr,num);
    cout << "the sorted out come is " << endl;
    for(int i = 0; i < num; i++)
    {
        std::cout << arr[i] << "  " << std::endl;
    }
    cout << "___________________________" << endl;
    cout << "office hour sort: " << endl;
    averager a;
    averager b;
    averager c;
    record d;
    int prob = 0;
    int min = 0;
    int max = 0;
    cout << "enter the probility of a stduent arrving every second(a number between 0 and 100)" << endl;
    cin >> prob;
    cout << "enter the minimum then the maximum question length in seconds sperated by a space" << endl;
    cin >> min;
    cin >> max;
    max++;
    srand(time(0));
    for(int i = 0; i< 100; i++)
    {
        officeHours(a,b,c,d,prob,min,max);
    }
    d.print_records();
    cout << "average time a student spends is line is: " << a.answer() << endl
       << "average time a student spends with the professor is: " << b.answer() << endl
       << "average time a professor spends after the intended time is: " << c.answer() << endl;
    int col = 0;
    int dir = 0;
    cout << "enter a colum student name(1) or subject(2): " << endl;
    cin >> col;
    cout << "enter a direction acending(1) or descending(2): " << endl;
    cin >> dir;
    d.SortMaster(col, dir);
    
    return 0;
}
template<class item>
void insertionSort(item arr[], int size)
{
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        j = i;
        while(swap(arr, j , j - 1  ) && j > 0)
        {
            j--;
        }
    }
}
void insertionSort(questions arr[], int size)
{
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        j = i;
        while(swapo(arr, j , j - 1  ) && j > 0)
        {
            j--;
        }
    }
}
void insertionSortr(questions arr[], int size)
{
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        j = i;
        while(swapr(arr, j , j - 1  ) && j > 0)
        {
            j--;
        }
    }
}
template<class item>
bool swap(item arr[], int a, int b)
{
    item temp;
    if(arr[a]< arr[b])
    {
        temp = arr[b];
        arr[b] = arr[a];
        arr[a] = temp;
        return true;
    }else
    {
        return false;
    }
}
template<class item>
bool swapo(item arr[], int a, int b)
{
    string temp;
    if(arr[a].subject < arr[b].subject)
    {
        temp = arr[b].subject;
        arr[b].subject = arr[a].subject;
        arr[a].subject = temp;
        return true;
    }else
    {
        return false;
    }
}
template<class item>
bool swapr(item arr[], int a, int b)
{
    string temp;
    if(arr[a].subject > arr[b].subject)
    {
        temp = arr[b].subject;
        arr[b].subject = arr[a].subject;
        arr[a].subject = temp;
        return true;
    }else
    {
        return false;
    }
}
void officeHours(averager& a, averager& b, averager& c, record& d, int prob, int min, int max)
{
  const int totalLength = 60;
  const int interations = 100;
  pQueue waiting;
  int length = 0;
  int chance = 0;
  int current = 0;
  int s = 0;
  int su = 0;
  int students_used = 51;
  int subjects_used = 20;
  string students[52];
  string subjects[22];
  ifstream fin;
  string input;
  fin.open("students.txt");
  for(int i = 0; i < students_used; i++)
  {
    getline(fin,input);
    students[i] = input;
  }
  fin.close();
  fin.open("subjects.txt");
  for(int i = 0; i < subjects_used; i++)
  {
    getline(fin,input);
    subjects[i] = input;
  }
  fin.close();
    while(length <= 60 || waiting.empty() || current > 0)
    {
      chance = (rand() % 101) + 1;
      if(chance <= prob & length <= 60)
      {
        s = (rand() % students_used);
        su = (rand() % subjects_used);
        d.insert(students[s],subjects[su]);
        remove(students, students_used, s);
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