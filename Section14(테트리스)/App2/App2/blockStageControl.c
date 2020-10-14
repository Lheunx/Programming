/* Name : blockStageControl.c ver 1.0
 * content: 블록 상태 함수 
 * Implemnetation : LHH
 * last modified : 2020.10.06

*/

#include "common.h"
#include "keyCurControl.h"
#include "drawBoard.h"
#include "blockInfo.h"
#include "Board.h"

static int currentBlockModel;
static int curPosX, curPosY;
static int a=0;

/*
함수: InitNewBlockPos(int x, int y)
기능: 블록 첫 위치 지정
반환: void
*/
void InitNewBlockPos(int x, int y){
	if(x<0||y<0) return ;

	curPosX=x;
	curPosY=y;

	SetCurrentCursorPos(x,y);
}

/*
함수: void ChooseBlock(void)
기능: block 무작위 선택
반환: void
*/
void ChooseBlock(void){
	srand((unsigned int)time(NULL));	
	currentBlockModel = (rand() % 7) * 4;
}


/*
함수: int GetCurrentBlockIdx(void)
기능: 현재 출력해야 하는 블록의 index 정보 반환
반환: int
*/

int GetCurrentBlockIdx(void){
	return currentBlockModel;	
}

/*
함수: showBlock(char block[][4])
기능: block 정보 출력
반환: void
*/
void showBlock(char block[][4]){
	int x, y;
	COORD curPos=GetCurrentCursorPos();

	for(y=0; y<4; y++){
		for(x=0; x<4; x++){
			SetCurrentCursorPos(curPos.X + (x*2), curPos.Y + y);
			if(block[y][x]==1){	
				printf("■");
			}
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}
/*
함수: DeleteBlock(char block[][4])
기능: 출력된 block 정보 삭제
반환: void
*/
void DeleteBlock(char block[][4]){
	int x, y;
	COORD curPos=GetCurrentCursorPos();

	for(y=0; y<4; y++){
		for(x=0; x<4; x++){
			SetCurrentCursorPos(curPos.X + (x*2), curPos.Y + y);
			if(block[y][x]==1){	
				printf("  ");
			}
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

/*
함수: BlockDown(void)
기능: 모니터에 그려진 블록을 아래로 한 칸 내림
반환: void
*/
void BlockDown(void){
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY+=1;

	SetCurrentCursorPos(curPosX, curPosY);
	showBlock(blockModel[GetCurrentBlockIdx()]);
}


int BlockCrushCheck(){
	int i, j,x,y;
	int idx = GetCurrentBlockIdx();
	y=curPosY-3;
	x=curPosX / 2 - 7;
	printf("X: %d Y: %d ",curPosX,curPosY);
	
	for(i=0; i< 4; i++){
		for(j=0; j<4; j++){
			if(GameBoard[y+i][x+j] + blockModel[idx][i][j] == 2){//2이면 충돌이겠쥬? 수정필요
				printf("y: %d x: %d i: %d j: %d ",y+i,x+j,i,j);
				return 1;
			}
		}
	}
	printf("y: %d x: %d i: %d j: %d ",y+i,x+j,i,j);
	return 0; // 충돌이 없으면
}
/*
함수: BlockLeft(void)
기능: 모니터에 그려진 블록을 왼쪽으로 한 칸 이동
반환: void
*/
void BlockLeft(void){
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX-=2;
	if(BlockCrushCheck()){
		curPosX+=2;
	}
	printf("X: %d",curPosX);
	//x가 가로 2씩 줄어듦.
	SetCurrentCursorPos(curPosX, curPosY);
	showBlock(blockModel[GetCurrentBlockIdx()]);
}

/*
함수: BlockRight(void)
기능: 모니터에 그려진 블록을 오른쪽으로 한 칸 이동
반환: void
*/

void BlockRight(void){
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX+=2;	
	if(BlockCrushCheck()){
		curPosX-=2;	
	}
	printf("X: %d",curPosX);

	SetCurrentCursorPos(curPosX, curPosY);
	showBlock(blockModel[GetCurrentBlockIdx()]);
}

/*
함수: BlockRotate(void)
기능: 모니터에 그려진 블록을 90도 회전
반환: void
*/
void BlockRotate(void){
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	a++;
	if(a>3){
		a=0;
		currentBlockModel-=3;
		if(BlockCrushCheck()){
			a=3;
			currentBlockModel+=3;
		}
	}
	else{	
		currentBlockModel++;
		if(BlockCrushCheck()){
			a--;
			currentBlockModel--;
		}
	}

	SetCurrentCursorPos(curPosX, curPosY);
	showBlock(blockModel[GetCurrentBlockIdx()]);

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

