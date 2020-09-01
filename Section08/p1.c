#include <stdio.h>
#include <string.h>
#define STR_LEN 50
#define BOOK_INFO_NUM 3

typedef struct _bookInfo{
	char bookTitle[STR_LEN];
	char bookPub[STR_LEN];
	int bookPrice;
}bookInfo;

bookInfo arr[BOOK_INFO_NUM];

void InputBook(char *t,char *p, int n,int x){
	int i,j;
	
	for(i=0;i<x;i++){
		if(strcmp(arr[i].bookTitle,t)==1){//str1 < str2 -1, str1 > str2 1;
		printf("strcmp : %s, %s, %d \n",arr[i].bookTitle,t,strcmp(arr[i].bookTitle,t));
			for(j=x;j>i;j--){
				strcpy(arr[j].bookTitle,arr[j-1].bookTitle);
				strcpy(arr[j].bookPub,arr[j-1].bookPub);
				arr[j].bookPrice=arr[j-1].bookPrice;
			}
			strcpy(arr[i].bookTitle,t);
			strcpy(arr[i].bookPub,p);
			arr[i].bookPrice=n;
			return 0; 
		}
	}
	
	strcpy(arr[x].bookTitle,t);
	strcpy(arr[x].bookPub,p);
	arr[x].bookPrice=n;
	return 0;	
}

int main(){
	
	bookInfo buf;
	int i;
	
	for(i=0;i<BOOK_INFO_NUM;i++){
		printf("책 제목, 출판사, 가격 :"); 
		scanf("%s %s %d",buf.bookTitle,buf.bookPub,&buf.bookPrice);
		InputBook(buf.bookTitle,buf.bookPub,buf.bookPrice,i);
	}
	for(i=0;i<BOOK_INFO_NUM;i++){
		printf("결과 : %s %s %d\n",arr[i].bookTitle,arr[i].bookPub,arr[i].bookPrice);
	}
	
}

/*
typedef struct _bookInfo{
	char bookTitle[STR_LEN];
	char bookPub[STR_LEN];
	int bookPrice;
}bookInfo;
int main(){
	bookInfo arr[3]={0,};
	int i;
	for(i=0;i<3;i++){
		scanf("%s %s %d",arr[i].bookTitle,arr[i].bookPub,&arr[i].bookPrice);
	}
	for(i=0;i<3;i++){
		printf("%s %s %d\n",arr[i].bookTitle,arr[i].bookPub,arr[i].bookPrice);
	}
}



int main(void){
	char Bname[3][50];
	char Cname[3][50];
	int arr[3];
	int i;
	for(i=0;i<3;i++){
		scanf("%s %s %d",&Bname[i],&Cname[i],&arr[i]);
	}
	for(i=0;i<3;i++){
		printf("%s %s %d\n",Bname[i],Cname[i],arr[i]);
	}
}

*/
