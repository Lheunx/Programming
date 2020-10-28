#include <stdio.h>
#include <string.h>

void printA(FILE *fp){
	char buf[100];
	int i;
	for(i=0; ;i++){
		
		fgets(buf,100,fp);	
		if(feof(fp)!=0)break;
		printf("%s",buf);
	}
}

void printN(FILE *fp,int n){
	char buf[100];
	int i;
	for(i=0; i<n; i++){
		fgets(buf,100,fp);	
	}
	printf("%s",buf);
}

int main(){
	FILE * fp;
	int i;
	char str[100];
//	fp=fopen("string.txt","w");
//	for(i=0;i<5;i++){
//		printf("%d 번째 문자열 입력:",i+1);
//		fgets(str,100,stdin);
//		fputs(str,fp);
////		fflush(stdin);
////		fprintf(fp,"%s",str); 
//	}
//	
//	fclose(fp);

	fp=fopen("string.txt","r");
	fputs("출력할 문자열 정보 입력(6이상은 전체 출력):",stdout) ;
	scanf("%d",&i);
	if(i>=6){
		printA(fp);
	}
	else{
		printN(fp,i);
	}
	
}
