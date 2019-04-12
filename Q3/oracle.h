#include<iostream>
#include"human.h"
#ifndef ORACLE_H
#define ORACLE_H

class Oracle 
{
 public:
 Oracle(std::string Name);
  ~Oracle();
  bool marry(Human* , Human*);
  void setChild(Human*,Human*,Human*);
  bool isFamily(Human*,Human*);
  Human** getFamily(Human*);
  int getPopulationOfFamily(Human*);

  std::string Name;
};


#endif
