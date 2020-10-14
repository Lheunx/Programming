/* Name : keyCurControl.h ver 1.0
 * content: 키보드, 커서관련 함수 선언
 * Implemnetation : LHH
 * last modified : 2020.10.06

*/

#ifndef __KEYCURCONTROL_H__
#define __KEYCURCONTROL_H__

void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);
void removeCursor(void);

#endif
//end