#include<stdio.h>
//10진수 2ㅣ진수 변환 프로그램 
void main(){
	int dec=0;
	int barr[10]={0};
	int i=-1;
	printf("10진수 정수 입력:");
	scanf("%d",&dec);
	printf("%d를 2진수로 변환하면:",dec);
	while(dec!=0){
		i++;
		barr[i]=dec%2;
		dec=dec/2;
	}
	for(;i>=0;i--){
		printf("%d",barr[i]);
	}
	
}
/* 25점 
 22 점 

void main(){
	int a=0, b=0, c=0;
	int max=0;
	printf("두 개의 숫자를 입력하세요:");
	scanf("%d %d",&a,&b);
	max = a>b?a:b;
	printf("큰수는 %d\n",max);
	
	printf("세 개의 숫자를 입력하세요:");
	scanf("%d %d %d",&a,&b,&c);
	max = a>b?(a>c)?a:c : (b>c)?b:c;
	printf("큰수는 %d",max);
}


 28점 
void main(){
	int a=0;
	int max=0;
	int min=999;
	int avg=0;
	int i=0;
	for(i=0;i<7;i++){
		fputs("정수형 데이터 입력:",stdout);
		scanf("%d",&a);
		if(a>max)max=a;
		else if(a<min)min=a;
		avg+=a;
	}
	printf("최대 값:%d\n",max);
	printf("최소 값:%d\n",min);
	printf("전체 합:%d\n",avg);
	printf("평 균:%f",(double)avg/7);
	return 0;
}

20점 
void main(){
	double a,b;
	printf("두 개의 실수 입력:");
	scanf("%lf %lf",&a,&b);
	printf("덧셈 결과:%f\n",a+b);
	printf("뺄셈 결과:%f\n",a-b);
	printf("곱셈 결과:%f\n",a*b);
	printf("나눗셈 결과:%f\n",a/b);
	
	printf("반지름 입력:");
	scanf("%lf",&a);
	printf("원의 넓이: %lf",a*a*3.14);
	return 0;
}
*/
