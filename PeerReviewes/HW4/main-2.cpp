#include "queue-2.h"
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

void SimulateOneMinute(double& total_wait,double& total_serve,double& extraOfficeTime,int& priority);

template<class Item>
int find_position(const priority_queue<Item>& q,const Item& target);

template<class Item>
void insert_position(queue<Item>& q,int i,Item entry);

int main(){
  double total_wait(0),total_serve(0),extraOfficeTime(0);
  averager avg_wait,avg_serve,avg_office;
  //newly added parameter
  int priority(0);//this will be a random integer from 1 to 100
  for (int i=0;i<100;i++){
    SimulateOneMinute(total_wait,total_serve,extraOfficeTime,priority);
    avg_wait.next(total_wait);
    avg_serve.next(total_serve);
    avg_office.next(extraOfficeTime);
  }
  cout<<"The average time (in seconds) a student spends waiting during an office hour visit is: "<<avg_wait.average()<<endl;
  cout<<"The average time (in seconds) a student spends with the professor during an office hour visit is: "<<avg_serve.average()<<endl;
  cout<<"The average time (in seconds) a Professor spends at an office hour beyond the 1 minute he intended to is: "<<avg_office.average()<<endl;
  return 0;
}

void SimulateOneMinute(double& total_wait,double& total_serve,double& extraOfficeTime,int& priority){
  int current_second = 1;
  int next; //stores the arrival time of the next student
  int service_time; //a randome number between 1 to 20 seconds and is used as the elements for the queue students
  queue<int> students, arrival_time;
  priority_queue<int> priority_line;
  bool_souce arrival(0.3);
  office professor;

  while (current_second<=60 || (current_second>60 && (!students.empty() || professor.busy()))) {
    if (current_second<=60 && arrival.query()){//The program would run for a very long time without the first condition since the professor would be likely to sit in his office forever
      priority = rand()%100 + 1;
      priority_line.push(priority);
      int i = find_position(priority_line,priority);
      service_time = rand()%20 + 1;
      insert_position(students,i,service_time);
      total_serve += service_time;
      insert_position(arrival_time,i,current_second);
    }
    if (!professor.busy() && !students.empty()){
      priority_line.pop();
      next = students.front();
      students.pop();
      professor = office(next);
      next = arrival_time.front();
      arrival_time.pop();
      total_wait += (current_second-next);
      professor.start();
    }
    professor.one_second();
    current_second++;
  }

  if (current_second > 60)
    extraOfficeTime = current_second-60;
}

template<class Item>
int find_position(const priority_queue<Item>& q,const Item& target){
  priority_queue<Item> temp = q;
  int i=0;
  Item next = temp.top();
  temp.pop();
  while (target<next){
    next = temp.top();
    temp.pop();
    i++;
  }
  //to clear memory
  while (!temp.empty())
    temp.pop();
  return i;
}

template<class Item>
void insert_position(queue<Item>& q,int i,Item entry){
  int size = q.size();
  Item arr[size+1];
  int k = 0;
  while (k<i){
    arr[k++]=q.front();
    q.pop();
  }
  arr[k++]=entry;
  while (!q.empty()){
    arr[k++]=q.front();
    q.pop();
  }
  for (int j=0;j<k;j++){
    Item next = arr[j];
    q.push(next);
  }
}
