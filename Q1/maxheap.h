#include<iostream>
#ifndef MAXHEAP_H
#define MAXHEAP_H

class MaxHeap
{
 public:
  MaxHeap();
  MaxHeap(int*,int);
  MaxHeap(const MaxHeap&);
  ~MaxHeap();
  void add(int);
  int Parent(int);
  int RightChild(int);
  int LeftChild(int);
  int Left(int);
  int Right(int);
  void max_heapify(int,int);
  void build_max_heap();
  int operator[](int i);
  void printArray();
  int Max();
  void Delete();
  void operator=(const MaxHeap&);
  int getHeight();
  void Heapsort();
  
  int* arr;
  int size{};
};

std::ostream& operator<<(std::ostream&,MaxHeap);
void swap(int&,int&);
#endif
