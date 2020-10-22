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
static int x,y;

static int level=1;
static int j=0;
static int jum=0;

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
	a=0;
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
함수: BlockCrushCheck(void)
기능: 블록에 충돌을 체크 출동이 없을 시 0, 충돌 시 1.
반환: int
*/

int BlockCrushCheck(){
	int i, j;
	int idx = GetCurrentBlockIdx();
	y=curPosY-returnGboardOriginy();
	x=(curPosX-returnGboardOriginx()) / 2 ;
	//printf("X: %d Y: %d ",curPosX,curPosY);
	
	for(i=0; i< 4; i++){
		for(j=0; j<4; j++){
			if(GameBoard[y+i][x+j] + blockModel[idx][i][j] == 2){//2이면 충돌이겠쥬? 수정필요
				//printf("y: %d x: %d i: %d j: %d ",y+i,x+j,i,j);
				return 1;
			}
		}
	}
	//printf("y: %d x: %d i: %d j: %d ",y+i,x+j,i,j);
	return 0; // 충돌이 없으면
}

/*
함수: IsOver()
기능: 게임 종료 체크
반환: void
*/

int IsOver(){
	if(BlockCrushCheck())return 1;
	return 0;
}

/*
함수: ShowGameBoardBlock(void)
기능: Game에 추가된 블록 출력
반환: void
*/

void ShowGameBoardBlock(void){
	int x = returnGboardOriginx();
	int y = returnGboardOriginy();
	int i,j;
	//printf("%d",x);
	for(i=0; i<20; i++){
		for(j=1; j<11; j++){
			SetCurrentCursorPos(x + (j*2), y + i);
			if(GameBoard[i][j]==1){	
				printf("■");
				SetCurrentCursorPos(0,0);
				printf("X: %d Y: %d",x + (j*2),y + i);
			}
		}
	}
}

/*
함수: GameBoardBlockAdd(void)
기능: GameBoard에 블록을 입력
반환: void
*/
void GameBoardBlockAdd(void){
	int i, j;
	int idx = GetCurrentBlockIdx();
	/*y=curPosY-5;*/
	y=curPosY-returnGboardOriginy()-1;
	x=(curPosX-returnGboardOriginx()) / 2 ;
	for(i=0; i< 4; i++){
		for(j=0; j<4; j++){
			if(blockModel[idx][i][j] == 1){
				GameBoard[y+i][x+j] = 1;
				/*printf("y: %d x: %d i: %d j: %d ",y+i,x+j,i,j);*/
			}
		}
	}
	/*printBoardStatus();
	ShowGameBoardBlock();*/
}


/*
함수: BlockDown(void)
기능: 모니터에 그려진 블록을 아래로 한 칸 내림
반환: void
*/
int BlockDown(void){
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY+=1;
	if(BlockCrushCheck()){
		return 1;
	}
	SetCurrentCursorPos(curPosX, curPosY);
	showBlock(blockModel[GetCurrentBlockIdx()]);
	return 0;
}

int BlockSuperDown(void){
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY+=1;
	if(BlockCrushCheck()){
		curPosY--;
		return 1;
	}
	SetCurrentCursorPos(curPosX, curPosY);
	showBlock(blockModel[GetCurrentBlockIdx()]);
	return 0;
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
	//printf("X: %d",curPosX);
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
	//printf("X: %d",curPosX);

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
void BoardArrCheck(){
	int i,j,tot,c;
	for(i=19; i>0; i--){
		tot=0;
		for(j=1;j<11; j++){
			tot+=GameBoard[i][j];
		}
		if(tot==0)return;
		else if(tot==10){
			for(c=i; c>0; c--){
				for(j=1;j<11; j++){
					GameBoard[c][j]=GameBoard[c-1][j];
				}
			}
		i++;
		jum+=20;
		j+=2;
		}
	}
}
void jumplus(){
	jum+=10;
	j++;
}

int levelplus(){
	if(j>3){
		level++;
		j=0;
	}
	return level;
}

void printJumLevel(){
	printf("현재 점수는 : %d 입니다.\n",jum);
	printf("현재 레벨은 : %d 입니다.",level);
}

void printBoardStatus(){
	int i,j;
	for(i=0; i<20; i++){
		for(j=1;j<11; j++){
			printf("%d",GameBoard[i][j]);
		}
		printf("\n");
	}
}

