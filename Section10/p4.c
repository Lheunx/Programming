#include <stdio.h>
#include <string.h>

int main(){
	FILE* fp;
	char buf3[100];
	char buf2[100];
	char buf1[100];
	char c,c1;
	int i,j,ret=1,x;
	
//	fp=fopen("weather.txt","w");
//	for(j=0;;j++){
//		fputs("**���� ���� �Է�*****\n",stdout);
//		fputs("��¥: ",stdout);
//		ret=scanf("%d",&i);
//		if(ret==EOF)break;
//		fputs("����: ",stdout);
//		fflush(stdin);
//		fgets(buf1,50,stdin);
//		fflush(stdin);
//		fputs("����(A)/����(P): ",stdout);
//		c=fgetc(stdin);
//		fputs("����: ",stdout);
//		fflush(stdin);
//		fgets(buf2,100,stdin);
//		
//		fwrite(&i,sizeof(int),1,fp);//���� �Է�
//		fputs(buf1,fp);
//		fputc(c,fp);
//		fputs(buf2,fp);
//	}
//	fclose(fp);
	
//	fp=fopen("weather.txt","r");
//	while(1){
//		
//		fread(&i,sizeof(int),1,fp);
//		if(feof(fp) != 0)break;	
//		
//		fputs("��¥: ",stdout);
//		printf("%d\n",i);
//		
//		fputs("����: ",stdout);
//		fgets(buf1,50,fp);
//		printf("%s",buf1);
//		
//		fputs("����(A)/����(P): ",stdout);
//		c=fgetc(fp);
//		printf("%c\n",c);
//		
//		fputs("����: ",stdout);
//		fgets(buf2,100,fp);
//		printf("%s",buf2);
//		puts("");
//	}
//	fclose(fp);

	fp=fopen("weather.txt","r");
	fputs("�˻��� ��¥ �� ���� ���� �Է�:",stdout);
	scanf("%d %s %c",&x,buf3,&c1);
	sprintf(buf3,"%s\n",buf3);
//	buf3[strlen(buf3)]='\n';
//	buf3[strlen(buf3)+1]=0;
	while(1){
		
		fread(&i,sizeof(int),1,fp);
		if(feof(fp) != 0)break;	
		
		fgets(buf1,50,fp);
		c=fgetc(fp);
		fgets(buf2,100,fp);
		
//		printf("buf1:%sbuf3:%s | %d",buf1,buf3,strcmp(buf1,buf3));
		if(x==i && c1 == c && (strcmp(buf1,buf3)==0)){
			fputs("��¥: ",stdout);
			printf("%d\n",i);		
			fputs("����: ",stdout);			
			printf("%s",buf1);			
			fputs("����(A)/����(P): ",stdout);		
			printf("%c\n",c);			
			fputs("����: ",stdout);			
			printf("%s",buf2);
			puts("");
			ret=0;
		}
	}
	if(ret==1)printf("�ش� ��¥ �� ������ �����Ͱ� �������� �ʽ��ϴ�."); 
	else printf("�˻��� �Ϸ�Ǿ����ϴ�."); 
	fclose(fp);

}
