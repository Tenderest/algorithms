// 解救小哈 使用深度优先搜索
#include <stdio.h>
int n, m, p, q, min = 999999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step)
{
        int next[4][2] = {
                {0, 1},  // 向右走
                {1, 0},  // 向下走
                {0, -1}, // 向左走
                {-1, 0}  // 向上走
        };

        int tx, ty, k;
        // 判断是否达到小哈的位置
        if ( x == p && y == q )
        {
                // 更新最小值
                if ( step < min )
                {
                        min = step;
                }
                // 注意返回
                return ;
        }
        
        // 枚举 4 钟走法
        for ( k = 0; k <= 3; k ++ )
        {
                // 计算下一个点的坐标
                tx = x + next[k][0];
                ty = y + next[k][1];
                // 判断是否越界
                if ( tx < 1 || tx > n || ty < 1 || ty > m )
                {
                        continue;
                }
                // 判断该点是否为障碍物或者已经在路径中
                if ( a[tx][ty] == 0 && book[tx][ty] == 0 )
                {
                        book[tx][ty] = 1;      // 标记这个点的标记
                        dfs(tx, ty, step + 1); // 开始尝试下一个点
                        book[tx][ty] = 0;      // 尝试结束，取消这个点的标记
                }
        }
        return ;
}

int main(void)
{
        int i, j, startx, starty;
        // 读入 n 和 m ，n 为行，m 为列
        scanf("%d %d", &n, &m);
        // 读入迷宫
        for ( i = 1; i <= n; i ++ )
        {
                for ( j = 1; j <= m; j ++ )
                {
                        scanf("%d", &a[i][j]);
                }
        }
        // 读入起点和终点坐标
        scanf("%d %d %d %d", &startx, &starty, &p, &q);

        // 从起点开始搜索
        book[startx][starty] = 1; // 标记起点已经在路径中，防止后面重复走
        // 第一个参数是起点的 x 坐标，第二个参数是起点的 y 坐标，第三个参数是初始步数为 0
        dfs(startx, starty, 0);

        // 输出最短步数
        printf("%d", min);
        return 0;
}
