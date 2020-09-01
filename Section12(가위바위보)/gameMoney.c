/* Name: gameMoney.c ver 1.0
* Content : ���ӸӴ� �Լ� �ڵ� 
* Implementation : LHH
*
*Last Modified: 08/13
*/
#include "common.h"

static int comMoney;
static int youMoney;
static int gameTableMoney;

void setYouMoney(){
	int youInputMoney;
	printf("#����� ���ӸӴϸ� �Է��ϼ���:"); 
	while(1){
		scanf("%d",&youInputMoney);
		if(youInputMoney==0){
			printf("0 �̻��� ���� �Է��Ͻÿ�") ;
		}
		else break;
	}
	SetYouMoney2(youInputMoney);
}

void setGameTableMoney(){
	int gameMoney;
	while(1){
		printf("$$$$$$ �ǵ� �Է� :"); 
		scanf("%d",&gameMoney);
		if(gameMoney > comMoney){
			printf("��ǻ�� �Ӵ�: %d �ǵ� : %d ��ǻ�Ͱ� ������ �ݾ׺��� ���� ���� �Է��ϼ���.\n",comMoney,gameMoney); 
		}
		else if(gameMoney > youMoney){
			printf("����� �Ӵ�: %d �ǵ� : %d ����ڰ� ������ �ݾ׺��� ���� ���� �Է��ϼ���.\n",youMoney,gameMoney); 
		}
		else break;
	}
	gameTableMoney=gameMoney;
}

void youWinMoney(void){
	comMoney-=gameTableMoney;
	youMoney+=gameTableMoney;
}
void comWinMoney(void){
	comMoney+=gameTableMoney;
	youMoney-=gameTableMoney;
}
int getComMoney(void){
	return comMoney;
}
int getYouMoney(void){
	return youMoney;
}

void SetYouMoney2(int a){
	youMoney=a;
}
void SetComMoney(int a){
	comMoney=a;
}

//end of file
