#include <stdio.h>

int main(){
	FILE * fp;
	int j,i,c;
//	fp = fopen("character.txt","wt");
//	if(fp==NULL){
//		printf("���� - ����\n");
//		return 1; 
//	}
//	while(1){
//		c=getchar();
//		if(c=='\n')break;
//		fputc(c,fp);
//	}
//	fclose(fp);
	
	fp = fopen("character.txt","rt");
	if(fp==NULL){
		printf("���� - ����\n");
		return 1; 
	}
	printf("����� ������ ������?"); 
	scanf("%d",&j);
	for(i=0;i<j*2;i++){
		printf("%c",fgetc(fp));
	}
	printf("\n��� �Ϸ�"); 
	fclose(fp);
}
