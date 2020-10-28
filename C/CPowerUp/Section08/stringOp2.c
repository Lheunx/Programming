#include "myString.h"
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

