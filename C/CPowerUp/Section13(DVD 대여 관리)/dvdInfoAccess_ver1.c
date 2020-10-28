/* Name: dvdInfoAccess.c ver 1.0
* Content : dvd ���� ���� �� ���� �Լ����� ���� 
* Implementation : LHH
*
*Last Modified: 08/19
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
//	if(!IsRegistID(ID)){
		strcpy(pDvdInfo->ISBN,ISBN);
		strcpy(pDvdInfo->title,title);
		pDvdInfo->genre=genre;
		dvdList[idx]=pDvdInfo;
		pDvdInfo->numOfRentCus=0; 
		numOfDvd++;
	printf("����� �Ϸ�Ǿ����ϴ�."); 
//	}
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

/*�Լ� : int rentDVD(void)
*��� : DVD �뿩 
*��ȯ : 
*/

int RentDVD(){
	dvdInfo* ptr;
	dvdRentInfo rentInfo;
	char rDvd[ISBN_LEN];
	printf("�뿩 DVD ISBN �Է�: "); gets(rDvd);
	ptr=GetDvdPtrById(rDvd);
	
	if(ptr==NULL){
		printf("��ϵ��� ���� DVD�Դϴ�.");
		return 0; 
	}
	if(ptr->rentState == RENTED){
		printf("���� �뿩���Դϴ�. �뿩�� �Ұ����մϴ�.");
		return 0; 
	}
	
	printf("�뿩�� �����մϴ�. �뿩 ������ �����մϴ�.\n�뿩 �� ID �Է�: "); 
	gets(rentInfo.cusID);
	if(!IsRegistID(rentInfo.cusID)){
		printf("���� ���� �ƴմϴ�.");
		return 0; 
	}
	printf("�뿩 ��¥ �Է�: ");
	scanf("%d",&rentInfo.rentDay);
	ptr->rentState=RENTED;
//	memcpy(ptr->rentList[ptr->numOfRentCus],rentInfo,sizeof(dvdRentInfo));
	strcpy(ptr->rentList[ptr->numOfRentCus].cusID,rentInfo.cusID);
	ptr->rentList[ptr->numOfRentCus].rentDay=rentInfo.rentDay;
	ptr->numOfRentCus++;
	
}

/*�Լ� : int returnDVD(void)
*��� : DVD �ݳ� 
*��ȯ : 
*/
int returnDVD(void){
	dvdInfo* ptr;
	char rDvd[ISBN_LEN];
	printf("�ݳ� DVD ISBN �Է�: "); gets(rDvd);
	ptr=GetDvdPtrById(rDvd);
	
	if(ptr==NULL){
		printf("��ϵ��� ���� DVD�Դϴ�.");
		return 0; 
	}
	if(ptr->rentState != RENTED){
		printf("���� �뿩���� �ƴմϴ�. �ݳ��� �Ұ����մϴ�.");
		return 0; 
	} 
	ptr->rentState=RETURNED; 
	printf("�ݳ��� �Ϸ�Ǿ����ϴ�.");
}


/*�Լ� : int showDvdRentCus(void)
*��� : DVD �뿩 �� ��ȸ 
*��ȯ : 
*/
int showDvdRentCus(void){
	dvdInfo* ptr;
	int i;
	char rDvd[ISBN_LEN];
	printf("��ȸ DVD ISBN �Է�: "); gets(rDvd);
	ptr=GetDvdPtrById(rDvd);
	if(ptr==NULL){
		printf("��ϵ��� ���� DVD�Դϴ�.");
		return 0; 
	}
	if(ptr->numOfRentCus==0){
		printf("�뿩Ƚ���� 0���Դϴ�."); 
		return 0; 
	}
	for(i=0;i<ptr->numOfRentCus;i++){
		printf("\n�뿩��: %d\n",ptr->rentList[i].rentDay);
		ShowCustomerInfo(GetCusPtrById(ptr->rentList[i].cusID));
	}
}
//end of file

