/* Name: game.c ver 2.0
* Content : ���� ���� �Լ� ���� 
* Implementation : LHH
* 1.1 ChoiceOfCom, ChoiceOfYou, WhoIsWinner �Լ� �ϼ��� 
* 2.0 ChoiceOfCom, ChoiceOfYou, WhoIsWinner �Լ� ������������ ���� 
* 2.1 �·� �ý��� �߰� 
* 2.2 ���ӸӴ� �ý��� �߰� 
*Last Modified: 08/13
*/

#include <time.h>
#include "common.h"
#include "game.h"
#include "gameTimes.h"

/*�Լ�: int ChoiceOfCom(void)
* ���: ������ ���� ��ȯ
* ��ȯ: 0~99 ������ ���� ��ȯ
*
*/
int ChoiceOfCom(void){
	srand((unsigned int)time(NULL));
	return (rand()%3+1);
} 

/*�Լ�: int ChoiceOfYou(void)
* ���: ����� ������ �Է� ���� 
* ��ȯ: ����� �Է� 
*
*/
//SCISSORS ROCK PAPER
int ChoiceOfYou(void){ 
	int you;
	fputs("����(1) ����(2) ��(3) ����(4) ����? ",stdout);
	scanf("%d",&you);
	return you;
}

/*�Լ�: void WhoIsWinner(int com, int you) 
* ���: ���ڸ� ���� 
* ��ȯ: void
*
*/
void WhoIsWinner(int com, int you){
	
	if( (com==SCISSORS&&you==ROCK) || (com==ROCK&&you==PAPER) || (com==PAPER&&you==SCISSORS) ){
		fputs("����� �����Դϴ�!\n",stdout); 
		IncreYouWinTimes();
		youWinMoney();
	}
	else if(com == you){
		fputs("�����ϴ�!\n",stdout); 
	}
	else{
		fputs("��ǻ�Ͱ� �����̱���!\n",stdout);
		comWinMoney();
	}
	IncreGameTimes();
}

void ShowRSP(int rsp){
	switch(rsp){
		case SCISSORS:
			printf("���� \n");
			break; 
		case ROCK:
			printf("���� \n");
			break;
		case PAPER:
			printf("�� \n");
			break;
	}
}
//end of file
