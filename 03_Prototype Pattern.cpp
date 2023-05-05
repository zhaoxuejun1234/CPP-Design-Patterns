//
// Created by xuejun on 23-5-5.
//
// 原型模式，通过父类指针实现子类对象的拷贝  /\
// 思考为什么不通过拷贝构造函数实现对象的拷贝/|\
//                                   / | \

#include <iostream>
using namespace std;

class Naruto
{
public:
    Naruto()=default;
    virtual ~Naruto()
    {
        cout<<this->name<<"  has been cleared"<<endl;
    }
    virtual Naruto* clone(string name)=0;

protected:
    string name;
};

class Naruto2:public Naruto
{
public:
    Naruto* clone(string name) override
    {
        Naruto* ptr = new Naruto2;
        this->name = name;
        cout<<"solider name is "<<name<<endl;
        return ptr;
    }
private:
};
void test()
{
    Naruto* ptr1 = new Naruto2;
    ptr1->clone("Naruto1");
    delete ptr1;
}
int main()
{
    test();
}
