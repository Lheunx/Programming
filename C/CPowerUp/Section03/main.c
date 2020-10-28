#include <stdio.h>

void main(){
	int n;
	int i;
	int tot=0;
	fputs("2 이상 입력:",stdout);
	scanf("%d",&n);
	while(1){
		tot+=i;
		if(tot>n){
			printf("%d를 더할 때 처음 %d를 넘기 시작한다.\n",i,n);
			break;
		}
		i++;
	}
	printf("%d를 넘기 이전의 합:%d\n",n,tot-i);
	printf("%d를 넘기 이전의 합:%d\n",n,tot);
}

/*
void main(){
	int n;
	int a=0,b=0;
	int i=0;
	fputs("자연수 입력:",stdout);
	scanf("%d",&n);
	
	for(i=0; i<=n; i++){
		if((i%2) != 0){
			a=a+i;
		} 
		else {
			b=b+i;
		}
	}
	printf("%d 이하 홀수 합:%d\n",n,a);
	printf("%d 이하 짝수 합:%d\n",n,b);
	
}

void main(){
	int n1, n2;
	int tot=0;
	int i=0;
	int end;
	puts("두 개의 정수 입력:");
	scanf("%d %d",&n1,&n2);
	end=(n1>n2)?n1:n2;
	for(i=(n1<n2)?n1:n2; i<=end; i++){
		if(i%3==0 || i%5==0){
			printf("%d는 합에서 제외.\n",i);
			continue;
		}
		tot+=i;
	}
	printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합:%d",n1,n2,tot);
}

void main(){
	int a=0,b=0;
	int tot=0;
	int i,max;
	printf("두개의 정수 입력:");
	scanf("%d %d",&a,&b);
	max=(a>b)?a:b;
	
	for(i=(a<b)?a:b; i<=max; i++){
		tot+=i;	
	}
	printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합: %d",a,b,tot);
}

void main(){
	int n=0;
	int i=0;
	int tot=0;
	while(1){
		printf("1이상의 정수를 입력하세요:");
		scanf("%d",&n);
		if(n>0)break;
		printf("1이상의 정수를 입력해야 합니다.\n");
	}
	for(i=0;i<=n;i++){
		tot+=i;	
	}
	printf("1부터 %d까지의 합은 %d",n,tot);
}
*/
