/* Name : blockStageControl.c ver 1.0
 * content: ��� ���� �Լ� 
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
�Լ�: InitNewBlockPos(int x, int y)
���: ��� ù ��ġ ����
��ȯ: void
*/
void InitNewBlockPos(int x, int y){
	if(x<0||y<0) return ;

	curPosX=x;
	curPosY=y;

	SetCurrentCursorPos(x,y);
}

/*
�Լ�: void ChooseBlock(void)
���: block ������ ����
��ȯ: void
*/
void ChooseBlock(void){
	srand((unsigned int)time(NULL));	
	currentBlockModel = (rand() % 7) * 4;
}


/*
�Լ�: int GetCurrentBlockIdx(void)
���: ���� ����ؾ� �ϴ� ����� index ���� ��ȯ
��ȯ: int
*/

int GetCurrentBlockIdx(void){
	return currentBlockModel;	
}

/*
�Լ�: showBlock(char block[][4])
���: block ���� ���
��ȯ: void
*/
void showBlock(char block[][4]){
	int x, y;
	COORD curPos=GetCurrentCursorPos();

	for(y=0; y<4; y++){
		for(x=0; x<4; x++){
			SetCurrentCursorPos(curPos.X + (x*2), curPos.Y + y);
			if(block[y][x]==1){	
				printf("��");
			}
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}
/*
�Լ�: DeleteBlock(char block[][4])
���: ��µ� block ���� ����
��ȯ: void
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
�Լ�: BlockDown(void)
���: ����Ϳ� �׷��� ����� �Ʒ��� �� ĭ ����
��ȯ: void
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
			if(GameBoard[y+i][x+j] + blockModel[idx][i][j] == 2){//2�̸� �浹�̰���? �����ʿ�
				printf("y: %d x: %d i: %d j: %d ",y+i,x+j,i,j);
				return 1;
			}
		}
	}
	printf("y: %d x: %d i: %d j: %d ",y+i,x+j,i,j);
	return 0; // �浹�� ������
}
/*
�Լ�: BlockLeft(void)
���: ����Ϳ� �׷��� ����� �������� �� ĭ �̵�
��ȯ: void
*/
void BlockLeft(void){
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX-=2;
	if(BlockCrushCheck()){
		curPosX+=2;
	}
	printf("X: %d",curPosX);
	//x�� ���� 2�� �پ��.
	SetCurrentCursorPos(curPosX, curPosY);
	showBlock(blockModel[GetCurrentBlockIdx()]);
}

/*
�Լ�: BlockRight(void)
���: ����Ϳ� �׷��� ����� ���������� �� ĭ �̵�
��ȯ: void
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
�Լ�: BlockRotate(void)
���: ����Ϳ� �׷��� ����� 90�� ȸ��
��ȯ: void
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

