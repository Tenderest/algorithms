// 使用数组模拟栈 匹配回文数
#include <stdio.h>
#include <string.h>
int main(void)
{
        char a[101], s[101];
        int i, len, mid, next, top;

        gets(a);           // 读取一行字符串
        len = strlen(a);   // 获取长度
        mid = len / 2 - 1; // 求字符串的中点

        top = 0; // 栈的初始化
        // 将 mid 以前的字符依次入栈
        // 包括mid
        for ( i = 0; i <= mid; i ++ )
        {
                s[++ top] = a[i];
        }
        
        // //判断字符串的长度是奇数还是偶数，并找出需要进行字符匹配的起始下标
        if ( len % 2 == 0 )
        {
                next = mid + 1;
        }
        else
        {
                next = mid + 2;
        }
        
        // 开始匹配
        for ( i = next; i <= len - 1; i ++ )
        {
                if ( a[i] != s[top] )
                {
                        break;
                }
                top --;
        }
        
        // //如果top的值为0，则说明栈内所有的字符都被一一匹配了
        if ( top == 0 )
        {
                printf("Yes\n");
        }
        else
        {
                printf("No\n");
        }
        return 0;
}
