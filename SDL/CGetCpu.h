/*************************************************************************
    > File Name: cpuid.c
    > Author:
    > Mail:
    > Created Time:
 ************************************************************************/
#ifndef _CGETCPU_H_
#define _CGETCPU_H_

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include<ctype.h> //isspace
 
//memcpy
// C语言：#include<string.h>
// C++：#include<cstring>
#include<string.h>
 
//X86 linux获取cpu ID
static inline char* skip_ws(const char *p)
{
	while (isspace(*p)) p++;
	return (char *)p;
}
 
static inline char* skip_token(const char *p)
{
	while (isspace(*p)) p++;
	while (*p && !isspace(*p)) p++;
	return (char *)p;
}
 
int GetCpuIdByAsm_x86(char* cpu_id)
{
#if !WIN32
	char cpuId[256] = { 0 };
	size_t length = 0;
	FILE* fp = popen("sudo dmidecode -t 4 | grep ID", "r");
	if (fp)
	{
		char* ci = fgets(cpuId, sizeof(cpuId) - 1, fp);
		if (ci)
		{
			char* pstr = skip_ws(skip_token(cpuId));
			char* pchar = pstr;
			while (*pchar)
			{
				if (*pchar == ' ')
				{ // is space
					*pchar++ = '-';
				}
				else
				{
					++pchar;
				}
			}

			memcpy(cpu_id, pstr, strlen(cpuId));
		}
		else
		{
			fclose(fp);
			return -1;
		}
		pclose(fp);
	}
#endif // !WIN32

	
 
	return 0;
}
 
//ARM linux获取cpu ID
int GetCpuIdByAsm_arm(char* cpu_id)
{
	FILE *fp = fopen("/proc/cpuinfo", "r");
	if(NULL == fp)
	{
		printf("failed to open cpuinfo\n");
		return -1;
	}
 
	char cpuSerial[256] = {0};
 
	while(!feof(fp))
	{
		memset(cpuSerial, 0, sizeof(cpuSerial));
		fgets(cpuSerial, sizeof(cpuSerial) - 1, fp); // leave out \n
 
		char* pch = strstr(cpuSerial,"Serial");
		if (pch)
		{
			char* pch2 = strchr(cpuSerial, ':');
			if (pch2)
			{	
				memmove(cpu_id, pch2 + 2, strlen(cpuSerial));
 
				break;
			} 
			else
			{
                fclose(fp);
				return -1;
			}
		}
	}
	fclose(fp);
 
	return 0;
}
 
//X86、ARM获取cpu name
int GetCpuInfo(char* cpuName)
{
	FILE *fp = fopen("/proc/cpuinfo", "r");
	if(NULL == fp)
	{
		printf("failed to open cpuinfo\n");
		return -1;
	}
	char cpuModel[100] = {0};
 
	while(!feof(fp))
	{
		memset(cpuModel, 0, sizeof(cpuModel));
		fgets(cpuModel, sizeof(cpuModel) - 1, fp); // leave out \n
 
		char* pch = strstr(cpuModel,"model name");
		if (pch)
		{
			char* pch2 = strchr(cpuModel, ':');
			if (pch2)
			{	
				memmove(cpuName, pch2 + 2, strlen(cpuModel));
 
				break;
			} 
			else
			{
                fclose(fp);
				return -1;
			}
		}
	}
	fclose(fp);
 
	return 0;
}

#endif
 
/*int main(int argc, char **argv)
{
	int result;
 
	//获得文件状态信息
	if (argc > 1)
	{
		printf("%s\n", argv[1]);
	}
	else
	{
		printf("%s\n", argv[0]);
	}
 
	char cpu_id_x86[40] = {0};
	result = GetCpuIdByAsm_x86(cpu_id_x86); //EC-06-08-00-FF-FB-8B-1F
	if (result < 0)
	{
		printf("GetCpuIdByAsm_x86 failed\n");
	}
	else
	{
		int len = strlen(cpu_id_x86);
		if (iscntrl(cpu_id_x86[len-1]))
		{
			len--;
			cpu_id_x86[len] = 0;
		}
		
		printf("cpu id x86(%d) = %s\n", len, cpu_id_x86);
	}
 
	char cpu_id_arm[40] = {0};
	result = GetCpuIdByAsm_arm(cpu_id_arm); //EC-06-08-00-FF-FB-8B-1F
	if (result < 0)
	{
		printf("GetCpuIdByAsm_arm failed\n");
	}
	else
	{
		int len = strlen(cpu_id_arm);
		if (iscntrl(cpu_id_arm[len-1]))
		{
			len--;
			cpu_id_arm[len] = 0;
		}
		
		printf("cpu id arm(%d) = %s\n", len, cpu_id_arm);
 
		int i=0;
		for (; i<len; i++)
		{
			if (cpu_id_arm[i] != '0')
				break;
		}
		if (i == len)
		{
			printf("Serial is false\n");
		}
	}
 
	char cpu_name[40] = {0};
	result = GetCpuInfo(cpu_name); //EC-06-08-00-FF-FB-8B-1F
	if (result < 0)
	{
		printf("GetCpuInfo failed\n");
	}
	else
	{
		int len = strlen(cpu_name);
		if (iscntrl(cpu_name[len-1]))
		{
			len--;
			cpu_name[len] = 0;
		}
		
		printf("cpu name(%d) = %s\n", len, cpu_name);
	}
 
	return 0;
}*/