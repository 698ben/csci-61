#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <map>
#include <iterator>

using namespace std;

class Student{
public:

  //Keep track of which student
  int id = rand() % 100 + 1;

  //At what time does the student arrive
  int arrivalTime;

  //How long it takes for help
  int helpTime = rand() % 10 +1;

  // How long it takes to wait for help
  int waitTime;

  // Where in the line is the student waiting by priority
  int order = rand() % 3 + 1;

  // Value for topic and a list of chapters to pick from
  string chapters[6] = {"queues","stacks","binary trees", "b-trees", "hashmaps",
"sorting"};
  string topic = chapters[rand()%6];
};

//10% chance of student arriving
bool arrival(){
  int x = rand() % 10 + 1;
  if (x <= 1){
      return true;
  }
  else{
    return false;
  }
}

//Opertaor for comparing the priority of wich students are in line
bool operator < (const Student& a, const Student& b){
  return (a.order < b.order ? true : false);
}


void officeHrsSimulation(){
  multimap<int, string> studentReport;
  srand(time(NULL)); // # randomizer
  priority_queue<Student> enter_line;
  queue<Student> exit_line;

  // Data for final total
  int finalWait = 0;
  int finalStudents = 0;
  int finalOvertime = 0;

  //running the simulation 100 times
  for (int i = 0; i < 100; i++){
    while (!enter_line.empty()){
      enter_line.pop();
    }

    while (!exit_line.empty()){
      exit_line.pop();
    }

    // Starts minute and counts up checking arrival each time
    for (int minute = 0; minute < 60; minute++){
      // Adds student to enter_line if one arrives
      if (arrival()){
        Student temp;
        studentReport.insert(pair<int,string>(temp.id, temp.topic));
        temp.arrivalTime = minute;
        enter_line.push(temp);
      }
    }
    //if no one comes to office hours
    if (enter_line.empty()){
      cout << "no one came to office hours :(" << endl;
      exit(1);
    }
    Student temp = enter_line.top();
    int waitTotal = 0;
    int totalStudents = 0;
    int totalOvertime = 0;
    //start minute when first student arrives
    int minute = temp.arrivalTime;
    while (!enter_line.empty()){
      temp = enter_line.top();
      enter_line.pop();
      //if a student arrives when the professor is not busy
      if (minute - temp.arrivalTime < 0){
        minute = temp.arrivalTime;
        temp.waitTime = 0;
      }
      //wait time is minute - arrival times
      else{
        temp.waitTime = minute - temp.arrivalTime;
      }
      //add time until student is helped
      minute += temp.helpTime;
      exit_line.push(temp);
      totalStudents++;
      waitTotal += temp.waitTime;
    }
    int averageWait = waitTotal/totalStudents;
    finalWait += averageWait;
    finalStudents += totalStudents;

    //Tracks last students time to leave
    Student temp2 = exit_line.back();
    int lastStudent = temp2.arrivalTime + temp2.waitTime + temp2.helpTime;

    //if leave time is less than 0, progessor leaves at 1 hr
    totalOvertime = (lastStudent < 60) ? 0: lastStudent-60;
    finalOvertime += totalOvertime;
  }
  cout << "average wait time: " << finalWait/100 << endl;
  cout << "number students helped on average: " << finalStudents/100 << endl;
  cout << "overtime average: " << finalOvertime/100 << endl;

  //Final Student report output
  cout << endl;
  cout << "Student report:\n";
  for (int i = 1; i <= 100; i++){
    int count = 0;
    pair<multimap<int,string>::iterator, multimap<int,string>::iterator> ret;
    ret = studentReport.equal_range(i);
    cout << "Student " << i << ": ";
    cout<<endl;
    for (multimap<int,string>::iterator it =ret.first; it!=ret.second; ++it){
      cout << '\t' << it->second<<endl;
      ++count;
    }
    cout << "\ttimes visited: " << count;
    cout << '\n';
  }
}
