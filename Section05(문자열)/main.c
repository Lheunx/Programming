#include <stdio.h>
#include <string.h>

void main(){
	char str[100]={0,};
	int i;
	fputs("���ڿ� �Է�:",stdout); 
	gets(str);
	for(i=0;i<=strlen(str);i++){
		if('a'<=str[i] &&'z'>=str[i]){
			str[i] = str[i]-('a'-'A');
		}
		else if('A'<=str[i]&&'Z'>=str[i]){
			str[i] += ('a'-'A');
		}
	}
	printf("%s",str);
	
}

/*
void main(){
	char str1[20];
	char str2[20];
	char str3[20];
	char str4[20];
	char tostr[80]={0,};
	char buf[20];
	char* ptr[4]={str1,str2,str3,str4};
	int i,j,x;
	for(i=0;i<4;i++){
		printf("���ڿ� �Է� %d:",i+1); 
		scanf("%s",ptr[i]);
	}
	printf("%c",ptr[1][1]);
	for(i=0;i<3;i++){
		for(j=0;j<3-i;j++){
			printf("%d\n",j);
			for(x=0;;x++){
				//printf("ptr[j][x]=%c, ptr[j+1][x]=%c\n",ptr[j][x],ptr[j+1][x]);
				if(ptr[j][x]==0)break;
				else if( (ptr[j][x]) > (ptr[j+1][x]) ){
					strcpy(buf,ptr[j+1]);
					strcpy(ptr[j+1],ptr[j]);
					strcpy(ptr[j],buf);
					break;
				}
				else if( (ptr[j][x]) == (ptr[j+1][x])){
					continue;
				}
				else break;
			}
		}
	}
	
	for(i=0;i<4;i++){
		printf("%s\n",ptr[i]);
		strcat(tostr,ptr[i]);
		tostr[strlen(tostr)]=' ';
	}
	printf("%s\n",tostr);
	
	return 0;
}


void main(){
	char str[5][21]={0,};
	char buf[21]={0,};
	int i=0,j=0;
	for(i=0;i<5;i++){
		scanf("%s",str[i]);	
	}
	for(i=0;i<4;i++){
		for(j=0;j<4-i;j++){
			if( strlen(str[j]) > strlen(str[j+1]) ){
				strcpy(buf,str[j+1]);
				strcpy(str[j+1],str[j]);
				strcpy(str[j],buf);
			}
		}
	}
	for(i=0;i<5;i++){
		printf("%s\n",str[i]);
	}
	
	
	return 0;
}



void main(){
	char c;
	int i;
	fputs("���ڿ� �Է�:",stdout); 
	
	while(1){
		c=getchar();
		if(c == '\n')break;
		if('a'<=c &&'z'>=c){
			c -= ('a'-'A');
		}
		else if('A'<=c&&'Z'>=c){
			c += ('a'-'A');
		}
		printf("%c",c);
	}
}





void main(){
	char c;
	while(1){
		c=getchar();
		fflush(stdin);
		if(c == EOF){
			puts("���α׷��� �����մϴ�."); 
			break;
		}
		if( 'a'<= c && 'z'>=c){
			puts("�Է��Ͻ� ���ڴ� ���ĺ� �ҹ����Դϴ�."); 
		}
		else if( 'A'<= c && 'Z'>=c){
			puts("�Է��Ͻ� ���ڴ� ���ĺ� �빮���Դϴ�.");
		}
		else if( '0'<= c && '9' >= c){
			puts("�Է��Ͻ� ���ڴ� �ƶ��Ƽ����Դϴ�."); 
		}
		else{
			puts("Ư�����ڸ� �Է��ϼ̱���."); 
		}
	}
	return 0;
}
*/
