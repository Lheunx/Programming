#include "common.h"
//#include "blockInfo.h"
#include "point.h"
#include "blockStageControl.h"
#include "keyCurControl.h"


int main(){
	removeCursor();
	InitNewBlockPos(10,1);
	ChooseBlock();
	while(1){
		BlockDown();
		Sleep(1000);
	}
	return 0;
}