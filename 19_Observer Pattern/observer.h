//
// Created by xuejun on 23-5-25.
//

#ifndef DESIGN_PATTERNS_OBSERVER_H
#define DESIGN_PATTERNS_OBSERVER_H
#include "agents.h"
#include<string>
#include <memory>

class Observer
{
public:
    Observer(std::string name_,std::shared_ptr<Agents> ptr_);
    void Unsubscribe();
    virtual void update(std::string msg)=0;
    virtual ~Observer()=default;
protected:
    std::string name;
    std::shared_ptr<Agents> ptr;
};
class BJDT:public Observer
{
public:
    using Observer::Observer;
    virtual void update(std::string msg) override;
};
class TJDT:public Observer
{
public:
    using Observer::Observer;
    virtual void update(std::string msg) override;
};
#endif //DESIGN_PATTERNS_OBSERVER_H
