/* Name : phoneData.h ver 1.0
* Content : ����ü phoneData �� ���� �� ���� 
* Implementation : LHH
*
* Last modified 2020/08/05
*/

#ifndef __PHONEDATA_H__
#define __PHONEDATA_H__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __phoneData{
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
}phoneData;

#endif
//end of file
