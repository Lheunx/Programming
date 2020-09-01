/* Name : phoneFunc.c ver 1.4
* Content : 전화번호 컨트롤 함수들의 선언 
* Implementation : LHH
* 1.1 : SearchPhoneData, DeletePhoneData 추가
* 1.2 : StoreDataToFile, LoadDataFromFile 함수 추가 
* 1.3 : ChangePhoneData 함수 추 
* 1.4 : StoreDataToFileInStruct, LoadDataFromFileInStruct 함수 추가 
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
