#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����� ���;; 
//�޸��� ��������� �ø��� �Լ� 
char* MemEx(char* str,int max){
	char* buf;//�޸𸮹��ۻ��� 
	int i=0;
	buf=(char*)malloc(sizeof(char)*max);//�޸� ���� ���� �Ҵ��Ͽ� buf�� �ּҰ� ���� 
	for(i=0;i<max;i++){
		buf[i]=str[i];//���� �޸��ּҿ� ����Ǿ��ִ� ���ڹ迭 buf�� ���� 
	}
	//strcpy(buf,str);
	free(str);//str���ڿ� ���� 
	return buf; //buf(���ڿ�)�� �ּҰ� ���� 
}
//���ڸ� �о� �������� �����ϴ� �Լ� 
char* ReadString(){
	int max=10;
	int i=0;
	char* buf;//���ڿ� buf ���� 
	
	buf=(char*)malloc(sizeof(char)*max);
	if(buf==NULL)return 0; 
	while(1){
		if(i>=max){//i�� 10�̻��� �� 
			max+=10;
			buf=MemEx(buf,max);//���� ���۸� ����� �� ū ���۸� �Ҵ����. 
		}
		buf[i]=getchar();//���ڸ� �Է¹޾� ���ۿ� ���� 
		printf("%c",buf[i]); 
		if(buf[i]=='\n'){
			buf[i]=NULL;
			printf("���� Ȯ��,%s\n",buf); 
			return buf;
		}
		i++;
	}
}


int main(void){
	char *arr[5]={0,};
	char *buf;
	int i,j;
	for(i=0;i<5;i++){
		arr[i]=ReadString();
	}
	for(i=0;i<4;i++){
		for(j=0;j<4-i;j++){
			if(strlen(arr[j]) > strlen(arr[j+1])){
				buf=(char*)malloc(sizeof(char)*strlen(arr[j]));
				strcpy(buf,arr[j+1]);
				strcpy(arr[j+1],arr[j]);
				strcpy(arr[j],buf);
			}
		}
	}
	for(i=0;i<5;i++){
		printf("%s\n",arr[i]);
	}
}
