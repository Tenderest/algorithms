// 最短路径 深度优先搜索
#include <stdio.h>
int min = 99999999, book[101], n, e[101][101]; // 假设99999为正无穷

// cur 是当前所在城市编号，dis 是当前已经走过的路程
void dfs (int cur, int dis)
{
        int j;
        // 如果当前走过的路程已经大于之前找到的最短路径，则没有必要继续尝试了，立即返回
        if ( dis > min )
        {
                return ;
        }
        // 判断是否到达了目标城市
        if ( cur == n )
        {
                if ( dis < min )
                {
                        // 更新最小值
                        min = dis;
                }
                return ;
        }
        // 从 1 号城市到 n 号城市一次尝试
        for ( j = 1; j <= n; j ++ )
        {
                // 判断当前城市 cur 到城市 j 是否有路，并判断城市 j 是否在已走过的路径中
                if ( e[cur][j] != 9999999 && book[j] == 0 )
                {
                        // 标记城市 j 已经在路径中
                        book[j] = 1;
                        // 再从城市 j 出发，继续寻找目标城市
                        dfs(j, dis + e[cur][j]);
                        // 之前一步探索完毕之后，取消对城市 j 的标记
                        book[j] = 0;
                }
        }
        return ;
}

int main(void)
{
        int i, j, m, a, b, c;
        scanf("%d %d", &n, &m);

        // 初始化二维矩阵
        for ( i = 1; i <= n; i ++ )
        {
                for ( j = 1; j <= m; j ++ )
                {
                        if ( i == j )
                        {
                                e[i][j] = 0;
                        }
                        else
                        {
                                e[i][j] = 99999999; // 我们这里假设99999999为正无穷
                        }
                }
        }
        
        // 读入顶点之间的道路
        for ( i = 1; i <= m; i ++ )
        {
                scanf("%d %d %d", &a, &b, &c);
                e[a][b] = c;
        }
        
        // 从 1 号城市出发
        // 标记 1 号城市已经走过
        book[1] = 1;
        // 从 1 号城市开始遍历
        dfs(1, 0);

        printf("%d", min);
        return 0;
}
