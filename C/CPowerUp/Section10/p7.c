#include <stdio.h>

int main(){
	FILE* fp1, * fp2;
	char src[100];
	char dst[100];
	char tmp[100];
	int i;
	fputs("���� �̸�:",stdout);
	scanf("%s",src);
	fputs("���纻 �̸�:",stdout);
	scanf("%s",dst); 
	
	fp1=fopen(src,"rb");
	fp2=fopen(dst,"wb");
	if(fp1 == NULL || fp2 == NULL)puts("NULL ����");
	
	while(1){
		i=fread(tmp,1,100,fp1);
		printf("%d ",i);
		if(i < 100){
			if(feof(fp1)!=0){
				fwrite(tmp,1,i,fp2);
				break;
			}
			else{
				puts("���� �߻�");
				 return -1;
			}
		}
		fwrite(tmp,1,i,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	
}
