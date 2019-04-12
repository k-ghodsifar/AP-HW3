#ifndef VECTORR_H
#define VECTOR_H

#include<iostream>

class Vectorr
{
 public:

  Vectorr();
  Vectorr(Vectorr& v);
  Vectorr( Vectorr&& v);
  ~Vectorr();

  size_t size{};
  size_t capacity{2};
  
  void push_back(int m);
  void pop_back();
  void show();
  bool operator<(Vectorr& v);
  bool operator==(Vectorr& v);
  bool operator>(Vectorr& v);
  Vectorr& operator=(const Vectorr& v);
  Vectorr& operator=(Vectorr&& v);
  Vectorr operator+(const Vectorr& v);
  int dot(const Vectorr& v);

 private:
  int* s=new int[2];
};

#endif
