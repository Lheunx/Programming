/* Name: dvdInfoAccess.c ver 1.1
* Content : dvd ���� ���� �� ���� �Լ����� ���� 
* Implementation : LHH
* 1.1 : ����� ����ϰ� ���� 
*Last Modified: 09/01
*/

#include "common.h"
#include "dvdInfo.h"

#define MAX_CUSTOMER 100

static dvdInfo *dvdList[MAX_CUSTOMER]; // �����͹迭 cusInfo ������ ������ �ּҰ� ���� 
static int numOfDvd=0;
/* �Լ�: int AddDVDInfo(char *ID, char * name, char* num)
* ��� : dvdInfo �Ҵ� �� ����
* ��ȯ : ���� �� '��ϵ� ������ ����', ���� �� 0 ��ȯ
*/
int AddDvdInfo(char * ISBN, char * title, int genre){
	int idx;
	idx=numOfDvd;
	dvdInfo* pDvdInfo;
	
	if(numOfDvd >= MAX_CUSTOMER)
		return 0; // �Է� ���� 
	pDvdInfo = (dvdInfo *)malloc(sizeof(dvdInfo));
	strcpy(pDvdInfo->ISBN,ISBN);
	strcpy(pDvdInfo->title,title);
	pDvdInfo->genre=genre;
	dvdList[idx]=pDvdInfo;
//	pDvdInfo->numOfRentCus=0; 
	pDvdInfo->rentState=RETURNED;
	numOfDvd++;
	SaveDvdInfo();
	printf("����� �Ϸ�Ǿ����ϴ�."); 
	
	return numOfDvd;
} 

/*�Լ� : dvdInfo * GetDvdPtrByISBN(char * ISBN)
* ��� : �ش� ISBN�� ������ ��� �ִ� ������ ������ ��ȯ
*�� ȯ: ��� �ȵ� ISBN�� ��� NULL ������ ��ȯ
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

/*�Լ� : int IsRegistID(char*ID)
*��� : ��� �� ISBN ���� Ȯ��
*��ȯ : ��� �Ǿ����� 1, �ƴϸ� 0 ��ȯ
*/
int IsRegistISBN(char * ISBN){
	dvdInfo * pDvd = GetDvdPtrById(ISBN);
	if(pDvd==0)
		return 0;
	else
		return 1;
} 



/* �Լ� : int SetDVDRented(char*ISBN, char*cusID, int rentDay)
* ���: �뿩 ���·� ����
*��ȯ: ���� 1 ,���� 0
*/
int SetDVDRented(char *ISBN, char * cusID, int rentDay){
	int rentCusNum;
	dvdInfo * pDVD = GetDvdPtrById(ISBN);
	if(pDVD==0)return 0;
	
	pDVD->rentState=RENTED;
	return 1;
} 

/* �Լ� : int SetDVDReturned (char * ISBN)
* ��� : �뿩 ���� ���·� ����
* ��ȯ : ���� 1, ���� 0
* Ư�̻��� : ���ڰ� ������ �Լ�
*/
int SetDVDReturned(char * ISBN){
	dvdInfo * pDVD= GetDvdPtrById(ISBN);
	
	if(pDVD==0)return 0;
	
	pDVD->rentState=RETURNED;
	return 1;
} 

/* �Լ�: int GetDVDRentState(char * ISBN)
* ��� : ���� �뿩 ���� ��ȯ
* �� ȯ: RETURNED, RENTED, �������� �ʴ� ISBN�� ��� -1 ��ȯ
*/
int GetDVDRentState(char * ISBN){
	dvdInfo * pDVD=GetDvdPtrById(ISBN);
	if(pDVD==0)return 0;
	return pDVD->rentState;
} 

/*�Լ� : int SaveDvdInfo(void)
*��� : DvdInfo���� ���� 
*��ȯ : ���� 1, �ƴϸ� 0 ��ȯ
*/
int SaveDvdInfo(void){
	int i;
	FILE* fp;
	fp=fopen("data/DvdBackup.dat","w");
	if(fp==NULL){
		printf("���� ���� ����\n"); 
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
	puts("���� ���� ����"); 
}

/*�Լ� : int LoadDvdInfo(void)
*��� : DvdInfo���� �ε� 
*��ȯ : ���� 1, �ƴϸ� 0 ��ȯ
*/
int LoadDvdInfo(void){
	int i;
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	int rentState;// �뿩 ���� ����
	dvdInfo* pdvdInfo;
	FILE* fp;
	fp=fopen("data/DvdBackup.dat","r");
	if(fp==NULL){
		printf("���� ���� ����\n"); 
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
	puts("���� �ε� ����"); 
}

//end of file

