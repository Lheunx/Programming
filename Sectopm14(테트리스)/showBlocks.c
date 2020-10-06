#include "common.h"
#include "blockInfo.h"

void ShowBlock(char blockInfo [] [4]);
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);
void removeCursor(void);


int main(void){
	removeCursor();
	int i;
	
	srand(time(NULL));
//	time(NULL);
	int random = (rand() % 7) * 4;
	for(i=0; i < 30 ; i ++){
		printf("%d", random);
		SetCurrentCursorPos(10,i);
//		random = rand() % 7;
		ShowBlock(blockModel[random]);
		Sleep(1000);
		system("cls");
	}
	return 0;
} 

void ShowBlock(char blockInfo [] [4]){
	int y, x;
	COORD curPos=GetCurrentCursorPos();
	
	for(y=0; y<4; y++){
		for(x=0; x<4; x++){
			
			SetCurrentCursorPos(curPos.X + (x *2), curPos.Y + y);
			if(blockInfo[y][x] == 1)
			printf("бс"); 
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void SetCurrentCursorPos(int x, int y){
	COORD pos= {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

COORD GetCurrentCursorPos(void){
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	
	GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
		curPoint.X=curInfo.dwCursorPosition.X;
		curPoint.Y=curInfo.dwCursorPosition.Y;
		
		return curPoint;
}
void removeCursor(void){
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible=0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
