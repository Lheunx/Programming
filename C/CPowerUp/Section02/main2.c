#include<stdio.h>
//10���� 2������ ��ȯ ���α׷� 
void main(){
	int dec=0;
	int barr[10]={0};
	int i=-1;
	printf("10���� ���� �Է�:");
	scanf("%d",&dec);
	printf("%d�� 2������ ��ȯ�ϸ�:",dec);
	while(dec!=0){
		i++;
		barr[i]=dec%2;
		dec=dec/2;
	}
	for(;i>=0;i--){
		printf("%d",barr[i]);
	}
	
}
/* 25�� 
 22 �� 

void main(){
	int a=0, b=0, c=0;
	int max=0;
	printf("�� ���� ���ڸ� �Է��ϼ���:");
	scanf("%d %d",&a,&b);
	max = a>b?a:b;
	printf("ū���� %d\n",max);
	
	printf("�� ���� ���ڸ� �Է��ϼ���:");
	scanf("%d %d %d",&a,&b,&c);
	max = a>b?(a>c)?a:c : (b>c)?b:c;
	printf("ū���� %d",max);
}


 28�� 
void main(){
	int a=0;
	int max=0;
	int min=999;
	int avg=0;
	int i=0;
	for(i=0;i<7;i++){
		fputs("������ ������ �Է�:",stdout);
		scanf("%d",&a);
		if(a>max)max=a;
		else if(a<min)min=a;
		avg+=a;
	}
	printf("�ִ� ��:%d\n",max);
	printf("�ּ� ��:%d\n",min);
	printf("��ü ��:%d\n",avg);
	printf("�� ��:%f",(double)avg/7);
	return 0;
}

20�� 
void main(){
	double a,b;
	printf("�� ���� �Ǽ� �Է�:");
	scanf("%lf %lf",&a,&b);
	printf("���� ���:%f\n",a+b);
	printf("���� ���:%f\n",a-b);
	printf("���� ���:%f\n",a*b);
	printf("������ ���:%f\n",a/b);
	
	printf("������ �Է�:");
	scanf("%lf",&a);
	printf("���� ����: %lf",a*a*3.14);
	return 0;
}
*/
