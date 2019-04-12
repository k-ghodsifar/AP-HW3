#include"oracle.h"
#include<iostream>


Oracle::Oracle(std::string Name) 
{
  this->Name = Name;
}

Oracle::~Oracle()
{
  std::cout<<"destructor of Oracle."<<std::endl;
}

bool Oracle::marry(Human* h1,Human* h2)
{
  if( (h1->spouse != h2) &&
       ( h1->getAge() >=18) &&
       (h2->getAge() >=18))
    {
      
      h1->spouse=h2;
      h2->spouse=h1;
      h1->setFamily(*h2);
      h2->setFamily(*h1);
      for(int i{};i<(*h1).numberOfFamily ;i++)
	{
	  h2->setFamily(*(h1->family[i]));
	  (*(h1->family[i])).setFamily(*h2);	  
	}
      for(int i{};i<h2->numberOfFamily ;i++)
	{
	  h1->setFamily(*(h2->family[i]));
	  (*(h2->family[i])).setFamily(*h1);	  
	  }
      return true;
    }
  else
    return false;
}

void Oracle::setChild(Human* baby,Human* h1,Human* h2)
{
  if((h1->spouse == h2)  && (baby!=h1) && (baby!=h2))
    {
      srand(time(0));
      if(h1->gender)
        {
      	  baby->lastName=h2->lastName;
          baby->mother=h1;
          baby->father=h2;
        }
      else
        {
	  baby->lastName=h1->lastName;
          baby->mother=h2;
          baby->father=h1;
         }
      h1->numberOfChildren++;
      h2->numberOfChildren++;
      if( h1->numberOfChildren > 1)
     	{
	  Human** temp=new Human* [ (*h1).numberOfChildren];
          for(int i{};i<(h1->numberOfChildren-1);i++)
            {
	      temp[i]=h1->children[i];
             }
          temp[h1->numberOfChildren-1]=baby;
          delete [] h1->children;
          delete [] h2->children;
          h1->children=temp;
          h2->children=temp;
          temp=nullptr;
     	}
        else
	{
	  h1->children=new Human*;
	  h2->children=new Human*;
	  h1->children[0]=baby;
	  h1->children[0]=baby;
	  }
      
        h1->setFamily(*baby);
        h2->setFamily(*baby);
        baby->setFamily(*h1);
        baby->setFamily(*h2);  
       for(int j{};j<(*h1).numberOfFamily;j++)
	{
	  baby->setFamily(*(h1->family[j]));
	  (h1->family[j])->setFamily(*baby);
	}
       for(int j{};j< h2->numberOfFamily ;j++)
	{
	  baby->setFamily(*(h2->family[j]));
	  (h2->family[j])->setFamily(*baby);
	}
    }
  else
    std::cout<<"false order."<<std::endl;
} 

bool Oracle::isFamily(Human* h1,Human* h2)
{
  bool resault{false};
  int counter{};
  while( (counter < h1->numberOfFamily) && (resault==false) )
    {
      if(*( (h1->family)[counter]) == *h2)
	resault = true;
      ++counter;
    }
  return resault;
}

Human** Oracle::getFamily(Human* h)
{
  return h->family;
}
//////It counts himself/herself
int Oracle::getPopulationOfFamily(Human* h)
{
  return (h->numberOfFamily+1);
}

