/* Name : screenOut.c ver 1.3
* Content : �ܼ� ����� ���� �Լ� ���� 
* Implementation : LHH
* 1.1: ShowMenu�Լ��� ��ȭ��ȣ �˻�, ���� ��� �߰� 
* 1.2: ShowPhoneInfoByPtr �Լ� �߰� 
* 1.3: ShowMenu�Լ��� ��ȭ��ȣ ���� �߰� 
* Last modified 2020/08/11
*/
#include "common.h"
#include "phoneData.h"

/*�� ��: void ShowMenu(void)
�� ��: ������ ���� �޴� ���
�� ȯ: void 
*/

void ShowMenu(void){
	system("timeout 5");
	system("cls");
	
	puts("--------------�޴�--------------");
	puts("1. ��ȭ��ȣ �Է�"); 
	puts("2. ��ü ���� ���");
	puts("3. ��ȭ��ȣ �˻�");
	puts("4. ��ȭ��ȣ ����");
	puts("5. ��ȭ��ȣ ����");
	puts("6. ����");
	puts("--------------------------------");
	printf("���� >> "); 
}
/*�� ��: void ShowPhoneInfo(phoneData phone)
�� ��: �̸��� ��ȭ��ȣ ���� ���
�� ȯ: void
*/

void ShowPhoneInfo(phoneData phone){
	puts("��-------------------------");
	printf("�����̸�: %s \n",phone.name); 
	printf("������ȭ��ȣ: %s \n",phone.phoneNum);
	puts("��-------------------------");
}

void ShowPhoneInfoByPtr(phoneData *phone){
	puts("��-------------------------");
	printf("�����̸�: %s \n",phone->name); 
	printf("������ȭ��ȣ: %s \n",phone->phoneNum);
	puts("��-------------------------");
}

//end of file
