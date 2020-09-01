#include <stdio.h>
#include <string.h>
#define STR_LEN 50
#define BOOK_INFO_NUM 3
//내일 다시  
typedef struct _bookInfo{
	char bookTitle[STR_LEN];
	char bookPub[STR_LEN];
	int bookPrice;
}bookInfo;

bookInfo arr[BOOK_INFO_NUM];

void sort(int n){
	bookInfo * parr[BOOK_INFO_NUM];
	bookInfo * tmp;
	
	int i,j;
	
	for(i=0;i<BOOK_INFO_NUM;i++){
		parr[i]=&arr[i];
	}
	//제목순 정렬
	if(n==1){
		for(i=0;i<2;i++){
			for(j=0;j<2-i;j++){
				if(strcmp(parr[j]->bookTitle,parr[j+1]->bookTitle) > 0){
					tmp=parr[j+1];
					parr[j+1]=parr[j];
					parr[j]=tmp;
				}
			}
		}
	} 
	//출판사순 
	else if(n==2){
		for(i=0;i<2;i++){
			for(j=0;j<2-i;j++){
				if(strcmp(parr[j]->bookPub,parr[j+1]->bookPub) > 0){
					tmp=parr[j+1];
					parr[j+1]=parr[j];
					parr[j]=tmp;
				}
			}
		}
	}
	//가격순 
	else if(n==3){
		for(i=0;i<2;i++){
			for(j=0;j<2-i;j++){
				if(parr[j]->bookPrice > parr[j+1]->bookPrice){
					tmp=parr[j+1];
					parr[j+1]=parr[j];
					parr[j]=tmp;
				}
			}
		}
	}
	for(i=0;i<BOOK_INFO_NUM;i++){
		printf("%d 번째 도서 정보 출력.\n",i);
		printf("도서제목:%s\n",parr[i]->bookTitle);
		printf("출판사명:%s\n",parr[i]->bookPub);
		printf("도서가격:%d\n",parr[i]->bookPrice);
		puts("");
	}
	//return 0;
}

void InputBook(bookInfo* book,int i){
	strcpy(arr[i].bookTitle,book->bookTitle);
	strcpy(arr[i].bookPub,book->bookPub);
	arr[i].bookPrice=book->bookPrice;
	//return 0;
}

int main(){
	bookInfo buf;
	int i;
	int choice=0;
	for(i=0;i<BOOK_INFO_NUM;i++){
		printf("책 제목, 출판사, 가격 :"); 
		scanf("%s %s %d",buf.bookTitle,buf.bookPub,&buf.bookPrice);
		InputBook(&buf,i);
	}
	for(i=0; ;i++){
		printf("\n*****************도서 정보 출력*****************\n");
		printf("1.도서 제목 순, 2.출판사 순, 3.가격 순. 4. 종료\n입력:");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				sort(1);
				continue;
			case 2 :
				sort(2);
				continue;
			case 3 :
				sort(3);
				continue;
			default :
				return 0;
		}
		//printf("결과 : %s %s %d\n",arr[i].bookTitle,arr[i].bookPub,arr[i].bookPrice);
	}
	
}

