/* Name: rentInfoAccess.c ver 1.0
* Content : 영화 DVD 대여 정보 리스트 
* Implementation : LHH
*
*Last Modified: 08/25
*/
#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

#define RENT_LEN 100

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus=0;

/*함수: void AddRentList(char * ISBN, char * cusID, int rentDay)
* 기능: 대여 정보를 저장
* 반환: void
*/
void AddRentList(char*ISBN, char*cusID, int rentDay){
	strcpy(rentList[numOfRentCus].cusID,cusID);
	strcpy(rentList[numOfRentCus].ISBN,ISBN);
	rentList[numOfRentCus].rentDay=rentDay;
	numOfRentCus++;
} 

/*함수: void PrintOutRentAllCusInfo(char * ISBN)
*기능: 특정 ISBN의 DVD 대여 정보 전체 출력
*반환: void
*/
void PrintOutRentAllCusInfo(char * ISBN){
	int i;
	for(i=0;i<numOfRentCus;i++){
		if(strcmp(rentList[i].ISBN,ISBN)==0){
			printf("대여일: %d\n",rentList[i].rentDay);
			ShowCustomerInfo(GetCusPtrById(rentList[i].cusID));
		}
	}
} 

/* 함수: void PrintOUtCusALlRentInfo(char *, unsigned int, unsigned int)
* 기능: 일정 기간 안에 이뤄진 특정 고객의 DVD 대여 정보 출력
*반환 : void
*/
void PrintOutCusALlRentInfo(char * ID, unsigned int start, unsigned int end){
	int i; 
	for(i=0;i<numOfRentCus;i++){
		if(strcmp(rentList[i].cusID,ID)==0 && rentList[i].rentDay >= start && rentList[i].rentDay <= end){
			printf("-------------------------\n"); 
			printf("| ▶ISBN: %s\n",rentList[i].ISBN);
			printf("| ▶대여일: %u\n",rentList[i].rentDay);
			printf("-------------------------\n");
		}
	}
} 
//end of file
