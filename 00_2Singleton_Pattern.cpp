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
class TaskQueue2
{
public:
    TaskQueue2& operator=(const TaskQueue2&)=delete;
    static TaskQueue2* getInstance()
    {
        if(Task== nullptr)
        {
            Task = new TaskQueue2;
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