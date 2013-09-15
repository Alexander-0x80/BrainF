#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 30000
#define OP_RIGHT '>'
#define OP_LEFT '<' 
#define OP_INC '+'
#define OP_DEC '-'
#define OP_F_MATCH '['
#define OP_B_MATCH ']'
#define P_BYTE '.'
#define R_BYTE ','

void interpret(char *program);

char mem[MEM_SIZE];
char *data_ptr = &mem[0];

void interpret(char *program)
{
    char *pc = program;
    
    while (*pc)
    {
        switch(*pc)
        {
            case OP_RIGHT:
                if (*data_ptr == MEM_SIZE) 
                {
                    printf("Error: Pointer Overflow!\n");
                    exit(1);
                }

                ++data_ptr;
                break;
            case OP_LEFT:
                if (data_ptr == &mem[0])
                {
                    printf("Error: Pointer Underflow!\n");
                    exit(1);
                }

                --data_ptr;
                break;
            case OP_INC:
                ++(*data_ptr);
                break;
            case OP_DEC:
                --(*data_ptr);
                break;
            case OP_F_MATCH:
                if (!*data_ptr)
                    while(*(++pc) != OP_B_MATCH);
                break;
            case OP_B_MATCH:
                if (*data_ptr)
                    while(*(--pc) != OP_F_MATCH);
                 break;
            case P_BYTE:
                putchar(*data_ptr);
                break;
            case R_BYTE:
                *data_ptr = getchar();
                break;
        }

        pc++;
    }
}

int main()
{
    interpret("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    return 0;
}

