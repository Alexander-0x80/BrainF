#include <stdio.h>
#include <stdlib.h>

#define PROG_HELLO ">++++++++[<+++++++++>-]<.>>+>+>++>[-]+<[>[->+<<++++>]<<]>.+++++++..+++.>>+++++++.<<<<+++++++++++++++.>>.+++.------.--------.>>+.>++++."
#define PROG_FIB "+++++++++++>+>>>>++++++++++++++++++++++++++++++++++++++++++++>++++++++++++++++++++++++++++++++<<<<<<[>[>>>>>>+>+<<<<<<<-]>>>>>>>[<<<<<<<+\
                >>>>>>>-]<[>++++++++++[-<-[>>+>+<<<-]>>>[<<<+>>>-]+<[>[-]<[-]]>[<<[>>>+<<<-]>>[-]]<<]>>>[>>+>+<<<-]>>>[<<<+>>>-]+<[>[-]<[-]]>[<<+>>[-]]<<\
                <<<<<]>>>>>[++++++++++++++++++++++++++++++++++++++++++++++++.[-]]++++++++++<[->-<]>++++++++++++++++++++++++++++++++++++++++++++++++.[-]<<\
                <<<<<<<<<<[>>>+>+<<<<-]>>>>[<<<<+>>>>-]<-[>>.>.<<<[-]]<<[>>+>+<<<-]>>>[<<<+>>>-]<<[<+>-]>[<+>-]<<<-]"

#define MEM_SIZE 30000
#define INC_DP '>'
#define DEC_DP '<' 
#define INC '+'
#define DEC '-'
#define JZ '['
#define JNZ ']'
#define OUT '.'
#define INP ','

void run(char *program);

char mem[MEM_SIZE];
char *dp = mem;

void run(char *program)
{
    unsigned int level;
    char *pc = program;

    while (*pc)
    {
        switch(*pc)
        {
            case INC_DP:
                if (*dp == MEM_SIZE) 
                {
                    printf("Error: Pointer Overflow!\n");
                    exit(1);
                }

                ++dp;
                break;
            case DEC_DP:
                if (dp == &mem[0])
                {
                    printf("Error: Pointer Underflow!\n");
                    exit(1);
                }

                --dp;
                break;
            case INC:
                ++(*dp);
                break;
            case DEC:
                --(*dp);
                break;
            case JZ:
                if (! *dp)
                {
                    level++;
                    while(level)
                    {
                        pc++;
                        if (*pc == JZ) level++;
                        if (*pc == JNZ) level--;
                    }
                }
                break;
            case JNZ:
                if (*dp)
                {
                   level++;
                   while (level)
                   {
                        pc--;
                        if (*pc == JZ) level--;
                        if (*pc == JNZ) level++;
                   }
                } 
                break;
            case OUT:
                putchar(*dp);
                break;
            case INP:
                *dp = getchar();
                break;
        }

        pc++;
    }
}

int main()
{
    run(PROG_HELLO);
    return 0;
}

