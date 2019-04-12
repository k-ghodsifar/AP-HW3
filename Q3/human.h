#include<iostream>
#include<string>
#ifndef HUMAN_H
#define HUMAN_H

class Human
{
 public:
  Human();
  Human(std::string firstName,std::string lastName,int hairColor,int eyeColor,int age,bool gender,int numberOfChildren);
  Human(Human&);
  Human(Human&&);
  ~Human();

  Human& operator=(const Human&);
  Human& operator=(Human&&);
  std::string getFirstName();
  std::string getLastName();
  bool getGender();
  int getHairColor();
  int getEyeColor();
  int getAge();
  bool isFatherOf(Human*);
  bool operator>(const Human&);
  bool operator==(const Human&);
  bool operator!=(const Human&);
  bool isChildOf(Human*);
  bool isMotherOf(Human*);
  void operator++();
  Human* operator+(Human&);
  void printChildren();
  void setFamily(Human&);///self define :) 
  int numberOfChildren{};
  int numberOfFamily{}; 
  Human* mother;
  Human* father;
  Human* spouse;
  Human** children;
  Human** family;   
  bool gender;
  std::string lastName;
 private:
  std::string firstName;
  
  int hairColor;
  int eyeColor;
  int age;
};

#endif
