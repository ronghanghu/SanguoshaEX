/*
//最后编辑时间2012-06-28
//编辑者：李昂‘
//全局变量定义
*/
#include "sgsdata_enum.h"
#include "sgsdata_extern.h"
#include "sgsdata_card.h"
#include "sgsdata_gamedata.h"
#include "sgsdata_history.h"
#include "sgsdata_platform.h"
#include "sgsdata_heroes.h"
using namespace sgs;
using namespace ConstData;
using namespace DataType;

Surface::GameData ExternData::gamedata;
DataType::History ExternData::history;
DataType::Platform ExternData::platform;
sgsui::Outstream ExternData::sgsout;

Derive::HSuJiang ExternData::hsujiang;
Derive::HNvSuJiang ExternData::hnvsujiang;

Derive::HZhangFei ExternData::hzhangfei;
Derive::HLvMeng ExternData::hlvmeng;
Derive::HMaChao ExternData::hmachao;
Derive::HGuanYu ExternData::hguanyu;
Derive::HXiaHouDun ExternData::hxiahoudun;
Derive::HXuChu ExternData::hxuchu;
Derive::HZhenJi ExternData::hzhenji;
Derive::HLaoZhuGe ExternData::hlaozhuge;
Derive::HZhaoYun ExternData::hzhaoyun;
Derive::HGanNing ExternData::hganning;
Derive::HSiMaYi ExternData::hsimayi;
Derive::HHuangGai ExternData::hhuanggai;
Derive::HHuaTuo ExternData::hhuatuo;
Derive::HLiuBei ExternData::hliubei;
Derive::HCaoCao ExternData::hcaocao;
Derive::HHuangYueYing ExternData::hhuangyueying;
Derive::HDiaoChan ExternData::hdiaochan;
Derive::HZhangLiao ExternData::hzhangliao;
Derive::HGuoJia ExternData::hguojia;
Derive::HSunQuan ExternData::hsunquan;
Derive::HLvBu ExternData::hlvbu;
Derive::HZhouYu ExternData::hzhouyu;
Derive::HSunShangXiang ExternData::hsunshangxiang;
Derive::HLuXun ExternData::hluxun;
Derive::HDaQiao ExternData::hdaqiao;

