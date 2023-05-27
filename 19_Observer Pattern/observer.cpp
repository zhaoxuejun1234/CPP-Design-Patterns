//
// Created by xuejun on 23-5-25.
//
#include "observer.h"
//#include "agents.h"
#include <memory>
Observer::Observer(std::string name_,std::shared_ptr<Agents> ptr_):name(name_),ptr(ptr_)
{
    ptr->Add_User(this);
};
void Observer::Unsubscribe()
{
    ptr->Delete_User(this);
}

void BJDT::update(std::string msg) 
{
    std::cout<<"Subscriber "<<name<<" accept info: "<<msg<<std::endl;
};
void TJDT::update(std::string msg)
{
    std::cout<<"Subscriber "<<name<<" accept info:"<<msg<<std::endl;
}