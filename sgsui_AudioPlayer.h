/*
 * sgsui_AudioPlayer.h
 *
 *  Created on: Apr 14, 2012
 *      Author: latios
 */

#ifndef SGSUI_AUDIOPLAYER_H_
#define SGSUI_AUDIOPLAYER_H_

#include "sgsdata_enum.h"
#include <QObject>
#include <vector>
#include <list>

namespace Phonon {
class MediaObject;
}

namespace sgsui {

class MainWindow;

enum SoundType {
	DamageEffectSound, LightningEffectSound, YourTurn, UseEquip, PlayersCreated
};

class AudioPlayer: public QObject {
Q_OBJECT
public:
	explicit AudioPlayer(MainWindow *parent = 0);
	~AudioPlayer();
	void terminateThisPlayer();
	static void terminateAllPlayers();

public slots:
	void startBGM();
	void pauseBGM();
	void playEndingMusic(bool isWinner);
	void playSound(SoundType soundType, bool sex = true);
	void playSound(sgs::ConstData::CardType cardType, bool sex = true);
	void playSound(sgs::ConstData::HeroSkill Skill, int playerIndex);
	void playSound(sgs::ConstData::HeroType deadHeroType);

private:
	void playSoundStr(const QString &file);

	Phonon::MediaObject * backgroundMusic;
	const MainWindow * mainWindow;
	std::vector<Phonon::MediaObject *> soundVec;

	static std::list<AudioPlayer *> audioPlayerList;

	sgs::ConstData::HeroSkill lastSkill;
	int lastPlayerIndex;
	bool aboutToTerminate;
};

} /* namespace sgsui */
#endif /* SGSUI_AUDIOPLAYER_H_ */
