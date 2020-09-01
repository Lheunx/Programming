/* Name : phoneFunc.c ver 1.7
* Content : 전화번호 컨트롤 함수 
* Implementation : LHH
* 1.1: 함수 InputPhoneData, ShowAllData의 구현 완료
* 1.2: SearchPhoneData, DeletePhoneData 함수 추가 
* 1.3: phoneList를 포인터 배열로 변경, 출력 함수 ShowPhoneInfoByPtr 함수로 변경 
* 1.4: 동명이인을 처리하기 함수확장 
* 1.5: StoreDataToFile, LoadDataFromFile 함수 추가 
* 1.6: ChangePhoneData 함수 추가 
* 1.7 : StoreDataToFileInStruct, LoadDataFromFileInStruct 함수 추가 
* Last modified 2020/08/11
*/
 
#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData=0;
phoneData *phoneList[LIST_NUM];

/*함 수: void InputPhoneData(void)
*기 능: 전화번호 관련 데이터 입력 받아서 저장
*반 환: void
*/
void InputPhoneData(void){
	if (numOfData>LIST_NUM){
		fputs("저장 공간이 부족합니다.",stdout); 
		return;
	}
	int i; 
	phoneData *data;
	data=(phoneData*)malloc(sizeof(phoneData));
	fputs("이름 입력:",stdout); 
	gets(data->name );
	
	fputs("전화번호 입력:",stdout); 
	gets(data->phoneNum);
	//비교 
	for(i=0;i<numOfData;i++){
		if((strcmp(data->name,phoneList[i]->name)==0) && (strcmp(data->phoneNum,phoneList[i]->phoneNum) == 0)){
			fputs("이미 입력된 데이터 입니다.",stdout);
			free(data);
			return ;
		}
	}
	
	phoneList[numOfData]=data;
	numOfData++;
	fputs("입력이 완료되었습니다.",stdout); 
	StoreDataToFileInStruct();
} 
/*함 수: void ShowAllData(void)
*기 능: 저장된 데이터 전체 출력
*반 환: void
*/
void ShowAllData(void){
	int i;
	for(i=0;i<numOfData;i++){
		ShowPhoneInfoByPtr(phoneList[i]);
		}
	fputs("출력이 완료되었습니다.",stdout); 
} 

void SearchPhoneData(void){
	char sName[NAME_LEN];
	int i;
	int ret=0;
	fputs("찾는 이름은?:",stdout);
	gets(sName);
	for(i=0;i<numOfData;i++){
		if(strcmp(sName,phoneList[i]->name)==0){
			ShowPhoneInfoByPtr(phoneList[i]);
			ret=1;
			//break;
		}
	}
	if(ret=1) fputs("검색이 완료되었습니다.",stdout); 
	else fputs("찾는 이름의 데이터가 없습니다.",stdout); 
}

void DeletePhoneData(void){
	char sName[NAME_LEN];
	int num[LIST_NUM]={0,};// 동명이인을 처리하기위한 배열 
	int i;
	int j=0; //동명이인을 처리하기 위한 변수 
	fputs("찾는 이름은?:",stdout);
	gets(sName);
	
	for(i=0;i<numOfData;i++){
		if(strcmp(sName,phoneList[i]->name)==0){
			num[j]=i;
			j++;
		}
	}
	
	if(j==0){
		fputs("찾는 이름이 없습니다.",stdout); 
		return ;	
	}
	
	if(j>1){
		for(i=0;i<j;i++){
			printf("선택 %d:\n",i+1); 
			ShowPhoneInfoByPtr(phoneList[num[i]]);
		}
		fputs("선택 :",stdout); 
		scanf("%d",&j); 
		i=num[j-1];
		numOfData--; 
	}
	
	else{	
		for(i=0;i<numOfData;i++){
			if(strcmp(sName,phoneList[i]->name)==0){
				numOfData--;
				break;
			}
		}
	}
	
	for(; i<numOfData;i++){
		phoneList[i]=phoneList[i+1];
	}
	fputs("삭제가 완료되었습니다.",stdout); 
	StoreDataToFileInStruct();
}

