/* Name: gameTimes.c ver 1.0
* Content : ���� ���� �Լ� ���� 
* Implementation : LHH
*
*Last Modified: 08/12
*/

/* �Լ� �̸� : void gameUserWin(void) 
* �� ��: �·� ���
*/

static int gameNumOfTimes=0;
static int youWinNumOfTimes=0;

void IncreGameTimes(void){
	gameNumOfTimes++;
}
int GetGameTimes(void){
	return gameNumOfTimes;
}
void IncreYouWinTimes(void){
	youWinNumOfTimes++;
}
int GetYouWinTImes(void){
	return youWinNumOfTimes;
}
int GetPercenOfVictory(void){
	if (gameNumOfTimes==0)
		return 0;
	return (double)youWinNumOfTimes/gameNumOfTimes * 100;
}

void SetGameTimes(int a){
	gameNumOfTimes=a;
}
void SetYouWinTimes(int a){
	youWinNumOfTimes=a;
}
