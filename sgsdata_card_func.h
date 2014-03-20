/*
 //最后整理时间：2012-06-28
 //编辑者：李昂
 //卡牌效果函数的声明
 */
#ifndef _SGSDATA_CARD_FUNC_H
#define _SGSDATA_CARD_FUNC_H
#include "sgsdata_namespace.h"

namespace sgs {
    namespace func {
        DataType::Message * pcsha(DataType::Message *);//杀结算函数
        DataType::Message * pcsha(Derive::MZhangBa *);//专为丈八蛇矛设置的
        DataType::Message * pcshan(DataType::Message *);//闪结算函数
        DataType::Message * pctao(DataType::Message *);//桃结算函数
        DataType::Message * pcatk(DataType::Message *);//减一马的装备过程
        DataType::Message * pcdfd(DataType::Message *);//加一马的装备过程
        DataType::Message * pcweapon(DataType::Message *);//武器的装备过程
        DataType::Message * pcarmor(DataType::Message *);//防具的装备过程
        bool pchanbing(DataType::Message *); //使用寒冰剑，传入参数为打杀的消息。不用检查玩家是否装备了寒冰剑，在本函数中有检查。主要被pcsha调用。
        bool pcrenwang(DataType::Message *); //使用仁王盾，传入参数为打杀的消息。不用检查玩家是否装备了仁王盾，在本函数中有检查。主要被pcsha调用。
        bool pcbagua(DataType::Message *); //使用八卦阵，传入参数为导致使用八卦阵的消息。不用检查玩家是否装备了八卦阵，在本函数中有检查。主要被pcsha调用。
        bool pcqinglong(DataType::Message *); //使用青龙偃月刀，传入参数为打杀的消息。不用检查玩家是否装备了青龙偃月刀，在本函数中有检查。主要被pcsha调用。
        bool pcguanshi(DataType::Message *); //使用贯石斧，传入参数为打杀的消息。不用检查玩家是否装备了贯石斧，在本函数中有检查。主要被pcsha调用。
        bool pcqilin(DataType::Message *); //使用麒麟弓，传入参数为打杀的消息。不用检查玩家是否装备了麒麟弓，在本函数中有检查。主要被pcsha调用。
        bool pccixiong(DataType::Message *); //使用雌雄双股剑，传入参数为打杀的消息。不用检查玩家是否装备了雌雄双股剑，在本函数中有检查。主要被pcsha调用。
        DataType::Message * pcshunqian(DataType::Message *); //顺手牵羊结算函数
        DataType::Message * pcguochai(DataType::Message *); //过河拆桥结算函数
        bool pcwuxie(DataType::Message *, DataType::Message * = 0, int = 0); //询问无懈可击，传入为可能被无懈的消息，第二个参数为最初引发无懈的消息， 第三个参数为已经被无懈的次数。返回是否被无懈掉。
        DataType::Message * pcwuzhong(DataType::Message *); //无中生有结算函数
        DataType::Message * pcjuedou(DataType::Message *); //决斗结算函数
        DataType::Message * pctaoyuan(DataType::Message *); //桃园结义结算函数
        DataType::Message * pcwanjian(DataType::Message *); //万箭齐发结算函数
        DataType::Message * pcnanman(DataType::Message *); //南蛮入侵结算函数
        DataType::Message * pcyanshi(DataType::Message *);//延时锦囊的使用，不是判定时的函数
        DataType::Message * pcshandian(DataType::Message *);//判定闪电
        DataType::Message * pcsishu(DataType::Message *);//判定乐不思蜀
        Derive::MZhangBa * pczhangba(Derive::MZhangBa *);//使用丈八蛇矛
        DataType::Message * pcwugu(DataType::Message *);//五谷丰登结算函数
        DataType::Message * pcjiedao(DataType::Message *);//借刀杀人结算函数
    }
}

#endif /*_SGSDATA_CARD_FUNC_H*/
