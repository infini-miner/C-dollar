// vm-c$.c
#include <stdio.h>
#include <windows.h>

__declspec(dllexport)
void PrintMessage() {
    printf("�� ���� ������ � EXE �� ��� DLL.\n");
}