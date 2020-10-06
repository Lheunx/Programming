/* Name : blockStageControl.c ver 1.0
 * content: ��� ���� �Լ� 
 * Implemnetation : LHH
 * last modified : 2020.10.06

*/

#include "common.h"
#include "keyCurControl.h"
#include "blockInfo.h"

static int currentBlockModel;
static int curPosX, curPosY;


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

