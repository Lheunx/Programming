#include <stdio.h>

int main(){
	FILE *fp;
	int num,i;
	
	fp=fopen("numeric.dat","w");
	for(i=0;i<5;i++){
		printf("파일에 저장할 숫자 %d :",i+1);
		scanf("%d",&num);
		fwrite(&num,sizeof(int),1,fp);
	}
	fclose(fp);
	
	fp=fopen("numeric.dat","r");
	for(i=0;i<5;i++){
		printf("%d번째 입력 된 숫자 :",i+1);
		fread(&num,sizeof(int),1,fp);
		printf("%d\n",num); 
	}
	fclose(fp);
}