const Card ExternData::card[108]=
{Card(DIAMOND,6,SHA),   Card(DIAMOND,7,SHA),    Card(DIAMOND,8,SHA),    Card(DIAMOND,9,SHA),     Card(DIAMOND,10,SHA),     //5
 Card(DIAMOND,13,SHA),  Card(SPADE,7,SHA),      Card(SPADE,8,SHA),      Card(SPADE,8,SHA),       Card(SPADE,9,SHA),        //10
 Card(SPADE,9,SHA),     Card(SPADE,10,SHA),     Card(SPADE,10,SHA),     Card(HEART,10,SHA),      Card(HEART,10,SHA),       //15
 Card(HEART,11,SHA),    Card(CLUB,2,SHA),       Card(CLUB,3,SHA),       Card(CLUB,4,SHA),        Card(CLUB,5,SHA),         //20
 Card(CLUB,6,SHA),      Card(CLUB,7,SHA),       Card(CLUB,8,SHA),       Card(CLUB,8,SHA),        Card(CLUB,9,SHA),         //25
 Card(CLUB,9,SHA),      Card(CLUB,10,SHA),      Card(CLUB,10,SHA),      Card(CLUB,11,SHA),       Card(CLUB,11,SHA),        //30
 Card(DIAMOND,2,SHAN),  Card(DIAMOND,2,SHAN),   Card(DIAMOND,3,SHAN),   Card(DIAMOND,4,SHAN),    Card(DIAMOND,5,SHAN),     //35
 Card(DIAMOND,6,SHAN),  Card(DIAMOND,7,SHAN),   Card(DIAMOND,8,SHAN),   Card(DIAMOND,9,SHAN),    Card(DIAMOND,10,SHAN),    //40
 Card(DIAMOND,11,SHAN), Card(DIAMOND,11,SHAN),  Card(HEART,2,SHAN),     Card(HEART,2,SHAN),      Card(HEART,13,SHAN),      //45
 Card(DIAMOND,12,TAO),  Card(HEART,3,TAO),      Card(HEART,4,TAO),      Card(HEART,6,TAO),       Card(HEART,7,TAO),        //50
 Card(HEART,8,TAO),     Card(HEART,9,TAO),      Card(HEART,12,TAO),     Card(HEART,1,WANJIAN/*&pcwanjian*/),   Card(HEART,1,TAOYUAN/*&&pctaoyuan*/),    //55
 Card(CLUB,12,JIEDAO/*&pcjiedao*/),  Card(CLUB,13,JIEDAO/*&pcjiedao*/),   Card(HEART,3,WUGU/*&pcwugu*/),     Card(HEART,4,WUGU/*&pcwugu*/),      Card(SPADE,1,SHANDIAN/*&&pcshandian*/),   //60
 Card(DIAMOND,1,JUEDOU/*&pcjuedou*/),Card(SPADE,1,JUEDOU/*&pcjuedou*/),   Card(CLUB,1,JUEDOU/*&pcjuedou*/),    Card(SPADE,7,NANMAN/*&pcnanman*/),    Card(SPADE,13,NANMAN/*&pcnanman*/),    //65
 Card(CLUB,7,NANMAN/*&pcnanman*/),   Card(SPADE,6,SISHU/*&pcsishu*/),    Card(HEART,6,SISHU/*&pcsishu*/),    Card(CLUB,6,SISHU/*&pcsishu*/),      Card(HEART,7,WUZHONG/*&pcwuzhong*/),    //70
 Card(HEART,8,WUZHONG/*&pcwuzhong*/), Card(HEART,9,WUZHONG/*&pcwuzhong*/),  Card(HEART,11,WUZHONG/*&pcwuzhong*/), Card(DIAMOND,3,SHUNQIAN/*&pcshunqian*/),Card(DIAMOND,4,SHUNQIAN/*&pcshunqian*/), //75
 Card(SPADE,3,SHUNQIAN/*&pcshunqian*/),Card(SPADE,4,SHUNQIAN/*&pcshunqian*/), Card(SPADE,11,SHUNQIAN/*&pcshunqian*/),Card(SPADE,3,GUOCHAI/*&pcguochai*/),	Card(SPADE,4,GUOCHAI/*&pcguochai*/),    //80
 Card(SPADE,12,GUOCHAI/*&pcguochai*/),Card(HEART,12,GUOCHAI/*&pcguochai*/), Card(CLUB,3,SHUNQIAN/*&pcshunqian*/),  Card(CLUB,4,SHUNQIAN/*&pcshunqian*/),   Card(SPADE,11,WUXIE/*&pcwuxie*/),     //85
 Card(CLUB,12,WUXIE/*&pcwuxie*/),   Card(CLUB,13,WUXIE/*&pcwuxie*/),    Card(DIAMOND,1,ZHUGE/*&pczhuge*/),  Card(CLUB,1,ZHUGE/*&pczhuge*/),      Card(SPADE,2,CIXIONG/*&pccixiong*/),    //90
 Card(SPADE,6,QINGGANG/*&pcqinggang*/),Card(SPADE,5,QINGLONG/*&pcqinglong*/), Card(SPADE,12,ZHANGBA/*&pczhangba*/), Card(DIAMOND,5,GUANSHI/*&pcguanshi*/), Card(DIAMOND,12,FANGTIAN/*&pcfangtian*/),//95
 Card(HEART,5,QILIN/*&pcqilin*/),   Card(SPADE,2,BAGUA/*&pcbagua*/),    Card(CLUB,2,BAGUA/*&pcbagua*/),     Card(CLUB,5,CHITU/*&pcatk*/),      Card(SPADE,13,DAWAN/*&pcatk*/),     //100
 Card(DIAMOND,13,ZICI/*&pcatk*/), Card(CLUB,5,DILU/*&pcdfd*/),      Card(SPADE,5,JUEYING/*&pcdfd*/),  Card(HEART,5,ZHUAHUANG/*&pcdfd*/) , Card(SPADE,2,HANBING),			//105
 Card(CLUB,2,RENWANG),		Card(HEART, 12, SHANDIAN),		Card(DIAMOND, 12, WUXIE)
};
