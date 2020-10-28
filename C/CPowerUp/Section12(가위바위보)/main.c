/* Name: main.c ver 2.2
* Content : ���� main �Լ� 
* Implementation : LHH
* 2.0: ������������ ���� ���� 
* 2.1: �·� �߰� 
* 2.0: ���ӸӴ� �߰� 
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
		printf("������ �̾ �Ͻðڽ��ϱ�? (yew 1, No 2):");
		scanf("%d",&a);
		if(a==2){
			gameDataReset();
			setYouMoney();
			SetComMoney(1000);
		}
	}
	
	while(1){
		puts("�� ������ �����մϴ�.");
		puts("");
		puts("�١١١١١١١١ٴ��!�١١١١١١١�!!");		
		setGameTableMoney();
		com=ChoiceOfCom();
		you=ChoiceOfYou();
		if(you==4){
			gameSave();
			break ;
		}
		
		puts("");
		
		puts("�ڡڡڡڡڡڡڡڰ��!�ڡڡڡڡڡڡڡڡ�!!");	
		WhoIsWinner(com, you);
		printf("��ǻ���� ������ :"); 
		ShowRSP(com);
		printf("����� ������ :"); 
		ShowRSP(you);
		puts("");	
		printf("�·� : %d %%\n",GetPercenOfVictory());
		printf("���̸� �Ӵ� : %d \n",getYouMoney());
		printf("��ǻ�� �Ӵ� : %d \n",getComMoney());
		if( getYouMoney()==0 || getComMoney()==0){
			gameDataReset();
			break;	
		} 
	}
	printf("�������������������������������������������������������\n");
	printf("���� �·� : %d %%\n",GetPercenOfVictory());
	return 0;
}

//end of file
