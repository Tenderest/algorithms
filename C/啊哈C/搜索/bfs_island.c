// 宝岛探险 广度优先搜索
#include <stdio.h>
struct note
{
        int x; // 横坐标
        int y; // 纵坐标
};

int main(void)
{
        struct note que[2501];
        int head, tail;
        int a[51][51];
        int book[51][51] = {0};
        int i, j, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;
        // 定义一个用于表示走的方向的数组
        int next[4][2] = {
                {0, 1},  // 向右走
                {1, 0},  // 向下走
                {0, -1}, // 向左走
                {-1, 0}  // 向上走
        };

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

        // 队列初始化
        head = 1;
        tail = 1;
        
        // 往队列插入小人的起始坐标
        que[tail].x = startx;
        que[tail].y = starty;
        tail ++;
        book[startx][starty] = 1;
        sum = 1;
        // 当队列不为空的时候循环
        while ( head < tail )
        {
                // 枚举 4 个方向
                for ( k = 0; k <= 3; k ++ )
                {
                        // 计算走的下一个点的坐标
                        tx = que[head].x + next[k][0];
                        ty = que[head].y + next[k][1];

                        // 判断是否越界
                        if ( tx < 0 || tx > n || ty < 0 || ty > m )
                        /* if ( tx < 0 || tx > n || ty < 0 || ty > m ) */
                        {
                                continue;
                        }
                        
                        // 判断是否为陆地或者曾经走过
                        if ( a[tx][ty] > 0 && book[tx][ty] == 0 )
                        {
                                sum ++;
                                // 每个点只入队一次，所以需要标记这个点已经走过
                                book[tx][ty] = 1;
                                // 插入新扩展的点到队列中
                                que[tail].x = tx;
                                que[tail].y = ty;
                                tail ++;
                        }
                }
                // 注意不能忘记，当一个扩展点结束后，必须要 head++ 才能对后面的点进行扩展
                head ++;
        }

        // 输出岛屿大小
        printf("%d\n", sum);
        return 0;
}
