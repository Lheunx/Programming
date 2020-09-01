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



//end of file

