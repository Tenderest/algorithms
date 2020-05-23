// 第三节 火柴棍等式
#include <stdio.h>
int fun (int x)
{
        int num = 0;
        int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        while ( x / 10 != 0 ) // 如果不等于0，说明至少有两位
        {
                num += f[x % 10];
                x = x / 10;
        }
        // 最后加上此时x所需的火柴棍的根数（此时x一定是一位数）
        num += f[x];
        return num;
}

int main(void)
{
        int a, b, c, m, i, sum = 0;
        scanf("%d", &m); // 读入火柴棍的个数
        // 开始枚举a和b
        for ( a = 0; a <= 1111; a ++ )
        {
                for ( b = 0; b <= 1111; b ++ )
                {
                        c = a + b;
                        // fun 用来计算一个数所需的火柴棍总数
                        if ( fun(a) + fun(b) + fun(c) == m - 4 )
                        {
                                printf("%d + %d = %d\n", a, b, c);
                                sum ++;
                        }
                }
        }
        
        printf("一共可以拼出%d个不同的等式\n", sum);
        return 0;
}
