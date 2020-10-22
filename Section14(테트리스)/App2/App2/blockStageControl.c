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
static int x,y;

static int level=1;
static int j=0;
static int jum=0;

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
	a=0;
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
�Լ�: BlockCrushCheck(void)
���: ��Ͽ� �浹�� üũ �⵿�� ���� �� 0, �浹 �� 1.
��ȯ: int
*/

int BlockCrushCheck(){
	int i, j;
	int idx = GetCurrentBlockIdx();
	y=curPosY-returnGboardOriginy();
	x=(curPosX-returnGboardOriginx()) / 2 ;
	//printf("X: %d Y: %d ",curPosX,curPosY);
	
	for(i=0; i< 4; i++){
		for(j=0; j<4; j++){
			if(GameBoard[y+i][x+j] + blockModel[idx][i][j] == 2){//2�̸� �浹�̰���? �����ʿ�
				//printf("y: %d x: %d i: %d j: %d ",y+i,x+j,i,j);
				return 1;
			}
		}
	}
	//printf("y: %d x: %d i: %d j: %d ",y+i,x+j,i,j);
	return 0; // �浹�� ������
}

/*
�Լ�: IsOver()
���: ���� ���� üũ
��ȯ: void
*/

int IsOver(){
	if(BlockCrushCheck())return 1;
	return 0;
}

/*
�Լ�: ShowGameBoardBlock(void)
���: Game�� �߰��� ��� ���
��ȯ: void
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
				printf("��");
				SetCurrentCursorPos(0,0);
				printf("X: %d Y: %d",x + (j*2),y + i);
			}
		}
	}
}

/*
�Լ�: GameBoardBlockAdd(void)
���: GameBoard�� ����� �Է�
��ȯ: void
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
�Լ�: BlockDown(void)
���: ����Ϳ� �׷��� ����� �Ʒ��� �� ĭ ����
��ȯ: void
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
	//printf("X: %d",curPosX);
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
	//printf("X: %d",curPosX);

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
	printf("���� ������ : %d �Դϴ�.\n",jum);
	printf("���� ������ : %d �Դϴ�.",level);
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

