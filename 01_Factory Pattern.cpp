//
// Created by xuejun on 23-5-5.
//

//工厂模式类关系UML图
//例子：生产不同类型的恶魔果实，通过多态实现，父类指针指向子类对象
//父类和子类发生继承关系，并通过指针实现多态时，父类需要是虚析构函数
//简单工厂模式(1个工厂类，1个工厂生产多个对象)-->工厂模式(多个工厂，工厂类和对象1对1，解耦合)-->抽象工厂模式
//开放封闭原则(类内封闭、类外开放，已经开发好的类不再改变)，单一职责原则，依赖倒置原则

#include <iostream>

using namespace std;

enum class Type:char{Sheep,Lion};
class AbstractSmile
{
public:
    virtual void transform()=0;
    virtual void ability()=0;
    virtual ~AbstractSmile()=default;
private:

};
class SheepSmile: public AbstractSmile
{
    void transform()
    {
        cout<<"Transform into sheep"<<endl;
    }
    void ability()
    {
        cout<<"Can produce milk"<<endl;
    }
};

class LionSmile: public AbstractSmile
{
    void transform()
    {
        cout<<"Transform into lion"<<endl;
    }
    void ability()
    {
        cout<<"Can produce fire"<<endl;
    }
};
class SimleFactory
{
public:
    AbstractSmile* CreateSmile(Type type)
    {
        switch(type)
        {
            case Type::Sheep:
            {
                AbstractSmile* p1 = new SheepSmile;
                return p1;
            }
            case Type::Lion:
            {
                AbstractSmile* p1 = new LionSmile;
                return p1;
            }
        }
    }

private:

};
int main()
{
    SimleFactory f;
    AbstractSmile* p = f.CreateSmile(Type::Lion);
    p->transform();
    p->ability();

}