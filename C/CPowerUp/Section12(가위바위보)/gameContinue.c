/* Name: gameContinue.c ver 1.0
* Content : �����̾��ϱ� �Լ� �ڵ� 
* Implementation : LHH
*
*Last Modified: 08/13
*/

#include "common.h"

/* ������ �����ϴ� �Լ�
* ������ �ʿ��� ������:
1. ����� ���� �Ӵ�, ��ǻ�� ���� �Ӥ�
2. �·� ��꿡 �ʿ��� ��ü �Ǽ��� �̱� �� 
*/

int gameSave(void){
	FILE * fp;
	int youM,comM,youW,comW;
	fp=fopen("RSP.dat","w");
	if(fp==NULL){
		fputs("���� ���� ����\n",stdout); 
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

/* ������ �ε��ϴ� �Լ�
* 
2�� 2�� 800 700
800 700 2 3 
*/
int gameLoad(void){
	FILE * fp;
	int youM=0,comM=0,youW=0,comW=0;
	fp=fopen("RSP.dat","r");
	if(fp==NULL){
		fputs("���� ���� ����\n",stdout); 
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
/* ������ �ʱ�ȭ �Լ�
*
*/ 
int gameDataReset(void){
	FILE * fp;
	fp=fopen("RSP.dat","w");
	if(fp==NULL){
		fputs("���� ���� ����\n",stdout);
		return -1; 
	}
	while(feof(fp)!=0) fwrite(NULL,sizeof(int),1,fp);
	SetYouWinTimes(0);
	SetGameTimes(0);
	fclose(fp);
}

/* ���� ������ �ʱ�ȭ �˻� �Լ�
*/
int gameDataCheck(void){
	FILE * fp;
	int i=0,ret=0;
	fp=fopen("RSP.dat","r");
	if(fp==NULL){
		puts("������ ã�� �� �����ϴ�.");
		return 0; 
	}
	while(1){
		fread(&i,sizeof(int),1,fp);
		if(feof(fp)!=0)break;
		ret+=i;
		puts("��"); 
	}
	fclose(fp);
	return ret;
} 
