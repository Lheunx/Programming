/* Name : phoneFunc.c ver 1.7
* Content : ��ȭ��ȣ ��Ʈ�� �Լ� 
* Implementation : LHH
* 1.1: �Լ� InputPhoneData, ShowAllData�� ���� �Ϸ�
* 1.2: SearchPhoneData, DeletePhoneData �Լ� �߰� 
* 1.3: phoneList�� ������ �迭�� ����, ��� �Լ� ShowPhoneInfoByPtr �Լ��� ���� 
* 1.4: ���������� ó���ϱ� �Լ�Ȯ�� 
* 1.5: StoreDataToFile, LoadDataFromFile �Լ� �߰� 
* 1.6: ChangePhoneData �Լ� �߰� 
* 1.7 : StoreDataToFileInStruct, LoadDataFromFileInStruct �Լ� �߰� 
* Last modified 2020/08/11
*/
 
#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData=0;
phoneData *phoneList[LIST_NUM];

/*�� ��: void InputPhoneData(void)
*�� ��: ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
*�� ȯ: void
*/
void InputPhoneData(void){
	if (numOfData>LIST_NUM){
		fputs("���� ������ �����մϴ�.",stdout); 
		return;
	}
	int i; 
	phoneData *data;
	data=(phoneData*)malloc(sizeof(phoneData));
	fputs("�̸� �Է�:",stdout); 
	gets(data->name );
	
	fputs("��ȭ��ȣ �Է�:",stdout); 
	gets(data->phoneNum);
	//�� 
	for(i=0;i<numOfData;i++){
		if((strcmp(data->name,phoneList[i]->name)==0) && (strcmp(data->phoneNum,phoneList[i]->phoneNum) == 0)){
			fputs("�̹� �Էµ� ������ �Դϴ�.",stdout);
			free(data);
			return ;
		}
	}
	
	phoneList[numOfData]=data;
	numOfData++;
	fputs("�Է��� �Ϸ�Ǿ����ϴ�.",stdout); 
	StoreDataToFileInStruct();
} 
/*�� ��: void ShowAllData(void)
*�� ��: ����� ������ ��ü ���
*�� ȯ: void
*/
void ShowAllData(void){
	int i;
	for(i=0;i<numOfData;i++){
		ShowPhoneInfoByPtr(phoneList[i]);
		}
	fputs("����� �Ϸ�Ǿ����ϴ�.",stdout); 
} 

void SearchPhoneData(void){
	char sName[NAME_LEN];
	int i;
	int ret=0;
	fputs("ã�� �̸���?:",stdout);
	gets(sName);
	for(i=0;i<numOfData;i++){
		if(strcmp(sName,phoneList[i]->name)==0){
			ShowPhoneInfoByPtr(phoneList[i]);
			ret=1;
			//break;
		}
	}
	if(ret=1) fputs("�˻��� �Ϸ�Ǿ����ϴ�.",stdout); 
	else fputs("ã�� �̸��� �����Ͱ� �����ϴ�.",stdout); 
}

void DeletePhoneData(void){
	char sName[NAME_LEN];
	int num[LIST_NUM]={0,};// ���������� ó���ϱ����� �迭 
	int i;
	int j=0; //���������� ó���ϱ� ���� ���� 
	fputs("ã�� �̸���?:",stdout);
	gets(sName);
	
	for(i=0;i<numOfData;i++){
		if(strcmp(sName,phoneList[i]->name)==0){
			num[j]=i;
			j++;
		}
	}
	
	if(j==0){
		fputs("ã�� �̸��� �����ϴ�.",stdout); 
		return ;	
	}
	
	if(j>1){
		for(i=0;i<j;i++){
			printf("���� %d:\n",i+1); 
			ShowPhoneInfoByPtr(phoneList[num[i]]);
		}
		fputs("���� :",stdout); 
		scanf("%d",&j); 
		i=num[j-1];
		numOfData--; 
	}
	
	else{	
		for(i=0;i<numOfData;i++){
			if(strcmp(sName,phoneList[i]->name)==0){
				numOfData--;
				break;
			}
		}
	}
	
	for(; i<numOfData;i++){
		phoneList[i]=phoneList[i+1];
	}
	fputs("������ �Ϸ�Ǿ����ϴ�.",stdout); 
	StoreDataToFileInStruct();
}

