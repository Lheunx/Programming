/* Name: dvdInfo.h ver 1.1
* Content : ��ȭ DVD ���� ����ü 
* Implementation : LHH
*
*Last Modified: 08/20
*/

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include"cusInfo.h" // ��� ID_LEN�� ����� ���� 

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100

enum{ACTION=1, COMIC,SF,ROMANTIC
};
enum {RENTED, RETURNED}; // �뿩 ���¸� ��Ÿ���� ��� 

typedef struct __dvdInfo{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	int rentState;// �뿩 ���� ����
}dvdInfo;

#endif

//end of file

