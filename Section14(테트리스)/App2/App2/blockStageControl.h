/* Name : blockStageControl.h ver 1.0
 * content: 블록 상태 함수 
 * Implemnetation : LHH
 * last modified : 2020.10.06

*/
#ifndef __SHOWBLOCK_H__
#define __SHOWBLOCK_H__


void InitNewBlockPos(int x, int y);

void ChooseBlock(void);
int GetCurrentBlockIdx(void);
void showBlock(char block[][4]);
void DeleteBlock(char block[][4]);
int BlockDown();
void BlockLeft();
void BlockRight();
void BlockRotate();
void BlockCrushCheck(void);

#endif
//end