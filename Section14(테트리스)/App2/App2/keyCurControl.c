
/* Name : keyCurCuontrol.c ver 1.0
 * content: 키보드, 커서관련 함수
 * Implemnetation : LHH
 * last modified : 2020.10.06

*/

#include "common.h"

/*
함수: SetCurrentCursorPos(int x, int y)
기능: 커서 위치를 설정
반환: void
*/

void SetCurrentCursorPos(int x, int y){
	COORD pos= {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
/*
함수: GetCurrentCursorPos(void)
기능: 커서 위치 가져옴
반환: COORD -> point 로 변경 예정
*/
COORD GetCurrentCursorPos(void){
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	
	GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
		curPoint.X=curInfo.dwCursorPosition.X;
		curPoint.Y=curInfo.dwCursorPosition.Y;
		
		return curPoint;
}
/*
함수: removeCursor(void)
기능: 깜빡이는 커서 제거
반환: void
*/
void removeCursor(void){
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible=0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}