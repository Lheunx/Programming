#include <stdio.h>

void main(){
	int n;
	int i;
	int tot=0;
	fputs("2 �̻� �Է�:",stdout);
	scanf("%d",&n);
	while(1){
		tot+=i;
		if(tot>n){
			printf("%d�� ���� �� ó�� %d�� �ѱ� �����Ѵ�.\n",i,n);
			break;
		}
		i++;
	}
	printf("%d�� �ѱ� ������ ��:%d\n",n,tot-i);
	printf("%d�� �ѱ� ������ ��:%d\n",n,tot);
}

/*
void main(){
	int n;
	int a=0,b=0;
	int i=0;
	fputs("�ڿ��� �Է�:",stdout);
	scanf("%d",&n);
	
	for(i=0; i<=n; i++){
		if((i%2) != 0){
			a=a+i;
		} 
		else {
			b=b+i;
		}
	}
	printf("%d ���� Ȧ�� ��:%d\n",n,a);
	printf("%d ���� ¦�� ��:%d\n",n,b);
	
}

void main(){
	int n1, n2;
	int tot=0;
	int i=0;
	int end;
	puts("�� ���� ���� �Է�:");
	scanf("%d %d",&n1,&n2);
	end=(n1>n2)?n1:n2;
	for(i=(n1<n2)?n1:n2; i<=end; i++){
		if(i%3==0 || i%5==0){
			printf("%d�� �տ��� ����.\n",i);
			continue;
		}
		tot+=i;
	}
	printf("%d�� %d�� �����Ͽ� �� ���̿� �ִ� �������� ��:%d",n1,n2,tot);
}

void main(){
	int a=0,b=0;
	int tot=0;
	int i,max;
	printf("�ΰ��� ���� �Է�:");
	scanf("%d %d",&a,&b);
	max=(a>b)?a:b;
	
	for(i=(a<b)?a:b; i<=max; i++){
		tot+=i;	
	}
	printf("%d�� %d�� �����Ͽ� �� ���̿� �ִ� �������� ��: %d",a,b,tot);
}

void main(){
	int n=0;
	int i=0;
	int tot=0;
	while(1){
		printf("1�̻��� ������ �Է��ϼ���:");
		scanf("%d",&n);
		if(n>0)break;
		printf("1�̻��� ������ �Է��ؾ� �մϴ�.\n");
	}
	for(i=0;i<=n;i++){
		tot+=i;	
	}
	printf("1���� %d������ ���� %d",n,tot);
}
*/
