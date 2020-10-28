/* Name : main.c ver 1.3
* Content : main 함수 
* Implementation : LHH
* 1.1: SEARCH,DELETE 기능 추가 
* 1.3: 파일에 저장 불러오기 추가 
* 1.3: CHANGE 추가 
* 1.4: 저장 로드 함수 변경 
* Last modified 2020/08/11
*/

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum{INPUT=1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT};
/*함 수: int main(void)
*기 능: 사용자 선택 처리
*반 환: 정상 종료 시 0
*/

int main(){
	LoadDataFromFileInStruct();
	int inputMenu = 0;
	
	while(1){
		ShowMenu();
		fputs("선택하세요: ",stdout);
		scanf("%d", &inputMenu);
		fflush(stdin);
		
		switch(inputMenu){
			case INPUT:
				InputPhoneData();				
				break;
			case SHOWALL:
				ShowAllData();
				break;
			case SEARCH:
				SearchPhoneData();
				break;
			case DELETE:
				DeletePhoneData();
				break;
			case CHANGE:
				ChangePhoneData();
				break;
		}
		if(inputMenu==QUIT){
			StoreDataToFileInStruct();
			puts("이용해 주셔서 고마워요~");
			break; 
		}
	}	
	return 0;
}
// end of File
