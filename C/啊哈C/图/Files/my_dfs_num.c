#include <stdio.h>
int e[101][101] = {0};
int book[101] = {0};
// n 表示顶点的总个数 m 表示有多少条边
// int i, j, a, b, n, m;
// 注意全局变量的问题，dfs 时 for 循环会出错
int a, b, n, m;
void dfs (int cur)
{
        // 注意全局变量的问题
        int i;
        printf("%d ", cur);
        if ( cur == n )
        {
                return ;
        }
        
        
        // 如果是全局变量会出错
        for ( i = 1; i <= n; i ++ )
        {
                if ( e[cur][i] == 1 && book[i] == 0 )
                {
                        book[i] = 1;
                        dfs(i);
                }
        }
        return ;
}
int main(void)
{
        int i, j;
        scanf("%d %d", &n, &m);
        // 初始化二维矩阵
        for ( i = 1; i <= n; i ++ )
        {
                for ( j = 1; j <= n; j ++ )
                {
                        if ( i == j )
                        {
                                e[i][j] = 0;
                        }
                        else
                        {
                                e[i][j] = 999999;
                        }
                }
        }
        

        // 读入边
        for ( i = 1; i <= m; i ++ )
        {
                scanf("%d %d", &a, &b);
                // 无向图
                e[a][b] = 1;
                e[b][a] = 1;
        }
        
        book[1] = 1;
        dfs(1);
        return 0;
}
