#include"vectorr.h"
#include<iostream>

///////////////////////constructors
Vectorr::Vectorr()
{
  std::cout<<"Created."<<std::endl;
}
Vectorr::Vectorr(Vectorr& v)
{
  size = v.size;
  capacity = v.capacity;
  s=new int[v.capacity];
  for(size_t j{};j < v.size ; j++)
     s[j]= (v.s)[j];
  std::cout<<"copy constructor."<<std::endl;
}

Vectorr::Vectorr( Vectorr&& v)
{
  size = v.size;
  capacity = v.capacity;
  delete[] s;
  s=new int[capacity];
  s=v.s;
  v.s=nullptr;
  std::cout<<"constructor,move version."<<std::endl;
}

Vectorr:: ~Vectorr()
{
  delete [] s;
  std::cout<<"destructrd."<<std::endl;
}

Vectorr& Vectorr::operator=(const Vectorr& v)
{
  std::cout<<"Operator = copy version."<<std::endl;
  if(this == &v)
    return *this;
  else
    {
      capacity = v.capacity;
      size = v.size;
      s=new int[capacity];
      for(size_t j{}; j<size ;j++)
	s[j]=(v.s)[j];
      return *this;
    }
}

Vectorr& Vectorr::operator=(Vectorr&& v)
{
  std::cout<<"Operator = move version."<<std::endl;
  if(this == &v)
    return *this;
  else
    {
      capacity = v.capacity;
      size = v.size;
      delete []s;
      s=v.s;
      v.s=nullptr;
      return *this;
    }
}

void Vectorr::push_back(int m)
{
  size++;
  if(size > (capacity/2) )
      capacity=capacity*2;
  int* temp=s;
  s=new int[capacity];
  for(size_t i{};i<(size-1) ;i++)
    s[i]=temp[i];
  s[size-1]=m;
  delete [] temp;
}

void Vectorr::pop_back()
{
  size--;
  if(size < (capacity/2) )
    capacity = (capacity/2);
  int* temp=s;
  s=new int[capacity];
  for(size_t i{};i< size ;i++)
    s[i]=temp[i];
  delete [] temp; 
}

void Vectorr::show()
{
  std::cout<<"vector:{";
  for(size_t j{};j<size;j++)
    {
      if(j != (size-1) )
	std::cout<<s[j]<<",";
      else
	std::cout<<s[j];
    }
  std::cout<<"}"<<std::endl;
}

bool Vectorr::operator<(Vectorr& v)
{
  return size<v.size;
}

bool Vectorr::operator==(Vectorr& v)
{
  return size==v.size ;
}

bool Vectorr::operator>(Vectorr& v)
{
  return size>v.size ;
}

Vectorr Vectorr::operator+(const Vectorr& v)
{
  Vectorr n;
    if(capacity > v.capacity)
    n.capacity= capacity; 
  else
    n.capacity=v.capacity;
  n.s=new int[n.capacity];
  size_t min{},max{};
  if(size > v.size)
    {
      n.size= size;
      max = size;
      min = v.size;
    }
  else
    {
      n.size=v.size;
      min = size;
      max = v.size;
    }
  for(size_t j{};j<max;j++)
    {
      if( j < min )
	(n.s)[j]= s[j] + (v.s)[j];
      else
	if(max == v.size)
	  (n.s)[j] = (v.s)[j];
        else
	  (n.s)[j] = s[j];
    }
  return n;
}

int Vectorr::dot(const Vectorr& v)
{
  if(size != v.size )
    {
      std::cout<<"We cannot dot.Sizes are different."<<std::endl;
      return 0;
    }
  else
    {
      int result{};
      for(size_t i{};i< size ; i++)
	result += s[i]*(v.s)[i];
      return result;
    }
}
