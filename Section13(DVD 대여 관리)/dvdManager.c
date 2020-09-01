/* Name: cusManager.c ver 1.0
* Content : 고객 관련 업무 처리 함수들의 정의 
* Implementation : LHH
*
*Last Modified: 08/18
*/
#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

/*함수 : void RegistDvd(void)
* 기능 : 신규 DVD 등록 
* 반환: void
*/
//ID_LEN 10
////NAME_LEN 30
//PHONE_LEN 30
void RegistDvd(void){
	char ISBN[ISBN_LEN];
	char TITLE[TITLE_LEN];
	int genre;
	printf("DVD ISBN 입력: ");gets(ISBN);
	if(IsRegistISBN(ISBN)){
		puts("ISBN이 중복됩니다");
		return 0; 
	}
	printf("DVD 제목 입력: ");gets(TITLE);
	printf("장르 입력(1: 액션 2: 코믹 3: SF 4: 로맨스) :");scanf("%d",&genre); 
	AddDvdInfo(ISBN,TITLE,genre);
} 

/* 함수 : void SearchDvdInfo(void)
* 기능 : ID를 통한 회원 정보 검색 
* 반환 : void
*/
void SearchDvdInfo(void){
	char ISBN[ISBN_LEN];
	dvdInfo* ptr;
	printf("검색할 ID입력:");gets(ISBN);
	ptr=GetDvdPtrById(ISBN);
	if(ptr==NULL){
		puts("ID가 존재하지 않습니다.");
		return 0; 
	}
	ShowDvdInfo(ptr);
} 

/*함수 : void rentDVD(void)
*기능 : DVD 대여 
*반환 : 
*/

void RentDVD(void){
	char ISBN[ISBN_LEN];
	int registDVD;
	int registCus;
	int rentSte;
	
	char cusID[ID_LEN];
	unsigned int rentDay;
	
	//1 대여할 DVD ISBN 입력 및 검증 
	printf("대여 DVD ISBN 입력: "); gets(ISBN);
	registDVD=IsRegistISBN(ISBN);
	if(registDVD==0){
		puts("등록되지 않은 ISBN 입니다.");
		getchar();
		return; 
	} 
	
	// 2 대여 가능한 상태인지 확인
	rentSte=GetDVDRentState(ISBN);
	if(rentSte==RENTED){
		puts("대여 중이라 대여가 불가능합니다.");
		getchar();
		return; 
	} 
	
	//3  대여 절차 진행
	 
	printf("대여가 가능합니다. 대여 과정을 진행합니다.\n대여 고객 ID 입력: "); 
	gets(cusID);
	
	registCus=IsRegistID(cusID); 
	if(registCus==0){
		puts("가입 고객이 아닙니다.");
		getchar();
		return; 
	}
	
	printf("대여 날짜 입력: ");
	scanf("%u",&rentDay);
	fflush(stdin);
	
	SetDVDRented(ISBN, cusID, rentDay);
	puts("대여가 완료되었습니다.");
	getchar(); 
}

/*함수 : int returnDVD(void)
*기능 : DVD 반납 
*반환 : 
*/
int returnDVD(void){
	char ISBN[ISBN_LEN];
	int registDVD;
	int rentSte;
	
	//1. 반납할 DVD ISBN 입력 및 검증 
	
	printf("반납 DVD ISBN 입력: "); gets(ISBN);
	registDVD=IsRegistISBN(ISBN);
	if(registDVD==0){
		puts("등록되지 않은 ISBN입니다.");
		getchar();
		return; 
	}
	
	//2. 반밥이 가능한 대상인지 확인 
	rentSte=GetDVDRentState(ISBN);
	if(rentSte==RETURNED){
		puts("대여되지 않은 DVD 입니다.");
		getchar();
		return; 
	}
	
	
	//3. 반납 절차 진행
	SetDVDReturned(ISBN);
	puts("반납이 완료되었습니다.");
	getchar();
}

/*함수 : int showDvdRentCus(void)
*기능 : DVD 대여 고객 조회 
*반환 : 
*/
int showDvdRentCus(void){
	char ISBN[ISBN_LEN];
	dvdInfo* ptrDVDInfo;
	
	//찾을 대상의 ISBN 입력
	fputs("찾는 ISBN 입력: ", stdout);
	gets(ISBN);
	
	ptrDVDInfo=GetDvdPtrById(ISBN);
	if(ptrDVDInfo==0){
		puts("존재하지 않는 ISBN 입니다.");
		getchar();
		return; 
	} 
	PrintOutRentAllCusInfo(ISBN);
	
	puts("조회를 완료하였습니다.");
	getchar(); 
}

int showDvdRentCusDay(void){
	char ID[ID_LEN];
	unsigned int start,end;
	cusInfo* ptrCusInfo;
	
	printf("찾는 ID 입력: ");
	gets(ID);
	
	ptrCusInfo=GetCusPtrById(ID);
	if(ptrCusInfo==0){
		puts("등록되지 않은 ID 입니다.");
		getchar();
		return; 
	}
	
	printf("대여 기간 입력:");
	scanf("%d %d",&start,&end);
	if(start>end){
		puts("날짜를 잘못 입력하셨습니다.");
		getchar();
		return; 
	}
	PrintOutCusALlRentInfo(ID,start,end); 
	puts("조회를 완료하였습니다.");
	getchar(); 
}

//end of file
