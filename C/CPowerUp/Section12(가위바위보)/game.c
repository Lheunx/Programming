/* Name: game.c ver 2.0
* Content : 게임 관련 함수 정의 
* Implementation : LHH
* 1.1 ChoiceOfCom, ChoiceOfYou, WhoIsWinner 함수 완성ㅑ 
* 2.0 ChoiceOfCom, ChoiceOfYou, WhoIsWinner 함수 가위바위보로 변경 
* 2.1 승률 시스템 추가 
* 2.2 게임머니 시스템 추가 
*Last Modified: 08/13
*/

#include <time.h>
#include "common.h"
#include "game.h"
#include "gameTimes.h"

/*함수: int ChoiceOfCom(void)
* 기능: 무작위 값을 반환
* 반환: 0~99 범위의 값을 반환
*
*/
int ChoiceOfCom(void){
	srand((unsigned int)time(NULL));
	return (rand()%3+1);
} 

/*함수: int ChoiceOfYou(void)
* 기능: 사용자 선택을 입력 받음 
* 반환: 사용자 입력 
*
*/
//SCISSORS ROCK PAPER
int ChoiceOfYou(void){ 
	int you;
	fputs("가위(1) 바위(2) 보(3) 종료(4) 선택? ",stdout);
	scanf("%d",&you);
	return you;
}

/*함수: void WhoIsWinner(int com, int you) 
* 기능: 승자를 가름 
* 반환: void
*
*/
void WhoIsWinner(int com, int you){
	
	if( (com==SCISSORS&&you==ROCK) || (com==ROCK&&you==PAPER) || (com==PAPER&&you==SCISSORS) ){
		fputs("당신이 승자입니다!\n",stdout); 
		IncreYouWinTimes();
		youWinMoney();
	}
	else if(com == you){
		fputs("비겼습니다!\n",stdout); 
	}
	else{
		fputs("컵퓨터가 승자이군요!\n",stdout);
		comWinMoney();
	}
	IncreGameTimes();
}

void ShowRSP(int rsp){
	switch(rsp){
		case SCISSORS:
			printf("가위 \n");
			break; 
		case ROCK:
			printf("바위 \n");
			break;
		case PAPER:
			printf("보 \n");
			break;
	}
}
//end of file
