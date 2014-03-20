/*
 * sgsui_PixmapAnimationWidget.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: latios
 */

#include "sgsui_PixmapAnimationWidget.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

PixmapAnimationWidget::PixmapAnimationWidget(QWidget *parent) :
		QLabel(parent) {
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/0.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/1.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/2.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/3.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/4.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/5.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/6.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/7.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/8.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/9.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/10.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/11.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/12.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/13.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/14.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/15.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/16.png"));
	useBlackSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_black/17.png"));

	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/0.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/1.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/2.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/3.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/4.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/5.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/6.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/7.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/8.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/9.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/10.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/11.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/12.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/13.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/14.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/15.png"));
	useRedSlashPixmapList.push_back(
			new QPixmap("images/animation/slash_red/16.png"));

	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/0.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/1.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/2.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/3.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/4.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/5.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/6.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/7.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/8.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/9.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/10.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/11.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/12.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/13.png"));
	useFireSlashPixmapList.push_back(
			new QPixmap("images/animation/fire_slash/14.png"));

	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/0.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/1.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/2.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/3.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/4.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/5.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/6.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/7.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/8.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/9.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/10.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/11.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/12.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/13.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/14.png"));
	useThunderSlashPixmapList.push_back(
			new QPixmap("images/animation/thunder_slash/15.png"));

	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/0.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/1.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/2.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/3.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/4.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/5.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/6.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/7.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/8.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/9.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/10.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/11.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/12.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/12.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/12.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/12.png"));
	useJinkPixmapList.push_back(new QPixmap("images/animation/jink/12.png"));

	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/0.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/1.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/2.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/3.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/4.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/5.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/6.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/7.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/8.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/9.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/10.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/11.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/12.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/13.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/14.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/15.png"));
	usePeachPixmapList.push_back(new QPixmap("images/animation/peach/16.png"));

	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/0.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/1.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/2.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/3.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/4.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/5.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/6.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/7.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/8.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/9.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/10.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/11.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/12.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/13.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/14.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/15.png"));
	useAnalepticPixmapList.push_back(
			new QPixmap("images/animation/analeptic/16.png"));

	damagePixmapList.push_back(new QPixmap("images/animation/damage/0.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/1.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/2.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/3.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));
	damagePixmapList.push_back(new QPixmap("images/animation/damage/4.png"));

	lightningPixmapList.push_back(
			new QPixmap("images/animation/lightning/0.png"));

	chainPixmapList.push_back(new QPixmap("images/animation/chain/0.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/1.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/2.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/3.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/4.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/5.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/6.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/7.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/8.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/9.png"));
	chainPixmapList.push_back(new QPixmap("images/animation/chain/10.png"));

	duelPixmapList.push_back(new QPixmap("images/animation/duel/0.png"));
	duelPixmapList.push_back(new QPixmap("images/animation/duel/1.png"));

	wuxiePixmapList.push_back(new QPixmap("images/animation/wuxie/0.png"));

	blackSlashSize = QSize(300, 320);
	redSlashSize = QSize(310, 320);
	fireSlashSize = QSize(200, 258);
	thunderSlashSize = QSize(640, 406);
	jinkSize = QSize(128, 128);
	peachSize = QSize(320, 314);
	analepticSize = QSize(268, 263);
	damageSize = QSize(172, 170);
	lightningSize = QSize(112, 189);
	chainSize = QSize(202, 180);
	duelSize = QSize(180, 185);
	wuxieSize = QSize(106, 130);

	basicTimer = new QTimer(this);
	connect(basicTimer, SIGNAL(timeout()), this, SLOT(updatePixmap()));
}

PixmapAnimationWidget::~PixmapAnimationWidget() {
	std::list<QPixmap*>::iterator iter;
	for (iter = useBlackSlashPixmapList.begin();
			iter != useBlackSlashPixmapList.end(); ++iter) {
		delete *iter;
	}
	for (iter = useRedSlashPixmapList.begin();
			iter != useRedSlashPixmapList.end(); ++iter) {
		delete *iter;
	}
	for (iter = useFireSlashPixmapList.begin();
			iter != useFireSlashPixmapList.end(); ++iter) {
		delete *iter;
	}
	for (iter = useThunderSlashPixmapList.begin();
			iter != useThunderSlashPixmapList.end(); ++iter) {
		delete *iter;
	}
	for (iter = useJinkPixmapList.begin(); iter != useJinkPixmapList.end();
			++iter) {
		delete *iter;
	}
	for (iter = usePeachPixmapList.begin(); iter != usePeachPixmapList.end();
			++iter) {
		delete *iter;
	}
	for (iter = useAnalepticPixmapList.begin();
			iter != useAnalepticPixmapList.end(); ++iter) {
		delete *iter;
	}
	for (iter = damagePixmapList.begin(); iter != damagePixmapList.end();
			++iter) {
		delete *iter;
	}
	for (iter = lightningPixmapList.begin(); iter != lightningPixmapList.end();
			++iter) {
		delete *iter;
	}
	for (iter = chainPixmapList.begin(); iter != chainPixmapList.end();
			++iter) {
		delete *iter;
	}
	for (iter = duelPixmapList.begin(); iter != duelPixmapList.end(); ++iter) {
		delete *iter;
	}
	for (iter = wuxiePixmapList.begin(); iter != wuxiePixmapList.end();
			++iter) {
		delete *iter;
	}
}

void PixmapAnimationWidget::pixmapAnimation(const QPoint &position,
		PixmapAnimationType animationType) {
	QSize pixmapSize;
	std::list<QPixmap*> * pixmapList = 0;
	switch (animationType) {
	case BlackSlashAnimation:
		pixmapList = &useBlackSlashPixmapList;
		pixmapSize = blackSlashSize;
		break;
	case RedSlashAnimation:
		pixmapList = &useRedSlashPixmapList;
		pixmapSize = redSlashSize;
		break;
	case PeachAnimation:
		pixmapList = &usePeachPixmapList;
		pixmapSize = peachSize;
		break;
	case FireSlashAnimation:
		pixmapList = &useFireSlashPixmapList;
		pixmapSize = fireSlashSize;
		break;
	case ThunderSlashAnimation:
		pixmapList = &useThunderSlashPixmapList;
		pixmapSize = thunderSlashSize;
		break;
	case JinkAnimation:
		pixmapList = &useJinkPixmapList;
		pixmapSize = jinkSize;
		break;
	case AnalepticAnimation:
		pixmapList = &useAnalepticPixmapList;
		pixmapSize = analepticSize;
		break;
	case DamageAnimation:
		pixmapList = &damagePixmapList;
		pixmapSize = damageSize;
		break;
	case LightningAnimation:
		pixmapList = &lightningPixmapList;
		pixmapSize = lightningSize;
		break;
	case ChainAnimation:
		pixmapList = &chainPixmapList;
		pixmapSize = chainSize;
		break;
	case DuelAnimation:
		pixmapList = &duelPixmapList;
		pixmapSize = duelSize;
		break;
	case WuxieAnimation:
		pixmapList = &wuxiePixmapList;
		pixmapSize = wuxieSize;
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>PixmapAnimationWidget::pixmapAnimation: running PixmapAnimation of an invalid type");
		break;
	}

	setGeometry(
			QRect(
					position
							+ QPoint(-pixmapSize.width() / 2,
									-pixmapSize.height() / 2), pixmapSize));
	setPixmap(*(pixmapList->front()));
	show();

	basicAnimationIter = ++(pixmapList->begin());
	endIter = pixmapList->end();
	basicTimer->start(
			GUIStaticData::basicAnimationDuration / int(pixmapList->size()));
}

void PixmapAnimationWidget::updatePixmap() {
	if (basicAnimationIter != endIter)
		setPixmap(*(*basicAnimationIter++));
	else {
		basicTimer->stop();
		hide();
	}
}

} /* namespace sgsui */
