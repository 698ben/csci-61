#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

class OfficeHour {
  //public functions (getters + setters)
public:
  //constructor
  OfficeHour(int newArrivalTime){
    arrivalTime = newArrivalTime;
    serviceDuration = 0;
  }

  int getArrivalTime(){
    return arrivalTime;
  }

  int getServiceDuration(){
    return serviceDuration;
  }

  int getServiceStartTime(){
    return serviceStartTime;
  }

  void setServiceDuration(int newServiceDuration){
    serviceDuration = newServiceDuration;
  }

  void setServiceStartTime(int newServiceStartTime){
    serviceStartTime = newServiceStartTime;
  }

  int getWaitTime(){
    if (serviceStartTime > arrivalTime)
      return (serviceStartTime - arrivalTime);

      return 0;
  }

private:
  //private variables
  int arrivalTime;
  int serviceStartTime;
  int serviceDuration;
};

//when student arrives
void simulateArrival(queue<OfficeHour *> & inStudent){
  int studentArrivalTime = 0;
  int hour = 60;
  srand(time(0));

  do{
    int random = rand() % hour;
    studentArrivalTime += random;

    if (studentArrivalTime <= hour)
      inStudent.push(new OfficeHour(studentArrivalTime));
  }
  while (studentArrivalTime < hour);
}

//the amount of time it takes for the student to help during office hours
void serviceTime(queue<OfficeHour *> inStudent){
  int currentTime = 0;
  int arrivalTime;
  int serviceDuration;

  while (inStudent.empty() == false) {
    OfficeHour *studentRecord = inStudent.front();

    arrivalTime = studentRecord->getArrivalTime();
    if (arrivalTime > currentTime) {
      currentTime = arrivalTime;
    }

    serviceDuration = rand() % 60;
    studentRecord->setServiceStartTime(currentTime);
    studentRecord->setServiceDuration(serviceDuration);
    currentTime += serviceDuration;

    inStudent.pop();
  }
}

//this updates the time that a student spends (all parts of it )
void updateAvgs(queue<OfficeHour *> inStudent, int & studentTotal,
int & studentWaitTimeTotal, int & studentServiceDurationTotal,int & professorOvertimeTotal){
  while (inStudent.empty() == false){
    OfficeHour *studentRecord = inStudent.front();
    inStudent.pop();
    studentTotal++;
    studentWaitTimeTotal += studentRecord->getWaitTime();
    studentServiceDurationTotal += studentRecord->getServiceDuration();

    if (inStudent.empty()){
      int endTime = studentRecord->getServiceStartTime() + studentRecord->getServiceDuration();
      if (endTime > 60)
        professorOvertimeTotal += (endTime - 60);

    }
  }
}

//main function
int main(){
  queue<OfficeHour *> inStudent;
  int studentTotal = 0;
  int studentWaitTimeTotal = 0;
  int studentServiceDurationTotal = 0;
  int professorOvertimeTotal = 0;

  //to loop it 100 times
  for (int i = 0; i < 100; i++){
    simulateArrival(inStudent);
    serviceTime(inStudent);
    updateAvgs(inStudent, studentTotal, studentWaitTimeTotal, studentServiceDurationTotal, professorOvertimeTotal);
    while (inStudent.empty() == false)
      inStudent.pop();
  }

  //runnable code
  cout << "The average time spent waiting during an office hour visit: " <<
  (studentWaitTimeTotal * 1.0) / studentTotal << endl;
  cout << "The average time spent during an office hour visit: " <<
  (studentServiceDurationTotal * 1.0) / studentTotal << endl;
  cout << "The average time professor spends beyond the 1 hour he intended to: " <<
  (professorOvertimeTotal * 1.0) / 100 << endl;
}
