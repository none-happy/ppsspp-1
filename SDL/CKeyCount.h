#pragma once
#pragma pack(4)
extern "C"
{
	unsigned short JiaoYan_JYM_encipher(unsigned int QuanBuZong_LR,
		unsigned int FenJi_HM, unsigned char* jym);

	unsigned char JiSuan_DKXZM_decrypt(unsigned int QuanBuZong_LR,
		unsigned int FenJi_HM,
		unsigned char* jym,
		unsigned char *pInputData);
};
#pragma pack()
