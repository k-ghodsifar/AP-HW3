#include<iostream>
#include"vectorr.h"

Vectorr f(int);
int main()
{
  Vectorr v1{};
  v1.push_back(2);
  v1.push_back(3);
  v1.show();
  Vectorr v2{v1};
  v2.show();
  v2.pop_back();
  if( v1 == v2)
    std::cout<<"equal"<<std::endl;
  if( v1 > v2)
    std::cout<<">"<<std::endl;
  if( v1 < v2)
    std::cout<<"<"<<std::endl;
  v2.push_back(4);
  v2=v1+v2;
  v2.show();
  std::cout<<v1.dot(v2)<<std::endl;
  Vectorr v3{f(1)};
  v3.show();
  return 0;
}

Vectorr f(int i)
{
  Vectorr v1{};
  Vectorr v2{};
  for(size_t j{};j<4;j++)
    {
      v1.push_back(j+3);
      v2.push_back(j+4);
    }
  if (i==1)
    return v1;
  else
    return v2;
}
