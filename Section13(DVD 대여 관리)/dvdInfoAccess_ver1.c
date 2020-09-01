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
//	if(!IsRegistID(ID)){
		strcpy(pDvdInfo->ISBN,ISBN);
		strcpy(pDvdInfo->title,title);
		pDvdInfo->genre=genre;
		dvdList[idx]=pDvdInfo;
		pDvdInfo->numOfRentCus=0; 
		numOfDvd++;
	printf("등록이 완료되었습니다."); 
//	}
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

/*함수 : int rentDVD(void)
*기능 : DVD 대여 
*반환 : 
*/

int RentDVD(){
	dvdInfo* ptr;
	dvdRentInfo rentInfo;
	char rDvd[ISBN_LEN];
	printf("대여 DVD ISBN 입력: "); gets(rDvd);
	ptr=GetDvdPtrById(rDvd);
	
	if(ptr==NULL){
		printf("등록되지 않은 DVD입니다.");
		return 0; 
	}
	if(ptr->rentState == RENTED){
		printf("현재 대여중입니다. 대여가 불가능합니다.");
		return 0; 
	}
	
	printf("대여가 가능합니다. 대여 과정을 진행합니다.\n대여 고객 ID 입력: "); 
	gets(rentInfo.cusID);
	if(!IsRegistID(rentInfo.cusID)){
		printf("가입 고객이 아닙니다.");
		return 0; 
	}
	printf("대여 날짜 입력: ");
	scanf("%d",&rentInfo.rentDay);
	ptr->rentState=RENTED;
//	memcpy(ptr->rentList[ptr->numOfRentCus],rentInfo,sizeof(dvdRentInfo));
	strcpy(ptr->rentList[ptr->numOfRentCus].cusID,rentInfo.cusID);
	ptr->rentList[ptr->numOfRentCus].rentDay=rentInfo.rentDay;
	ptr->numOfRentCus++;
	
}

/*함수 : int returnDVD(void)
*기능 : DVD 반납 
*반환 : 
*/
int returnDVD(void){
	dvdInfo* ptr;
	char rDvd[ISBN_LEN];
	printf("반납 DVD ISBN 입력: "); gets(rDvd);
	ptr=GetDvdPtrById(rDvd);
	
	if(ptr==NULL){
		printf("등록되지 않은 DVD입니다.");
		return 0; 
	}
	if(ptr->rentState != RENTED){
		printf("현재 대여중이 아닙니다. 반납이 불가능합니다.");
		return 0; 
	} 
	ptr->rentState=RETURNED; 
	printf("반납이 완료되었습니다.");
}


/*함수 : int showDvdRentCus(void)
*기능 : DVD 대여 고객 조회 
*반환 : 
*/
int showDvdRentCus(void){
	dvdInfo* ptr;
	int i;
	char rDvd[ISBN_LEN];
	printf("조회 DVD ISBN 입력: "); gets(rDvd);
	ptr=GetDvdPtrById(rDvd);
	if(ptr==NULL){
		printf("등록되지 않은 DVD입니다.");
		return 0; 
	}
	if(ptr->numOfRentCus==0){
		printf("대여횟수가 0번입니다."); 
		return 0; 
	}
	for(i=0;i<ptr->numOfRentCus;i++){
		printf("\n대여일: %d\n",ptr->rentList[i].rentDay);
		ShowCustomerInfo(GetCusPtrById(ptr->rentList[i].cusID));
	}
}
//end of file

