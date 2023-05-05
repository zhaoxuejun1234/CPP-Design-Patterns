//
// Created by xuejun on 23-5-5.
// 本节开始为创建型模式
// 单例模式有且仅有一个实例：饿汉模式，懒汉模式
// 创建实例的多线程安全问题：懒汉模式,解决方法：原子变量，静态变量

// 实现一个单例模式的类：任务队列，生产者、消费者模式
#include <iostream>
#include <queue>
using namespace std;
class Q_Task
{
public:

private:
    queue<int> Tasks;


};


int main()
{
    return 0;
}