#include <iostream>
#include <queue>
#include <cstdlib>
#include <time.h>

using namespace std;

struct student
{
  int length;
  int time;
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

void officeHours(averager& a, averager& b, averager& c, int prob, int min, int max);

int main()
{
  averager a;
  averager b;
  averager c;
  int prob = 0;
  int min = 0;
  int max = 0;
  cout << "enter the proobility of a stduent arrving every second(a number between 0 and 100)" << endl;
  cin >> prob;
  cout << "enter the minimum then the maximum question length in seconds sperated by a space" << endl;
  cin >> min;
  cin >> max;
  max++;
  for(int i = 0; i < 100; i++)
    officeHours(a, b, c, prob, min, max);
  cout << "average time a student spends is line is: " << a.answer() << endl
       << "average time a student spends with the professor is: " << b.answer() << endl
       << "average time a professor spends after the intended time is: " << c.answer() << endl;
}
void officeHours(averager& a, averager& b, averager& c, int prob, int min, int max)
{
  const int totalLength = 60;
  const int interations = 100;
  queue<student> waiting;
  int length = 0;
  int chance = 0;
  int current = 0;
  srand(time(0));
    while(length <= 60 || !(waiting.empty()) || current > 0)
    {
      chance = (rand() % 101) + 1;
      if(chance <= prob & length <= 60)
      {
        student t = {(rand() % (max - min)) + min, length};
        waiting.push(t);
      }
      if(current == 0 && !(waiting.empty()))
      {
        current = waiting.front().length;
        a.sum(length - waiting.front().time );
        b.sum(current);
        waiting.pop();
      }
      if(current > 0)
        current--;
        length++;
    }
    c.sum(length - totalLength);
}