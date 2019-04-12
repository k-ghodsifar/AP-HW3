#include"maxheap.h"
#include<iostream>
#include<cmath>
MaxHeap::MaxHeap()
{
  std::cout<<"Created."<<std::endl;
}

MaxHeap::MaxHeap(int* array, int size)
{
  this->size = size;
  arr=new int[size];
  for(int j{};j<size;j++)
    arr[j]=array[j];
  std::cout<<"normal constructor."<<std::endl;
  build_max_heap();
}

MaxHeap::MaxHeap(const MaxHeap& h)
{
  size=h.size;
  arr=new int[size];
  for(int i{};i<size;i++)
    arr[i]=h.arr[i];
}

MaxHeap::~MaxHeap()
{
  delete arr;
}

void MaxHeap::max_heapify(int length,int i)
{
  int largest{i};
  if( Left(i) < length)
    {
      if( arr[Left(i)] > arr[i])
	largest=Left(i);
    }
  if( Right(i) < length)
    {
      if(arr[Right(i)] > arr[largest] )
	largest=Right(i);
    }
  if(largest != i)
    {
      swap(arr[i] , arr[largest]);
      max_heapify(length,largest);
    }
}

void MaxHeap::build_max_heap()
{
  for(int i{(size/2)-1} ; i >=0 ; i--)
    max_heapify(size,i);
}

void MaxHeap::Heapsort()
{
  for(int i{size-1};i>=0 ; i--)
    {
      swap(arr[i],arr[0]);
      max_heapify(i,0);
    }
  for(int i{};i<size;i++)
    std::cout<<arr[size-i-1]<<"  ";
  std::cout<<std::endl;
  build_max_heap();//we build max_heap again
  //because sort destroyed it.
}

void MaxHeap::add(int a)
{
  if(size > 0)
    {
      ++size;
      int* temp=new int[size];
      for(int i{};i<(size-1);i++)
	temp[i]=arr[i];
      temp[size-1]=a;
      delete arr;
      arr=temp;
      temp=nullptr;
      build_max_heap();
    }
  else
    {
      arr= new int;
      arr[0]=a;
      ++size;
    }
}

int MaxHeap::Left(int i)
{
  return (2*i)+1;
} 

int MaxHeap::Right(int i)
{
    return (2*i)+2;
}

int MaxHeap::RightChild(int i)
{
  if(Right(i) < size)
    return arr[Right(i)];
  else
    {
    std::cout<<"Wrong Order.We returned you 0."<<std::endl;
    return 0;
    }
}

int MaxHeap::LeftChild(int i)
{
  if(Left(i) < size)
    return arr[Left(i)];
  else
    {
      std::cout<<"Wrong Order.We returned you 0."<<std::endl;
      return 0;
    }
}

int MaxHeap::Parent(int i)
{
  return arr[(i-1)/2];
}

int MaxHeap::operator[](int i)
{
  if( i>=0 && i<size)
    return arr[i];
  else
    {
      std::cout<<"We don`t have this index."<<std::endl;
      return 0;
    }
}

void MaxHeap::printArray()
{
  for(int i{};i<size;i++)
    std::cout<<arr[i]<<"  ";
  std::cout<<std::endl;
}

int MaxHeap::Max()
{
  return arr[0];
}

void MaxHeap::Delete()
{
  --size;
  int* temp=new int[size];
  for(int j{};j<size;j++)
    temp[j]=arr[j+1];
  delete arr;
  arr=temp;
  temp=nullptr;
  build_max_heap();
}

void MaxHeap::operator=(const MaxHeap& h)
{
  if(size > 0)
    delete arr;
  size=h.size;
  arr=new int[size];
  for(int i{};i<size;i++)
    arr[i]=h.arr[i];
}

////////in every floor we have 2^n numbers.
//so we can know number of floors or height by
//number of 2^n s.
int MaxHeap::getHeight()
{
  int sum{},index{-1};
  while( sum < size)
    { ++index;
      sum += static_cast<int>(pow(2,index));
    }
  return index;
}


std::ostream& operator<<(std::ostream& os ,MaxHeap h)
{
  int sum{};
  int height{h.getHeight()};
  for(int i{};i<height;i++)
    { 
      for(int j{};j<static_cast<int>(pow(2,i)) ;j++)
	os<<h.arr[j+sum]<<"    ";
      sum += static_cast<int>(pow(2,i));
      os<<std::endl;
    }
  for(int k{sum};k<h.size;k++)
    os<<h.arr[k]<<"    ";
  os<<std::endl;
  return os;
}

void swap(int& a,int& b)
{
  int temp{a};
  a=b;
  b=temp;
}

