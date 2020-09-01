#include <stdio.h>

void main(){
	int arr[5]={0,};
	int i=0;
	int j;
	int tmp=0;
	for(i=0;i<5;i++){
		printf("숫자 %d 입력:",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<4;i++){
		for(j=0;j<4-i;j++){
			if(arr[j] > arr[j+1]){
				tmp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=tmp;
			}
		}
	}
	for(i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
	
}

/*
void main(){
	int n=0;
	int i=0;
	int ret=0;
	while(1){
		fputs("1 이상의 정수 입력:",stdout);
		ret=scanf("%d",&n); 
		if(ret==EOF)break;
		if(n>=1){
			printf("%d의 약수들\n",n);
			for(i=1;i<=n;i++){
				if(n%i==0)printf("%d ",i);
			}
			puts("");
		}
		else puts("1 이상의 입력을 필요로 합니다."); 
	}
}


void main(){
	int n=0;
	int a,b,c;
	fputs("정수 입력:",stdout);
	scanf("%d",&n); 
	for(a=0;a<=100;a++){
		for(b=0;b<=100;b++){
			for(c=0;c<=100;c++){
				if(a * b - c == n){
					printf("(%d) X (%d) - (%d) = (%d)\n",a,b,c,n);
				}
			}
		}
	}
	return 0;
}


void main(){
	int i=0;
	int n=0;
	while( 1 ){
		fputs("홀수 단(1), 짝수 단(2):",stdout);
		scanf("%d",&n);
		if(n==1 || n==2){
			break;
		}
		else{
			puts("잘못된 입력입니다. 1 또는 2만 입력하세요.");
		}
	}
	for(;n<=9;n=n+2){
		for(i=1;i<=9;i++){
			printf("%d X %d = %d\n",n,i,n*i);
		}
	}
}
*/
