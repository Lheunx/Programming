/* Name: screenOut.c ver 1.2
* Content : �ܼ� ����� ���� �Լ����� ���� 
* Implementation : LHH
* 1.1: DVD���, DVD �˻� �߰� showDVDINFO �߰� 
* 1.2: DVD �뿩,�ݳ�,�뿩�� ��ü ��ȸ �߰� 
*Last Modified: 08/20
*/

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

/* ���α׷� ����� ���� �޴� */
void ShowMenu(void){
	system("TIMEOUT 5");
	system("cls");// stdlib.h
	
	
	printf("---------�޴�------------\n"); 
	printf("1.�ű԰��� \n"); 
	printf("2.���˻� \n");
	printf("---------------------\n"); 
	printf("3.DVD ��� \n");
	printf("4.DVD �˻� \n");
	printf("---------------------\n"); 
	printf("5.DVD �뿩 \n");
	printf("6.DVD �ݳ� \n");
	printf("---------------------\n"); 
	printf("7.DVD �뿩�� ��ü ��ȸ \n");
	printf("8.�� �뿩 DVD ��ü ��ȸ \n"); 
	printf("9.���� \n"); 
	printf("------------------------\n");
	printf("���� >"); 
} 

void ShowCustomerInfo(cusInfo * pCus){
	
	printf("-------------------------\n");
	printf("I > ID : %s \n", pCus->ID);
	printf("I > �̸� : %s \n", pCus->name);
	printf("I > ��ȭ��ȣ : %s \n", pCus->phoneNum);
	printf("-------------------------\n\n");
	
	getchar();
} 

void ShowDvdInfo(dvdInfo * pDvd){
	
	printf("-------------------------\n");
	printf("I > ID : %s \n", pDvd->ISBN);
	printf("I > �̸� : %s \n", pDvd->title);
	printf("I > �帣 : ");
	switch (pDvd->genre){
		case ACTION:
			printf("�׼�\n");
			break; 
		case COMIC:
			printf("�ڹ�\n");
			break;
		case SF:
			printf("SF\n");
			break;
		case ROMANTIC:
			printf("�θ�ƽ\n");
			break;
	}
//	printf("I > �帣 1: �׼� 2: �ڹ� 3:SF 4:�θ�ƽ : %d \n", pDvd->genre);
	printf("-------------------------\n\n");
	
	getchar();
} 
//end of file
