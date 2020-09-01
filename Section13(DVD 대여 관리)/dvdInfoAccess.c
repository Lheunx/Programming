/* Name: dvdInfoAccess.c ver 1.0
* Content : dvd 정보 저장 및 참조 함수들의 정의 
* Implementation : LHH
*
*Last Modified: 08/19
*/

#include "common.h"
#include "dvdInfo.h"

#define MAX_CUSTOMER 100

static dvdInfo *dvdList[MAX_CUSTOMER]; // 포인터배열 cusInfo 형식의 데이터 주소값 저장 
static int numOfDvd=0;
/* 함수: int AddDVDInfo(char *ID, char * name, char* num)
* 기능 : dvdInfo 할당 및 저장
* 반환 : 성공 시 '등록된 정보의 개수', 실패 시 0 반환
*/
int AddDvdInfo(char * ISBN, char * title, int genre){
	int idx;
	idx=numOfDvd;
	dvdInfo* pDvdInfo;
	
	if(numOfDvd >= MAX_CUSTOMER)
		return 0; // 입력 실패 
	pDvdInfo = (dvdInfo *)malloc(sizeof(dvdInfo));
	strcpy(pDvdInfo->ISBN,ISBN);
	strcpy(pDvdInfo->title,title);
	pDvdInfo->genre=genre;
	dvdList[idx]=pDvdInfo;
//	pDvdInfo->numOfRentCus=0; 
	pDvdInfo->rentState=RETURNED;
	numOfDvd++;
	printf("등록이 완료되었습니다."); 
} 

/*함수 : dvdInfo * GetDvdPtrByISBN(char * ISBN)
* 기능 : 해당 ISBN의 정보를 담고 있는 변수의 포인터 반환
*반 환: 등록 안된 ISBN의 경우 NULL 포인터 반환
*/
dvdInfo * GetDvdPtrById (char * ISBN){
	int i;
	for(i=0;i<numOfDvd;i++){
		if(strcmp(dvdList[i]->ISBN,ISBN)==0){
			return dvdList[i];
		}
	}
	return NULL;
}

/*함수 : int IsRegistID(char*ID)
*기능 : 등록 된 ISBN 인지 확인
*반환 : 등록 되었으면 1, 아니면 0 반환
*/
int IsRegistISBN(char * ISBN){
	dvdInfo * pDvd = GetDvdPtrById(ISBN);
	if(pDvd==0)
		return 0;
	else
		return 1;
} 



/* 함수 : int SetDVDRented(char*ISBN, char*cusID, int rentDay)
* 기능: 대여 상태로 변경
*반환: 성공 1 ,실패 0
*/
int SetDVDRented(char *ISBN, char * cusID, int rentDay){
	int rentCusNum;
	dvdInfo * pDVD = GetDvdPtrById(ISBN);
	if(pDVD==0)return 0;
	
	pDVD->rentState=RENTED;
	AddRentList(ISBN,cusID,rentDay);
	return 1;
} 

/* 함수 : int SetDVDReturned (char * ISBN)
* 기능 : 대여 가능 상태로 변경
* 반환 : 성공 1, 실패 0
* 특이사항 : 필자가 제공한 함수
*/
int SetDVDReturned(char * ISBN){
	dvdInfo * pDVD= GetDvdPtrById(ISBN);
	
	if(pDVD==0)return 0;
	
	pDVD->rentState=RETURNED;
	return 1;
} 

/* 함수: int GetDVDRentState(char * ISBN)
* 기능 : 현재 대여 상태 반환
* 반 환: RETURNED, RENTED, 존재하지 않는 ISBN의 경우 -1 반환
*/
int GetDVDRentState(char * ISBN){
	dvdInfo * pDVD=GetDvdPtrById(ISBN);
	if(pDVD==0)return 0;
	return pDVD->rentState;
} 




//end of file

