/*
 * sgsui_AudioPlayer.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: latios
 */

#include "sgsui_AudioPlayer.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_MainWindow.h"
#include "sgsui_nameConvert.h"
#include "sgsui_output.h"
#include <phonon/MediaObject>
#include <phonon/AudioOutput>
#include <phonon/BackendCapabilities>

namespace sgsui {

std::list<AudioPlayer *> AudioPlayer::audioPlayerList;

AudioPlayer::AudioPlayer(MainWindow * parent) :
		QObject(parent), mainWindow(parent), aboutToTerminate(false) {
	backgroundMusic = Phonon::createPlayer(Phonon::MusicCategory,
			GUIStaticData::backgroundMusicLocation);

	backgroundMusic->setCurrentSource(GUIStaticData::backgroundMusicLocation);
	for (int i = 0; i < 100; ++i) {
		// make enough enqueue to ensure that background music never ends
		backgroundMusic->enqueue(GUIStaticData::backgroundMusicLocation);
	}

	audioPlayerList.push_back(this);
}

AudioPlayer::~AudioPlayer() {
	printDebug("AudioPlayer::~AudioPlayer: start");
	delete backgroundMusic;
	printDebug("AudioPlayer::~AudioPlayer: backgroundMusic has been deleted");
	for (std::vector<Phonon::MediaObject *>::iterator iter = soundVec.begin();
			iter != soundVec.end(); ++iter) {
		delete *iter;
	}
	printDebug(
			"AudioPlayer::~AudioPlayer: all sound objects have been deleted");
	audioPlayerList.remove(this);
	printDebug("AudioPlayer::~AudioPlayer: over");
}

void AudioPlayer::terminateThisPlayer() {
	aboutToTerminate = true;
	backgroundMusic->stop();
	printDebug("AudioPlayer::terminateThisPlayer: backgroundMusic is stopped");
	for (std::vector<Phonon::MediaObject *>::iterator iter = soundVec.begin();
			iter != soundVec.end(); ++iter) {
		(*iter)->stop();
	}
	printDebug(
			"AudioPlayer::terminateThisPlayer: all sound objects are stopped");
}

void AudioPlayer::terminateAllPlayers() {
	for (std::list<AudioPlayer *>::iterator iter = audioPlayerList.begin();
			iter != audioPlayerList.end(); ++iter) {
		(*iter)->terminateThisPlayer();
	}
}

void AudioPlayer::startBGM() {
	backgroundMusic->play();
}

void AudioPlayer::pauseBGM() {
	backgroundMusic->pause();
}

void AudioPlayer::playEndingMusic(bool isWinner) {
	if (aboutToTerminate)
		return;

	backgroundMusic->pause();
	backgroundMusic->clear();
	backgroundMusic->setCurrentSource(
			isWinner ? QString("music/win.mp3") : QString("music/lose.mp3"));
	backgroundMusic->play();
}

void AudioPlayer::playSound(SoundType soundType, bool sex) {
	if (aboutToTerminate)
		return;

	if (mainWindow->isSoundOn()) {
		QString fileLocation;
		switch (soundType) {
		case DamageEffectSound:
			fileLocation =
					sex ? "sound/card/male/damage.mp3" : "sound/card/female/damage.mp3";
			playSoundStr(fileLocation);
			break;
		case LightningEffectSound:
			fileLocation = "sound/system/lightning.mp3";
			playSoundStr(fileLocation);
			break;
		case YourTurn:
			fileLocation = "sound/system/yourturn.mp3";
			playSoundStr(fileLocation);
			break;
		case UseEquip:
			fileLocation = "sound/system/use-equip.mp3";
			playSoundStr(fileLocation);
			break;
		case PlayersCreated:
			fileLocation = "sound/system/players-created.mp3";
			playSoundStr(fileLocation);
			break;
		default:
			break;
		}
	}
}

void AudioPlayer::playSound(sgs::ConstData::CardType cardType, bool sex) {
	if (aboutToTerminate)
		return;

	if (mainWindow->isSoundOn()) {
		playSoundStr(cardSoundStr(cardType, sex));
	}
}

void AudioPlayer::playSound(sgs::ConstData::HeroSkill skill, int playerIndex) {
	if (aboutToTerminate)
		return;

	if (lastSkill == skill && lastPlayerIndex == playerIndex
			&& lastSkill == sgs::ConstData::LUOSHEN) {
		return;
	}
	lastSkill = skill;
	lastPlayerIndex = playerIndex;
	if (mainWindow->isSoundOn()) {
		playSoundStr(skillSoundStr(skill));
	}
}

void AudioPlayer::playSound(sgs::ConstData::HeroType deadHeroType) {
	if (aboutToTerminate)
		return;

	if (mainWindow->isSoundOn()) {
		playSoundStr(wujiangDeathSoundStr(deadHeroType));
	}
}

void AudioPlayer::playSoundStr(const QString &file) {
	if (aboutToTerminate)
		return;

	for (std::vector<Phonon::MediaObject *>::iterator iter = soundVec.begin();
			iter != soundVec.end(); ++iter) {
		Phonon::MediaObject * prevSoundEffect = (*iter);
		switch (prevSoundEffect->state()) {
		case Phonon::StoppedState:
		case Phonon::PausedState:
			prevSoundEffect->clear();
			prevSoundEffect->setCurrentSource(file);
			prevSoundEffect->play();
			return;
		default:
			break;
		}
	}

	Phonon::MediaObject * soundEffect = Phonon::createPlayer(
			Phonon::MusicCategory, file);
	soundEffect->play();
	soundVec.push_back(soundEffect);
	printDebug(
			"<font color=red><b>Notice: </b></font>AudioPlayer::playSoundStr: creating new MediaObject, current MediaObject count = "
					+ QString::number(static_cast<unsigned>(soundVec.size())));
	return;
}

} /* namespace sgsui */
