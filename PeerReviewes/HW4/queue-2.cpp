#include "queue-2.h"
#include <cassert>
#include <cstdlib>
using namespace std;

bool_souce::bool_souce(double p){
  assert(p>=0);
  assert(p<=1);
  probability = p;
}

bool bool_souce::query() const{
  return (rand()<probability*RAND_MAX);
}

void averager::next(double value){
  sum+=value;
  count++;
}

double averager::average() const{
  assert(size()>0);
  return sum/count;
}

office::office(unsigned int s){
  serve_time = s;
  time_left = 0;
}

void office::one_second(){
  if (busy())
    time_left--;
}

void office::start(){
  assert(!busy());
  time_left = serve_time;
}
