//
// Created by xuejun on 23-5-25.
//
#include "observer.h"
#include "agents.h"
Observer::Observer(std::string name_,Agents* ptr_):name(name_),ptr(ptr_)
{
    ptr->Add_User(this);
};
void Observer::Unsubscribe()
{
    ptr->Delete_User(this);
}

void BJDT::update(std::string msg) 
{
    std::cout<<"Subscriber "<<name<<" accept "<<msg<<std::endl;
};
