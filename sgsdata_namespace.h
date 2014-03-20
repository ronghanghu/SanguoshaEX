/*
//最后整理时间：2012-06-28
//编辑者：李昂
//命名空间，声明了大量的类和派生类。
*/
#ifndef _SGSDATA_NAMESPACE_H
#define _SGSDATA_NAMESPACE_H
 
namespace sgs{
	class Interface;
	namespace DataType{
		class Message;
		class Card;
		class Skill;
		class Hero;
		class Player;
		class GameCard;
		class Manager;
		class Platform;
		class History;
	}
	namespace Surface{
		class GameData;
	}
	namespace Derive{
		//消息派生类
		class MCard;//使用/打出卡牌
		class MZhangBa;//专用于处理丈八蛇矛的消息
		class MSkill;//使用/触发技能
		class MJudge;//判定
		class MHurt;//造成伤害或回复
		class MTransCard;//转移卡牌
		class MSwitchPhase;//切换阶段
		class MDying;//濒死
		class MKill;//击杀
		class MBegin;//连锁开始标记
		class MError;//错误消息
		class MFinale;//游戏结束

		class MWuSheng;//武圣技能
		class MGangLie;//刚烈技能
		class MQingGuo;//倾国技能
		class MLongDan;//龙胆技能
		class MQiXi;//奇袭技能
		class MFanKui;//反馈技能
		class MJiJiu;//急救技能
		class MQingNang;//青囊技能
		class MRenDe;//仁德技能
		class MJiJiang;//激将技能
		class MLiJian;//离间技能
		class MTuXi;//突袭技能
		class MYiJi;//遗计技能
		class MZhiHeng;//制衡技能
		class MFanJian;//反间技能
		class MJieYin;//结姻技能
		class MGuoSe;//国色技能
		class MLiuLi;//流离技能

		//武将派生类
		class HSuJiang;//素将
		class HNvSuJiang;//女素将
		class HCaoCao;//曹操
		class HSiMaYi;//司马懿
		class HXiaHouDun;//夏侯?
		class HZhangLiao;//张辽
		class HXuChu;//许褚
		class HGuoJia;//郭嘉
		class HZhenJi;//甄姬
		class HLiuBei;//刘备
		class HGuanYu;//关羽
		class HZhangFei;//张飞
		class HLaoZhuGe;//老诸葛
		class HZhaoYun;//赵云
		class HMaChao;//马超
		class HHuangYueYing;//黄月英
		class HSunQuan;//孙权
		class HGanNing;//甘宁
		class HLvMeng;//吕蒙
		class HHuangGai;//黄盖
		class HZhouYu;//周瑜
		class HDaQiao;//大乔
		class HLuXun;//陆逊
		class HSunShangXiang;//孙尚香
		class HHuaTuo;//华佗
		class HLvBu;//吕布
		class HDiaoChan;//貂蝉
		//后续的稍后补充
	}
}
 
#endif /*_SGSDATA_NAMESPACE_H*/
