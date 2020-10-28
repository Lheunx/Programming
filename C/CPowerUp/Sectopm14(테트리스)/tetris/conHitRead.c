/* name : conHitRead.c  ver 1.0
 * content : keyInput 관련 함수
 * Implementation : LHH
 * Last Modified 2020.10.07
 */

#include <conio.h>
#include "common.h"
#include "blockStageControl.h"
#define KEY_SENSITIVE 100
#define SYS_DELAY 20

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

static int keyDelayRate;

int leftInput(){
	BlockLeft();
}

int rightInput(){
	BlockRight();
}

int upInput(){
	BlockRotate();
}

int keyCheck(){
	int i,j,a,b;
	for(i=0; i<KEY_SENSITIVE; i++){
		if(_kbhit()){
			a=_getch();

			switch(a){
			case LEFT:
				leftInput();
				break;
			case RIGHT:
				rightInput();
				break;
			case UP:
				upInput();
				break;
			}
		}
		if(i%keyDelayRate == 0) Sleep(SYS_DELAY);
	}	
}

void InitKeyDelayRate(int rate){
	if(rate <1)return;
	keyDelayRate=rate;
}

//end