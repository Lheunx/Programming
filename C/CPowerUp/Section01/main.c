#include <stdio.h>


//EOF �Է� �� ����Ǵ� ���α׷� 
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
	printf("�� ���� 16������ �Է�:"); 
	scanf("%x %x",&a,&b);
	printf("���� ��� 8����: %o\n",a+b); 
	printf("���� ��� 10����: %d\n",a+b); 
	printf("���� ��� 16����: %x\n",a+b); 
	
	printf("�� ���� 16������ �Է�:"); 
	scanf("%x %x",&a,&b);
	printf("���� ��� 8����: %o\n",a+b); 
	printf("���� ��� 10����: %d\n",a+b); 
	printf("���� ��� 16����: %x\n",a+b); 
}



void main(){
	char str[50];
	fputs("���ڿ� �Է�:",stdout);
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
