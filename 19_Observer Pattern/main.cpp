//
// Created by xuejun on 23-5-25.
//
//
// Created by xuejun on 23-5-25.
//

#include "agents.h"
#include "observer.h"
#include<memory>
using namespace std;
int main()
{
    //1.两个类交叉引用在同一个文件下有什么问题 
    //2.接口模式改写程序，去掉
    shared_ptr<Agents> mqtt(new MQTT);
    shared_ptr<Observer> bjdt = make_shared<BJDT>("BJDT",mqtt);
    shared_ptr<Observer> thdt = make_shared<TJDT>("TJDT",mqtt);
    // mqtt->Add_User(bjdt);
    mqtt->Notify_User("Abnormal Behavior");
    bjdt->Unsubscribe();
    mqtt->Notify_User("BJDT has gone");
//    bjdt->update();
//    delete mqtt;
//    delete bjdt;
    return 0;
}


