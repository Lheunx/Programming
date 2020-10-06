
/* Name : keyCurCuontrol.c ver 1.0
 * content: Ű����, Ŀ������ �Լ�
 * Implemnetation : LHH
 * last modified : 2020.10.06

*/

#include "common.h"

/*
�Լ�: SetCurrentCursorPos(int x, int y)
���: Ŀ�� ��ġ�� ����
��ȯ: void
*/

void SetCurrentCursorPos(int x, int y){
	COORD pos= {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
/*
�Լ�: GetCurrentCursorPos(void)
���: Ŀ�� ��ġ ������
��ȯ: COORD -> point �� ���� ����
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
�Լ�: removeCursor(void)
���: �����̴� Ŀ�� ����
��ȯ: void
*/
void removeCursor(void){
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible=0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}