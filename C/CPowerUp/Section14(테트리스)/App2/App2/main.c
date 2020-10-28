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
	InitKeyDelayRate(1);
	/*DrawGameBoard();*/
	removeCursor();
	//
	//ChooseBlock();
	////printBoardStatus();

	//InitNewBlockPos(20,1);
	while(1){
		
		system("cls");
		ShowGameBoardBlock();
		DrawGameBoard();
		printJumLevel();
		InitNewBlockPos(20,2);
		ChooseBlock();
		if(IsOver())break;
		while(1){
			if(BlockDown()){
				GameBoardBlockAdd();
				BoardArrCheck();
				jumplus();
				InitKeyDelayRate(levelplus());					
				break;
			}
			keyCheck();
		}
	}


	InitNewBlockPos(20,20);
	puts("게임 오버");
	getchar();
	return 0;
}