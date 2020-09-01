/* Name: gameTimes.h ver 1.0
* Content : 게임 관련 함수 선언 
* Implementation : LHH
*
*Last Modified: 08/12
*/

#ifndef __GAMETIMES_H__
#define __GAMETIMES_H__


void IncreGameTimes(void);
int GetGameTimes(void);
void IncreYouWinTimes(void);
int GetYouWinTImes(void);
int GetPercenOfVictory(void);

void SetGameTimes(int a);
void SetYouWinTimes(int a);

#endif

//end of file
