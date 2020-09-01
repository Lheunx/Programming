/* Name: main.c ver 1.2
* Content : DVD �뿩 ���� �����׷� 
* Implementation : LHH
* 1.1 : DVD ���, �˻� ��� �߰� 
* 1.2 : DVD �뿩 �ݳ� �߰� 
*Last Modified: 08/20
*/

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"

enum{CUS_REGIST=1,CUS_SEARCH,DVD_REGIST,DVD_SEARCH,DVD_RENT,DVD_RETURN,DVD_RENT_CUS_PRINT, DVD_RENT_CUS_DAY_PRINT,QUIT};

int main(void){
	int inputMenu=0;
	
	while(1){
		ShowMenu();
		scanf("%d", &inputMenu);
		fflush(stdin);
		
		switch(inputMenu){
			case CUS_REGIST:
				RegistCustomer();
				break;
			case CUS_SEARCH:
				SearchCusInfo();
				break;
			case DVD_REGIST:
				RegistDvd();
				break;
			case DVD_SEARCH:
				SearchDvdInfo();
				break;
			case DVD_RENT:
				RentDVD();
				break;
			case DVD_RETURN:
				returnDVD();
				break;
			case DVD_RENT_CUS_PRINT:
				showDvdRentCus();
				break;
			case DVD_RENT_CUS_DAY_PRINT:
				showDvdRentCusDay();
				break;
		}
		if(inputMenu==QUIT){
			puts("�̿��� �ּż� �����մϴ�~");
			break; 
		}
	}
	return 0;
}
//end of file
