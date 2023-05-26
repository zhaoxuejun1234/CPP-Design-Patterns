//
// Created by xuejun on 23-5-25.
//
#include "agents.h"
#include "observer.h"

void Agents::Add_User(Observer *ptr) { obj.push_back(ptr);}
void Agents::Delete_User(Observer *ptr) {obj.remove(ptr);}

void MQTT::Notify_User(std::string msg) 
{
    std::cout<<"MQTT has "<<obj.size()<<" subscribers "<<std::endl;
    for (auto &item:obj)
    {
        item->update(msg);
    }
}

