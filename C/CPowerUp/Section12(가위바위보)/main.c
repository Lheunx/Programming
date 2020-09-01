/* Name: main.c ver 2.2
* Content : 惟績 main 敗呪 
* Implementation : LHH
* 2.0: 亜是郊是左稽 惟績 痕井 
* 2.1: 渋懸 蓄亜 
* 2.0: 惟績袴艦 蓄亜 
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
		printf("惟績聖 戚嬢辞 馬獣畏柔艦猿? (yew 1, No 2):");
		scanf("%d",&a);
		if(a==2){
			gameDataReset();
			setYouMoney();
			SetComMoney(1000);
		}
	}
	
	while(1){
		puts("切 惟績聖 獣拙杯艦陥.");
		puts("");
		puts("』』』』』』』』』企衣!』』』』』』』』!!");		
		setGameTableMoney();
		com=ChoiceOfCom();
		you=ChoiceOfYou();
		if(you==4){
			gameSave();
			break ;
		}
		
		puts("");
		
		puts("【【【【【【【【衣引!【【【【【【【【【!!");	
		WhoIsWinner(com, you);
		printf("陳濃斗税 識澱精 :"); 
		ShowRSP(com);
		printf("雁重税 識澱精 :"); 
		ShowRSP(you);
		puts("");	
		printf("渋懸 : %d %%\n",GetPercenOfVictory());
		printf("惟戚袴 袴艦 : %d \n",getYouMoney());
		printf("陳濃斗 袴艦 : %d \n",getComMoney());
		if( getYouMoney()==0 || getComMoney()==0){
			gameDataReset();
			break;	
		} 
	}
	printf("けけけけけけけけけけけけけけ置曽衣引けけけけけけけけけけ\n");
	printf("置曽 渋懸 : %d %%\n",GetPercenOfVictory());
	return 0;
}

//end of file
