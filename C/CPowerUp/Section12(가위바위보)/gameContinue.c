/* Name: gameContinue.c ver 1.0
* Content : 게임이어하기 함수 코드 
* Implementation : LHH
*
*Last Modified: 08/13
*/

#include "common.h"

/* 게임을 저장하는 함수
* 저장이 필요한 데이터:
1. 사용자 게임 머니, 컴퓨터 게임 머ㅣ
2. 승률 계산에 필요한 전체 판수와 이긴 수 
*/

int gameSave(void){
	FILE * fp;
	int youM,comM,youW,comW;
	fp=fopen("RSP.dat","w");
	if(fp==NULL){
		fputs("파일 오픈 오류\n",stdout); 
		return -1;
	}
	youM=getYouMoney();
	comM=getComMoney();
	youW=GetYouWinTImes();
	comW=GetGameTimes();
	
	fwrite(&youM,sizeof(int),1,fp);
	fwrite(&comM,sizeof(int),1,fp);
	
	fwrite(&youW,sizeof(int),1,fp);
	fwrite(&comW,sizeof(int),1,fp);
	fclose(fp);
} 

/* 게임을 로드하는 함수
* 
2판 2승 800 700
800 700 2 3 
*/
int gameLoad(void){
	FILE * fp;
	int youM=0,comM=0,youW=0,comW=0;
	fp=fopen("RSP.dat","r");
	if(fp==NULL){
		fputs("파일 오픈 오류\n",stdout); 
		return -1;
	}
	
	fread(&youM,sizeof(int),1,fp);
	if(feof(fp)!=0)return -1;
	fread(&comM,sizeof(int),1,fp);
	fread(&youW,sizeof(int),1,fp);
	fread(&comW,sizeof(int),1,fp);

	SetYouMoney2(youM);
	SetComMoney(comM);
	SetYouWinTimes(youW);
	SetGameTimes(comW);
	
	printf("%d %d %d %d",getYouMoney(),getComMoney(),GetYouWinTImes(),GetGameTimes());
	
	fclose(fp);
}
/* 데이터 초기화 함수
*
*/ 
int gameDataReset(void){
	FILE * fp;
	fp=fopen("RSP.dat","w");
	if(fp==NULL){
		fputs("파일 오픈 오류\n",stdout);
		return -1; 
	}
	while(feof(fp)!=0) fwrite(NULL,sizeof(int),1,fp);
	SetYouWinTimes(0);
	SetGameTimes(0);
	fclose(fp);
}

/* 게임 데이터 초기화 검사 함수
*/
int gameDataCheck(void){
	FILE * fp;
	int i=0,ret=0;
	fp=fopen("RSP.dat","r");
	if(fp==NULL){
		puts("파일을 찾을 수 없습니다.");
		return 0; 
	}
	while(1){
		fread(&i,sizeof(int),1,fp);
		if(feof(fp)!=0)break;
		ret+=i;
		puts("ㅁ"); 
	}
	fclose(fp);
	return ret;
} 
