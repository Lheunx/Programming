/* Name : main.c ver 1.3
 * content: main.c
 * Implemnetation : LHH
 * last modified : 2020.10.07

*/

#include "common.h"
//#include "blockInfo.h"
#include "point.h"
#include "blockStageControl.h"
#include "keyCurControl.h"
#include "conHitRead.h"
#include "drawBoard.h"


int main(){
	int i,j ;
	InitKeyDelayRate(2);
	DrawGameBoard();
	removeCursor();
	
	ChooseBlock();
	printBoardStatus();

	InitNewBlockPos(20,0);
	while(1){
		BlockDown();
		keyCheck();
	}
	return 0;
}