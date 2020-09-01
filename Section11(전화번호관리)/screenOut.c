/* Name : screenOut.c ver 1.3
* Content : 콘솔 출력을 위한 함수 정의 
* Implementation : LHH
* 1.1: ShowMenu함수에 전화번호 검색, 삭제 기능 추가 
* 1.2: ShowPhoneInfoByPtr 함수 추가 
* 1.3: ShowMenu함수에 전화번호 변경 추가 
* Last modified 2020/08/11
*/
#include "common.h"
#include "phoneData.h"

/*함 수: void ShowMenu(void)
기 능: 선택을 위한 메뉴 출력
반 환: void 
*/

void ShowMenu(void){
	system("timeout 5");
	system("cls");
	
	puts("--------------메뉴--------------");
	puts("1. 전화번호 입력"); 
	puts("2. 전체 정보 출력");
	puts("3. 전화번호 검색");
	puts("4. 전화번호 삭제");
	puts("5. 전화번호 변경");
	puts("6. 종료");
	puts("--------------------------------");
	printf("선택 >> "); 
}
/*함 수: void ShowPhoneInfo(phoneData phone)
기 능: 이름과 전화번호 정보 출력
반 환: void
*/

void ShowPhoneInfo(phoneData phone){
	puts("┏-------------------------");
	printf("┃▶이름: %s \n",phone.name); 
	printf("┃▶전화번호: %s \n",phone.phoneNum);
	puts("┗-------------------------");
}

void ShowPhoneInfoByPtr(phoneData *phone){
	puts("┏-------------------------");
	printf("┃▶이름: %s \n",phone->name); 
	printf("┃▶전화번호: %s \n",phone->phoneNum);
	puts("┗-------------------------");
}

//end of file
