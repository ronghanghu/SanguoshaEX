/*
//最后编辑时间：2012-06-28
//编辑者：李昂
*/
#include <iostream>
#include "sgsdata_extern.h"
#include "sgsdata_platform.h"
#include "sgsui_output.h"

char datamain(int playernum) {
	printDebug("datamain: starting");
	sgs::ExternData::platform.start(playernum);
    printDebug("datamain: from start to run");
	char result = sgs::ExternData::platform.run();
    printDebug("datamain: from run to end");
	sgs::ExternData::platform.end();
    printDebug("datamain: game ended");
	return result;
}
