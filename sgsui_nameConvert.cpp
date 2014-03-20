/*
 * sgsui_nameConvert.cpp
 *
 *  Created on: Mar 20, 2012
 *      Author: latios
 */

#include "sgsui_nameConvert.h"
#include "sgsui_output.h"
#include "sgsui_GUIStaticData.h"
#include "sgsdata_card.h"
#include "sgsdata_player.h"
#include "sgsdata_msg.h"
#include <QObject>
#include <cstdlib>

namespace sgsui {

QString phasePixmapStr(sgs::ConstData::PlayerPhase phase, bool isDying,
		bool isResponding) {
	if (isResponding)
		return QString("images/phase/response.png");
	if (isDying)
		return QString("images/phase/sos.png");

	using namespace sgs::ConstData;
	switch (phase) {
	case START:
		return QString("images/phase/start.png");
	case JUDGEMENT:
		return QString("images/phase/judge.png");
	case GETCARD:
		return QString("images/phase/draw.png");
	case MAIN:
		return QString("images/phase/play.png");
	case ABANDONCARD:
		return QString("images/phase/discard.png");
	case END:
		return QString("images/phase/finish.png");
	case OTHER:
		printDebug(
				"<font color=red><b>Warning: </b></font>phasePixmapStr: you should not call this when the phase is OTHER");
		return QString();
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>phasePixmapStr: Invalid Phase");
		return QString();
	}
}

QString phaseFramePixmapStr(sgs::ConstData::PlayerPhase phase, bool isDying,
		bool isResponding) {
	if (isResponding)
		return QString("images/frame/responsing.png");
	if (isDying)
		return QString("images/frame/sos.png");

	using namespace sgs::ConstData;
	switch (phase) {
	case START:
	case JUDGEMENT:
	case GETCARD:
	case MAIN:
	case ABANDONCARD:
	case END:
		return QString("images/frame/playing.png");
	case OTHER:
		printDebug(
				"<font color=red><b>Warning: </b></font>phaseFramePixmapStr: you should not call this when the phase is OTHER");
		return QString();
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>phaseFramePixmapStr: Invalid Phase");
		return QString();
	}

}

QString roleDisplayName(sgs::ConstData::PlayerRole playerRole) {
	switch (playerRole) {
	case sgs::ConstData::ZHU:
		return QObject::trUtf8("\344\270\273\345\205\254");
	case sgs::ConstData::ZHONG:
		return QObject::trUtf8("\345\277\240\350\207\243");
	case sgs::ConstData::FAN:
		return QObject::trUtf8("\345\217\215\350\264\274");
	case sgs::ConstData::NEI:
		return QObject::trUtf8("\345\206\205\345\245\270");
	default:
		return QString();
	}
}

QString roleSmallPixmapStr(sgs::ConstData::PlayerRole playerRole, bool dead) {
	switch (playerRole) {
	case sgs::ConstData::ZHU:
		return dead ?
				QString("images/roles/dead-lord.png") :
				QString("images/roles/small-lord.png");
	case sgs::ConstData::ZHONG:
		return dead ?
				QString("images/roles/dead-loyalist.png") :
				QString("images/roles/small-loyalist.png");
	case sgs::ConstData::FAN:
		return dead ?
				QString("images/roles/dead-rebel.png") :
				QString("images/roles/small-rebel.png");
	case sgs::ConstData::NEI:
		return dead ?
				QString("images/roles/dead-renegade.png") :
				QString("images/roles/small-renegade.png");
	default:
		return QString();
	}
}

QString rolePixmapStr(sgs::ConstData::PlayerRole playerRole, bool visible) {
	if (visible) {
		switch (playerRole) {
		case sgs::ConstData::ZHU:
			return QString("images/roles/lord.png");
		case sgs::ConstData::ZHONG:
			return QString("images/roles/loyalist.png");
		case sgs::ConstData::FAN:
			return QString("images/roles/rebel.png");
		case sgs::ConstData::NEI:
			return QString("images/roles/renegade.png");
		default:
			return QString("images/roles/unknown.png");
		}
	} else {
		switch (playerRole) {
		case sgs::ConstData::ZHU:
			return QString("images/roles/lord.png");
		default:
			return QString("images/roles/unknown.png");
		}
	}

}

QString deadRolePixmapStr(sgs::ConstData::PlayerRole playerRole) {
	switch (playerRole) {
	case sgs::ConstData::ZHU:
		return QString("images/death/lord.png");
	case sgs::ConstData::ZHONG:
		return QString("images/death/loyalist.png");
	case sgs::ConstData::FAN:
		return QString("images/death/rebel.png");
	case sgs::ConstData::NEI:
		return QString("images/death/renegade.png");
	default:
		return QString("images/death/unknown.png");
	}
}

QString HPPixmapStr(int hp) {
	switch (hp) {
	case 0:
		return QString("images/HP/0.png");
	case 1:
		return QString("images/HP/1.png");
	case 2:
		return QString("images/HP/2.png");
	case 3:
		return QString("images/HP/3.png");
	case 4:
		return QString("images/HP/4.png");
	default:
		return QString("images/HP/5.png");
	}
}

QString smallHPPixmapStr(int hp) {
	switch (hp) {
	case 0:
		return QString("images/HP/small-0.png");
	case 1:
		return QString("images/HP/small-1.png");
	case 2:
		return QString("images/HP/small-2.png");
	case 3:
		return QString("images/HP/small-3.png");
	case 4:
		return QString("images/HP/small-4.png");
	default:
		return QString("images/HP/small-5.png");
	}
}

QString countrySmallPixmapStr(sgs::ConstData::HeroSide heroSide) {
	switch (heroSide) {
	case sgs::ConstData::WEI:
		return QString("images/country/wei.png");
	case sgs::ConstData::SHU:
		return QString("images/country/shu.png");
	case sgs::ConstData::WU:
		return QString("images/country/wu.png");
	case sgs::ConstData::QUN:
		return QString("images/country/qun.png");
	default:
		return QString("images/country/god.png");
	}
}

QString countryFramePixmapStr(sgs::ConstData::HeroSide heroSide) {
	switch (heroSide) {
	case sgs::ConstData::WEI:
		return QString("images/frame/wei.png");
	case sgs::ConstData::SHU:
		return QString("images/frame/shu.png");
	case sgs::ConstData::WU:
		return QString("images/frame/wu.png");
	case sgs::ConstData::QUN:
		return QString("images/frame/qun.png");
	default:
		return QString("images/frame/god.png");
	}
}

QString cardNumberStr(int number, sgs::ConstData::CardColor cardColor) {
	QString cardNumberString;

	if (cardColor == sgs::ConstData::HEART
			|| cardColor == sgs::ConstData::DIAMOND)
		cardNumberString.append("images/red/");
	else
		cardNumberString.append("images/black/");
	return cardNumberString.append(QString::number(number) + ".png");
}

QString cardColorStr(sgs::ConstData::CardColor cardColor) {
	switch (cardColor) {
	case sgs::ConstData::HEART:
		return QString("images/color/heart.png");
	case sgs::ConstData::DIAMOND:
		return QString("images/color/diamond.png");
	case sgs::ConstData::CLUB:
		return QString("images/color/club.png");
	default:
		return QString("images/color/spade.png");
	}
}

QString cardColorDisplayName(sgs::ConstData::CardColor cardColor,
		bool richText) {
	QString colorName;
	if (richText) {
		switch (cardColor) {
		case sgs::ConstData::HEART:
		case sgs::ConstData::DIAMOND:
			colorName.append("<font color=red>");
			break;
		default:
			colorName.append("<font color=black>");
			break;
		}
	}

	switch (cardColor) {
	case sgs::ConstData::HEART:
		colorName.append(QObject::trUtf8("\342\231\245"));
		break;
	case sgs::ConstData::DIAMOND:
		colorName.append(QObject::trUtf8("\342\231\246"));
		break;
	case sgs::ConstData::CLUB:
		colorName.append(QObject::trUtf8("\342\231\243"));
		break;
	default:
		colorName.append(QObject::trUtf8("\342\231\240"));
		break;
	}

	if (richText)
		colorName.append("</font>");
	return colorName;
}

QString bigCardColorStr(sgs::ConstData::CardColor cardColor) {
	switch (cardColor) {
	case sgs::ConstData::HEART:
		return QString("images/big-color/heart.png");
	case sgs::ConstData::DIAMOND:
		return QString("images/big-color/diamond.png");
	case sgs::ConstData::CLUB:
		return QString("images/big-color/club.png");
	default:
		return QString("images/big-color/spade.png");
	}
}

QString cardPixmapStr(sgs::ConstData::CardType cardType) {
	QString cardPixmapString("images/card/");
	return cardPixmapString.append(cardFilenameStr(cardType)).append(".jpg");
}

QString cardSoundStr(sgs::ConstData::CardType cardType, bool sex) {
	if (isZhuangbeiCard(cardType))
		return QString("sound/system/install-equip.mp3");

	QString cardSoundString("sound/card/");
	cardSoundString.append(sex ? "male/" : "female/");
	return cardSoundString.append(cardFilenameStr(cardType)).append(".mp3");
}

bool isZhuangbeiCard(sgs::ConstData::CardType cardType) {
	return getEquipType(cardType) != NotEquip;
}

bool isJinnangCard(sgs::ConstData::CardType cardType) {
	using namespace sgs::ConstData;
	switch (cardType) {
	case BINGLIANG:
	case SISHU:
	case SHANDIAN:
	case GUOCHAI:
	case HUOGONG:
	case JIEDAO:
	case JUEDOU:
	case NANMAN:
	case SHUNQIAN:
	case TAOYUAN:
	case TIESUO:
	case WANJIAN:
	case WUXIE:
	case WUZHONG:
	case WUGU:
		return true;
	default:
		return false;
	}
}

bool isJudgeCard(sgs::ConstData::CardType cardType) {
	using namespace sgs::ConstData;
	switch (cardType) {
	case BINGLIANG:
	case SISHU:
	case SHANDIAN:
		return true;
	default:
		return false;
	}
}

QString cardDisplayName(sgs::ConstData::CardType cardType) {
	using namespace sgs::ConstData;
	switch (cardType) {
	//Jiben
	case HUOSHA:
		return QObject::trUtf8("\347\201\253\346\235\200");
	case LEISHA:
		return QObject::trUtf8("\351\233\267\346\235\200");
	case SHA:
		return QObject::trUtf8("\346\235\200");
	case SHAN:
		return QObject::trUtf8("\351\227\252");
	case TAO:
		return QObject::trUtf8("\346\241\203");
	case JIU:
		return QObject::trUtf8("\351\205\222");

	case CHITU:
		return QObject::trUtf8("\350\265\244\345\205\224");
	case DAWAN:
		return QObject::trUtf8("\345\244\247\345\256\233");
	case ZICI:
		return QObject::trUtf8("\347\264\253\351\250\202");

	case DILU:
		return QObject::trUtf8("\347\232\204\345\215\242");
	case JUEYING:
		return QObject::trUtf8("\347\273\235\345\275\261");
	case ZHUAHUANG:
		return QObject::trUtf8(
				"\347\210\252\351\273\204\351\243\236\347\224\265");
	case HUALIU:
		return QObject::trUtf8("\351\252\205\351\252\235");

		//Wuqi
	case BAIYIN:
		return QObject::trUtf8(
				"\347\231\275\351\223\266\347\213\256\345\255\220");
	case TENGJIA:
		return QObject::trUtf8("\350\227\244\347\224\262");
	case BAGUA:
		return QObject::trUtf8("\345\205\253\345\215\246\351\230\265");
	case RENWANG:
		return QObject::trUtf8("\344\273\201\347\216\213\347\233\276");
	case ZHUGE:
		return QObject::trUtf8(
				"\350\257\270\350\221\233\350\277\236\345\274\251");
	case QINGGANG:
		return QObject::trUtf8("\351\235\222\351\207\255\345\211\221");
	case HANBING:
		return QObject::trUtf8("\345\257\222\345\206\260\345\211\221");
	case CIXIONG:
		return QObject::trUtf8(
				"\351\233\214\351\233\204\345\217\214\350\202\241\345\211\221");
	case GUANSHI:
		return QObject::trUtf8("\350\264\257\347\237\263\346\226\247");
	case YINYUE:
		return QObject::trUtf8("\351\223\266\346\234\210\346\236\252");
	case QINGLONG:
		return QObject::trUtf8(
				"\351\235\222\351\276\231\345\201\203\346\234\210\345\210\200");
	case GUDING:
		return QObject::trUtf8("\345\217\244\351\224\255\345\210\200");
	case ZHANGBA:
		return QObject::trUtf8(
				"\344\270\210\345\205\253\350\233\207\347\237\233");
	case FANGTIAN:
		return QObject::trUtf8(
				"\346\226\271\345\244\251\347\224\273\346\210\237");
	case QILIN:
		return QObject::trUtf8("\351\272\222\351\272\237\345\274\223");
	case ZHUQUE:
		return QObject::trUtf8(
				"\346\234\261\351\233\200\347\276\275\346\211\207");

		//Yanshi
	case BINGLIANG:
		return QObject::trUtf8(
				"\345\205\265\347\262\256\345\257\270\346\226\255");
	case SISHU:
		return QObject::trUtf8(
				"\344\271\220\344\270\215\346\200\235\350\234\200");
	case SHANDIAN:
		return QObject::trUtf8("\351\227\252\347\224\265");

		//Feiyanshi
	case GUOCHAI:
		return QObject::trUtf8(
				"\350\277\207\346\262\263\346\213\206\346\241\245");
	case HUOGONG:
		return QObject::trUtf8("\347\201\253\346\224\273");
	case JIEDAO:
		return QObject::trUtf8(
				"\345\200\237\345\210\200\346\235\200\344\272\272");
	case JUEDOU:
		return QObject::trUtf8("\345\206\263\346\226\227");
	case NANMAN:
		return QObject::trUtf8(
				"\345\215\227\350\233\256\345\205\245\344\276\265");
	case SHUNQIAN:
		return QObject::trUtf8(
				"\351\241\272\346\211\213\347\211\265\347\276\212");
	case TAOYUAN:
		return QObject::trUtf8(
				"\346\241\203\345\233\255\347\273\223\344\271\211");
	case TIESUO:
		return QObject::trUtf8(
				"\351\223\201\351\224\201\350\277\236\347\216\257");
	case WANJIAN:
		return QObject::trUtf8(
				"\344\270\207\347\256\255\351\275\220\345\217\221");
	case WUXIE:
		return QObject::trUtf8(
				"\346\227\240\346\207\210\345\217\257\345\207\273");
	case WUZHONG:
		return QObject::trUtf8(
				"\346\227\240\344\270\255\347\224\237\346\234\211");
	case WUGU:
		return QObject::trUtf8(
				"\344\272\224\350\260\267\344\270\260\347\231\273");
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>cardDisplayName: Invalid Card Type");
		return QString();
	}
}

QString cardFullDisplayName(const sgs::DataType::Card * card, bool richText) {
	if (card)
		return cardDisplayName(card->type())
				+ cardColorDisplayName(card->color(), richText)
				+ cardNumberChar(card->number());
	else
		return "null pointer";
}

QString cardFullDisplayName(sgs::ConstData::CardType cardType,
		sgs::ConstData::CardColor cardColor, int number, bool richText) {
	return cardDisplayName(cardType) + cardColorDisplayName(cardColor, richText)
			+ cardNumberChar(number);
}

QString cardNumberChar(int number) {
	switch (number) {
	case 1:
		return QString("A");
	case 11:
		return QString("J");
	case 12:
		return QString("Q");
	case 13:
		return QString("K");
	default:
		return QString::number(number);
	}
}

QString zhuangbeiPixmapStr(sgs::ConstData::CardType cardType) {
	QString zhuangbeiPixmapString("images/zhuangbei/");
	return zhuangbeiPixmapString.append(cardFilenameStr(cardType)).append(
			".png");
}

QString smallZhuangbeiPixmapStr(sgs::ConstData::CardType cardType) {
	QString zhuangbeiPixmapString("images/small-zhuangbei/");
	return zhuangbeiPixmapString.append(cardFilenameStr(cardType)).append(
			".png");
}

QString cardFilenameStr(sgs::ConstData::CardType cardType) {
	using namespace sgs::ConstData;
	switch (cardType) {

	//Jiben
	case HUOSHA:
		return QString("fire_slash");
	case LEISHA:
		return QString("thunder_slash");
	case SHA:
		return QString("slash");
	case SHAN:
		return QString("jink");
	case TAO:
		return QString("peach");
	case JIU:
		return QString("analeptic");

	case CHITU:
		return QString("chitu");
	case DAWAN:
		return QString("dayuan");
	case ZICI:
		return QString("zixing");

	case DILU:
		return QString("dilu");
	case JUEYING:
		return QString("jueying");
	case ZHUAHUANG:
		return QString("zhuahuangfeidian");
	case HUALIU:
		return QString("hualiu");

		//Wuqi
	case BAIYIN:
		return QString("silver_lion");
	case TENGJIA:
		return QString("vine");
	case BAGUA:
		return QString("eight_diagram");
	case RENWANG:
		return QString("renwang_shield");
	case ZHUGE:
		return QString("crossbow");
	case QINGGANG:
		return QString("qinggang_sword");
	case HANBING:
		return QString("ice_sword");
	case CIXIONG:
		return QString("double_sword");
	case GUANSHI:
		return QString("axe");
	case YINYUE:
		return QString("moon_spear");
	case QINGLONG:
		return QString("blade");
	case GUDING:
		return QString("guding_blade");
	case ZHANGBA:
		return QString("spear");
	case FANGTIAN:
		return QString("halberd");
	case QILIN:
		return QString("kylin_bow");
	case ZHUQUE:
		return QString("fan");

		//Yanshi
	case BINGLIANG:
		return QString("supply_shortage");
	case SISHU:
		return QString("indulgence");
	case SHANDIAN:
		return QString("lightning");

		//Feiyanshi
	case GUOCHAI:
		return QString("dismantlement");
	case HUOGONG:
		return QString("fire_attack");
	case JIEDAO:
		return QString("collateral");
	case JUEDOU:
		return QString("duel");
	case NANMAN:
		return QString("savage_assault");
	case SHUNQIAN:
		return QString("snatch");
	case TAOYUAN:
		return QString("god_salvation");
	case TIESUO:
		return QString("iron_chain");
	case WANJIAN:
		return QString("archery_attack");
	case WUXIE:
		return QString("nullification");
	case WUZHONG:
		return QString("ex_nihilo");
	case WUGU:
		return QString("amazing_grace");
	default:
		return QString("card-back");
	}
}

QString wujiangSelfPixmapStr(sgs::ConstData::HeroType heroType) {
	QString wujiangSelfPixmapString("images/generals/big/");
	return wujiangSelfPixmapString.append(wujiangFilenameStr(heroType)).append(
			".png");
}

QString wujiangMiniPixmapStr(sgs::ConstData::HeroType heroType) {
	QString wujiangSelfPixmapString("images/generals/tiny/");
	return wujiangSelfPixmapString.append(wujiangFilenameStr(heroType)).append(
			".png");
}

QString wujiangOtherPixmapStr(sgs::ConstData::HeroType heroType) {
	QString wujiangOtherPixmapString("images/generals/small/");
	return wujiangOtherPixmapString.append(wujiangFilenameStr(heroType)).append(
			".png");
}

QString wujiangCardPixmapStr(sgs::ConstData::HeroType heroType) {
	QString wujiangCardPixmapString("images/generals/card/");
	return wujiangCardPixmapString.append(wujiangFilenameStr(heroType)).append(
			".jpg");
}

QString wujiangFilenameStr(sgs::ConstData::HeroType heroType) {
	using namespace sgs::ConstData;
	switch (heroType) {
	case CAOCAO:
		return QString("caocao");
	case SIMAYI:
		return QString("simayi");
	case XIAHOUDUN:
		return QString("xiahoudun");
	case ZHANGLIAO:
		return QString("zhangliao");
	case XUCHU:
		return QString("xuchu");
	case GUOJIA:
		return QString("guojia");
	case ZHENJI:
		return QString("zhenji");
	case XIAHOUYUAN:
		return QString("xiahouyuan");
	case ZHANGHE:
		return QString("zhanghe");
	case XUHUANG:
		return QString("xuhuang");
	case CAOREN:
		return QString("caoren");
	case DIAWEI:
		return QString("dianwei");
	case XUNYU:
		return QString("xunyu");
	case CAOPI:
		return QString("caopi");
	case DENGAI:
		return QString("dengai");
	case CAOZHI:
		return QString("caozhi");
	case XUSHU:
		return QString("xushu");
	case YUJIN:
		return QString("yujin");
	case ZHANGCHUNHUA:
		printDebug(
				"<font color=red><b>Warning: </b></font>wujiangFilenameStr: Using ZHANGCHUNHUA, whick should not be called");
		return QString();
	case YANGXIU:
		return QString("yangxiu");
	case LIUBEI:
		return QString("liubei");
	case GUANYU:
		return QString("guanyu");
	case ZHANGFEI:
		return QString("zhangfei");
	case LAOZHUGE:
		return QString("zhugeliang");
	case ZHAOYUN:
		return QString("zhaoyun");
	case MACHAO:
		return QString("machao");
	case HUANGYUEYING:
		return QString("huangyueying");
	case HUANGZHONG:
		return QString("huangzhong");
	case WEIYAN:
		return QString("weiyan");
	case PANGTONG:
		return QString("pangtong");
	case HUOZHUGE:
		return QString("shenzhugeliang");
	case JIANGWEI:
		return QString("jiangwei");
	case LIUSHAN:
		return QString("liushan");
	case MENGHUO:
		return QString("menghuo");
	case ZHURONG:
		return QString("zhurong");
	case FAZHENG:
		return QString("fazheng");
	case MASU:
		return QString("masu");
	case SUNQUAN:
		return QString("sunquan");
	case GANNING:
		return QString("ganning");
	case LVMENG:
		return QString("lumeng");
	case HUANGGAI:
		return QString("huanggai");
	case ZHOUYU:
		return QString("zhouyu");
	case DAQIAO:
		return QString("daqiao");
	case LUXUN:
		return QString("luxun");
	case SUNSHANGXIANG:
		return QString("sunshangxiang");
	case SUNJIAN:
		return QString("sunjian");
	case SUNCE:
		return QString("sunce");
	case XIAOQIAO:
		return QString("xiaoqiao");
	case TAISHICI:
		return QString("taishici");
	case ZHOUTAI:
		return QString("zhoutai");
	case LUSU:
		return QString("lusu");
	case ZHANGZHAO:
		return QString("erzhang");
	case LINGTONG:
		return QString("lingtong");
	case WUGUOTAI:
		return QString("wuguotai");
	case XUSHENG:
		return QString("xusheng");
	case HUATUO:
		return QString("huatuo");
	case LVBU:
		return QString("lubu");
	case DIAOCHAN:
		return QString("diaochan");
	case YUANSHAO:
		return QString("yuanshao");
	case YANLIANG:
		return QString("shuangxiong");
	case DONGZHUO:
		return QString("dongzhuo");
	case JIAXU:
		return QString("jiaxu");
	case PANGDE:
		return QString("pangde");
	case ZUOCI:
		return QString("zuoci");
	case ZHANGJIAO:
		return QString("zhangjiao");
	case YUJI:
		return QString("yuji");
	case CAIWENJI:
		return QString("caiwenji");
	case CHENGONG:
		return QString("chengong");
	case GAOSHUN:
		return QString("gaoshun");
	case GONGSUNZAN:
		return QString("gongsunzan");
	case YUANSHU:
		return QString("yuanshu");
	case SUJIANG:
		return QString("sujiang");
	case NVSUJIANG:
		return QString("sujiangf");
	default:
		return QString();
	}
}

QString wujiangDeathSoundStr(sgs::ConstData::HeroType heroType) {
	return QString("sound/death/").append(wujiangFilenameStr(heroType)).append(
			".mp3");
}

QString wujiangDisplayName(sgs::ConstData::HeroType heroType) {
	using namespace sgs::ConstData;
	switch (heroType) {
	case SUJIANG:
		return QObject::trUtf8("\347\264\240\345\260\206");
	case NVSUJIANG:
		return QObject::trUtf8("\345\245\263\347\264\240\345\260\206");
	case HUATUO:
		return QObject::trUtf8("\345\215\216\344\275\227");
	case LVBU:
		return QObject::trUtf8("\345\220\225\345\270\203");
	case DIAOCHAN:
		return QObject::trUtf8("\350\262\202\350\235\211");
	case CAOCAO:
		return QObject::trUtf8("\346\233\271\346\223\215");
	case XIAHOUDUN:
		return QObject::trUtf8("\345\244\217\344\276\257\346\203\207");
	case XUCHU:
		return QObject::trUtf8("\350\256\270\350\244\232");
	case ZHENJI:
		return QObject::trUtf8("\347\224\204\345\247\254");
	case ZHANGLIAO:
		return QObject::trUtf8("\345\274\240\350\276\275");
	case GUOJIA:
		return QObject::trUtf8("\351\203\255\345\230\211");
	case SIMAYI:
		return QObject::trUtf8("\345\217\270\351\251\254\346\207\277");
	case SUNQUAN:
		return QObject::trUtf8("\345\255\231\346\235\203");
	case ZHOUYU:
		return QObject::trUtf8("\345\221\250\347\221\234");
	case GANNING:
		return QObject::trUtf8("\347\224\230\345\256\201");
	case LVMENG:
		return QObject::trUtf8("\345\220\225\350\222\231");
	case HUANGGAI:
		return QObject::trUtf8("\351\273\204\347\233\226");
	case LUXUN:
		return QObject::trUtf8("\351\231\206\351\200\212");
	case DAQIAO:
		return QObject::trUtf8("\345\244\247\344\271\224");
	case SUNSHANGXIANG:
		return QObject::trUtf8("\345\255\231\345\260\232\351\246\231");
	case LIUBEI:
		return QObject::trUtf8("\345\210\230\345\244\207");
	case GUANYU:
		return QObject::trUtf8("\345\205\263\347\276\275");
	case ZHANGFEI:
		return QObject::trUtf8("\345\274\240\351\243\236");
	case LAOZHUGE:
		return QObject::trUtf8("\350\257\270\350\221\233\344\272\256");
	case ZHAOYUN:
		return QObject::trUtf8("\350\265\265\344\272\221");
	case MACHAO:
		return QObject::trUtf8("\351\251\254\350\266\205");
	case HUANGYUEYING:
		return QObject::trUtf8("\351\273\204\346\234\210\350\213\261");
	default:
		return QObject::trUtf8(
				"\351\235\236\346\240\207\345\207\206\345\214\205\346\255\246\345\260\206");
	}
}

QString skillSoundStr(sgs::ConstData::HeroSkill heroSkill) {
	using namespace sgs::ConstData;
	QString skillSoundString("sound/skill/");
	switch (heroSkill) {
	case JIJIU:
		skillSoundString.append("jijiu");
		break;
	case QINGNANG:
		skillSoundString.append("qingnang");
		break;
	case WUSHUANG:
		skillSoundString.append("wushuang");
		break;
	case LIJIAN:
		skillSoundString.append("lijian");
		break;
	case BIYUE:
		skillSoundString.append("biyue");
		break;
	case JIANXIONG:
		skillSoundString.append("jianxiong");
		break;
	case HUJIA:
		skillSoundString.append("hujia");
		break;
	case GANGLIE:
		skillSoundString.append("ganglie");
		break;
	case QINGGUO:
		skillSoundString.append("qingguo");
		break;
	case LUOSHEN:
		skillSoundString.append("luoshen");
		break;
	case TUXI:
		skillSoundString.append("tuxi");
		break;
	case LUOYI:
		skillSoundString.append("luoyi");
		break;
	case TIANDU:
		skillSoundString.append("tiandu");
		break;
	case YIJI:
		skillSoundString.append("yiji");
		break;
	case FANKUI:
		skillSoundString.append("fankui");
		break;
	case GUICAI:
		skillSoundString.append("guicai");
		break;
	case ZHIHENG:
		skillSoundString.append("zhiheng");
		break;
	case JIUYUAN:
		skillSoundString.append("jiuyuan");
		break;
	case YINGZI:
		skillSoundString.append("yingzi");
		break;
	case FANJIAN:
		skillSoundString.append("fanjian");
		break;
	case QIXI:
		skillSoundString.append("qixi");
		break;
	case KEJI:
		skillSoundString.append("keji");
		break;
	case KUROU:
		skillSoundString.append("kurou");
		break;
	case QIANXUN:
		skillSoundString.append("qianxun");
		break;
	case LIANYING:
		skillSoundString.append("lianying");
		break;
	case GUOSE:
		skillSoundString.append("guose");
		break;
	case LIULI:
		skillSoundString.append("liuli");
		break;
	case JIEYIN:
		skillSoundString.append("jieyin");
		break;
	case XIAOJI:
		skillSoundString.append("xiaoji");
		break;
	case RENDE:
		skillSoundString.append("rende");
		break;
	case JIJIANG:
		skillSoundString.append("jijiang");
		break;
	case WUSHENG:
		skillSoundString.append("wusheng");
		break;
	case PAOXIAO:
		skillSoundString.append("paoxiao");
		break;
	case GUANXING:
		skillSoundString.append("guanxing");
		break;
	case KONGCHENG:
		skillSoundString.append("kongcheng");
		break;
	case LONGDAN:
		skillSoundString.append("longdan");
		break;
	case MASHU:
		skillSoundString.append("mashu");
		break;
	case TIEQI:
		skillSoundString.append("tieqi");
		break;
	case JIZHI:
		skillSoundString.append("jizhi");
		break;
	case QICAI:
		skillSoundString.append("qicai");
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>skillSoundStr: Invalid Skill Type");
		break;
	}
	return skillSoundString.append((rand() % 2) ? '1' : '2').append(".mp3");
}

QString skillDisplayName(sgs::ConstData::HeroSkill heroSkill) {
	using namespace sgs::ConstData;
	switch (heroSkill) {
	case JIJIU:
		return QObject::trUtf8("\346\200\245\346\225\221");
	case QINGNANG:
		return QObject::trUtf8("\351\235\222\345\233\212");
	case WUSHUANG:
		return QObject::trUtf8("\346\227\240\345\217\214");
	case LIJIAN:
		return QObject::trUtf8("\347\246\273\351\227\264");
	case BIYUE:
		return QObject::trUtf8("\351\227\255\346\234\210");
	case JIANXIONG:
		return QObject::trUtf8("\345\245\270\351\233\204");
	case HUJIA:
		return QObject::trUtf8("\346\212\244\351\251\276");
	case GANGLIE:
		return QObject::trUtf8("\345\210\232\347\203\210");
	case QINGGUO:
		return QObject::trUtf8("\345\200\276\345\233\275");
	case LUOSHEN:
		return QObject::trUtf8("\346\264\233\347\245\236");
	case TUXI:
		return QObject::trUtf8("\347\252\201\350\242\255");
	case LUOYI:
		return QObject::trUtf8("\350\243\270\350\241\243");
	case TIANDU:
		return QObject::trUtf8("\345\244\251\345\246\222");
	case YIJI:
		return QObject::trUtf8("\351\201\227\350\256\241");
	case FANKUI:
		return QObject::trUtf8("\345\217\215\351\246\210");
	case GUICAI:
		return QObject::trUtf8("\351\254\274\346\211\215");
	case ZHIHENG:
		return QObject::trUtf8("\345\210\266\350\241\241");
	case JIUYUAN:
		return QObject::trUtf8("\346\225\221\346\217\264");
	case YINGZI:
		return QObject::trUtf8("\350\213\261\345\247\277");
	case FANJIAN:
		return QObject::trUtf8("\345\217\215\351\227\264");
	case QIXI:
		return QObject::trUtf8("\345\245\207\350\242\255");
	case KEJI:
		return QObject::trUtf8("\345\205\213\345\267\261");
	case KUROU:
		return QObject::trUtf8("\350\213\246\350\202\211");
	case QIANXUN:
		return QObject::trUtf8("\350\260\246\351\200\212");
	case LIANYING:
		return QObject::trUtf8("\350\277\236\350\220\245");
	case GUOSE:
		return QObject::trUtf8("\345\233\275\350\211\262");
	case LIULI:
		return QObject::trUtf8("\346\265\201\347\246\273");
	case JIEYIN:
		return QObject::trUtf8("\347\273\223\345\247\273");
	case XIAOJI:
		return QObject::trUtf8("\346\236\255\345\247\254");
	case RENDE:
		return QObject::trUtf8("\344\273\201\345\276\267");
	case JIJIANG:
		return QObject::trUtf8("\346\277\200\345\260\206");
	case WUSHENG:
		return QObject::trUtf8("\346\255\246\345\234\243");
	case PAOXIAO:
		return QObject::trUtf8("\345\222\206\345\223\256");
	case GUANXING:
		return QObject::trUtf8("\350\247\202\346\230\237");
	case KONGCHENG:
		return QObject::trUtf8("\347\251\272\345\237\216");
	case LONGDAN:
		return QObject::trUtf8("\351\276\231\350\203\206");
	case MASHU:
		return QObject::trUtf8("\351\251\254\346\234\257");
	case TIEQI:
		return QObject::trUtf8("\351\223\201\351\252\221");
	case JIZHI:
		return QObject::trUtf8("\351\233\206\346\231\272");
	case QICAI:
		return QObject::trUtf8("\345\245\207\346\211\215");
	default:
		return QObject::trUtf8(
				"\351\235\236\346\240\207\345\207\206\345\214\205\346\212\200\350\203\275");
	}
}

QString resultDisplayStr(bool win) {
	return win ?
			QObject::trUtf8("\350\203\234\345\210\251") :
			QObject::trUtf8("\345\244\261\350\264\245");
}
QString messageInterpret(const sgs::Derive::MCard * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Message: </b></font>MCard: ");
	sgs::DataType::Player * from = message->from(), *to = 0;
	const sgs::DataType::Card * card = message->card();

	if (card) {
		interpret.append(" card: " + cardFullDisplayName(card, false));
		interpret.append(" mask: " + cardDisplayName(card->mask()));
	} else {
		interpret.append(" card: none");
	}

	if (from) {
		interpret.append(" from: " + QString::number(from->seat()));
		interpret.append(wujiangDisplayName(message->from()->type()));
	} else {
		interpret.append(" from: nobody");
	}

	if (message->targets() == 0) {
		interpret.append(" to: nobody");
	} else {
		interpret.append(" to: ");
		for (int i = 0; i < message->targets(); ++i) {
			to = message->to(i);
			if (to) {
				interpret.append(QString::number(to->seat()));
				interpret.append(wujiangDisplayName(to->type()));
				interpret.append(' ');
			} else {
				interpret.append("invalid pointer");
			}
		}
	}

	std::pair<sgs::ConstData::PlayerRegionType, int> pos = message->pos();
	interpret.append(" pos: first = ");
	switch (pos.first) {
	case sgs::ConstData::prtNone:
		interpret.append("prtNone");
		break;
	case sgs::ConstData::PHAND:
		interpret.append("PHAND");
		break;
	case sgs::ConstData::PEQUIP:
		interpret.append("PEQUIP");
		break;
	case sgs::ConstData::PJUDGE:
		interpret.append("PJUDGE");
		break;
	default:
		interpret.append("Invalid");
		break;
	}
	interpret.append(" second = ");
	interpret.append(QString::number(pos.second));
	return interpret;
}

QString messageInterpret(const sgs::Derive::MZhangBa * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Message: </b></font>MZhangBa: ");
	sgs::DataType::Player * from = message->from(), *to = 0;
	const sgs::DataType::Card * card = message->card();

	if (card) {
		interpret.append(
				" card: " + cardDisplayName(card->type())
						+ cardColorDisplayName(card->color(), false)
						+ QString::number(card->number()));
	} else {
		interpret.append(" card: none");
	}

	if (from) {
		interpret.append(" from: " + QString::number(from->seat()));
		interpret.append(wujiangDisplayName(message->from()->type()));
	} else {
		interpret.append(" from: nobody");
	}

	if (message->targets() == 0) {
		interpret.append(" to: nobody");
	} else {
		interpret.append(" to: ");
		for (int i = 0; i < message->targets(); ++i) {
			to = message->to(i);
			if (to) {
				interpret.append(QString::number(to->seat()));
				interpret.append(wujiangDisplayName(to->type()));
				interpret.append(' ');
			} else {
				interpret.append("invalid pointer");
			}
		}
	}

	std::pair<sgs::ConstData::PlayerRegionType, int> pos = message->pos();
	interpret.append(" pos: first = ");
	switch (pos.first) {
	case sgs::ConstData::prtNone:
		interpret.append("prtNone");
		break;
	case sgs::ConstData::PHAND:
		interpret.append("PHAND");
		break;
	case sgs::ConstData::PEQUIP:
		interpret.append("PEQUIP");
		break;
	case sgs::ConstData::PJUDGE:
		interpret.append("PJUDGE");
		break;
	default:
		interpret.append("Invalid");
		break;
	}
	interpret.append(" second = ");
	interpret.append(QString::number(pos.second));
	interpret.append(" Cost 0:");
	interpret.append(cardFullDisplayName(message->cost(0).first, false));
	interpret.append(" Cost 1:");
	interpret.append(cardFullDisplayName(message->cost(1).first, false));
	return interpret;
}

QString messageInterpret(const sgs::Derive::MSkill * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Message: </b></font>MSkill: ");

	using namespace sgs::ConstData;
	using namespace sgs::Derive;
	using namespace sgs::DataType;
	sgs::DataType::Player * fromPlayer = message->from();
	interpret.append(" skill: " + skillDisplayName(message->skill()));
	interpret.append(" from: ");
	interpret.append(
			fromPlayer ?
					QString::number(fromPlayer->seat()) : QString("nobody"));

	if (dynamic_cast<const MQingNang *>(message)) {
		interpret.append(" real type: MQingNang");
		interpret.append(" card: ");
		interpret.append(
				cardFullDisplayName(
						static_cast<const MQingNang *>(message)->card(),
						false));
		interpret.append(" to: ");
		interpret.append(
				static_cast<const MQingNang *>(message)->to() ?
						QString::number(
								static_cast<const MQingNang *>(message)->to()->seat()) :
						"nobody");
		interpret.append(" pos: ");
		interpret.append(
				QString::number(
						static_cast<const MQingNang *>(message)->pos()));
	}

	if (dynamic_cast<const MJiJiu *>(message)) {
		interpret.append(" real type: MJiJiu");
		interpret.append(" card: ");
		interpret.append(
				cardFullDisplayName(
						static_cast<const MJiJiu *>(message)->card(), false));

		interpret.append(" pos.first: ");
		switch (static_cast<const MJiJiu *>(message)->pos().first) {
		case PHAND:
			interpret.append("PHAND");
			break;
		case PEQUIP:
			interpret.append("PEQUIP");
			break;
		case PJUDGE:
			interpret.append("PJUDGE");
			break;
		default:
			interpret.append("prtNone");
			break;
		}
		interpret.append(" pos.second: ");
		interpret.append(
				QString::number(
						static_cast<const MJiJiu *>(message)->pos().second));
	}

	if (dynamic_cast<const MGangLie *>(message)) {
		interpret.append(" real type: MGangLie");
		interpret.append(" to: ");
		interpret.append(
				static_cast<const MGangLie *>(message)->to() ?
						QString::number(
								static_cast<const MGangLie *>(message)->to()->seat()) :
						"nobody");
	}

	if (dynamic_cast<const MFanKui *>(message)) {
		interpret.append(" real type: MFanKui");
		interpret.append(" to: ");
		interpret.append(
				dynamic_cast<const MFanKui *>(message)->to() ?
						QString::number(
								static_cast<const MFanKui *>(message)->to()->seat()) :
						"nobody");
	}

	if (dynamic_cast<const MQiXi *>(message)) {
		interpret.append(" real type: MQiXi");
		interpret.append(" card: ");
		interpret.append(
				cardFullDisplayName(static_cast<const MQiXi *>(message)->card(),
						false));

		interpret.append(" to: ");
		interpret.append(
				QString::number(
						static_cast<const MQiXi *>(message)->to()->seat()));

		interpret.append(" pos.first: ");
		switch (static_cast<const MQiXi *>(message)->pos().first) {
		case PHAND:
			interpret.append("PHAND");
			break;
		case PEQUIP:
			interpret.append("PEQUIP");
			break;
		case PJUDGE:
			interpret.append("PJUDGE");
			break;
		default:
			interpret.append("prtNone");
			break;
		}
		interpret.append(" pos.second: ");
		interpret.append(
				QString::number(
						static_cast<const MQiXi *>(message)->pos().second));
	}

	if (dynamic_cast<const MLongDan *>(message)) {
		interpret.append(" real type: MLongDan");
		interpret.append(" card: ");
		interpret.append(
				cardFullDisplayName(
						static_cast<const MLongDan *>(message)->card(), false));
		interpret.append(" pos: ");
		interpret.append(
				QString::number(static_cast<const MLongDan *>(message)->pos()));
		interpret.append(" targets: ");
		interpret.append(
				QString::number(
						static_cast<const MLongDan *>(message)->targets()));
		interpret.append(" to: ");
		for (int i = 0; i < static_cast<const MLongDan *>(message)->targets();
				++i) {
			Player * player = static_cast<const MLongDan *>(message)->to(i);
			interpret.append(
					player ? QString::number(player->seat()) : "nobody");
			interpret.append(", ");
		}
	}

	if (dynamic_cast<const MQingGuo *>(message)) {
		interpret.append(" real type: MQingGuo");
		interpret.append(" card: ");
		interpret.append(
				cardFullDisplayName(
						static_cast<const MQingGuo *>(message)->card(), false));

		interpret.append(" pos: ");
		interpret.append(
				QString::number(static_cast<const MQingGuo *>(message)->pos()));
	}

	if (dynamic_cast<const MWuSheng *>(message)) {
		interpret.append(" real type: MWuSheng");
		interpret.append(" card: ");
		interpret.append(
				cardFullDisplayName(
						static_cast<const MWuSheng *>(message)->card(), false));

		interpret.append(" pos.first: ");
		switch (static_cast<const MWuSheng *>(message)->pos().first) {
		case PHAND:
			interpret.append("PHAND");
			break;
		case PEQUIP:
			interpret.append("PEQUIP");
			break;
		case PJUDGE:
			interpret.append("PJUDGE");
			break;
		default:
			interpret.append("prtNone");
			break;
		}

		interpret.append(" pos.second: ");
		interpret.append(
				QString::number(
						static_cast<const MWuSheng *>(message)->pos().second));
		interpret.append(" targets: ");
		interpret.append(
				QString::number(
						static_cast<const MWuSheng *>(message)->targets()));
		interpret.append(" to: ");
		for (int i = 0; i < static_cast<const MWuSheng *>(message)->targets();
				++i) {
			Player * player = static_cast<const MWuSheng *>(message)->to(i);
			interpret.append(
					player ? QString::number(player->seat()) : "nobody");
			interpret.append(", ");
		}
	}

	if (dynamic_cast<const MRenDe *>(message)) {
		interpret.append(" real type: MRenDe");
		interpret.append(" to: ");
		Player * player = static_cast<const MRenDe *>(message)->to();
		interpret.append(player ? QString::number(player->seat()) : "nobody");
		interpret.append(", ");
		interpret.append(" cards: ");
		interpret.append(
				QString::number(static_cast<const MRenDe *>(message)->cards()));
		interpret.append(" card and pos: ");
		for (int i = 0; i < static_cast<const MRenDe *>(message)->cards();
				++i) {
			interpret.append("(");
			interpret.append(
					cardFullDisplayName(
							static_cast<const MRenDe *>(message)->card(i),
							false));
			interpret.append(", ");
			interpret.append(
					QString::number(
							static_cast<const MRenDe *>(message)->pos(i)));
			interpret.append(") ");
		}
	}

	return interpret;
}

QString messageInterpret(const sgs::Derive::MHurt * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Message: </b></font>MHurt: ");
	sgs::DataType::Player * from = message->from(), *to = message->to();

	if (from) {
		interpret.append(" from: " + QString::number(from->seat()));
		interpret.append(wujiangDisplayName(message->from()->type()));
	} else {
		interpret.append(" from: god");
	}

	if (to) {
		interpret.append(" to: ");
		interpret.append(QString::number(to->seat()));
		interpret.append(wujiangDisplayName(to->type()));
	} else {
		interpret.append(" to: nobody");
	}

	interpret.append(" hurt: " + QString::number(message->hurt()));
	return interpret;
}

QString messageInterpret(const sgs::Derive::MTransCard * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Message: </b></font>MTransCard: ");
	sgs::DataType::Player * from = message->from(), *to = message->to();
	const sgs::DataType::Card * card = 0;
	interpret.append(" card: ");
	for (int i = 0; i < message->cards(); ++i) {
		card = message->trans(i);
		interpret.append(cardFullDisplayName(card, false));
		interpret.append(' ');
	}

	if (from) {
		interpret.append(" from: " + QString::number(from->seat()));
		interpret.append(wujiangDisplayName(message->from()->type()));
	} else {
		interpret.append(" from: nobody(maybe card deck)");
	}

	if (to) {
		interpret.append(" to: ");
		interpret.append(QString::number(to->seat()));
		interpret.append(wujiangDisplayName(to->type()));
	} else {
		interpret.append(" to: nobody(maybe used card deck)");
	}

	interpret.append(" frompos: ");
	switch (message->frompos()) {
	case sgs::ConstData::prtNone:
		interpret.append("prtNone");
		break;
	case sgs::ConstData::PHAND:
		interpret.append("PHAND");
		break;
	case sgs::ConstData::PEQUIP:
		interpret.append("PEQUIP");
		break;
	case sgs::ConstData::PJUDGE:
		interpret.append("PJUDGE");
		break;
	default:
		interpret.append("Invalid");
		break;
	}

	interpret.append(" open = ");
	interpret.append(message->open() ? "true" : "false");
	interpret.append(" tojudge = ");
	interpret.append(message->tojudge() ? "true" : "false");
	return interpret;
}

QString messageInterpret(const sgs::Derive::MSwitchPhase * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Message: </b></font>MSwitchPhase: ");
	sgs::DataType::Player * from = message->from();

	if (from) {
		interpret.append(" from: " + QString::number(from->seat()));
		interpret.append(wujiangDisplayName(message->from()->type()));
	} else {
		interpret.append(" from: nobody");
	}

	using namespace sgs::ConstData;
	interpret.append(" before: ");
	switch (message->before()) {
	case START:
		interpret.append("START");
		break;
	case JUDGEMENT:
		interpret.append("JUDGEMENT");
		break;
	case GETCARD:
		interpret.append("GETCARD");
		break;
	case MAIN:
		interpret.append("MAIN");
		break;
	case ABANDONCARD:
		interpret.append("ABANDONCARD");
		break;
	case END:
		interpret.append("END");
		break;
	case OTHER:
		interpret.append("OTHER");
		break;
	default:
		interpret.append("invalid phase");
		break;
	}
	interpret.append(" after: ");
	switch (message->after()) {
	case START:
		interpret.append("START");
		break;
	case JUDGEMENT:
		interpret.append("JUDGEMENT");
		break;
	case GETCARD:
		interpret.append("GETCARD");
		break;
	case MAIN:
		interpret.append("MAIN");
		break;
	case ABANDONCARD:
		interpret.append("ABANDONCARD");
		break;
	case END:
		interpret.append("END");
		break;
	case OTHER:
		interpret.append("OTHER");
		break;
	default:
		interpret.append("invalid phase");
		break;
	}
	return interpret;
}
QString messageInterpret(const sgs::Derive::MDying * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Message: </b></font>MDying: ");
	sgs::DataType::Player * from = message->from();
	if (from) {
		interpret.append(" from: " + QString::number(from->seat()));
		interpret.append(wujiangDisplayName(message->from()->type()));
	} else {
		interpret.append(" from: nobody");
	}
	interpret.append(" neg: " + QString::number(message->neg()));
	return interpret;
}

QString messageInterpret(const sgs::Derive::MKill * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Message: </b></font>MKill: ");
	sgs::DataType::Player * from = message->from(), *to = message->to();

	if (from) {
		interpret.append(" from: " + QString::number(from->seat()));
		interpret.append(wujiangDisplayName(message->from()->type()));
	} else {
		interpret.append(" from: god");
	}

	if (to) {
		interpret.append(" to: ");
		interpret.append(QString::number(to->seat()));
		interpret.append(wujiangDisplayName(to->type()));
	} else {
		interpret.append(" to: nobody");
	}
	return interpret;
}
QString messageInterpret(const sgs::Derive::MJudge * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Message: </b></font>MJudge: ");
	sgs::DataType::Player * from = message->from();
	const sgs::DataType::Card * card = message->card(), *result =
			message->result();

	interpret.append(
			" cardJudge: " + message->cardJudge() ?
					QString("true") : QString("false"));

	if (card) {
		interpret.append(
				" card: " + cardDisplayName(card->type())
						+ cardColorDisplayName(card->color(), false)
						+ QString::number(card->number()));
	} else {
		interpret.append(" card: none");
	}

	interpret.append(" skill: " + skillDisplayName(message->skill()));

	if (result) {
		interpret.append(
				" result (the judge card): " + cardDisplayName(result->type())
						+ cardColorDisplayName(result->color(), false)
						+ QString::number(result->number()));
	} else {
		interpret.append(" result: none");
	}

	if (from) {
		interpret.append(" from: " + QString::number(from->seat()));
		interpret.append(wujiangDisplayName(message->from()->type()));
	} else {
		interpret.append(" from: nobody");
	}

	interpret.append(" effect = ");
	interpret.append(message->effect() ? QString("true") : QString("false"));

	return interpret;
}

QString allMessageInterpret(const sgs::DataType::Message * message) {
	if (!message || !GUIStaticData::isDebugLogOn())
		return "<font color=red><b>Message: </b></font>cannot interpret due to null pointer, or debug log is off";

	using namespace sgs::ConstData;
	using namespace sgs::Derive;
	switch (message->type()) {
	case sgs::ConstData::HITCARD:
		if (dynamic_cast<const MZhangBa *>(message)) {
			return messageInterpret(static_cast<const MZhangBa *>(message));
		} else {
			return messageInterpret(static_cast<const MCard *>(message));
		}
	case sgs::ConstData::USECARD: {
		if (dynamic_cast<const MZhangBa *>(message)) {
			return messageInterpret(static_cast<const MZhangBa *>(message));
		} else {
			return messageInterpret(static_cast<const MCard *>(message));
		}
	}
	case sgs::ConstData::USESKILL:
		return messageInterpret(static_cast<const MSkill *>(message));
	case sgs::ConstData::HURT:
		return messageInterpret(static_cast<const MHurt *>(message));
	case sgs::ConstData::TRANSCARD:
		return messageInterpret(static_cast<const MTransCard *>(message));
	case sgs::ConstData::SWITCHPHASE:
		return messageInterpret(static_cast<const MSwitchPhase *>(message));
	case sgs::ConstData::DYING:
		return messageInterpret(static_cast<const MDying *>(message));
	case sgs::ConstData::KILL:
		return messageInterpret(static_cast<const MKill *>(message));
	case sgs::ConstData::JUDGE:
		return messageInterpret(static_cast<const MJudge *>(message));
	default:
		return QString("Invalid Message Type");
	}
}

QString discardInterpret(const std::vector<int>& discardVec,
		sgs::DataType::Player * from) {
	if (!from)
		return "<font color=red><b>Discard: </b></font>cannot interpret due to null pointer, or debug log is off";

	QString interpret("<font color=red><b>Discard: </b></font>card: ");
	const sgs::DataType::Card * card = 0;
	for (std::vector<int>::const_iterator iter = discardVec.begin();
			iter != discardVec.end(); ++iter) {
		card = from->hand(*iter);
		if (card) {
			interpret.append(
					cardDisplayName(card->type())
							+ cardColorDisplayName(card->color(), false)
							+ QString::number(card->number()));
			interpret.append(' ');
		} else {
			interpret.append("non-exist card ");
		}
	}
	return interpret;
}

QString selectInterpret(
		const std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> >& selectVec) {
	QString interpret("<font color=red><b>Select: </b></font>card pair: ");
	for (std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> >::const_iterator citer =
			selectVec.begin(); citer != selectVec.end(); ++citer) {
		switch ((*citer).first) {
		case sgs::ConstData::PHAND:
			interpret.append("PHAND(");
			break;
		case sgs::ConstData::PJUDGE:
			interpret.append("PJUDGE(");
			break;
		case sgs::ConstData::PEQUIP:
			interpret.append("PEQUIP(");
			break;
		default:
			interpret.append(
					"<font color=red><b>Warning: </b></font>Invalid PlayerRegionType(");
			break;
		}
		interpret.append(QString::number((*citer).second));
		interpret.append(") ");
	}
	return interpret;
}

QString setColored(const QString &originalString, bool bold) {
	return bold ?
			("<font color=\"white\"><b>" + originalString + "</b></font>") :
			("<font color=\"white\">" + originalString + "</font>");
}

QString splashStr() {
	switch (rand() % 3) {
	case 1:
		return QString("images/splash/splash1.png");
	case 2:
		return QString("images/splash/splash2.png");
	default:
		return QString("images/splash/splash3.png");
	}
}

EquipType getEquipType(sgs::ConstData::CardType cardType) {
	using namespace sgs::ConstData;
	switch (cardType) {
	case ZHUGE:
	case QINGGANG:
	case HANBING:
	case CIXIONG:
	case GUANSHI:
	case YINYUE:
	case QINGLONG:
	case GUDING:
	case ZHANGBA:
	case FANGTIAN:
	case QILIN:
	case ZHUQUE:
		return Wuqi;
	case BAIYIN:
	case TENGJIA:
	case BAGUA:
	case RENWANG:
		return Fangju;
	case CHITU:
	case DAWAN:
	case ZICI:
		return Jianma;

	case DILU:
	case JUEYING:
	case ZHUAHUANG:
	case HUALIU:
		return Jiama;
	default:
		return NotEquip;
	}
}

} /* namespace sgsui */
