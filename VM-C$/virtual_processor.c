#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(0, "");
    void *ptr_label[] = {&&_1, &&_2, &&_3};
    for (char i = 0; i < 3; i++)
    {
        goto *ptr_label[i]; // ������ *(ptr_label+i)
        _1:
        puts("� ����� � ����� 1.");
        continue;
        _2:
        puts("� ����� � ����� 2.");
        continue;
        _3:
        puts("� ����� � ����� 3.");
        continue;
    }
    return 0;
}