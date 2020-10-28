/* Name: cusInfoAccess.c ver 1.0
* Content : �� ���� ���� �� ���� �Լ����� ���� 
* Implementation : LHH
*
*Last Modified: 08/18
*/

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo *cusList[MAX_CUSTOMER]; // �����͹迭 cusInfo ������ ������ �ּҰ� ���� 
static int numOfCustomer=0;
/* �Լ�: int AddCusInfo(char *ID, char * name, char* num)
* ��� : cusInfo �Ҵ� �� ����
* ��ȯ : ���� �� '��ϵ� ������ ����', ���� �� 0 ��ȯ
*/
int AddCusInfo(char * ID, char * name, char * num){
	int idx;
	idx=numOfCustomer;
	cusInfo* pcusInfo;
	
	if(numOfCustomer >= MAX_CUSTOMER)
		return 0; // �Է� ���� 
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

/*�Լ� : cusInfo * GetCusPtrById(char * ID)
* ��� : �ش� ID�� ������ ��� �ִ� ������ ������ ��ȯ
*�� ȯ: ��� �ȵ� ID�� ��� NULL ������ ��ȯ
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

/*�Լ� : int IsRegistID(char*ID)
*��� : ���� �� ID ���� Ȯ��
*��ȯ : ���� �Ǿ����� 1, �ƴϸ� 0 ��ȯ
*/
int IsRegistID(char * ID){
	cusInfo * pCus = GetCusPtrById(ID);
	if(pCus==0)
		return 0;
	else
		return 1;
} 

/*�Լ� : int SaveCusInfo(void)
*��� : cusInfo���� ���� 
*��ȯ : ���� 1, �ƴϸ� 0 ��ȯ
*/
int SaveCusInfo(void){
	int i;
	FILE* fp;
	fp=fopen("data/cusBackup.dat","w");
	if(fp==NULL){
		printf("���� ���� ����\n"); 
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
	puts("���� ���� ����"); 
}

/*�Լ� : int LoadCusInfo(void)
*��� : cusInfo���� �ε� 
*��ȯ : ���� 1, �ƴϸ� 0 ��ȯ
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
		printf("���� ���� ����\n"); 
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
	puts("���� �ε� ����"); 
}

//end of file

