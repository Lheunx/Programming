/* Name: rentInfoAccess.c ver 1.0
* Content : ��ȭ DVD �뿩 ���� ����Ʈ 
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

/*�Լ�: void AddRentList(char * ISBN, char * cusID, int rentDay)
* ���: �뿩 ������ ����
* ��ȯ: void
*/
void AddRentList(char*ISBN, char*cusID, int rentDay){
	strcpy(rentList[numOfRentCus].cusID,cusID);
	strcpy(rentList[numOfRentCus].ISBN,ISBN);
	rentList[numOfRentCus].rentDay=rentDay;
	numOfRentCus++;
} 

/*�Լ�: void PrintOutRentAllCusInfo(char * ISBN)
*���: Ư�� ISBN�� DVD �뿩 ���� ��ü ���
*��ȯ: void
*/
void PrintOutRentAllCusInfo(char * ISBN){
	int i;
	for(i=0;i<numOfRentCus;i++){
		if(strcmp(rentList[i].ISBN,ISBN)==0){
			printf("�뿩��: %d\n",rentList[i].rentDay);
			ShowCustomerInfo(GetCusPtrById(rentList[i].cusID));
		}
	}
} 

/* �Լ�: void PrintOUtCusALlRentInfo(char *, unsigned int, unsigned int)
* ���: ���� �Ⱓ �ȿ� �̷��� Ư�� ���� DVD �뿩 ���� ���
*��ȯ : void
*/
void PrintOutCusALlRentInfo(char * ID, unsigned int start, unsigned int end){
	int i; 
	for(i=0;i<numOfRentCus;i++){
		if(strcmp(rentList[i].cusID,ID)==0 && rentList[i].rentDay >= start && rentList[i].rentDay <= end){
			printf("-------------------------\n"); 
			printf("| ��ISBN: %s\n",rentList[i].ISBN);
			printf("| ���뿩��: %u\n",rentList[i].rentDay);
			printf("-------------------------\n");
		}
	}
} 
//end of file
