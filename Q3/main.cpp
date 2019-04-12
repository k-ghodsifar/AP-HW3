#include<iostream>
#include"human.h"
#include"oracle.h"

int main()
{
  Human h1("Emily","k",9,7,30,0,0);
  Human* H1=&h1;
  Human h2("John","k",6,7,30,1,0);
  Human* H2=&h2;
  Human h4("Jack","f",2,3,5,0,0);
  std::cout<<h1.getHairColor()<<std::endl;
  std::cout<<h1.getEyeColor()<<std::endl;
  Human h5{};
  h5=h1;
  std::cout<<h5.getEyeColor()<<std::endl;
  if( h4 == h1)
    std::cout<<"equal."<<std::endl;
  if( h4 != h2)
    std::cout<<"not equal"<<std::endl;
  Oracle m("K");
  if( m.marry(H1,H2) )
    std::cout<<"done"<<std::endl;
  Human* H3;
  H3=h1+h2;
  std::cout<<h1.getAge()<<std::endl;
  ++h1;
  std::cout<<h1.getAge()<<std::endl;
  
  if ( h2.isMotherOf(H3))
    std::cout<<"His/Her mother"<<std::endl;

  if ( h1.isFatherOf(H3))
    std::cout<<"His/Her father"<<std::endl;

  if( (*H3).isChildOf(H1))
    std::cout<<"His/Her child"<<std::endl;

  if ( h2.isMotherOf(&h4))
    std::cout<<"His/Her mother"<<std::endl;

  m.setChild(&h4,H1,H2);

  h1.printChildren();

  if (m.isFamily(&h4,H3))
    std::cout<<"of family"<<std::endl;

  std::cout<<m.getPopulationOfFamily(&h4)<<std::endl;

  ///////You can see name of h4 family except for himself
  for(int i{};i<(m.getPopulationOfFamily(&h4)-1);i++)
    std::cout<< (m.getFamily(H1)[i])->getFirstName()<<std::endl;

  delete H3;////////we new a pointer in operator+,now we must delete it
  return 0;
}
