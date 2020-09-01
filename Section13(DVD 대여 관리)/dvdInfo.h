/* Name: dvdInfo.h ver 1.1
* Content : 영화 DVD 관리 구조체 
* Implementation : LHH
*
*Last Modified: 08/20
*/

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include"cusInfo.h" // 상수 ID_LEN의 사용을 위해 

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100

enum{ACTION=1, COMIC,SF,ROMANTIC
};
enum {RENTED, RETURNED}; // 대여 상태를 나타내는 상수 

typedef struct __dvdInfo{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	int rentState;// 대여 상태 정보
}dvdInfo;

#endif

//end of file

