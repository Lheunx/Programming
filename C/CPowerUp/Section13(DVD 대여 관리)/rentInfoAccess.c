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
	SaveRentInfo();
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

/*�Լ� : int SaveRentInfo(void)
*��� : DvdInfo���� ���� 
*��ȯ : ���� 1, �ƴϸ� 0 ��ȯ
*/
int SaveRentInfo(void){
	int i;
	FILE* fp;
	fp=fopen("data/RentBackup.dat","w");
	if(fp==NULL){
		printf("���� ���� ����\n"); 
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
	puts("���� ���� ����"); 
}

/*�Լ� : int LoadRentInfo(void)
*��� : RentInfo���� �ε� 
*��ȯ : ���� 1, �ƴϸ� 0 ��ȯ
*/
int LoadRentInfo(void){
	int i;
	char cusID[ID_LEN];
	char ISBN[ISBN_LEN];
	unsigned int rentDay;
	FILE* fp;
	fp=fopen("data/RentBackup.dat","r");
	if(fp==NULL){
		printf("���� ���� ����\n"); 
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
	puts("���� �ε� ����"); 
}
//end of file
