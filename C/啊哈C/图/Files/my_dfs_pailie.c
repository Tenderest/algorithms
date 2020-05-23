#include <stdio.h>
int book[101] = {0};
// 需要有一个数组存放数据
int a[101] = {0};
int n, step = 0;
void dfs (int step)
{
        int i;
        if ( step == n + 1 )
        {
                for ( i = 1;  i <= n; i ++ )
                {
                        printf("%d", a[i]);
                }
                printf("\n");
                return;
        }
        
        for ( i = 1; i <= n; i ++ )
        {
                if ( book[i] == 0 )
                {
                        a[step] = i;
                        book[i] = 1;
                        dfs(step + 1);
                        book[i] = 0;
                }
        }
        return ;
}

int main(void)
{
        scanf("%d", &n);
        dfs(1);
        return 0;
}
