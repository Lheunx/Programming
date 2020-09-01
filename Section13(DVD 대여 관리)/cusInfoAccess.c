/* Name: cusInfoAccess.c ver 1.0
* Content : 고객 정보 저장 및 참조 함수들의 정의 
* Implementation : LHH
*
*Last Modified: 08/18
*/

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo *cusList[MAX_CUSTOMER]; // 포인터배열 cusInfo 형식의 데이터 주소값 저장 
static int numOfCustomer=0;
/* 함수: int AddCusInfo(char *ID, char * name, char* num)
* 기능 : cusInfo 할당 및 저장
* 반환 : 성공 시 '등록된 정보의 개수', 실패 시 0 반환
*/
int AddCusInfo(char * ID, char * name, char * num){
	int idx;
	idx=numOfCustomer;
	cusInfo* pcusInfo;
	
	if(numOfCustomer >= MAX_CUSTOMER)
		return 0; // 입력 실패 
	pcusInfo = (cusInfo *)malloc(sizeof(cusInfo));
//	if(!IsRegistID(ID)){
		strcpy(pcusInfo->ID,ID);
		strcpy(pcusInfo->name,name);
		strcpy(pcusInfo->phoneNum,num);
		cusList[idx]=pcusInfo;
		numOfCustomer++;
//	}
} 

/*함수 : cusInfo * GetCusPtrById(char * ID)
* 기능 : 해당 ID의 정보를 담고 있는 변수의 포인터 반환
*반 환: 등록 안된 ID의 경우 NULL 포인터 반환
*/
cusInfo * GetCusPtrById (char * ID){
	int i;
	for(i=0;i<numOfCustomer;i++){
		if(strcmp(cusList[i]->ID,ID)==0){
			return cusList[i];
		}
	}
	return NULL;
}

/*함수 : int IsRegistID(char*ID)
*기능 : 가입 된 ID 인지 확인
*반환 : 가입 되었으면 1, 아니면 0 반환
*/
int IsRegistID(char * ID){
	cusInfo * pCus = GetCusPtrById(ID);
	if(pCus==0)
		return 0;
	else
		return 1;
} 



//end of file

