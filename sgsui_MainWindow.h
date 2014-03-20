/*
 * sgsui_MainWindow.h
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#ifndef SGSUI_MAINWINDOW_H_
#define SGSUI_MAINWINDOW_H_

#include "ui_MainWindow.h"
#include "sgs_Interface.h"
#include "sgsui_AbstractCardContainer.h"
#include "sgsui_AbstractEquipProcessor.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_BlockLoop.h"
#include "sgsdata_namespace.h"
#include <QEventLoop>
#include <list>

class QPropertyAnimation;
class QParallelAnimationGroup;
class QPauseAnimation;
class QCloseEvent;

namespace sgsai {
class AIBasic;
}

namespace sgsui {

class MessageBox;
class BlockingFrame;
class DialogBox;
class CardContainer;
class WujiangChooseBox;
class GuanxingBox;
class WugufengdengBox;
class FanjianBox;
class PixmapAnimationWidget;
class LineAnimationWidget;
class AboutFrame;
class HelpBox;
class CardFrame;
class ZhuangbeiArea;
class WujiangArea;
class PlayerArea;
class AudioPlayer;
class Shoupai;
class BlockTimer;
class AbstractPlayerArea;
class GameOverBox;
class PosAnimation;
class ZhuangbeiLabel;
class CardViewer;

enum ResponseType {
	NotResponding,
	UseCard,
	DiscardCard,
	ShanOrNot,
	TaoOrNot,
	ShaOrNot,
	WuxieOrNot,
	GetTuxi,
	GetYiji,
	GetLiuli
};

class MainWindow: public QMainWindow,
		protected Ui::MainWindow,
		protected AbstractCardContainer,
		public AbstractEquipProcessor,
		public sgs::Interface {
Q_OBJECT
public:
	MainWindow();
	~MainWindow();
	void createPlayers();

	virtual std::vector<int> discardCard(unsigned int cardNumToDiscard);
	virtual sgs::DataType::Message * useCardResponse();
	virtual sgs::DataType::Message * taoOrNot(sgs::DataType::Player * from,
			int neededTaoNumber);
	virtual sgs::DataType::Message * shanOrNot(sgs::DataType::Player * from,
			const sgs::DataType::Card * card);
	virtual sgs::DataType::Message * shanOrNot(sgs::DataType::Player * from,
			sgs::ConstData::HeroSkill skillType);
	virtual sgs::DataType::Message * shaOrNot(sgs::DataType::Player * from,
			const sgs::DataType::Card * card);
	virtual sgs::DataType::Message * shaOrNot(sgs::DataType::Player * from,
			sgs::ConstData::HeroSkill skillType);
	virtual sgs::DataType::Message * wuxieOrNot(
			sgs::DataType::Message * originMsg, int count);
	virtual bool useEquipOrNot(sgs::ConstData::CardType equipCardType,
			sgs::DataType::Player *targetPlayer);
	virtual bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
	virtual bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Message * message);
	virtual std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > chooseCardResponse(
			sgs::DataType::Player *targetPlayer, bool isHandSelectable,
			bool isEquipSelectable, bool isJudgeSelectable, int num,
			sgs::ConstData::CardType reason);
	virtual std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > chooseCardResponse(
			sgs::DataType::Player *targetPlayer, bool isHandSelectable,
			bool isEquipSelectable, bool isJudgeSelectable, int num,
			sgs::ConstData::HeroSkill reason);
	virtual bool yesOrNot(sgs::ConstData::CardType reason);
	virtual bool yesOrNot(sgs::ConstData::HeroSkill reason);
	virtual int chooseWugu(
			const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wuguCards);
	virtual void chooseGuanxing(std::vector<const sgs::DataType::Card *>& top,
			std::vector<const sgs::DataType::Card *>& buttom);
	virtual sgs::DataType::Message * getTuxi();
	virtual sgs::DataType::Message * getYiji(const sgs::DataType::Card * card1,
			const sgs::DataType::Card * card2);
	virtual sgs::DataType::Message * getLiuli(sgs::DataType::Player * attacker);
	virtual std::pair<sgs::ConstData::CardColor, int> respondFanjian(
			sgs::DataType::Player * zhouyu);

	void MCardReceived(const sgs::Derive::MCard * message);
	void MSkillReceived(const sgs::Derive::MSkill * message);
	void MHurtReceived(const sgs::Derive::MHurt * message);
	void MTransCardReceived(const sgs::Derive::MTransCard * message);
	void MSwitchPhaseReceived(const sgs::Derive::MSwitchPhase * message);
	void MDyingReceived(const sgs::Derive::MDying * message);
	void MKillReceived(const sgs::Derive::MKill * message);
	void MJudgeReceived(const sgs::Derive::MJudge * message);

	bool isSingleStep() const;
	void pause();
	bool isBlocked() const;
	bool isResponding() const;
	bool isRespondingNoAnimation() const;
	void setResponding(bool responding, BlockingFrame *blockWidget);
	bool isSoundOn() const;

	sgs::ConstData::HeroType chooseWujiang(sgs::ConstData::HeroType zhugong,
			sgs::ConstData::PlayerRole shenfen,
			sgs::ConstData::HeroType avaliable1,
			sgs::ConstData::HeroType avaliable2,
			sgs::ConstData::HeroType avaliable3);
	sgs::ConstData::HeroType chooseZhugongWujiang(
			sgs::ConstData::HeroType avaliable1,
			sgs::ConstData::HeroType avaliable2,
			sgs::ConstData::HeroType avaliable3,
			sgs::ConstData::HeroType avaliable4,
			sgs::ConstData::HeroType avaliable5);

	// TODO make these methods private
	void runGuanxing(); // TODO complete it;
	void runWugufengdeng(); // TODO complete it;
	sgs::ConstData::CardColor runFanjian();
	int getDialogResponse(const QString &message);

	void showTipMessage(const QString &tip, bool richText = false,
			int duration = GUIStaticData::showTipDuration);
	void showPauseMessage(const QString &pause, bool richText = false);
	void showStatusBarMessage(const QString &tip, bool richText = false,
			int duration = GUIStaticData::showTipDuration);

	void runPixmapAnimation(int targetPlayerIndex,
			PixmapAnimationType animationType);
	void runLineAnimation(int sourcePlayerIndex, int targetPlayerIndex1,
			int targetPlayerIndex2 = 0, int targetPlayerIndex3 = 0,
			int targetPlayerIndex4 = 0, int targetPlayerIndex5 = 0,
			int targetPlayerIndex6 = 0, int targetPlayerIndex7 = 0);
	void gameOver(char result);
	AudioPlayer * getAudioPlayer() const;
	AudioPlayer * getSkillPlayer() const;
	static MainWindow * mainWindowPtr();
	static void appendHistory(const QString &textInput);
	static void appendDebug(const QString &textInput);
	static QPoint realPos(QWidget * widgetToCal);
	void showWugu(
			const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wuguCards);

signals:
	void blocked();
	void unblocked();

public slots:
	void playerClicked(AbstractPlayerArea * clickedPlayerArea);
	void sleepSomeTime(int sleepTime);

private slots:
	virtual void cardClicked(CardButton * clickedCard);
	virtual void zhuangbeiClicked(ZhuangbeiPic *clickedEquip);
	int getIndex(Shoupai * clickedCard) const;
	Shoupai * goToCard(const sgs::DataType::Card * card) const;
	void exec();
	void pauseClicked();
	void skillClicked(sgs::ConstData::HeroSkill, int skillIndex);

	void unblock();
	void okClicked();
	void cancelClicked();
	void resetSkillSelect();
	void abandonClicked();
	void changeMusicState(bool musicOn);
	void changeScreenState(bool fullscreen);
	void addUsedCard(CardFrame* usedCard);
	void addShoupai(const sgs::DataType::Card * card);
	void removeShoupai(Shoupai *shoupaiToRemove);
	void trustClicked(bool trust);

	// these functions are for debug use
	void refreshPlayer();
	void refreshData();
	void refreshHistory();
	void exchangeCard();
	void setHPDebug();
	void setAutoRefresh(bool);
	void refreshFrequencyChanged(int);
	void debug1();
	void debug2();
	void debug3();
	void debug4();

private:
	CardButton* goToShoupai(unsigned shoupaiIndex);
	AbstractPlayerArea* goToAbstractPlayerArea(int pressedKey);
	void checkButtons();
	void newSelectedCard(Shoupai * selectedCard);
	void newUnselectedCard(Shoupai * unselectedCard);
	void newSelectedPlayer(AbstractPlayerArea * playerArea);
	void newUnselectedPlayer(AbstractPlayerArea * playerArea);
	void collectDiscardedShoupai();
	void clearAbandonData();
	void cardNormalize();
	void skillNormalize();
	void skillCardNormalize();
	void skillPlayerChooseNormalize();
	void enableAllShoupai();
	void disableAllShoupai();
	void disableAllPlayers();
	void disableAllZhuangbei();
	void clearCardPlayerEquipSelect();
	void unselectAllShoupai();
	void unselectAllPlayers();
	void unselectAllZhuangbei();
	void playerChooseNormalize();
	void enableShaTarget();
	void enableJiedaoVictim(int attackerIndex); // this function does not disable players that is already selected
	void enableShunqianTarget();
	void enablePlayer(int targetPlayerIndex);
	void enablePlayerWithWeapon(bool enableMyself = false);
	void enableAllPlayers(bool hasCard = false, bool enableMyself = false);
	void enableJuedouTarget();
	void enableSishuTarget();
	void enableQingnangTarget();
	void enableMalePlayers();
	void enableTuxiTarget();
	void enableJieyinTarget();
	void enableLiuliTarget();
	void setDead(int targetPlayerIndex);
	void setRespodingPhase(int targetPlayerIndex, bool responding);
	void setDying(int targetPlayerIndex, bool dying);
	int getHP(int targetPlayerIndex) const;
	void setHP(int targetPlayerIndex, int HP);
	void setHPDamage(int targetPlayerIndex, int HPDamage);
	void closeEvent(QCloseEvent *event);
	void keyPressEvent(QKeyEvent *event);

	sgs::Derive::MCard * collectZhuangbei();
	sgs::Derive::MSkill * collectSkill();
	void endResponse();
	void terminatePlayerSelect();
	void terminateCardSelect();
	void terminateZhuangbeiSelect();
	void terminateSkillSelect();

	static MainWindow* mainWindowPointer;
	friend void printDebug(const QString& textInput);
	friend void printHistory(const QString& textInput);
	friend void printAI(const QString& textInput);

	void setOptions(int options);
	//used by the constructor
	void initiateWindowWidgets();
	void initiateStyleSheet();
	void initiateAnimation();
	void initiateMusic();
	void initiateDebug();

	QPoint cardDeckPoint() const;
	QPoint lastShoupaiPoint() const;
	QPoint shoupaiEndPoint() const;
	QPoint usedCardPoint() const;
	QPoint zhuangbeiPoint() const;
	QPoint shoupaiCenterPoint() const;
	QPoint wujiangCenterPoint() const;

	// get element in otherPlayerVector only by this function
	PlayerArea* otherPlayerAreaAtIndex(int index) const;
	QPoint cardPointAtIndex(int index) const;
	QPoint animationPointAtIndex(int index) const;
	QPoint judgePointAtIndex(int index) const;
	QPoint zhuangbeiPointAtIndex(int index) const;
	sgs::ConstData::HeroSex getSexAtIndex(int index) const;
	sgs::ConstData::HeroType getHeroTypeAtIndex(int index) const;
	sgs::ConstData::PlayerRole getRoleAtIndex(int index) const;
	bool getIsDeadAtIndex(int index) const;

	const CardFrame * getWuqiAtIndex(int index) const;
	const CardFrame * getFangjuAtIndex(int index) const;
	const CardFrame * getJianmaAtIndex(int index) const;
	const CardFrame * getJiamaAtIndex(int index) const;
	void addWuqiAtIndex(int index, CardFrame * newWuqiCard);
	void addFangjuAtIndex(int index, CardFrame * newFangjuCard);
	void addJianmaAtIndex(int index, CardFrame * newJianmaCard);
	void addJiamaAtIndex(int index, CardFrame * newJiamaCard);
	void removeWuqiAtIndex(int index);
	void removeFangjuAtIndex(int index);
	void removeJianmaAtIndex(int index);
	void removeJiamaAtIndex(int index);
	void addJudgeAtIndex(int index, sgs::ConstData::CardType judgeCard);
	void removeJudgeAtIndex(int index, sgs::ConstData::CardType judgeCard);

	void showSkillAtIndex(int index, sgs::ConstData::HeroSkill skill);
	void showZhuangbeiAtIndex(int index, sgs::ConstData::CardType equipCard);

	MessageBox * tipBox;
	MessageBox * pauseBox;
	DialogBox * dialogBox;
	CardContainer * cardContainer;
	WujiangChooseBox * wujiangChooseBox;
	GuanxingBox * guanxingBox;
	AboutFrame * aboutFrame;
	HelpBox * helpBox;
	WugufengdengBox * wugufengdengBox;
	FanjianBox * fanjianBox;
	GameOverBox * gameOverBox;
	CardViewer * cardViewer;
	ZhuangbeiLabel * zhuangbeiLabel;

	std::list<Shoupai *> shoupaiList;

	PosAnimation * cardAnimation;
	PixmapAnimationWidget * pixmapAnimationWidget;
	LineAnimationWidget * lineAnimationWidget;
	QPropertyAnimation * damageMovingAnimation;

	BlockTimer * blockTimer;

	ZhuangbeiArea * zhuangbeiA;
	WujiangArea * wujiangA;
	AudioPlayer * audioPlayer;
	AudioPlayer * skillPlayer;

	int playerCount;
	int playerIndex;
	std::vector<PlayerArea *> otherPlayerAreaVector;

	BlockLoop blockLoop;
	bool GUIresponding;
	std::list<BlockingFrame *> blockingFrameList;
	QPropertyAnimation * blockingFrameMovingAnimation;

	int currentPlayerSeat;

	ResponseType responseType;
	bool skillVerShaOrNot;
	bool isGoingToAbandon;
	bool cancelResponse;

	// for abandonCard
	std::vector<int> discardIndexList;
	std::list<Shoupai *> selectedAbandonList;
	unsigned shoupaiNumToDiscard;

	std::list<Shoupai *> selectedShoupaiList;
	unsigned maxShoupaiSelect;
	unsigned minShoupaiSelect;
	std::list<AbstractPlayerArea *> selectedPlayerAreaList;
	unsigned maxPlayerSelect;
	unsigned minPlayerSelect;

	ZhuangbeiPic * selectedZhuangbei;
	sgs::ConstData::HeroSkill selectedSkill;
	std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > selectedSkillCardVec;
	std::list<std::pair<int, AbstractPlayerArea*> > tuxiList;
	sgs::DataType::Player * liuliAttacker;

	Interface * innerAI;

	QTimer * debugTimer;

	const static QSize minSize;
	friend class GameOverBox;
};

} /* namespace sgsui */
#endif /* SGSUI_MAINWINDOW_H_ */
