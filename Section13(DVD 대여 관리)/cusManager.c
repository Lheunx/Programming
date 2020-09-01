///* Name: cusManager.c ver 1.0
//* Content : 고객 관련 업무 처리 함수들의 정의 
//* Implementation : LHH
//*
//*Last Modified: 08/18
//*/
//#include "common.h"
//#include "cusInfo.h"
//#include "cusInfoAccess.h"
//#include "screenOut.h"
//
///*함수 : void RegistCustomer(void)
//* 기능 : 신규 회원 가입
//* 반환: void
//*/
////ID_LEN 10
//////NAME_LEN 30
////PHONE_LEN 30
//void RegistCustomer(void){
//	char ID[10];
//	char NAME[30];
//	char PHONE[30];
//	printf("ID 입력: ");gets(ID);
//	if(IsRegistID(ID)){
//		puts("ID가 중복됩니다");
//		return 0; 
//	}
//	printf("이름 입력: ");gets(NAME);
//	printf("번호 입력: ");gets(PHONE);
//	AddCusInfo(ID,NAME,PHONE);
//} 
//
///* 함수 : void SearchCusInfo(void)
//* 기능 : ID를 통한 회원 정보 검색 
//* 반환 : void
//*/
//void SearchCusInfo(void){
//	char ID[10];
//	cusInfo* ptr;
//	printf("검색할 ID입력:");gets(ID);
//	ptr=GetCusPtrById(ID);
//	if(ptr==NULL){
//		puts("ID가 존재하지 않습니다.");
//		return 0; 
//	}
//	ShowCustomerInfo(ptr);
//} 
////end of file
