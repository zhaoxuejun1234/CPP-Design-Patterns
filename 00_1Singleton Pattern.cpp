//
// Created by xuejun on 23-5-5.
// 本节开始为创建型模式
// 单例模式有且仅有一个实例：饿汉模式，懒汉模式
// 创建实例的多线程安全问题：懒汉模式,解决方法：原子变量，静态变量

// 任务队列，生产者、消费者模式
// 本代码主要实现单例模式的创建，严格的生产者消费者模式参见一下代码仓库
//https://github.com/zhaoxuejun1234/Modern-CPP/blob/master/11_cp_model.cpp
#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>
using namespace std;
//region0 单例队列
//类初始化后生成唯一任务队列，生产者消费者轮番访问任务队列
class Q_Task
{
public:
    static Q_Task* GetInstance()
    {
        return &Tasks;
    }
    bool IsEmpty()
    {
        lock_guard<mutex> lock(mtx);
        bool flag = taskQ.empty();
        return flag;
    }
    void AddTasks(int data)
    {
        lock_guard<mutex> lock(mtx);
        taskQ.push(data);
//        cout<<"Queue size is "<<taskQ.size()<<endl;
    }
    int GetTasks()
    {
        lock_guard<mutex> lock(mtx);
        if (!taskQ.empty())
            return taskQ.front();
        return -1;
    }

    void PopTasks()
    {
        lock_guard<mutex> lock(mtx);
        if (!taskQ.empty()){taskQ.pop();}
        else {cout<<"Task queue is empty"<<endl;}
    }


private:
    Q_Task()=default;
    Q_Task(const Q_Task&)=default;
    Q_Task& operator=(const Q_Task&)=default;
    static Q_Task Tasks;
    queue<int> taskQ;
    mutex mtx;
    condition_variable cv;

};
Q_Task Q_Task::Tasks;
//Q_Task*  Q_Task::Tasks = new Q_Task;
//endregion0 单例队列
int main()
{
    thread t1  = thread([]()
    {
        Q_Task* Q = Q_Task::GetInstance();
        for(int i=0;i<100;i++)
        {
            Q->AddTasks(i);
            cout<<"Set Task number is "<<i<<endl;
                this_thread::sleep_for(chrono::milliseconds (1000));
        }
    }
    );
    thread t2  = thread([]()
    {
        Q_Task* Q = Q_Task::GetInstance();
        while(!Q->IsEmpty())
        {
            cout<<"Get Task number is "<<Q->GetTasks()<<endl;
            Q->PopTasks();
            this_thread::sleep_for(chrono::milliseconds (2000));
            //代码存在的bug，如果消费者消费速度太快，将直接跳出循环，结束程序，无法获得队列信号量的变化

        }
    }
    );
    t1.join();
    t2.join();
    return 0;
}

