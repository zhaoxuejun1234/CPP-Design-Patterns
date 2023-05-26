//
// Created by xuejun on 23-5-25.
//

#ifndef DESIGN_PATTERNS_AGENTS_H
#define DESIGN_PATTERNS_AGENTS_H
#include<iostream>
#include<string>
#include<list>
class Observer;
class Agents
{
public:
    void Add_User(Observer* ptr);
    void Delete_User(Observer* ptr);
    virtual void Notify_User(std::string msg)=0;
    virtual ~Agents()=default;

protected:
    std::list<Observer*> obj;
};

class MQTT:public Agents
{
public:
    void Notify_User(std::string msg) override;
};
#endif //DESIGN_PATTERNS_AGENTS_H
