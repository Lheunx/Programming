///* Name: cusManager.c ver 1.0
//* Content : �� ���� ���� ó�� �Լ����� ���� 
//* Implementation : LHH
//*
//*Last Modified: 08/18
//*/
//#include "common.h"
//#include "cusInfo.h"
//#include "cusInfoAccess.h"
//#include "screenOut.h"
//
///*�Լ� : void RegistCustomer(void)
//* ��� : �ű� ȸ�� ����
//* ��ȯ: void
//*/
////ID_LEN 10
//////NAME_LEN 30
////PHONE_LEN 30
//void RegistCustomer(void){
//	char ID[10];
//	char NAME[30];
//	char PHONE[30];
//	printf("ID �Է�: ");gets(ID);
//	if(IsRegistID(ID)){
//		puts("ID�� �ߺ��˴ϴ�");
//		return 0; 
//	}
//	printf("�̸� �Է�: ");gets(NAME);
//	printf("��ȣ �Է�: ");gets(PHONE);
//	AddCusInfo(ID,NAME,PHONE);
//} 
//
///* �Լ� : void SearchCusInfo(void)
//* ��� : ID�� ���� ȸ�� ���� �˻� 
//* ��ȯ : void
//*/
//void SearchCusInfo(void){
//	char ID[10];
//	cusInfo* ptr;
//	printf("�˻��� ID�Է�:");gets(ID);
//	ptr=GetCusPtrById(ID);
//	if(ptr==NULL){
//		puts("ID�� �������� �ʽ��ϴ�.");
//		return 0; 
//	}
//	ShowCustomerInfo(ptr);
//} 
////end of file
