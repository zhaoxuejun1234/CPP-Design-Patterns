//
// Created by xuejun on 23-5-25.
//

#ifndef DESIGN_PATTERNS_AGENTS_H
#define DESIGN_PATTERNS_AGENTS_H
//#include "observer.h" 此处注意不能加入observer.h
#include<iostream>
#include<string>
#include<list>  //注意list和vector在使用上的差异，涉及频繁的增删操作需用list，频繁访问需用vector

//前置声明
/*(1))Agents.h中前置声明class Observer
 *(2)Observer中引用Agents.h
 *(3)Agents.h中只能声明Observer的指针或者引用
 */
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
