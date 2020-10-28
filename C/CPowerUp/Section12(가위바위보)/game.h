/* Name: game.h ver 2.0
* Content : 게임 관련 함수 선언 
* Implementation : LHH
*
* 2.0: 열거형 값 변경 가위바위보로 
*Last Modified: 08/12
*/

#ifndef __GAME_H__
#define __GAME_H__

enum {SCISSORS=1,ROCK , PAPER};

int ChoiceOfCom(void);
int ChoiceOfYou(void);
void WhoIsWinner(int com, int you);
void ShowRSP(int rsp);

#endif
//end of file
