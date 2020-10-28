
int strLen(char *str){
	int i=0;
	for(i=0; ;i++){
		if(str[i]=='\0')break;
	}
	return i;
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


