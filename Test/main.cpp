
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>

HHOOK g_hMouseHook;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        PMSLLHOOKSTRUCT pmll = (PMSLLHOOKSTRUCT) lParam;

        printf("msg: %lu, x:%ld, y:%ld\n", wParam, pmll->pt.x, pmll->pt.y);

        switch (wParam)
        {
            case WM_MBUTTONDOWN:
                ShowCursor(FALSE);
                break;

            case WM_MBUTTONUP:
                ShowCursor(TRUE);
                break;
        }
    }

    return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
}


int main(void)
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
    return (int) msg.wParam;
}
