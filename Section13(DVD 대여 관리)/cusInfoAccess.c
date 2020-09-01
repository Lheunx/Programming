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
	SaveCusInfo();
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

/*함수 : int SaveCusInfo(void)
*기능 : cusInfo정보 저방 
*반환 : 정상 1, 아니면 0 반환
*/
int SaveCusInfo(void){
	int i;
	FILE* fp;
	fp=fopen("data/cusBackup.dat","w");
	if(fp==NULL){
		printf("파일 오픈 오류\n"); 
		return 0;
	}
	fwrite(&numOfCustomer,sizeof(int),1,fp);
	printf("%d",numOfCustomer);
	for(i=0;i<numOfCustomer;i++){
		fprintf(fp,"%s %s %s\n",cusList[i]->ID,cusList[i]->name,cusList[i]->phoneNum);
//		fwrite(cusList[i]->ID,sizeof(cusList[i]->ID),1,fp);
//		fwrite(cusList[i]->name,sizeof(cusList[i]->name),1,fp);
//		fwrite(cusList[i]->phoneNum,sizeof(cusList[i]->phoneNum),1,fp);
	}
	fclose(fp);
	puts("파일 저장 성공"); 
}

/*함수 : int LoadCusInfo(void)
*기능 : cusInfo정보 로드 
*반환 : 정상 1, 아니면 0 반환
*/
int LoadCusInfo(void){
	int i;
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
	cusInfo* pcusInfo;
	FILE* fp;
	fp=fopen("data/cusBackup.dat","r");
	if(fp==NULL){
		printf("파일 오픈 오류\n"); 
		return 0;
	}
	fread(&numOfCustomer,sizeof(int),1,fp);
	printf("%d",numOfCustomer);
	for(i=0;i<numOfCustomer;i++){
		fscanf(fp,"%s%s%s",&ID,&name,&phoneNum);
		printf("ID:%s name:%s num:%s I:%d\n",ID,name,phoneNum,i);	
		pcusInfo = (cusInfo *)malloc(sizeof(cusInfo));
		strcpy(pcusInfo->ID,ID);
		strcpy(pcusInfo->name,name);
		strcpy(pcusInfo->phoneNum,phoneNum);
		cusList[i]=pcusInfo;
	}
	fclose(fp);
	puts("파일 로드 성공"); 
}

//end of file

