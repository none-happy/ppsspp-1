#include "stdio.h"
#include "CGameShowIamge.h"
#include <rapidjson/rapidjson.h>
#include <rapidjson/pointer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#if _WIN32
#include <intrin.h>
class CSysSetting;
#else
#include <unistd.h>
class CSysSetting;
#endif
#include <fstream>
#include <iostream>
//#pragma warning(disable:4996)


#pragma pack(4)

using namespace std;
#define MaxLineSize 4096
#define MaxKeySize 256
#if WIN32
#include "components/TextComponent.h"
#include "CGetCpu.h"
#else
#include "CGetCpu.h"
#endif

//std::string filePath = "/storage/font/";
std::string esKeyPath = "/storage/es_key";
//std::string filePath = "./font/";
//std::string esKeyPath = "/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/emuelec-emulationstation/emuelec-emulationstation-ae2850d70751a4c468af6e700cd0394e9bec275a/es_key";
bool g_bIsKeySuc=false;
#define CODE_LENGTH 512
int m_is[CODE_LENGTH];
int m_it[CODE_LENGTH];
static const unsigned char vendor_code[CODE_LENGTH] = "l%rZh0ZvcaGvR)`uI_Q@<3%M9f?j01wtJJ0(B=BcFbpEF&1He>_P..&M$=$*;,Zpt:2q$dIa1CE67#>Vpb7\#`=[D$CEgw/q*'NPeke+Cm%KBBmh49^IJBd<n:LM>L-o-^ms2Z9,_>v+AqoPgVjmkag5HJqBp9\86o(%NL*OXolFchDXPuJme,pRFIl0PZbM<k(H%$CDc(a@%NgR:Wc;UfUZU3";

void Init()
{
	int j = 0;
	int temp;
	int kmax = strlen((char *)vendor_code);
	for (int i = 0; i < CODE_LENGTH; i++)//////////////���ֽ�״̬ʸ���Ϳɱ䳤����Կ���鸳ֵ
	{
		m_is[i] = i;
		m_it[i] = vendor_code[i%kmax];
	}
	for (int i = 0; i < CODE_LENGTH; i++) //////ʹ�ÿɱ䳤����Կ�����ʼ���ֽ�״̬ʸ������s
	{
		j = (j + m_is[i] + m_it[i]) % 256;
		temp = m_is[i];
		m_is[i] = m_is[j];
		m_is[j] = temp;
	}
}
void EnCrypt(char *enStr, int nLen, char * outStr)
{
	int temps[CODE_LENGTH] = { 0 };
	for (int i = 0; i < CODE_LENGTH; i++)
	{
		temps[i] = m_is[i];
	}

	int m = 0;
	int n = 0;
	int	 q = 0;
	int temp = 0;
	int max = nLen;
	for (int i = 0; i < max; i++)/////////////���ֽ�״̬ʸ������任������Կ�����������ַ����н���
	{
		m = (m + 1) % CODE_LENGTH;
		n = (n + temps[n]) % CODE_LENGTH;
		temp = temps[m];
		temps[m] = temps[n];
		temps[n] = temp;
		q = (temps[m] + temps[n]) % CODE_LENGTH;
		outStr[i] = enStr[i] ^ temps[q];
	}
}

//char* get_GameInfo2(char* pGameId);
void getcpuid2(unsigned int* pGameId, unsigned int InfoType);
void getcpuidex2(unsigned int* pGameId, unsigned int InfoType, unsigned int ECXValue);

