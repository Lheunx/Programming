/* Name: screenOut.c ver 1.2
* Content : 콘솔 출력을 위한 함수들의 정의 
* Implementation : LHH
* 1.1: DVD등록, DVD 검색 추가 showDVDINFO 추가 
* 1.2: DVD 대여,반납,대여고객 전체 조회 추가 
*Last Modified: 08/20
*/

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

/* 프로그램 사용을 위한 메뉴 */
void ShowMenu(void){
	system("TIMEOUT 5");
	system("cls");// stdlib.h
	
	
	printf("---------메뉴------------\n"); 
	printf("1.신규가입 \n"); 
	printf("2.고객검색 \n");
	printf("---------------------\n"); 
	printf("3.DVD 등록 \n");
	printf("4.DVD 검색 \n");
	printf("---------------------\n"); 
	printf("5.DVD 대여 \n");
	printf("6.DVD 반납 \n");
	printf("---------------------\n"); 
	printf("7.DVD 대여고객 전체 조회 \n");
	printf("8.고객 대여 DVD 전체 조회 \n"); 
	printf("9.종료 \n"); 
	printf("------------------------\n");
	printf("선택 >"); 
} 

void ShowCustomerInfo(cusInfo * pCus){
	
	printf("-------------------------\n");
	printf("I > ID : %s \n", pCus->ID);
	printf("I > 이름 : %s \n", pCus->name);
	printf("I > 전화번호 : %s \n", pCus->phoneNum);
	printf("-------------------------\n\n");
	
	getchar();
} 

void ShowDvdInfo(dvdInfo * pDvd){
	
	printf("-------------------------\n");
	printf("I > ID : %s \n", pDvd->ISBN);
	printf("I > 이름 : %s \n", pDvd->title);
	printf("I > 장르 : ");
	switch (pDvd->genre){
		case ACTION:
			printf("액션\n");
			break; 
		case COMIC:
			printf("코믹\n");
			break;
		case SF:
			printf("SF\n");
			break;
		case ROMANTIC:
			printf("로맨틱\n");
			break;
	}
//	printf("I > 장르 1: 액션 2: 코믹 3:SF 4:로맨틱 : %d \n", pDvd->genre);
	printf("-------------------------\n\n");
	
	getchar();
} 
//end of file
