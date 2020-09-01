#include <stdio.h>
#include <string.h>



int strLen(char *str){
	int i=0;
	for(i=0; ;i++){
		if(str[i]=='\0')break;
	}
	return i;
}

int strCpy(char* des, char* src){
	int i=0;
	
	for(i=0; ;i++){
		des[i]=src[i];
		if(src[i]=='\0')break;
	}
}

int strCat(char* des, char* src){
	int i=0;
	int j=0;
	
	i=strLen(des);
	for(j=0; ;j++,i++){
		if(src[j]=='\0')break;
		des[i]=src[j];
		printf("%d",i);
	}
}

int strCmp(char* str1, char* str2){
	while((*str1)!=0|| (*str2)!=0){
		if(*str1>*str2)return 1;
		else if((str1<*str2))return 1;
		else{
			str1++;
			str2++;
			continue;
		}
	}
	return 0;
}

/*
int strCmp(char *str1, char* str2){
	int i;
	if(strLen(str1)==strLen(str2)){
		for(i=0;i<strLen(str1);i++){
			if(str1[i]<str2[i])return -1;
			else if(str1[i]>str2[i])return 1;
		}
		return 0;
	}else if(strLen(str1)<strLen(str2)){
		for(i=0;i<strLen(str1);i++){
			if(str1[i]<str2[i])return -1;
			else if(str1[i]>str2[i])return 1;
		}
		return -1;
	}else if(strLen(str2)<strLen(str1)){
		for(i=0;i<strLen(str2);i++){
			if(str1[i]<str2[i])return -1;
			else if(str1[i]>str2[i])return 1;
		}
		return 1;
	}
}
*/

int main(void){
	char str1[100]="Good morning?";
	char str2[100]="HaHaHa!";
	char buffString[100];
	
	/** strLen test **/
	printf("length of \"%s\" : %d \n", str1, strLen(str1));
	printf("length of \"%s\" : %d \n", str2, strLen(str2));
	
	/** strCpy test **/
	strCpy(buffString, str1);
	printf("copy string: \"%s\" \n", buffString);
	
	/** strCat test **/
	strCat(buffString, str2);
	printf("concat string: \"%s\" \n", buffString);
	
	/** strCmp test **/
	printf("cmp str1, str1 : %d \n" ,strCmp(str1, str1) );
	printf("cmp str2, str2 : %d \n" ,strCmp(str2, str2) );
	printf("cmp str1, str2 : %d \n" ,strCmp(str1, str2) );

	printf("cmp str2, str1 : %d \n" ,strCmp(str2, str1) );
	return 0;
}

/*
int findC(char *str, char c){
	int i=0;
	int to=0;
	
	while(i<=strlen(str)){
		if(str[i]==c)to++;
		i++;
	}
	return to;
}

void main(){
	char str[100]={0,};
	char c;
	printf("��� ���ڿ� �Է�:");
	gets(str);
	printf("���� �� ���� �Է�:");
	scanf("%c",&c);
	printf("%c�� ����:%d",c,findC(str,c));
	
}


int arrA(int (*arrp)[2],int n){
	int to=0;
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			to+=arrp[i][j];
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			printf("%d, ",arrp[i][j]);
		}
	}
		//printf("%d�� ��",arrp[n-1][2]); 
	printf("�� ��%d\n",to);
}

int arrB(int (*arrp)[3], int n){
	int to=0;
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			to+=arrp[i][j];
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			printf("%d, ",arrp[i][j]);
		}
	}
		//printf("%d�� ��",arrp[n-1][2]); 
	printf("�� ��%d\n",to);
}

void main(){
	int arr3[2][2]={1,3,5,7};
	int arr4[2][3]={1,2,3,4,5,6};
	
	arrA(arr3,2);
	arrB(arr4,2);
	
}


void arrP(int *ptr1,int a, int *ptr2, int b){
	int i;
	int t1=0;
	int t2=0;
	
	for(i=0;i<a;i++){
		if(i==a-1)printf("%d ",ptr1[i]);
		else printf("%d, ",ptr1[i]);
		t1+=ptr1[i];
	}
	printf("�� ��: %d\n",t1);
	
	for(i=0;i<b;i++){
		if(i==b-1)printf("%d ",ptr2[i]);
		else printf("%d, ",ptr2[i]);
		t2+=ptr2[i];
	}
	printf("�� ��: %d\n",t2);
	
}

void main(){
	int arr1[3]={5,10,15};
	int arr2[5]={1,2,3,4,5};
	int a=sizeof(arr1)/sizeof(int);
	int b=sizeof(arr2)/sizeof(int);
	arrP(arr1,a, arr2,b);
}

�迭�� ������� �����ϰ� �����͸� �ϳ��� ����Ͽ��� ��. 
int Divlnt(int n1, int n2, int *p1, int* p2){
	if(n2==0){
		return -256;
	}
	*p1=n1/n2;
	*p2=n1%n2;
	return 0;
}

void main(){
	int n1,n2;	
	int n3,n4;
	int* p1=&n3, *p2=&n4;
	fputs("������ ���� �� ���� �Է�:",stdout);
	while(1){
		scanf("%d %d",&n1,&n2); 
		if(Divlnt(n1,n2,p1,p2)!=0)puts("0���� ������ �����߻�!���� �� �Է�");
		else break; 
	}
	printf("��: %d, ������: %d",n3,n4);
}

int fact(int n){
	int i=1;
	int to=1;
	if(n<1){
		puts("�Է��� �߸��Ǿ� ����ġ ���� ����� ������ϴ�."); 
		return 0;
	}
	for(i=1;i<=n;i++){
		to*=i;
	}
	printf("%d! = %d",n,to);
}

void main(){
	int n;
	fputs("���� �Է�(1�̻�):",stdout); 
	scanf("%d",&n);
	fact(n);
	
	
	return 0;
}

//strtok ���� ����� ���̵��� ����. 
char* StringTokenize(char *str, char* delim){
	char* sStr=0;// ���ڿ� ���� ��ġ 
	static char * tstr;// ���ڿ� �ּҸ� �����ϴ� �������� 
	int i=0;
	if(str!=NULL)sStr=str;// str�� �� ���� �ƴϸ� ������ġ�� ���� 
	else sStr=tstr;//str �� NULL�̸� ���� ������ġ�� ������ġ�� ���� 
	if(strlen(sStr)<1)return NULL;//���ڿ��� ������ Ȯ���ϱ� ���� ���� �������� ����� ���� �� �ִ�. 
	for(i=0; i<strlen(sStr); i++){
		if(sStr[i] == (*delim)||sStr[i] == '\0'){
			sStr[i]='\0';
			//printf("i:%d\n",i);
			break;
		}
	}
	tstr=&sStr[i+1];
	//printf("sStr[i]:%c &sStr[i]%x\n",sStr[i+1],&sStr[i+1]);
	return sStr;
}

int main(void){
	char str[]="010-1111-3333";//��ū�� ���� ���ڿ�
	char * delim="-";// ��ū�� ���� ����
	char * token;
	
	//printf("%d",str[0]);
	token=StringTokenize(str,delim);
	while(token!=NULL){
		puts(token);
		token=StringTokenize(NULL, delim);
	} 
	return 0;
}
*/

