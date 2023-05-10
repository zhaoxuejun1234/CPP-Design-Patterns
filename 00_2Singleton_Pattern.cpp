//
// Created by xuejun on 23-5-10.
//

// 饿汉模式
class TaskQueue
{
public:
    TaskQueue& operator=(const TaskQueue&)=delete;
    static TaskQueue* getInstance()
    {
        return Task;
    }
private:

    TaskQueue()=default;
    static TaskQueue* Task;
};
TaskQueue* TaskQueue::Task = new TaskQueue;  //静态成员需要进行类外初始化
//懒汉模式
// 创建实例的多线程安全问题：懒汉模式,解决方法：原子变量+锁，静态变量
class TaskQueue2
{
public:
    TaskQueue2& operator=(const TaskQueue2&)=delete;
    static TaskQueue2* getInstance()
    {
        if(Task== nullptr)
        {
            Task = new TaskQueue2;
            // new TaskQueue2 此处有三个原子操作：(1)new出一块内存(2)创建对象(3)Task指针指向创建的对象
        }
        return Task;
    }

private:
    TaskQueue2()=default;
    static TaskQueue2* Task;

};
TaskQueue2* TaskQueue2::Task = nullptr;
int main()
{
    TaskQueue* obj = TaskQueue::getInstance();

}