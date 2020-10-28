/* Name : main.c ver 1.3
* Content : main �Լ� 
* Implementation : LHH
* 1.1: SEARCH,DELETE ��� �߰� 
* 1.3: ���Ͽ� ���� �ҷ����� �߰� 
* 1.3: CHANGE �߰� 
* 1.4: ���� �ε� �Լ� ���� 
* Last modified 2020/08/11
*/

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum{INPUT=1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT};
/*�� ��: int main(void)
*�� ��: ����� ���� ó��
*�� ȯ: ���� ���� �� 0
*/

int main(){
	LoadDataFromFileInStruct();
	int inputMenu = 0;
	
	while(1){
		ShowMenu();
		fputs("�����ϼ���: ",stdout);
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
			puts("�̿��� �ּż� ������~");
			break; 
		}
	}	
	return 0;
}
// end of File
