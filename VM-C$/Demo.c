/*/
 **
 *   /!\ ��������� ����� ������ ���� Windows-1251.
 *   /!\ File encoding must be Windows-1251.
 * 
 *   ���� ���� ������ ������������� � ���������������� �����, ����� ��������, ��� ������������ ������� VM-API.
 *   �������� ��������� � ������� ����������� GCC.
 * 
 *   This file is created for demonstration purposes only to show how to use VM-API functions.
 *   Build the program using the GCC compiler.
 * 
 *   >_ gcc -o file_name.exe file_name.c VM-API.c
 *   >_ gcc file_name.exe
 **   
/*/
#include <locale.h>
#include "VM-API.h"

int main()
{
    setlocale(0, "");
    if (!VM_Init("VM-C$.dll")) return 1;
    VM_PrintMessage();
    VM_Cleanup();
    return 0;
}