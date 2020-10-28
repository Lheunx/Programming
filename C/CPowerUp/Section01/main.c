#include <stdio.h>


//EOF 입력 시 종료되는 프로그램 
void main(void){
	int c;
	char ret;
	while(1){
		fputs("Data input(Ctrl+Z to exit):", stdout);
		ret=scanf("%d",&c);
		if(ret==EOF)break;
		fflush(stdin);
	}
}

/*   

void main(){
	int a, b;
	printf("두 수를 16진수로 입력:"); 
	scanf("%x %x",&a,&b);
	printf("연산 결과 8진수: %o\n",a+b); 
	printf("연산 결과 10진수: %d\n",a+b); 
	printf("연산 결과 16진수: %x\n",a+b); 
	
	printf("두 수를 16진수로 입력:"); 
	scanf("%x %x",&a,&b);
	printf("연산 결과 8진수: %o\n",a+b); 
	printf("연산 결과 10진수: %d\n",a+b); 
	printf("연산 결과 16진수: %x\n",a+b); 
}



void main(){
	char str[50];
	fputs("문자열 입력:",stdout);
	gets(str);
	
	printf("%s",str);
	
}


void main(){
	char c;
	int a;
	double b;
	char string[50];
	
	scanf("%c, %d, %lf, %s",&c,&a,&b,string);
	printf("%c, %d, %lf, %s",c,a,b,string);
	return 0;
}


*/
