#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//상당히 어렵;; 
//메모리의 저장공간을 늘리는 함수 
char* MemEx(char* str,int max){
	char* buf;//메모리버퍼생성 
	int i=0;
	buf=(char*)malloc(sizeof(char)*max);//메모리 공간 동적 할당하여 buf에 주소값 저장 
	for(i=0;i<max;i++){
		buf[i]=str[i];//기존 메모리주소에 저장되어있는 문자배열 buf로 복사 
	}
	//strcpy(buf,str);
	free(str);//str문자열 삭제 
	return buf; //buf(문자열)의 주소값 리턴 
}
//문자를 읽어 동적으로 저장하는 함수 
char* ReadString(){
	int max=10;
	int i=0;
	char* buf;//문자열 buf 생성 
	
	buf=(char*)malloc(sizeof(char)*max);
	if(buf==NULL)return 0; 
	while(1){
		if(i>=max){//i가 10이상일 떄 
			max+=10;
			buf=MemEx(buf,max);//기존 버퍼를 지우고 더 큰 버퍼를 할당받음. 
		}
		buf[i]=getchar();//문자를 입력받아 버퍼에 저장 
		printf("%c",buf[i]); 
		if(buf[i]=='\n'){
			buf[i]=NULL;
			printf("엔터 확인,%s\n",buf); 
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
