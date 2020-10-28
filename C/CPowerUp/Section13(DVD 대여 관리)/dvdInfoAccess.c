/* Name: dvdInfoAccess.c ver 1.1
* Content : dvd 정보 저장 및 참조 함수들의 정의 
* Implementation : LHH
* 1.1 : 교재와 비슷하게 수정 
*Last Modified: 09/01
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
	SaveDvdInfo();
	printf("등록이 완료되었습니다."); 
	
	return numOfDvd;
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

/*함수 : int SaveDvdInfo(void)
*기능 : DvdInfo정보 저방 
*반환 : 정상 1, 아니면 0 반환
*/
int SaveDvdInfo(void){
	int i;
	FILE* fp;
	fp=fopen("data/DvdBackup.dat","w");
	if(fp==NULL){
		printf("파일 오픈 오류\n"); 
		return 0;
	}
	fwrite(&numOfDvd,sizeof(int),1,fp);
	printf("%d",numOfDvd);
	for(i=0;i<numOfDvd;i++){
		fprintf(fp,"%s %s %d %d\n",dvdList[i]->ISBN,dvdList[i]->title,dvdList[i]->genre,dvdList[i]->rentState);
//		fwrite(cusList[i]->ID,sizeof(cusList[i]->ID),1,fp);
//		fwrite(cusList[i]->name,sizeof(cusList[i]->name),1,fp);
//		fwrite(cusList[i]->phoneNum,sizeof(cusList[i]->phoneNum),1,fp);
	}
	fclose(fp);
	puts("파일 저장 성공"); 
}

/*함수 : int LoadDvdInfo(void)
*기능 : DvdInfo정보 로드 
*반환 : 정상 1, 아니면 0 반환
*/
int LoadDvdInfo(void){
	int i;
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	int rentState;// 대여 상태 정보
	dvdInfo* pdvdInfo;
	FILE* fp;
	fp=fopen("data/DvdBackup.dat","r");
	if(fp==NULL){
		printf("파일 오픈 오류\n"); 
		return 0;
	}
	fread(&numOfDvd,sizeof(int),1,fp);
	printf("%d",numOfDvd);
	for(i=0;i<numOfDvd;i++){
		fscanf(fp,"%s%s%d%d",&ISBN,&title,&genre,&rentState);
		printf("ISBN:%s title:%s genre:%d retnState:%d\n",ISBN,title,genre,rentState);	
		pdvdInfo = (dvdInfo *)malloc(sizeof(dvdInfo));
		strcpy(pdvdInfo->ISBN,ISBN);
		strcpy(pdvdInfo->title,title);
		pdvdInfo->genre=genre;
		pdvdInfo->rentState=rentState;
		dvdList[i]=pdvdInfo;
	}
	fclose(fp);
	puts("파일 로드 성공"); 
}

//end of file

