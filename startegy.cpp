/*********************************
Design Pattern 1: Startegy Pattern
Defination : the strategy pattern (also known as the policy pattern) is a behavioral 
             software design pattern that enables selecting an algorithm at runtime. 
             Instead of implementing a single algorithm directly, code receives run-time 
             instructions as to which in a family of algorithms to use.
**********************************/

/* In this code their is implemantation of different differt features of different different Duck*/
#include<iostream>

using namespace std;

//Interface for Flying Behaviour of bird
class Ifly{
  public:
    virtual void fly() = 0;
};


class flyslow : public Ifly{
  public:
    virtual void fly() override{
      cout<<"Flying slow"<<endl;
    }
};

class flyNormal : public Ifly{
  public:
    virtual void fly() override{
      cout<<"Flying Normal"<<endl;
    }
};

class flyRocket : public Ifly{
  public:
    virtual void fly() override{
      cout<<"Flying woooooooo"<<endl;
    }
};

class flyNo : public Ifly{
  public:
    virtual void fly() override{
      cout<<"I can not fly"<<endl;
    }
};

//Interface for quank Behaviour of bird
class Iquank{
  public:
    virtual void quank() = 0;
};

class quankChii : public Iquank {
  public:
    virtual void quank() override{
      cout<<"quanking chii chii"<<endl;
    }
};

class quankNo : public Iquank {
  public:
    virtual void quank() override{
      cout<<"Not able to quank"<<endl;
    }
};

//Interface for Swimming Behaviour of bird
class Iswim{
  public:
    virtual void swim() = 0;
};

class swimUnderWater : public Iswim{
  public:
    virtual void swim() override {
      cout<<"I can swim under Water"<<endl;
    }
};

class swimOverWater : public Iswim{
  public:
    virtual void swim() override {
      cout<<"I can swim over Water"<<endl;
    }
};

class swimNo : public Iswim{
  public:
    virtual void swim() override {
      cout<<"I can not swim"<<endl;
    }
};


class Duck final{
  private:
    Ifly *fptr;
    Iquank *qptr;
    Iswim *sptr;
  public:
    Duck(Ifly *f,Iquank *q,Iswim *s){
      fptr = f;
      qptr = q;
      sptr = s;
    }

    void flyMethod(){
      fptr->fly();
    }
    void quankMethod(){
      qptr->quank();
    }
    void swimMethod(){
      sptr->swim();
    }
};

int main(){
  Duck RealDuck(new flyNormal(), new quankChii(), new swimOverWater());
  Duck RubberDuck(new flyNo(), new quankNo(), new swimOverWater());
  Duck MountainDuck(new flyRocket(), new quankChii(), new swimNo());
  Duck RiverDuck(new flyNo(), new quankChii(), new swimUnderWater());
  

  RealDuck.flyMethod();
  RealDuck.quankMethod();
  RealDuck.swimMethod();

  RubberDuck.flyMethod();
  RubberDuck.quankMethod();
  RubberDuck.swimMethod();

  MountainDuck.flyMethod();
  MountainDuck.quankMethod();
  MountainDuck.swimMethod();

  RiverDuck.flyMethod();
  RiverDuck.quankMethod();
  RiverDuck.swimMethod();
  return 0;
}