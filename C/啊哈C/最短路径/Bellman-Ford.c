// 解决负权边
#include <stdio.h>
int main(void)
{
        int dis[10], i, k, n, m, u[10], v[10], w[10];
        int inf = 9999999; // 用inf（infintity的缩写）存储一个正无穷
        // 读入 n 和 m ，n 表示顶点个数，m 表示边的条数
        scanf("%d %d", &n, &m);

        // 读入边
        for ( i = 1; i <= m; i ++ )
        {
                scanf("%d %d %d", &u[i], &v[i], &w[i]);
        }
        
        // 初始化 dis 数组，这里是 1 号顶点到其余各个顶点的初始路程
        for ( i = 1; i <= n; i ++ )
        {
                dis[i] = inf;
        }
        dis[1] = 0;
        
        // Bellman-Ford 算法核心语句
        for ( k = 1; k <= n - 1; k ++ )
        {
                for ( i = 1; i <= m; i ++ )
                {
                        if ( dis[v[i]] > dis[u[i]] + w[i] )
                        {
                                dis[v[i]] = dis[u[i]] + w[i];
                        }
                        
                }
                
        }
        
        // 输出最终结果
        for ( i = 1; i <= n; i ++ )
        {
                printf("%d ", dis[i]);
        }
        
        return 0;
}
