/* Name: cusManager.c ver 1.0
* Content : �� ���� ���� ó�� �Լ����� ���� 
* Implementation : LHH
*
*Last Modified: 08/18
*/
#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

/*�Լ� : void RegistDvd(void)
* ��� : �ű� DVD ��� 
* ��ȯ: void
*/
//ID_LEN 10
////NAME_LEN 30
//PHONE_LEN 30
void RegistDvd(void){
	char ISBN[ISBN_LEN];
	char TITLE[TITLE_LEN];
	int genre;
	printf("DVD ISBN �Է�: ");gets(ISBN);
	if(IsRegistISBN(ISBN)){
		puts("ISBN�� �ߺ��˴ϴ�");
		return 0; 
	}
	printf("DVD ���� �Է�: ");gets(TITLE);
	printf("�帣 �Է�(1: �׼� 2: �ڹ� 3: SF 4: �θǽ�) :");scanf("%d",&genre); 
	AddDvdInfo(ISBN,TITLE,genre);
} 

/* �Լ� : void SearchDvdInfo(void)
* ��� : ID�� ���� ȸ�� ���� �˻� 
* ��ȯ : void
*/
void SearchDvdInfo(void){
	char ISBN[ISBN_LEN];
	dvdInfo* ptr;
	printf("�˻��� ID�Է�:");gets(ISBN);
	ptr=GetDvdPtrById(ISBN);
	if(ptr==NULL){
		puts("ID�� �������� �ʽ��ϴ�.");
		return 0; 
	}
	ShowDvdInfo(ptr);
} 

/*�Լ� : void rentDVD(void)
*��� : DVD �뿩 
*��ȯ : 
*/

void RentDVD(void){
	char ISBN[ISBN_LEN];
	int registDVD;
	int registCus;
	int rentSte;
	
	char cusID[ID_LEN];
	unsigned int rentDay;
	
	//1 �뿩�� DVD ISBN �Է� �� ���� 
	printf("�뿩 DVD ISBN �Է�: "); gets(ISBN);
	registDVD=IsRegistISBN(ISBN);
	if(registDVD==0){
		puts("��ϵ��� ���� ISBN �Դϴ�.");
		getchar();
		return; 
	} 
	
	// 2 �뿩 ������ �������� Ȯ��
	rentSte=GetDVDRentState(ISBN);
	if(rentSte==RENTED){
		puts("�뿩 ���̶� �뿩�� �Ұ����մϴ�.");
		getchar();
		return; 
	} 
	
	//3  �뿩 ���� ����
	 
	printf("�뿩�� �����մϴ�. �뿩 ������ �����մϴ�.\n�뿩 �� ID �Է�: "); 
	gets(cusID);
	
	registCus=IsRegistID(cusID); 
	if(registCus==0){
		puts("���� ���� �ƴմϴ�.");
		getchar();
		return; 
	}
	
	printf("�뿩 ��¥ �Է�: ");
	scanf("%u",&rentDay);
	fflush(stdin);
	
	SetDVDRented(ISBN, cusID, rentDay);
	puts("�뿩�� �Ϸ�Ǿ����ϴ�.");
	getchar(); 
}

/*�Լ� : int returnDVD(void)
*��� : DVD �ݳ� 
*��ȯ : 
*/
int returnDVD(void){
	char ISBN[ISBN_LEN];
	int registDVD;
	int rentSte;
	
	//1. �ݳ��� DVD ISBN �Է� �� ���� 
	
	printf("�ݳ� DVD ISBN �Է�: "); gets(ISBN);
	registDVD=IsRegistISBN(ISBN);
	if(registDVD==0){
		puts("��ϵ��� ���� ISBN�Դϴ�.");
		getchar();
		return; 
	}
	
	//2. �ݹ��� ������ ������� Ȯ�� 
	rentSte=GetDVDRentState(ISBN);
	if(rentSte==RETURNED){
		puts("�뿩���� ���� DVD �Դϴ�.");
		getchar();
		return; 
	}
	
	
	//3. �ݳ� ���� ����
	SetDVDReturned(ISBN);
	puts("�ݳ��� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

/*�Լ� : int showDvdRentCus(void)
*��� : DVD �뿩 �� ��ȸ 
*��ȯ : 
*/
int showDvdRentCus(void){
	char ISBN[ISBN_LEN];
	dvdInfo* ptrDVDInfo;
	
	//ã�� ����� ISBN �Է�
	fputs("ã�� ISBN �Է�: ", stdout);
	gets(ISBN);
	
	ptrDVDInfo=GetDvdPtrById(ISBN);
	if(ptrDVDInfo==0){
		puts("�������� �ʴ� ISBN �Դϴ�.");
		getchar();
		return; 
	} 
	PrintOutRentAllCusInfo(ISBN);
	
	puts("��ȸ�� �Ϸ��Ͽ����ϴ�.");
	getchar(); 
}

int showDvdRentCusDay(void){
	char ID[ID_LEN];
	unsigned int start,end;
	cusInfo* ptrCusInfo;
	
	printf("ã�� ID �Է�: ");
	gets(ID);
	
	ptrCusInfo=GetCusPtrById(ID);
	if(ptrCusInfo==0){
		puts("��ϵ��� ���� ID �Դϴ�.");
		getchar();
		return; 
	}
	
	printf("�뿩 �Ⱓ �Է�:");
	scanf("%d %d",&start,&end);
	if(start>end){
		puts("��¥�� �߸� �Է��ϼ̽��ϴ�.");
		getchar();
		return; 
	}
	PrintOutCusALlRentInfo(ID,start,end); 
	puts("��ȸ�� �Ϸ��Ͽ����ϴ�.");
	getchar(); 
}

//end of file
