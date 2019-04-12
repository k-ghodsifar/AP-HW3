#include"human.h"
#include<ctime>
#include<cstdlib>

Human::Human()
{
  std::cout<<"Created."<<std::endl;
}

Human::Human(std::string firstName,std::string lastName,int hairColor,int eyeColor,int age,bool gender,int numberOfChildren)
{
  for(size_t i{};i<firstName.length() ;i++)
    firstName[i]=static_cast<char>(toupper(firstName[i]));
  this->firstName=firstName;
  for(size_t i{};i<lastName.length() ;i++)
    lastName[i]=static_cast<char>(toupper(lastName[i]));
  this->lastName=lastName;
  if(hairColor >=0 && hairColor <=10)
    this->hairColor=hairColor;
  else
    std::cout<<"Hair Color wasnot valid.It set 0 as default.";
  if(eyeColor >=0 && eyeColor <=10)
    this->eyeColor=eyeColor;
  else
    std::cout<<"Eye Color wasnot valid.It set 10 as default.";
  this->age= age;
  this->gender=gender;
  this->numberOfChildren=numberOfChildren;
  std::cout<<"normal constructor."<<std::endl;
}

Human::Human(Human& h)
{
  firstName=h.firstName;
  lastName=h.lastName;
  hairColor=h.hairColor;
  eyeColor=h.eyeColor;
  age=h.age;
  gender=h.gender;
  numberOfChildren=h.numberOfChildren;
  mother=(h.mother);
  father=(h.father);
  spouse=(h.spouse);
  if (numberOfChildren > 0)
    {
      children=new Human* [h.numberOfChildren];
      for(int i{};i< h.numberOfChildren ; i++)
	children[i]= h.children[i];
    }
  numberOfFamily=h.numberOfFamily;
  if (numberOfFamily > 0)
    {
      family=new Human* [numberOfFamily];
      for(int i{};i< h.numberOfFamily ; i++)
	family[i]=h.family[i];       
    }
  std::cout<<"copy constructor."<<std::endl;
}

Human::Human(Human&& h)
{
  firstName=h.firstName;
  lastName=h.lastName;
  hairColor=h.hairColor;
  eyeColor=h.eyeColor;
  age=h.age;
  gender=h.gender;
  numberOfChildren=h.numberOfChildren;
  mother=h.mother;
  father=h.father;
  spouse=h.spouse;
  h.spouse=nullptr;
  h.mother=nullptr;
  h.spouse=nullptr;
  children=h.children;
  h.children=nullptr; 
  numberOfFamily=h.numberOfFamily;
  family=h.family;
  h.family=nullptr; 
  std::cout<<"move constructor."<<std::endl;
}

Human::~Human()
{
    if(numberOfChildren > 0)
      delete [] children;
    if( numberOfFamily > 0) 
      delete [] family; 
  std::cout<<"destructor."<<std::endl;
  } 

Human& Human::operator=(const Human& h)
{
  firstName=h.firstName;
  lastName=h.lastName;
  hairColor=h.hairColor;
  eyeColor=h.eyeColor;
  age=h.age;
  gender=h.gender;
  if( numberOfChildren > 0)
    delete [] children;
  if( numberOfFamily > 0)
    delete [] family;
  numberOfChildren=h.numberOfChildren;
  numberOfFamily=h.numberOfFamily;
  mother=h.mother;
  father=h.father;
  spouse=h.spouse;
  if( numberOfChildren >0)
    {
      children=new Human*[numberOfChildren];
      for(int i{} ;i<numberOfChildren ; i++)
	children[i]=h.children[i];
    }
  if( numberOfFamily >0)
    {
      family=new Human*[numberOfFamily];
      for(int i{} ;i<numberOfFamily ; i++)
	family[i]=h.family[i];
    }
  std::cout<<"operator= copy version."<<std::endl;
  return *this;
}


Human& Human::operator=(Human&& h)
{
  firstName=h.firstName;
  lastName=h.lastName;
  hairColor=h.hairColor;
  eyeColor=h.eyeColor;
  age=h.age;
  gender=h.gender;
  numberOfChildren=h.numberOfChildren;
  numberOfFamily=h.numberOfFamily;
  mother=h.mother;
  h.mother=nullptr;
  father=h.father;
  h.father=nullptr;
  spouse=h.spouse;
  h.spouse=nullptr;
  if(numberOfChildren>0)
    delete [] children;
  if(numberOfFamily>0)
    delete [] family;
  children=h.children;
  h.children=nullptr;
  family=h.family;
  h.family=nullptr; 
  std::cout<<"operator= move version."<<std::endl;
  return *this;
}

std::string Human::getFirstName()
 {
   return firstName;
 }