int get_GameInfo2(char* pGameId)
{
	int iLen=0;
#if !WIN32
	//iLen=GetCpuIdByAsm_arm(pGameId);
	iLen=GetCpuIdByAsm_x86(pGameId);
	//printf("pGameIdpGameIdpGameId:%s\n", pGameId);
	//printf("pGameId:%s\n", pGameId);
#else

	iLen=GetCpuIdByAsm_x86(pGameId);
#endif
	return iLen;
}
bool IsSpace2(char c)
{
	if (c == ' ' || c == '\t')
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
bool IsCommentChar2(char c)
{
	if (c == COMMENT_CHAR)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
// trim函数的作用是把一个字符串左边和右边的空格去掉，即为trim
void Trim2(string & str) // 引用传参，这样在函数中修改该参数也会修改相应的变�?
{
	if (str.empty())
	{
		return;
	}
	int i, start_pos, end_pos;
	for (i = 0; i < str.size(); i++)
	{
		if (!IsSpace2(str[i]))
		{
			break;//跳出
		}
	}
	if (i == str.size())//如果该行全是空格，则该行最后一个字符为"\n"，此时i == str.size()
	{
		str = "";
		return;
	}
	start_pos = i; // 获取到非空格的初始位�?

	for (i = str.size() - 1; i >= 0; i--)
	{
		if (!IsSpace2(str[i]))
		{
			break;
		}
	}
	end_pos = i;
	str = str.substr(start_pos, end_pos - start_pos + 1);
}
unsigned short GetCheckCode(unsigned char *sData, unsigned int wlen)
{
	unsigned short res = 0;
	unsigned char * CSData = (unsigned char *)sData;
	for (int i = 0; i < wlen; ++i)
	{
		res = ((*CSData) + res) % 0xFFFF;
		++CSData;
	}
	return res;
}
bool AnalyseLine2(const string & line, string & key, string & value) // 分析一行，如果是注释行，则不处理，如果是k-v行，则提取出key-value值�?
{
	if (line.empty())
	{
		return false;
	}
	int start_pos = 0, end_pos = line.size() - 1, pos;
	if ((pos = line.find(COMMENT_CHAR)) != -1)
	{
		if (0 == pos)
		{
			return false; // 如果一行的开头是#,说明是注释，�?不需�?
		}
		end_pos = pos - 1; // 參�昳�释在k-v后的情况--------------
	}
	string new_line = line.substr(start_pos, end_pos - start_pos + 1); // 删掉后半部分的注�?FIX_ME�?这里应该是减错了�?json
	// 下面pos的赋值时必要的，这样，就可在后面得到Key和value值了�?
	if ((pos = new_line.find("=")) == -1) //说明前面没有 = �?
	{
		return false;
	}
	key = new_line.substr(0, pos); // 获得key
	value = new_line.substr(pos + 1, end_pos + 1 - (pos + 1)); // 获得value
	Trim2(key);
	if (key.empty())
	{
		return false;
	}
	Trim2(value); // 因为这里的key和value都是引用传递，可以直接被修改，所以不用返�?
	return true;
}

void tea_encipher(unsigned int* plain, unsigned int* key, unsigned int* crypt)
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
void tea_decrypt(unsigned int* crypt, unsigned int* key, unsigned int* plain)
{
	unsigned int y = crypt[0], z = crypt[1], sum = 0xC6EF3720, i;			/* set up */
	unsigned int delta = 0x9e3779b9;										/* a key schedule constant */
	unsigned int a = key[0], b = key[1], c = key[2], d = key[3];			/* cache key */

	/* basic cycle start */
	for (i = 0; i < 32; i++)
	{
		z -= ((y << 4) + c) ^ (y + sum) ^ ((y >> 5) + d);
		y -= ((z << 4) + a) ^ (z + sum) ^ ((z >> 5) + b);
		sum -= delta;
	}

	/* end cycle */

	plain[0] = y;
	plain[1] = z;
}
unsigned long U8ArrayToU32(unsigned char* src, unsigned char pos)
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

void getcpuid2(unsigned int* pGameId, unsigned int InfoType)
{
#if _WIN32
#if defined(__GNUC__)// GCC  
	__cpuid(InfoType, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);
#elif defined(_MSC_VER)// MSVC  
#if _MSC_VER >= 1400 //VC2005��֧��__cpuid  
	__cpuid((int*)(void*)pGameId, (int)(InfoType));
#else //����ʹ��getcpuidex  
	getcpuidex(CPUInfo, InfoType, 0);
#endif  
#endif 
#endif
}

void getcpuidex2(unsigned int* CPUInfo, unsigned int InfoType, unsigned int ECXValue)
{
#if defined(_MSC_VER) // MSVC  
#if defined(_WIN64) // 64λ�²�֧���������. 1600: VS2010, ��˵VC2008 SP1֮���֧��__cpuidex.  
	__cpuidex((int*)(void*)CPUInfo, (int)InfoType, (int)ECXValue);
#else  
	if (NULL == CPUInfo)
		return;
	_asm {
		// load. ��ȡ�������Ĵ���.  
		mov edi, CPUInfo;
		mov eax, InfoType;
		mov ecx, ECXValue;
		// CPUID  
		cpuid;
		// save. ���Ĵ������浽CPUInfo  
		mov[edi], eax;
		mov[edi + 4], ebx;
		mov[edi + 8], ecx;
		mov[edi + 12], edx;
	}
#endif  
#endif  
}

void CGameShowIamge::get_GameInfo(unsigned char* TeZheng)
{
	unsigned int key[4] = { 3809741010, 4128049456, 1733281782, 3905716334 };
	unsigned int plain[2];
	unsigned int crypt[2];
	unsigned char i, j;
	unsigned int temp1 = 0, temp2 = 0, temp3 = 0;
	unsigned char temp4[4];
	unsigned int temp;
	unsigned char data[8];

	unsigned int iVal = 0;

	char pCpuId[256] = "";
	get_GameInfo2(pCpuId);
	
	int iLen = strlen(pCpuId);
	for (int i = 0; i < iLen;i++)
	{
		iVal += pCpuId[i];
	}
	printf("iLen:%d\n", iLen);
	printf("pCpuId:%s\n", pCpuId);
	printf("iValiValiValiValiVal:%d\n", iVal);
	
	key[0] += 12899999;
	key[1] += iVal;
	key[2] = m_iRand;
	key[3] = iVal;


	temp4[0] = 128;
	temp4[1] = 128;
	temp4[2] = 64;
	temp4[3] = 128;

	temp2 = U8ArrayToU32(temp4, 0);
	temp2 = temp2 % 10000;

	key[0] = temp2;

	plain[0] = 12899999, plain[1] = 12899999 << 2;
	tea_encipher(plain, key, crypt);
	temp1 = crypt[0] + crypt[1];



	for (i = 0, j = 7; i < 4; i++, j--)
	{
		TeZheng[j] = temp1 % 10;
		temp1 = temp1 / 10;
	}

	for (i = 4, j = 3; i < 8; i++, j--)
	{
		TeZheng[j] = temp2 % 10;
		temp2 = temp2 / 10;
	}
}
bool CGameShowIamge::IsReadGameInfo()
{
	printf("CGameShowIamge_000\n");
	char ch[512];
	string strFile =  esKeyPath;
	FILE* pRecFile = fopen(strFile.c_str(), "rb");

	unsigned char buf[512];
	long length = 0;

	if (pRecFile != NULL)
	{
		rewind(pRecFile);
		///获取长度
		
		fseek(pRecFile, 0, SEEK_END);
		length = ftell(pRecFile);
		fseek(pRecFile, 0, SEEK_SET);
		
		memset(buf, 0, length + 1);
		int readb = fread(buf, length, 1, pRecFile);
		if (readb != 1|| length<30)
		{
			printf("file_read_error\n");
			fclose(pRecFile);
			pRecFile = NULL;
			return false;
		}
	}
	else
	{
		printf("file_error\n");
		return false;
	}

	m_iRand = 0;
	m_iKey = 0;
	
	if (!Isrand(buf, length))
	{
		printf("hhhhhhh2\n");
		return false;
	}
	printf("CGameShowIamge_001\n");
	//-----------------改读数据库-------------
	
	int iData[5] = {0};

	unsigned char chSendData[256];

	get_GameInfo(chSendData);

	unsigned int u32TeZhengMa = 0;
	for (int i = 0; i < 8;i++)
	{
		u32TeZhengMa = u32TeZhengMa * 10 + chSendData[i];
	}
	if (u32TeZhengMa == m_iKey)
	{
		m_bIsAction = false;
		printf("key_suc\n");
		m_isSuccess = true;

		g_bIsKeySuc=true;
		return true;
	}
	else
	{
		m_iReadTye = 0;
		m_bIsAction = false;
		
		printf("CGameShowImage.cpp 635\n");
		return false;
	}
	
	printf("CGameShowImage.cpp 636\n");
	return false;
}
//--

void get_GameInfoT(unsigned char* TeZheng, int iRandNumber, char* cCPUID)
{
	unsigned int key[4] = { 3809741010, 4128049456, 1733281782, 3905716334 };
	unsigned int plain[2];
	unsigned int crypt[2];
	unsigned char i, j;
	unsigned int temp1 = 0, temp2 = 0, temp3 = 0;
	unsigned char temp4[4];
	unsigned int temp;
	unsigned char data[8];

	unsigned int iVal = 0;



	int iLen = strlen(cCPUID);

	key[0] += 12899999;
	key[1] += iLen;
	key[2] = iRandNumber;//需要发送
	key[3] = iLen;


	temp4[0] = 128;
	temp4[1] = 128;
	temp4[2] = 64;
	temp4[3] = 128;

	temp2 = U8ArrayToU32(temp4, 0);
	temp2 = temp2 % 10000;

	key[0] = temp2;

	plain[0] = 12899999, plain[1] = 12899999 << 2;
	tea_encipher(plain, key, crypt);
	temp1 = crypt[0] + crypt[1];

	for (i = 0, j = 7; i < 4; i++, j--)
	{
		TeZheng[j] = temp1 % 10;
		temp1 = temp1 / 10;
	}

	for (i = 4, j = 3; i < 8; i++, j--)
	{
		TeZheng[j] = temp2 % 10;
		temp2 = temp2 / 10;
	}
}

bool CGameShowIamge::Isrand(unsigned char* pBuffer,int iLen)
{
	//----------------解析文件-----------
	unsigned char* pBufferTem = pBuffer;
	unsigned short CS = 0;
	memcpy(&CS, pBufferTem, sizeof(CS));
	///校验
	unsigned char  databufTem[2048];
	unsigned char  databuf_Out[2048];
	for (int i = 2; i < iLen; i++)
	{
		databufTem[i - 2] = pBufferTem[i];
	}

	EnCrypt((char *)databufTem, iLen - 2, (char*)databuf_Out);//解密
	unsigned short checkCS = GetCheckCode((unsigned char *)databuf_Out, iLen - 2);//获得校验
	if (checkCS != CS)
	{
		printf("JIAOJIAN111\n");
		return false;
	}
	//--------------拷贝
	m_iKey = 0;
	int iCpy_Len = 0;
	memcpy(&m_iKey, databuf_Out, 4);
	iCpy_Len += 4;

	m_iRand = 0;
	memcpy(&m_iRand, databuf_Out + iCpy_Len, 4);
	iCpy_Len += 4;

	return true;
}



bool CGameShowIamge::setRand(unsigned char* pBuffer, int iLen)
{
	unsigned char sbuf[512];//receive data
	char cBufTem[512];

	int iDataLen = iLen;
	EnCrypt((char *)pBuffer, iDataLen, cBufTem);//����
	unsigned short CS = GetCheckCode(pBuffer, iDataLen);//���У��

	memcpy(sbuf, &CS, sizeof(CS));
	memcpy(sbuf + 2, cBufTem, iDataLen);

	string strFile = esKeyPath;
	FILE* pRecFile = fopen(strFile.c_str(), "rb+");

	if (pRecFile == NULL)////不存在创建文件
	{
		pRecFile = fopen(strFile.c_str(), "w");
		if (pRecFile != NULL)
			fclose(pRecFile);
		///再次打开
		pRecFile = fopen(strFile.c_str(), "rb+");
	}
	if (pRecFile != NULL)
	{
		///禁用缓冲区
		setvbuf(pRecFile, NULL, _IONBF, 0);
		int ret = fwrite((char*)sbuf, iLen+2, 1, pRecFile);

		if (ret != 1)///存储错误
		{
			return false;
		}
		else
		{
			fflush(pRecFile);
		}
	}
	else///打开失败 
	{
		return false;
	}

	if (pRecFile != NULL && fclose(pRecFile) != 0)
	{

	}
	printf("wIRT_KEY_SUC\n");
	return true;
	//mWindow->getSysSetting()->GetInPutSetting()->setCfg("driver_file_rand", (const char*)sbuf);
	//mWindow->getSysSetting()->GetInPutSetting()->WirtConfig();
	//setCfg("youtube_input_key", (const char*)m_pWriteBuf);//
}

#pragma pack()
