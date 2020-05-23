// 解决负权边
// 检测负权回路
#include <stdio.h>
int main(void)
{
        int dis[10], i, k, n, m, u[10], v[10], w[10], bak[10], check, flag;
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
                // 将 dis 数组备份至 bak 数组中
                for ( i = 1; i <= n; i ++ )
                {
                        bak[i] = dis[i];
                }
                
                // 进行一轮松弛
                for ( i = 1; i <= m; i ++ )
                {
                        if ( dis[v[i]] > dis[u[i]] + w[i] )
                        {
                                dis[v[i]] = dis[u[i]] + w[i];
                        }
                        
                }
                
                // 松弛完毕后检测 dis 数组是否有更新
                check = 0;
                for ( i = 1; i <= n; i ++ )
                {
                        if ( bak[i] != dis[i] )
                        {
                                check = 1;
                                break;
                        }
                        
                }
                // 如果 dis 数组没有更新，提前退出循环结束算法
                if ( check == 0 )
                {
                        break;
                }
        }
        
        // 检测负权回路
        flag = 0;
        for ( i = 1; i <= m; i ++ )
        {
                if ( dis[v[i]] > dis[u[i]] + w[i] )
                {
                        flag = 1;
                }
        }
        
        if ( flag = 1 )
        {
                printf("此图含有负权回路");
        }
        
        else
        {
                // 输出最终结果
                for ( i = 1; i <= n; i ++ )
                {
                        printf("%d ", dis[i]);
                }
        }
        
        return 0;
}