std::string Human::getLastName()
 {
   return lastName;
 }

bool Human::getGender()
{
  return gender;
}
  
int Human::getAge()
{
  return age;
}

int Human::getHairColor()
{
  return hairColor;
}

int Human::getEyeColor()
{
  return eyeColor;
}

bool Human::operator>(const Human& h)
{
  return age > h.age ;
}

bool Human::isFatherOf(Human* h) 
{
  return this == h->father;
}

bool Human::isMotherOf(Human* h) 
{
  return this == h->mother;
}

bool Human::isChildOf(Human* h)
{
  bool resualt{false};
  for(int i{};i< h->numberOfChildren ;i++)
    {
      if( this == h->children[i])
	resualt=true;
    }
  return resualt;
} 

bool Human::operator==(const Human& h)
{
  if(firstName != h.firstName)
    return false;
  if(lastName != h.lastName)
    return false;
  if(hairColor != h.hairColor)
    return false;
  if(eyeColor !=h.eyeColor)
    return false;
  if(age != h.age)
    return false;
  if(gender != h.gender)
    return false;
  if(numberOfChildren != h.numberOfChildren)
    return false;
  return true;
}

bool Human::operator!=(const Human& h)
{
  if (*this == h)
    return false;
  else
    return true;
}

void Human::operator++()
{
  ++age;
}

Human* Human::operator+(Human& h)
{
  Human* baby=new Human;
  if(*(this->spouse) == h)
    {
      srand(time(0));
      std::string name;
      if(gender)
        {
	  baby->lastName=h.lastName;
          baby->mother=this;
          baby->father=&h;
        }
      else
        {
          baby->lastName=lastName;
          baby->mother=&h;
          baby->father=this;
         }
      if((rand()%2) ==1)
        baby->hairColor=hairColor;
      else
        baby->hairColor=h.hairColor;
      if((rand()%2) ==1)
        baby->eyeColor=eyeColor;
      else
        baby->eyeColor=h.eyeColor;
      if((rand()%2) ==1)
	{
	  baby->gender=true;
	  std::cout<<"What is her name?";
	}
      else
	{
	   baby->gender=false;
	   std::cout<<"What is his name?";
	}
      std::cin>>name;
      for(size_t i{};i<name.length() ;i++)
      name[i]=static_cast<char>(toupper(name[i]));
      baby->firstName=name;
      numberOfChildren++;
      h.numberOfChildren++;
      if(numberOfChildren > 1)
     	{
	  Human** temp=new Human* [numberOfChildren];
          for(int i{};i<(numberOfChildren-1);i++)
            {
               temp[i]=children[i];
             }
          temp[numberOfChildren-1]=baby;
          delete [] children;
          delete [] h.children;
          children=temp;
          h.children=temp;
	  temp=nullptr;
     	}
        else
	{
	  children=new Human*;
	  h.children=new Human*;
	  h.children[0]=baby;
	  children[0]=baby;
	  }
      
       this->setFamily(*baby);
       h.setFamily(*baby);
       baby->setFamily(*this);
       baby->setFamily(h);  
       for(int j{};j<numberOfFamily;j++)
	{
	  baby->setFamily(*(family[j]));
	  ( *(family[j]) ).setFamily(*baby);
	}
      for(int j{};j<h.numberOfFamily;j++)
	{
	  baby->setFamily(*( (h.family)[j] ));
	  (*( (h.family)[j] )).setFamily(*baby);
	  }
    }
  else
    {
      std::cout<<"false order.We refer you Human that you called this function on him/her."<<std::endl;
      baby=this;
    }
    return baby;
}

void Human::printChildren()
{
  if(numberOfChildren > 0)
    {
      std::cout<<"Children: "<<std::endl;
      for(int i{};i< numberOfChildren ; i++)
        std::cout<<(*(children[i])).firstName<<" "<<(*(children[i])).lastName<<std::endl;
    }
  else
    std::cout<<"No child."<<std::endl;
}
///////////////////////////////////enter h to family if it isnot in family
void Human::setFamily(Human& h)
{
  bool repeated{false};
  if( this == &h)
    repeated=true;
  int counter{0};
  while( (repeated== false) && (counter< numberOfFamily) )
    {
      if( family[counter] == &h)
	repeated=true;
      ++counter;
    }
  if(repeated == false)
    {
      numberOfFamily++;
      if(numberOfFamily > 1)
	{
	  Human** temp=new Human* [numberOfFamily];
          for(int i{};i<(numberOfFamily-1);i++)
	    temp[i]=family[i];
          temp[numberOfFamily-1]=&h;
          delete [] family;
          family=temp;
          temp=nullptr;
	}
      else
	{
	  family=new Human*;
	  family[0]=&h;
	}
    }
} 
