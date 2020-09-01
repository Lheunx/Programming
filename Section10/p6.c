#include <stdio.h>

int main(){
	FILE* fp1, * fp2;
	char src[100];
	char dst[100];
	int i;
	int tmp;
	fputs("원본 이름:",stdout);
	scanf("%s",src);
	fputs("복사본 이름:",stdout);
	scanf("%s",dst); 
	
	fp1=fopen(src,"rb");
	fp2=fopen(dst,"wb");
	if(fp1 == NULL || fp2 == NULL)puts("NULL 오류");
	
	while(1){
		tmp=fgetc(fp1);
		printf("%d",tmp);
		if(feof(fp1)!=0)break;
		fputc(tmp,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	
}
