#include <stdio.h>
#include <string.h>
#define STR_LEN 50
#define BOOK_INFO_NUM 3
//���� �ٽ�  
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
	//����� ����
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
	//���ǻ�� 
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
	//���ݼ� 
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
		printf("%d ��° ���� ���� ���.\n",i);
		printf("��������:%s\n",parr[i]->bookTitle);
		printf("���ǻ��:%s\n",parr[i]->bookPub);
		printf("��������:%d\n",parr[i]->bookPrice);
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
		printf("å ����, ���ǻ�, ���� :"); 
		scanf("%s %s %d",buf.bookTitle,buf.bookPub,&buf.bookPrice);
		InputBook(&buf,i);
	}
	for(i=0; ;i++){
		printf("\n*****************���� ���� ���*****************\n");
		printf("1.���� ���� ��, 2.���ǻ� ��, 3.���� ��. 4. ����\n�Է�:");
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
		//printf("��� : %s %s %d\n",arr[i].bookTitle,arr[i].bookPub,arr[i].bookPrice);
	}
	
}

