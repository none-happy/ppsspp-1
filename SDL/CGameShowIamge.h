#pragma once
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

#pragma pack(4)

#define COMMENT_CHAR '#'

using namespace std;

class CGameShowIamge
{
public:
	map<string, string> GetKeyInfo()
	{
		return m_arrm;
	};
	bool IsReadGameInfo();
	void get_GameInfo(unsigned char* TeZheng);


	bool getDamaResult() {
		return m_isSuccess;
	}
private:
	bool Isrand(unsigned char* pBuffer, int iLen);
	bool setRand(unsigned char* pBuffer,int iLen);
private:
	int m_iKey;
	int m_iRand;
	map<string, string> m_arrm;
	string m_filenam;
	bool m_bIsAction;
	int m_iReadTye;

	bool m_isSuccess;
};
#pragma pack()
