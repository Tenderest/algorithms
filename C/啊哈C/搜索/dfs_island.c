// 宝岛探险 深度优先搜索
#include <stdio.h>
int a[51][51];
int book[51][51], n, m, sum;
void dfs (int x, int y)
{
        // 定义一个用于表示走的方向的数组
        int next[4][2] = {
                {0, 1},  // 向右走
                {1, 0},  // 向下走
                {0, -1}, // 向左走
                {-1, 0}  // 向上走
        };

        int k, tx, ty;

        // 枚举 4 个方向
        for ( k = 0; k <= 3; k ++ )
        {
                // 尝试走的下一个点的坐标
                tx = x + next[k][0];
                ty = y + next[k][1];

                // 判断是否越界
                if ( tx < 0 || tx > n || ty < 0 || ty > m )
                {
                        continue;
                }
                
                // 判断是否为陆地或者曾经走过
                if ( a[tx][ty] > 0 && book[tx][ty] == 0 )
                {
                        sum ++;
                        // 需要标记这个点已经走过
                        book[tx][ty] = 1;
                        dfs(tx, ty);
                }
        }

        return ;
}
int main(void)
{
        int i, j, startx, starty;
        // 读入 n 行 m 列以及小哼降落的坐标
        scanf("%d %d %d %d", &n, &m, &startx, &starty);

        // 读入地图
        for ( i = 1; i <= n; i ++ )
        {
                for ( j = 1; j <= m; j ++ )
                {
                        scanf("%d", &a[i][j]);
                }
        }

        book[startx][starty] = 1;
        sum = 1;

        // 从降落位置开始
        dfs(startx, starty);

        printf("%d\n", sum);
        return 0;
}
