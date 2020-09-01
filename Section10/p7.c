#include <stdio.h>

int main(){
	FILE* fp1, * fp2;
	char src[100];
	char dst[100];
	char tmp[100];
	int i;
	fputs("원본 이름:",stdout);
	scanf("%s",src);
	fputs("복사본 이름:",stdout);
	scanf("%s",dst); 
	
	fp1=fopen(src,"rb");
	fp2=fopen(dst,"wb");
	if(fp1 == NULL || fp2 == NULL)puts("NULL 오류");
	
	while(1){
		i=fread(tmp,1,100,fp1);
		printf("%d ",i);
		if(i < 100){
			if(feof(fp1)!=0){
				fwrite(tmp,1,i,fp2);
				break;
			}
			else{
				puts("오류 발생");
				 return -1;
			}
		}
		fwrite(tmp,1,i,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	
}
