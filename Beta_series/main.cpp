#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>
#include <winuser.h>
#include <iostream>
#include <iomanip>
#include <tlhelp32.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <dos.h>
#include <conio.h>


using namespace std;

HHOOK g_hMouseHook;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        PMSLLHOOKSTRUCT pmll = (PMSLLHOOKSTRUCT) lParam;
        switch (wParam)
        {
            case WM_LBUTTONDOWN:
                printf("msg: %lu, x:%ld, y:%ld\n", wParam, pmll->pt.x, pmll->pt.y);

                break;

            case WM_LBUTTONDBLCLK:
                printf("msg: %lu, x:%ld, y:%ld\n", wParam, pmll->pt.x, pmll->pt.y);
                break;
        }
    }
    return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
}

DWORD GetPidByName(char *szProcName)
{
    bool present = false;
  HANDLE hSnap;
  DWORD dwPID = 0;
  PROCESSENTRY32 pe = {sizeof(PROCESSENTRY32)};

  if((hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0))!= INVALID_HANDLE_VALUE)
  {
    if(Process32First(hSnap, &pe))
    {
      do
      {
        if(strcmpi(pe.szExeFile, szProcName) == 0)
        {
          dwPID = pe.th32ProcessID;
          break;
        }
      }
      while(Process32Next(hSnap, &pe) & !present);
    }
    CloseHandle(hSnap);
  }
  return dwPID;
}

void left_click(int x, int y)
{
	SetCursorPos(x,y);   //positionne le curseur
     mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);   //appuie sur le bouton gauche de la souris
     mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);   //relache---
}

void right_click(int x, int y)
{
    SetCursorPos(x,y);   //positionne le curseur
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}

void keyPress(byte key)
{
    keybd_event(key, 0, 0, 0);
    keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
}

void keyPressMulitple(BYTE key1, BYTE key2)
{
    keybd_event(key1,0xb8,0 , 0); //Alt Press
    keybd_event(key2,0x8f,0 , 0); // Tab Press
    keybd_event(key2,0x8f, KEYEVENTF_KEYUP,0); // Tab Release
    keybd_event(key1,0xb8,KEYEVENTF_KEYUP,0); // Alt Release
}

void setFocus(HWND h)
{
    BringWindowToTop(h);
    SetForegroundWindow(h);
    SetFocus(h); //Just playing safe
}

HWND myhWnd;
DWORD dapid;
DWORD processid;
BOOL CALLBACK MyEnumProc(HWND hWnd, LPARAM lParam)
{
    GetWindowThreadProcessId(hWnd, &dapid);

    if(dapid==processid)
    {
        setFocus(hWnd);
        myhWnd=hWnd;
    }
}

void recupereClicSouris()
{
    MSG msg;
    g_hMouseHook = SetWindowsHookEx( WH_MOUSE_LL, LowLevelKeyboardProc, GetModuleHandle(NULL), 0 );

    if (!g_hMouseHook) printf("err: %d\n", GetLastError());

    while ( GetMessage(&msg, NULL, 0, 0) )
    {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(g_hMouseHook);
}


void beta_series()
{
    processid = GetPidByName("firefox.exe");

    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, false, processid);
    EnumWindows(MyEnumProc, NULL);
    //beta series  874 355    678 512
    //google 615 325    32  460

    int wait = 5000;
    left_click(615, 325); // 1er clic alias gmail
    Sleep(wait);
    left_click(32, 460); //second clic alias prog
    Sleep(2000);
    //keyPressMulitple(VK_MENU,VK_TAB);
    keyPress(VK_NEXT);
    Sleep(1000);

    left_click(975, 44);//clic sur le champ recherche google
    Sleep(1000);
    int i;
    char* texte = "thomas cook";
    for (i = 0; i <= strlen(texte)-1; i++)
    {
        keybd_event(VkKeyScan(texte[i]),0x9e,0 , 0);
    }
    left_click(975, 44);//clic validation

    Sleep(wait);
}



int main(void)
{
    //recupereClicSouris();
    beta_series();

   return 0;
}

/*
    DWORD thepid;
    HWND fenetre=FindWindowEx(0,0,0,0);
    do
    {
        GetWindowThreadProcessId(fenetre,&thepid);
        if(thepid==processid) SetForegroundWindow(fenetre);
        fenetre=FindWindowEx(0,fenetre,0,0);
    }while(fenetre);
*/
