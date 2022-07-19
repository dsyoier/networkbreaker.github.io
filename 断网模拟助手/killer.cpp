#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
HWND hwnd = GetForegroundWindow();
void HideWindow() {
    ShowWindow(hwnd, SW_HIDE);
}
char wifi[120]={"netsh wlan connect name = "};
int main() {
	printf("请输入时分秒：\n");
	int dd,mm,ss;
	long long  times;
	scanf("%d时%d分%d秒",&dd,&mm,&ss);
	printf("请输入WiFi名称：\n");
	scanf("%s",wifi+26);
	system("pause");
	times = (dd*3600+mm*60+ss)*1e9; 
	freopen("nul","w",stdout);
	freopen("nul","r",stdin);
	HideWindow();
	long long t = chrono::system_clock::now().time_since_epoch().count();
	system("@echo off");
	while(1){
//		system("taskkill /f /im chrome.exe > nul");
//		system("taskkill /f /im 360se.exe > nul");
//		system("taskkill /f /im 360chrome.exe > nul");
		system(wifi); 
		if(t + times < chrono::system_clock::now().time_since_epoch().count())break;
	}	
	MessageBox(NULL,"时间到了，\n，傻逼。","提醒",MB_OK);
	system("taskkill /f /im devcpp.exe");
//	system("cmd");
	return 0;
}
/*0时0分20秒*/
