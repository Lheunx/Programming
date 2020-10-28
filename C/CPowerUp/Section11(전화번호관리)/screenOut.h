/* Name : screenOut.h ver 1.1
* Content : 콘솔 출력을 위한 함수 선언 
* Implementation : LHH
* 1.1: ShowPhoneInfoByPtr 추가 
* Last modified 2020/08/10
*/
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h"

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(phoneData * phone);

#endif
//end of file
