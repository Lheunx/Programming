/* Name : phoneFunc.c ver 1.4
* Content : ��ȭ��ȣ ��Ʈ�� �Լ����� ���� 
* Implementation : LHH
* 1.1 : SearchPhoneData, DeletePhoneData �߰�
* 1.2 : StoreDataToFile, LoadDataFromFile �Լ� �߰� 
* 1.3 : ChangePhoneData �Լ� �� 
* 1.4 : StoreDataToFileInStruct, LoadDataFromFileInStruct �Լ� �߰� 
* Last modified 2020/08/11
*/

#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__

#include "phoneData.h"

void InputPhoneData(void);
void ShowAllData(void);
void SearchPhoneData(void);
void DeletePhoneData(void);
void StoreDataToFile(void);
void LoadDataFromFile(void);
void ChangePhoneData(void);
void StoreDataToFileInStruct(void);
void LoadDataFromFileInStruct(void);

#endif
//end of file
