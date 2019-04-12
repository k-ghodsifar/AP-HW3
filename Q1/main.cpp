#include"maxheap.h"
#include<iostream>

int main()
{
  MaxHeap h1{};
  h1.add(25);
  h1.add(32);
  h1.add(17);
  h1.add(23);
  h1.add(101);
  
  std::cout<<"h1"<<std::endl<<h1<<std::endl;

  std::cout<<"h1.Parent(2):"<< h1.Parent(2)<<std::endl;
  std::cout<<"h1.LeftChild(0):"<< h1.LeftChild(0)<<std::endl;
  std::cout<<"h1.RightChild(0):"<< h1.RightChild(0)<<std::endl;

  int arr[7]{23,1,7,52,11,10,75};
  MaxHeap h2{arr,7};

  std::cout<<"h2:"<<std::endl<<h2<<std::endl;
  std::cout<<"Height of h2:"<<h2.getHeight()<<std::endl;

  MaxHeap h3{h2};
  std::cout<<"sorted h3:"<<std::endl;
  h2.Heapsort();
  std::cout<<"max-heap array:"<<std::endl;
  h2.printArray();

  std::cout<<"Max of h3:"<<h3.Max()<<std::endl;
  h3.Delete();
  std::cout<<"and now former max deleted:"<<h3.Max()<<std::endl;

  
  return 0;
}