void StoreDataToFile(void){
	FILE *fp;
	int i;
	fp=fopen("PhoneNumbers.txt","w"); 
	if(fp==NULL){
		fputs("���� ���� ����",stdout) ;
		return ;
	}
	fwrite(&numOfData,sizeof(int),1,fp);
	for(i=0;i<numOfData;i++){
		fprintf(fp,"%s\n%s\n",phoneList[i]->name,phoneList[i]->phoneNum);
		free(phoneList[i]);
	}
	fputs("���� �Ϸ�",stdout); 
	fclose(fp);
}


void LoadDataFromFile(void){
	FILE *fp;
	phoneData *buf;
	int i;
	int j=0;
	fp=fopen("PhoneNumbers.txt","r");
	if(fp==NULL){
		fputs("���� ���� ����",stdout);
		return 0; 
	}
	
	fread(&numOfData,sizeof(int),1,fp);
	for(i=0; i<numOfData; i++){
		phoneList[i]=(phoneData*)malloc(sizeof(phoneData));
		fgets(phoneList[i]->name, NAME_LEN, fp);
		j=strlen(phoneList[i]->name);
		phoneList[i]->name[j-1]=0;
		
		fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);
		j=strlen(phoneList[i]->phoneNum);
		phoneList[i]->phoneNum[j-1]=0;
	}
	fputs("��� �Ϸ�",stdout); 
	fclose(fp);
}

void ChangePhoneData(void){
	char sName[NAME_LEN];
	char sNum[PHONE_LEN];
	int num[LIST_NUM]={0,};// ���������� ó���ϱ����� �迭 
	int i;
	int j=0; //���������� ó���ϱ� ���� ���� 
	fputs("ã�� �̸���?:",stdout);
	gets(sName);
	
	for(i=0;i<numOfData;i++){
		if(strcmp(sName,phoneList[i]->name)==0){
			num[j]=i;
			j++;
		}
	}	
	if(j==0){
		fputs("ã�� �̸��� �����ϴ�.",stdout); 
		return ;	
	}
	
	if(j>1){
		for(i=0;i<j;i++){
			printf("���� %d:\n",i+1); 
			ShowPhoneInfoByPtr(phoneList[num[i]]);
		}
		fputs("���� :",stdout); 
		scanf("%d",&j);
		getchar(); 
		i=num[j-1];
	}
	else{
		for(i=0;i<numOfData;i++){
			if(strcmp(sName,phoneList[i]->name)==0){
				break; 
			}
		}
	}
	fputs("������ ��ȭ��ȣ��? ",stdout); 
	gets(sNum);
	strcpy(phoneList[i]->phoneNum,sNum);
	fputs("������ �Ϸ�Ǿ����ϴ�.",stdout); 
	StoreDataToFileInStruct();
}


void StoreDataToFileInStruct(void){
	FILE *fp;
	int i;
	fp=fopen("PhoneNumbers.dat","w"); 
	if(fp==NULL){
		fputs("���� ���� ����",stdout) ;
		return 0;
	}
	for(i=0;i<numOfData;i++){
		fwrite(phoneList[i],sizeof(phoneData),1,fp);	
	}
	fputs("���� �Ϸ�",stdout); 
	fclose(fp);
}

void LoadDataFromFileInStruct(void){
	FILE *fp;
	phoneData *buf;
	int i;
	int j=0;
	fp=fopen("PhoneNumbers.dat","r");
	if(fp==NULL){
		fputs("���� ���� ����",stdout);
		return 0; 
	}
	while(1){
		buf=(phoneData*)malloc(sizeof(phoneData));
		fread(buf,sizeof(phoneData),1,fp);
		if(feof(fp)!=0)break;
		phoneList[numOfData]=buf;
//		printf("%s %s %d\n",phoneList[numOfData]->name,phoneList[numOfData]->phoneNum,numOfData);
		numOfData++;
	}
	fputs("��� �Ϸ�",stdout); 
	fclose(fp);
}

//end of file
