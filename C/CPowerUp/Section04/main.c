#include <stdio.h>

void main(){
	int arr[5]={0,};
	int i=0;
	int j;
	int tmp=0;
	for(i=0;i<5;i++){
		printf("���� %d �Է�:",i+1);
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
		fputs("1 �̻��� ���� �Է�:",stdout);
		ret=scanf("%d",&n); 
		if(ret==EOF)break;
		if(n>=1){
			printf("%d�� �����\n",n);
			for(i=1;i<=n;i++){
				if(n%i==0)printf("%d ",i);
			}
			puts("");
		}
		else puts("1 �̻��� �Է��� �ʿ�� �մϴ�."); 
	}
}


void main(){
	int n=0;
	int a,b,c;
	fputs("���� �Է�:",stdout);
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
		fputs("Ȧ�� ��(1), ¦�� ��(2):",stdout);
		scanf("%d",&n);
		if(n==1 || n==2){
			break;
		}
		else{
			puts("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �Է��ϼ���.");
		}
	}
	for(;n<=9;n=n+2){
		for(i=1;i<=9;i++){
			printf("%d X %d = %d\n",n,i,n*i);
		}
	}
}
*/
