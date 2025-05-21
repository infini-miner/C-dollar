#include <locale.h>
#include "VMWrapper.h"

int main()
{
    setlocale(0, "");
    if (!VM_Init("VM-C$.dll")) return 1;
    VM_PrintMessage();
    VM_Cleanup();
    return 0;
}
/*
// VortexEngine.c
#include <windows.h>
#include <stdio.h>

#include <locale.h>

// ��������� ��� �������, ��� � DLL
typedef void (*PrintMessageFunc)();

int main()
{
    setlocale(0, "");

    // ��������� DLL
    HMODULE hDll = LoadLibraryA("VM-C$.dll");
    if (!hDll) {
        printf("�� ������� ��������� DLL.\n");
        return 1;
    }

    // �������� ����� �������
    PrintMessageFunc printFunc = (PrintMessageFunc) GetProcAddress(hDll, "PrintMessage");
    if (!printFunc) {
        printf("�� ������� ����� ������� PrintMessage.\n");
        return 1;
    }

    // �������� �������
    printFunc();

    // ����������� DLL
    FreeLibrary(hDll);
    return 0;
}
*/