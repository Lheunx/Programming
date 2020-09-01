#include "myString.h"

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

