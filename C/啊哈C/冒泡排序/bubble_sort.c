#include <stdio.h>
void eatline() { while (getchar() != '\n') {continue;} }
int main(void)
{
        int arr[10] = {0}; // 创建一个数组存放数据
        int n;             // 有多少个数据要输入 
        scanf("%d", &n);
        eatline();
        for ( int index = 1; index <= n; index ++ )
        {
                scanf("%d", &arr[index]);
                eatline();
        }
        
        for ( int index = 0; index < n; index ++ )
        {
                printf("%d ", arr[index]);
        }
        putchar('\n');

        printf("Sorting ... ...\n");
        // 原书j=1因为a[0] 不存储任何值，但书中并为描述
        for ( int i = 1; i <= n - 1; i ++ ) // n个数排序，只用进行n-1趟
        {
                for ( int d = 1; d <= n - i; d ++ )
                // 从第1位开始比较直到最后一个尚未归位的数，想一想为什么到n-i就可以了。
                // 因为循环比较过后有 i 个数已经被排好了
                // 原书j=1因为a[0] 不存储任何值，但书中并为描述
                // 因此可用arr[0]来做为临时交换变量
                {
                        if ( arr[d] < arr[d + 1] )
                        {
                                arr[0] = arr[d];
                                arr[d] = arr[d + 1];
                                arr[d + 1] = arr[0];
                        }
                }
        }
        
        printf("Print:\n");
        for ( int index = 1; index <= n; index ++ )
        {
                printf("%d ", arr[index]);
        }
        
        return 0;
}
