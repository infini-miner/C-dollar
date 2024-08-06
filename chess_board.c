#include <stdio.h>
#include <locale.h>
#include <string.h>
//
//char fop(FILE *h, const char *fn);
//
int main(int argc, char *argv[])
{
    setlocale(0, ""); // ��������� ������� ����
    //
    FILE* h = NULL;
    h = fopen("compiler.cfg", "rb"); // ������� ����
    if (h == NULL) // ���� ���� �� ����������, ��
    {
        h = fopen("compiler.cfg", "wb"); // �������� ���, �
        if (h == NULL) // ����� ��������, ��� ���� ������
        {
            printf("�� ���� ������� ����.");
            return -1;
        }
        printf("���� ������ � ������ �� ������.\n");
        char cfg[32] = "��������� � �����";
        // �������� ��� ����������������� ������� �� ���������
        fputs(cfg, h);
    }
    else
    {
        printf("���� ������ �� ������.\n"); // ���� ���� ����������, �� ������� � ���� ���������������� ������
        //if (fop(h, "compiler.cfg") == -1) return 1;
        char cfg[32]; cfg[0] = '\0';
        printf("A | cfg[] = \"%s\"\n", cfg);
        fgets(cfg, sizeof (cfg), h);
        printf("B | cfg[] = \"%s\"\n", cfg);
        if (!strcmp(cfg, "��������� � �������"))
        {
            printf("��������� � �������.");
            printf("���������� ���������� ���������� ������� main: %d.\n", argc);
            for (int i = 0; i < argc; ++i)
            {
                printf("�������� %d: %s\n", i, argv[i]);
            }
        }
        else if (!strcmp(cfg, "��������� � �����"))
        {
            printf("��������� � �����.\n");
        }
    }
    fclose(h);
    printf("���� ������.");
    /*
    char symbol;
    if ((symbol = fgetc(h)) == EOF) // ���� ���� ����, ��
    {
        printf("���� ������.\n");
    }
    else printf("���� �������� ������.");
    */
    return 0;
}
/*
char fop(FILE *h, const char *fn)
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
        // �������� ��� ����������������� ������� �� ���������
        fputs("��������� � �����", h);
        //fclose(h);
        //printf("���� ������.\n");
        
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
*/