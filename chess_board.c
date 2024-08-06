#include <stdio.h>
#include <locale.h>
//
char fop(FILE* h, const char* fn);
//
int main()
{
    setlocale(0, ""); // ��������� ������� ����
    //
    FILE* h = NULL;
    if (fop(h, "compiler.cfg") == -1) return 1;
    char symbol;
    if ((symbol = fgetc(h)) == EOF) // ���� ���� ����, ��
    {
        printf("���� ������.\n");
        // �������� ��� ����������������� ������� �� ���������
        fputc('t', h);
        fputc('e', h);
        fputc('s', h);
        fputc('t', h);
    }
    else printf("���� �������� ������.");
    fclose(h);
    printf("���� ������.");
    return 0;
}
char fop(FILE* h, const char* fn)
{
    h = fopen(fn, "rb"); // ������� ����
    if (h == NULL) // ���� ���� �� ����������, ��
    {
        h = fopen(fn, "wb"); // �������� ���, �
        if (h == NULL) // ����� ��������, ��� ���� ������
        {
            printf("�� ���� ������� ����.");
            return -1;
        }
        printf("���� ������ � ������ �� ������.\n");
        fclose(h);
        printf("���� ������.\n");
        h = fopen(fn, "rb"); // ������� ����, � ������� ���������������� ������ � ����
        if (h == NULL) // ���� ���� �� ����������, ��
        {
            printf("�� ���� ������� ���� �� ������.");
            return -1;
        }
        printf("���� ���������� �� ������.\n"); // ���� ���� ����������, �� ������� � ���� ���������������� ������
    }
    else printf("���� ������ �� ������.\n"); // ���� ���� ����������, �� ������� � ���� ���������������� ������
    return 0;
}