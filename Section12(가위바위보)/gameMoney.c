/* Name: gameMoney.c ver 1.0
* Content : 게임머니 함수 코드 
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
	printf("#당신의 게임머니를 입력하세요:"); 
	while(1){
		scanf("%d",&youInputMoney);
		if(youInputMoney==0){
			printf("0 이상의 값을 입력하시오") ;
		}
		else break;
	}
	SetYouMoney2(youInputMoney);
}

void setGameTableMoney(){
	int gameMoney;
	while(1){
		printf("$$$$$$ 판돈 입력 :"); 
		scanf("%d",&gameMoney);
		if(gameMoney > comMoney){
			printf("컴퓨터 머니: %d 판돈 : %d 컴퓨터가 소유한 금액보다 적은 값을 입력하세요.\n",comMoney,gameMoney); 
		}
		else if(gameMoney > youMoney){
			printf("사용자 머니: %d 판돈 : %d 사용자가 소유한 금액보다 적은 값을 입력하세요.\n",youMoney,gameMoney); 
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
