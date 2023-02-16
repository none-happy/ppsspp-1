#include "stdio.h"
#include "CKeyCount.h"
#pragma pack(4)
int g_iDaiLiNo=999;
int g_iXianHao=999;
unsigned long U8ArrayToU32_KEY(unsigned char *src, unsigned char pos)
{
	unsigned long temp, temp1, temp2;
	temp = 0x00000000;
	temp1 = 0x00000000;
	temp2 = 0x00000000;
	temp |= (src[pos + 3]);
	temp = temp << 24;
	temp1 |= (src[pos + 2]);
	temp1 = temp1 << 16;
	temp |= temp1;
	temp2 |= (src[pos + 1]);
	temp2 = temp2 << 8;
	temp |= temp2;
	temp |= (src[pos]);
	return temp;
}
void tea_encipherKey(unsigned int* plain, unsigned int* key, unsigned int* crypt)
{
	unsigned int left = plain[0], right = plain[1];
	unsigned int a = key[0], b = key[1], c = key[2], d = key[3];
	unsigned int n = 32, sum = 0;
	unsigned int delta = 0x9e3779b9;

	while (n-- > 0)
	{
		sum += delta;
		left += ((right << 4) + a) ^ (right + sum) ^ ((right >> 5) + b);
		right += ((left << 4) + c) ^ (left + sum) ^ ((left >> 5) + d);
	}

	crypt[0] = left;
	crypt[1] = right;
}
unsigned short JiaoYan_JYM_encipher(unsigned int QuanBuZong_LR,
	unsigned int FenJi_HM,unsigned char* jym)
{
	unsigned int key[4] = { 3256494985, 1436254594, 4165748379, 1236439473 };
	unsigned int plain[2];
	unsigned int crypt[2];
	unsigned char i;
	unsigned int u32_temp;
	unsigned short u16_temp, u16_temp1, u16_temp2;

	unsigned char jym1[5], jym2[5];

	key[0] += g_iDaiLiNo;
	key[1] += g_iDaiLiNo;
	key[2] -= g_iXianHao;
	key[3] += FenJi_HM;

	u32_temp = 0;
	plain[0] = QuanBuZong_LR, plain[1] = 0;
	tea_encipherKey(plain, key, crypt);
	u32_temp += crypt[0];
	u32_temp += crypt[1];

	plain[0] = FenJi_HM, plain[1] = 1;
	tea_encipherKey(plain, key, crypt);
	u32_temp += crypt[0];
	u32_temp += crypt[1];

	for (i = 4; i > 0; i--)
	{
		jym[i - 1] = u32_temp % 10;
		u32_temp = u32_temp / 10;
	}
	return 0;
}
unsigned char JiSuan_DKXZM_decrypt(unsigned int QuanBuZong_LR,
	unsigned int FenJi_HM,
	unsigned char* jym,
	unsigned char *pInputData)
{
	unsigned int key[4] = { 2793423498, 3465202843, 1702134343, 2234834981 };
	unsigned int plain[2];
	unsigned int crypt[2];
	unsigned short i, j;
	unsigned int temp = 0;
	unsigned int jym_temp;
	unsigned char Data[8];

	key[0] += g_iDaiLiNo;
	key[1] += g_iDaiLiNo;
	key[2] -= g_iXianHao;
	key[3] += FenJi_HM;

	plain[0] = QuanBuZong_LR, plain[1] = 0;
	tea_encipherKey(plain, key, crypt);
	temp += crypt[0];
	temp += crypt[1];

	plain[0] = FenJi_HM, plain[1] = 1;
	tea_encipherKey(plain, key, crypt);
	temp += crypt[0];
	temp += crypt[1];

	jym_temp = U8ArrayToU32_KEY(jym, 0);
	plain[0] = jym_temp, plain[1] = jym_temp;
	tea_encipherKey(plain, key, crypt);
	temp += crypt[0];
	temp += crypt[1];

	temp = temp / 100;

	for (i = 0, j = 7; i < 8; i++, j--)
	{
		Data[j] = temp % 10;
		temp = temp / 10;
	}

	for (i = 0; i < 6; i++)
	{
		if (Data[i] != pInputData[i])
		{
			break;
		}
	}

	if (i < 6)
	{
		return 0;
	}
	return 1;
}
#pragma pack()