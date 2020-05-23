// 用数组简单的括号匹配
#include <stdio.h>
#include <string.h>
int main(void)
{
        char arr[20]; // input
        char s[20]; // stack
        printf("Input: ");
        gets(arr);
        int len = strlen(arr);
        int top = 0;
        int tmp = 0;
        for ( int index = 0; index < len; index ++ )
        {
                if ( arr[index] == '(' )
                {
                        s[top] = arr[index];
                        top ++;
                }
                if ( arr[index] == '[' )
                {
                        s[top] = arr[index];
                        top ++;
                }
                if ( arr[index] == '{' )
                {
                        s[top] = arr[index];
                        top ++;
                }
                

                if ( arr[index] == ')' )
                {
                        if ( s[--top] == '(' )
                        {
                        }
                        else tmp ++;
                }
                if ( arr[index] == ']' )
                {
                        if ( s[--top] == '[' )
                        {
                        }
                        else tmp ++;
                }
                if ( arr[index] == '}' )
                {
                        if ( s[--top] == '{' )
                        {
                        }
                        else tmp ++;
                }
        }
        
        puts(arr);
        puts(s);
        if ( tmp == 0 )
        {
                printf("Yes\n");
        }
        else printf("No\n");

        return 0;
}
