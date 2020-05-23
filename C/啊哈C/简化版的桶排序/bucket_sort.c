#include <stdio.h>
void eatline() { while (getchar() != '\n') {continue;} }
int main(void)
{
        int book[1001] = {0}; // 创建一个计数的数组
        int tmp = 0;          // 存储数组索引
        int n;                // 有多少个数据要输入
        scanf("%d", &n);
        eatline();
        for ( int index = 0; index < n; index ++ )
        {
                scanf("%d", &tmp); // 读取数据
                eatline();
                book[tmp] ++;      // 数组中计数
        }
        
        for ( int index = 0; index < 1001; index ++ )
        {
                for ( int count = 1; count <= book[index]; count ++ )
                {
                        printf("%d ", index);
                }
        }
        
        return 0;
}
