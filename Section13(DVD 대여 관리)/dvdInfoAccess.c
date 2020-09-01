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
	strcpy(pDvdInfo->ISBN,ISBN);
	strcpy(pDvdInfo->title,title);
	pDvdInfo->genre=genre;
	dvdList[idx]=pDvdInfo;
//	pDvdInfo->numOfRentCus=0; 
	pDvdInfo->rentState=RETURNED;
	numOfDvd++;
	printf("����� �Ϸ�Ǿ����ϴ�."); 
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
	AddRentList(ISBN,cusID,rentDay);
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




//end of file

