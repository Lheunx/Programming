/* Name : screenOut.h ver 1.1
* Content : �ܼ� ����� ���� �Լ� ���� 
* Implementation : LHH
* 1.1: ShowPhoneInfoByPtr �߰� 
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
