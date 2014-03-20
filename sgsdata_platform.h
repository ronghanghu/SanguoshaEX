/*
//最后整理时间：2012-06-28
//编辑者：李昂
//平台类的定义。平台类是GameCard类和Manager类的派生类。
//平台是数据集散的中心和底层逻辑实现的平台。
//在底层逻辑的主函数中只执行平台的函数。
//平台也提供最主要的消息处理函数analyze，用在处理消息的各个地方。
//平台还提供摸牌、弃牌等接口。
//平台以全局变量的形式存在，在许多函数中被访问和调用成员函数。
*/
#ifndef _SGSDATA_PLATFORM_H
#define _SGSDATA_PLATFORM_H
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"
#include "sgsdata_gamecard.h"
#include "sgsdata_manager.h"
#include <stack>
 
class sgs::DataType::Platform : public sgs::DataType::GameCard, public sgs::DataType::Manager
{
    sgs::DataType::Player * _player;//当前动作的玩家。
	int _playernum;//玩家个数
    std::stack<sgs::DataType::Message *> _groove;//待处理消息沟道
    char endOrNot(); //返回游戏结果（每一位0代表玩家失败，1代表玩家获胜，如果游戏没有结束则返回0）
public:
    sgs::DataType::Message * analyze(sgs::DataType::Message *);//处理各种消息的核心函数。
    const Card * getJudge();//获得一张判定牌

    //主函数接口
	void start(int N);//游戏初始化
	char run();//游戏运行
	void end();//游戏结束

    //消息沟道相关函数
    void msgInsert(sgs::DataType::Message *);//向消息沟道插入一个新消息，如果传入空指针则不会插入
    bool msgEmpty();//调查消息沟道是否为空
    sgs::DataType::Message * msgRead();//读取消息沟道的最顶层消息
    void msgPop();//弹出消息沟道最顶层的消息

    friend class sgs::Surface::GameData;//界面可以通过数据堆访问玩家数据。
};
 
#endif /*_SGSDATA_PLATFORM_H*/
