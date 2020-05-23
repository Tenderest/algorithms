#include <stdio.h>
#include <string.h>
int main(void)
{
        // RLRRLLRLRL ---> RL RRLL RL RL
        // RLLLLRRRLR ---> RL LLLRRR LR
        // LLLLRRRR   ---> LLLLRRRR
        char input[20];
        char * next = NULL;
        char tmp[2];
        int num = 0;

        // 输入
        fgets(input, 20, stdin);
        next = input;

        /* while ( *next != '\0' ) */
        /* { */
        /*         /1* printf("%c", *next); *1/ */
        /*         if ( input[0] == 'L' ) // 字符串开头是L */
        /*         { */
        /*                 if ( *next == 'L' ) */
        /*                 { */
        /*                         tmp['L' - 'L'] ++; */
        /*                 } */
        /*                 else if ( *next == 'R' ) */
        /*                 { */
        /*                         tmp['R' - 'R' + 1] ++; */
        /*                 } */
        /*         } */
        /*         else if ( input[0] == 'R' ) // 字符串开头是R */
        /*         { */
        /*                 if ( *next == 'R' ) */
        /*                 { */
        /*                         tmp['R' - 'R'] ++; */
        /*                 } */
        /*                 else if ( *next == 'L' ) */
        /*                 { */
        /*                         tmp['L' - 'L' + 1] ++; */
        /*                 } */
        /*         } */
                

        /*         if ( tmp[0] == tmp[1] ) */
        /*         { */
        /*                 if ( input[0] == 'L' ) // 字符串开头是L */
        /*                 { */
        /*                         for ( int i = 0; i < tmp[0]; i ++ ) */
        /*                         { */
        /*                                 printf("L"); */
        /*                         } */
        /*                         for ( int j = 0; j < tmp[1]; j ++ ) */
        /*                         { */
        /*                                 printf("R"); */
        /*                         } */
        /*                         putchar('\n'); */
        /*                 } */
        /*                 else if ( input[0] == 'R' ) // 字符串开头是R */
        /*                 { */
        /*                         for ( int i = 0; i < tmp[0]; i ++ ) */
        /*                         { */
        /*                                 printf("R"); */
        /*                         } */
        /*                         for ( int j = 0; j < tmp[1]; j ++ ) */
        /*                         { */
        /*                                 printf("L"); */
        /*                         } */
        /*                         putchar('\n'); */
        /*                 } */
        /*                 /1* num = tmp[0] + tmp[1]; *1/ */
        /*                 tmp[0] = tmp[1] = 0; */
        /*         } */
        /*         next ++; */
        /* } */
        
        
        while ( *next != '\0' )
        {
                /* printf("%c", *next); */
                if ( input[num] == 'L' ) // 字符串开头是L
                {
                        if ( *next == 'L' )
                        {
                                tmp['L' - 'L'] ++;
                        }
                        else if ( *next == 'R' )
                        {
                                tmp['R' - 'R' + 1] ++;
                        }
                }
                else if ( input[num] == 'R' ) // 字符串开头是R
                {
                        if ( *next == 'R' )
                        {
                                tmp['R' - 'R'] ++;
                        }
                        else if ( *next == 'L' )
                        {
                                tmp['L' - 'L' + 1] ++;
                        }
                }
                

                if ( tmp[0] == tmp[1] )
                {
                        if ( input[num] == 'L' ) // 字符串开头是L
                        {
                                for ( int i = 0; i < tmp[0]; i ++ )
                                {
                                        printf("L");
                                }
                                for ( int j = 0; j < tmp[1]; j ++ )
                                {
                                        printf("R");
                                }
                                putchar('\n');
                        }
                        else if ( input[num] == 'R' ) // 字符串开头是R
                        {
                                for ( int i = 0; i < tmp[0]; i ++ )
                                {
                                        printf("R");
                                }
                                for ( int j = 0; j < tmp[1]; j ++ )
                                {
                                        printf("L");
                                }
                                putchar('\n');
                        }
                        num = tmp[0] + tmp[1];
                        tmp[0] = tmp[1] = 0;
                }
                next ++;
        }
        return 0;
}
