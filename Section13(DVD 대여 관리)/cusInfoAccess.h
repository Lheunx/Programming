/* Name: cusInfoAccess.h ver 1.0
* Content : �� ���� ���� �� ���� �Լ����� ���� 
* Implementation : LHH
*
*Last Modified: 08/18
*/

#ifndef __cusInfoAccess_h__
#define __cusInfoAccess_h__

#include "cusInfo.h"

int AddCusInfo(char * ID, char * name, char * num);
cusInfo * GetCusPtrById(char * ID);
int IsRegistID(char * ID);

#endif
//end of file
