/*/
 *   /!\ Encoding Windows-1251
 *   /!\ ��������� Windows-1251
/*/
#include <stdio.h>   // ��� �����/������ ������ �� �������.
#include <locale.h>  // ��� ����������� �������.
#include <stdbool.h> // ��� ������������� ���������� �����: false/true.

char bytecode[] = {0x00, 0x00, 0x00, 0x01};
short ip = 0x0000;

void Start_vCPU()
{
    void *instructions[] =
    {
        &&nop,
        &&hlt
    };
    while (true)
    {
        goto *instructions[bytecode[ip]]; // ������ *(ptr_label+i).
        nop: // ��������
        puts("#DEBUG: NOP - ��������");
        ip++;
        continue;
        hlt: // ������������� ���������� vCPU
        puts("#DEBUG: HLT - ���������� ���������� vCPU.");
        break;
    }
}
int main()
{
    setlocale(0, "");
    Start_vCPU();
    return 0;
}