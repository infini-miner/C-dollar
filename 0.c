#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
// ����������� ������
typedef enum
{
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_HALT // ������� ���������
} Opcode;
// ��������� ����������� ������ (VM) -  ����� �������� ������ ����, �������� ����
typedef struct
{
    unsigned char* code;
    int pc; // Program Counter
} VM;
// �������, ����������� �������
void op_add(VM *vm)
{
    printf("op_add();\n");
}
void op_sub(VM *vm)
{
    printf("op_sub();\n");
}
void op_mul(VM *vm)
{
    printf("op_mul();\n");
}
void op_div(VM *vm)
{
    printf("op_div();\n");
}
void op_halt(VM *vm)
{
    printf("op_halt();\n");
}
// ������� ���������
void (*op_table[])(VM*) = { op_add, op_sub, op_mul, op_div, op_halt };
// ���������� ���� ����������� ������
int execute(VM* vm)
{
    while (1)
    {
        vm->pc = 0;
        vm->code = "\0";
        printf("vm->pc = %i\n", vm->pc);
        printf("vm->code = \"%s\"\n", vm->code);
        printf("vm->code[vm->pc] = \"%s\"\n", vm->code[vm->pc]);
        Opcode opcode = (Opcode) vm->code[vm->pc++]; // ��������� ���� ��������
        // �������� �� ������������ o�-����, ��������� ������
        if (opcode >= sizeof (op_table) / sizeof (op_table[0]))
        {
            fprintf(stderr, "Invalid opcode: %d\n", opcode);
            return EXIT_FAILURE; // ��� ������ ��������, ��������������� �� ������
        }
        op_table[opcode](vm);  // ����� ��������������� �������
        if (opcode == OP_HALT) break;
    }
    return EXIT_SUCCESS;
}
int main(void)
{
    setlocale(0, "");
    // ������������� VM (�������� ���� � �.�.)
    VM vm;
    // ...
    execute(&vm);
    return 0;
}