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
	SaveRentInfo();
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

/*함수 : int SaveRentInfo(void)
*기능 : DvdInfo정보 저방 
*반환 : 정상 1, 아니면 0 반환
*/
int SaveRentInfo(void){
	int i;
	FILE* fp;
	fp=fopen("data/RentBackup.dat","w");
	if(fp==NULL){
		printf("파일 오픈 오류\n"); 
		return 0;
	}
	fwrite(&numOfRentCus,sizeof(int),1,fp);
	printf("%d",numOfRentCus);
	for(i=0;i<numOfRentCus;i++){
		fprintf(fp,"%s %s %d\n",rentList[i].cusID,rentList[i].ISBN,rentList[i].rentDay);
//		fwrite(cusList[i]->ID,sizeof(cusList[i]->ID),1,fp);
//		fwrite(cusList[i]->name,sizeof(cusList[i]->name),1,fp);
//		fwrite(cusList[i]->phoneNum,sizeof(cusList[i]->phoneNum),1,fp);
	}
	fclose(fp);
	puts("파일 저장 성공"); 
}

/*함수 : int LoadRentInfo(void)
*기능 : RentInfo정보 로드 
*반환 : 정상 1, 아니면 0 반환
*/
int LoadRentInfo(void){
	int i;
	char cusID[ID_LEN];
	char ISBN[ISBN_LEN];
	unsigned int rentDay;
	FILE* fp;
	fp=fopen("data/RentBackup.dat","r");
	if(fp==NULL){
		printf("파일 오픈 오류\n"); 
		return 0;
	}
	fread(&numOfRentCus,sizeof(int),1,fp);
	printf("%d",numOfRentCus);
	for(i=0;i<numOfRentCus;i++){
		fscanf(fp,"%s%s%u",&cusID,&ISBN,&rentDay);
		printf("cusID:%s ISBN:%s rentDay:%u\n",cusID,ISBN,rentDay);	
		strcpy(rentList[i].cusID,cusID);
		strcpy(rentList[i].ISBN,ISBN);
		rentList[i].rentDay=rentDay;
	}
	fclose(fp);
	puts("파일 로드 성공"); 
}
//end of file