void StoreDataToFile(void){
	FILE *fp;
	int i;
	fp=fopen("PhoneNumbers.txt","w"); 
	if(fp==NULL){
		fputs("파일 오픈 오류",stdout) ;
		return ;
	}
	fwrite(&numOfData,sizeof(int),1,fp);
	for(i=0;i<numOfData;i++){
		fprintf(fp,"%s\n%s\n",phoneList[i]->name,phoneList[i]->phoneNum);
		free(phoneList[i]);
	}
	fputs("저장 완료",stdout); 
	fclose(fp);
}


void LoadDataFromFile(void){
	FILE *fp;
	phoneData *buf;
	int i;
	int j=0;
	fp=fopen("PhoneNumbers.txt","r");
	if(fp==NULL){
		fputs("파일 오픈 오류",stdout);
		return 0; 
	}
	
	fread(&numOfData,sizeof(int),1,fp);
	for(i=0; i<numOfData; i++){
		phoneList[i]=(phoneData*)malloc(sizeof(phoneData));
		fgets(phoneList[i]->name, NAME_LEN, fp);
		j=strlen(phoneList[i]->name);
		phoneList[i]->name[j-1]=0;
		
		fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);
		j=strlen(phoneList[i]->phoneNum);
		phoneList[i]->phoneNum[j-1]=0;
	}
	fputs("출력 완료",stdout); 
	fclose(fp);
}

void ChangePhoneData(void){
	char sName[NAME_LEN];
	char sNum[PHONE_LEN];
	int num[LIST_NUM]={0,};// 동명이인을 처리하기위한 배열 
	int i;
	int j=0; //동명이인을 처리하기 위한 변수 
	fputs("찾는 이름은?:",stdout);
	gets(sName);
	
	for(i=0;i<numOfData;i++){
		if(strcmp(sName,phoneList[i]->name)==0){
			num[j]=i;
			j++;
		}
	}	
	if(j==0){
		fputs("찾는 이름이 없습니다.",stdout); 
		return ;	
	}
	
	if(j>1){
		for(i=0;i<j;i++){
			printf("선택 %d:\n",i+1); 
			ShowPhoneInfoByPtr(phoneList[num[i]]);
		}
		fputs("선택 :",stdout); 
		scanf("%d",&j);
		getchar(); 
		i=num[j-1];
	}
	else{
		for(i=0;i<numOfData;i++){
			if(strcmp(sName,phoneList[i]->name)==0){
				break; 
			}
		}
	}
	fputs("변경할 전화번호는? ",stdout); 
	gets(sNum);
	strcpy(phoneList[i]->phoneNum,sNum);
	fputs("변경이 완료되었습니다.",stdout); 
	StoreDataToFileInStruct();
}


void StoreDataToFileInStruct(void){
	FILE *fp;
	int i;
	fp=fopen("PhoneNumbers.dat","w"); 
	if(fp==NULL){
		fputs("파일 오픈 오류",stdout) ;
		return 0;
	}
	for(i=0;i<numOfData;i++){
		fwrite(phoneList[i],sizeof(phoneData),1,fp);	
	}
	fputs("저장 완료",stdout); 
	fclose(fp);
}

void LoadDataFromFileInStruct(void){
	FILE *fp;
	phoneData *buf;
	int i;
	int j=0;
	fp=fopen("PhoneNumbers.dat","r");
	if(fp==NULL){
		fputs("파일 오픈 오류",stdout);
		return 0; 
	}
	while(1){
		buf=(phoneData*)malloc(sizeof(phoneData));
		fread(buf,sizeof(phoneData),1,fp);
		if(feof(fp)!=0)break;
		phoneList[numOfData]=buf;
//		printf("%s %s %d\n",phoneList[numOfData]->name,phoneList[numOfData]->phoneNum,numOfData);
		numOfData++;
	}
	fputs("출력 완료",stdout); 
	fclose(fp);
}

//end of file
