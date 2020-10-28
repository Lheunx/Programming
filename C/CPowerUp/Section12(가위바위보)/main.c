/* Name: main.c ver 2.2
* Content : 게임 main 함수 
* Implementation : LHH
* 2.0: 가위바위보로 게임 변경 
* 2.1: 승률 추가 
* 2.0: 게임머니 추가 
*Last Modified: 08/13
*/

#include "common.h"
#include "game.h"
#include "gameTimes.h"

int main(void){
	int com;
	int you;	
	int a;
	
	if(gameLoad()==-1){
		setYouMoney();
		SetComMoney(1000);
	}
	else{
		printf("게임을 이어서 하시겠습니까? (yew 1, No 2):");
		scanf("%d",&a);
		if(a==2){
			gameDataReset();
			setYouMoney();
			SetComMoney(1000);
		}
	}
	
	while(1){
		puts("자 게임을 시작합니다.");
		puts("");
		puts("☆☆☆☆☆☆☆☆☆대결!☆☆☆☆☆☆☆☆!!");		
		setGameTableMoney();
		com=ChoiceOfCom();
		you=ChoiceOfYou();
		if(you==4){
			gameSave();
			break ;
		}
		
		puts("");
		
		puts("★★★★★★★★결과!★★★★★★★★★!!");	
		WhoIsWinner(com, you);
		printf("컴퓨터의 선택은 :"); 
		ShowRSP(com);
		printf("당신의 선택은 :"); 
		ShowRSP(you);
		puts("");	
		printf("승률 : %d %%\n",GetPercenOfVictory());
		printf("게이머 머니 : %d \n",getYouMoney());
		printf("컴퓨터 머니 : %d \n",getComMoney());
		if( getYouMoney()==0 || getComMoney()==0){
			gameDataReset();
			break;	
		} 
	}
	printf("ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ최종결과ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
	printf("최종 승률 : %d %%\n",GetPercenOfVictory());
	return 0;
}

//end of file
