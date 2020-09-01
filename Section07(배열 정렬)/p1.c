#include <stdio.h>
#include <stdlib.h>

void SortArr(int * arr, int num);
void ReadAndSortPrint(int number);

void main(void){
	int num;
	fputs("�Է��� ������ ���� :", stdout);
	scanf("%d", &num);
	
	ReadAndSortPrint(num);
	return 0; 
}

void SortArr(int * arr, int num){
	int i, j, temp;
	
	for(i=0; i<num-1; i++){
		for(j=0; j<(num-i)-1; j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void ReadAndSortPrint(int number){
	int *arr;
	int i;
	
	arr=(int *)malloc(sizeof(int)*number);
	for(i=0; i<number; i++){
		printf("%d ��° �Է�: ",i+1);
		scanf("%d", &arr[i]); 
	}
	
	SortArr(arr, number);
	
	puts("�Էµ� ������ ���ĵ� ���");
	for(i=0; i<number; i++){
		printf("%d ", arr[i]);
	} puts("");
	free(arr);
}
