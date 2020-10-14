/* name : drawBoard.c  ver 1.0
 * content : 보드판 생성 관련 함수
 * Implementation : LHH
 * Last Modified 2020.10.12
 */

#include "common.h"
#include "keyCurControl.h"
#include "drawBoard.h"

#define GBOARD_WIDTH 10
#define GBOARD_HEIGHT 20

#define GBOARD_ORIGIN_X 4
#define GBOARD_ORIGIN_Y 2


void DrawGameBoard(){
	int x,y;
	for(y=0; y<=GBOARD_HEIGHT; y++){
		SetCurrentCursorPos(
			GBOARD_ORIGIN_X,
			GBOARD_ORIGIN_Y + y);
			if(y==GBOARD_HEIGHT)
				printf("└");
			else
				printf("│"); 
	}
	for(y=0; y<=GBOARD_HEIGHT; y++){
		SetCurrentCursorPos(
			GBOARD_ORIGIN_X + (GBOARD_WIDTH+1) * 2,
			GBOARD_ORIGIN_Y + y);
			if(y==GBOARD_HEIGHT)
				printf("┘");
			else
				printf("│"); 
	}
	for(x=1; x<GBOARD_WIDTH+1;x++){
		SetCurrentCursorPos(
			GBOARD_ORIGIN_X+x *2, GBOARD_ORIGIN_Y+GBOARD_HEIGHT);
			printf("─"); 
	} 
	SetCurrentCursorPos(0,0);
}

int returnGboardWidth(void){
	return GBOARD_WIDTH;
}
int returnGboardHeight(void){
	return GBOARD_HEIGHT;
}

void printBoardStatus(){
	int i,j;
	for(i=0; i<20; i++){
		for(j=0;j<12; j++){
			printf("%d",GameBoard[i][j]);
		}
		printf("\n");
	}
}