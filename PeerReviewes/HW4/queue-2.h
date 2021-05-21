#ifndef QUEUE_H
#define QUEUE_H

class bool_souce{
public:
  bool_souce(double p = 0.5);
  bool query() const;
private:
  double probability;
};

class averager{
public:
  averager() : count(0),sum(0) {}
  void next(double value);
  int size() const {return count;}
  double average() const;
private:
  int count;
  double sum;
};

class office{
public:
  office(unsigned int s=1);
  void one_second();
  void start();
  bool busy() const {return time_left>0;}
private:
  unsigned int serve_time;
  unsigned int time_left;
};

#endif //QUEUE_H
