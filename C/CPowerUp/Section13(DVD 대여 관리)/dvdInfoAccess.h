/* Name: dvdInfoAccess.h ver 1.0
* Content : DVD ���� ���� �� ���� �Լ����� ���� 
* Implementation : LHH
*
*Last Modified: 08/19
*/

#ifndef __cusInfoAccess_h__
#define __cusInfoAccess_h__

#include "cusInfo.h"

int AddDvdInfo(char * ISBN, char * title, int genre);
dvdInfo * GetDvdPtrById(char * ISBN);
int IsRegistISBN(char * ISBN);

// �߰��� �Լ�
int SetDVDRented(char * ISBN, char *cusID, int rentDay);
int SetDVDReturned(char* ISBN);
int SetDVDRentState(char *ISBN); 

#endif
//end of file
