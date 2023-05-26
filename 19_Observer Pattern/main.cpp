//
// Created by xuejun on 23-5-25.
//
//
// Created by xuejun on 23-5-25.
//

#include "agents.h"
#include "observer.h"
#include<iostream>
using namespace std;
int main()
{
    //1.两个类交叉引用在同一个文件下有什么问题 
    //2.接口模式改写程序
    Agents* mqtt = new MQTT;
    Observer* bjdt = new BJDT("BJDT",mqtt);
    // mqtt->Add_User(bjdt);
    mqtt->Notify_User("Abnormal Behavior");
    // bjdt->update();
    
}


