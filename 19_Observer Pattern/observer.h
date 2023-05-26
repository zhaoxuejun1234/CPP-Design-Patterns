//
// Created by xuejun on 23-5-25.
//

#ifndef DESIGN_PATTERNS_OBSERVER_H
#define DESIGN_PATTERNS_OBSERVER_H
#include<string>
#include "agents.h"

class Observer
{
public:
    Observer(std::string name_,Agents* ptr_);
    void Unsubscribe();
    virtual void update(std::string msg)=0;
    virtual ~Observer()=default;
protected:
    std::string name;
    Agents* ptr;
};
class BJDT:public Observer
{
public:
    using Observer::Observer;
    virtual void update(std::string msg) override;
};
#endif //DESIGN_PATTERNS_OBSERVER_H
