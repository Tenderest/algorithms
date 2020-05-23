// 解救小哈 广度优先搜索
#include <stdio.h>
struct note
{
        int x; // 横坐标
        int y; // 纵坐标
        int f; // 父亲在队列中的编号，本题不要求输出路径，可以不用f
        int s; // 步数
};

int main(void)
{
        struct note que[2501]; // 因为地图大小不超过 50×50，因此队列扩展不会超过 2500 个

        int a[51][51] = {0}, book[51][51] = {0};
        int next[4][2] = {
                {0, 1},  // 向右走
                {1, 0},  // 向下走
                {0, -1}, // 向左走
                {-1, 0}  // 向上走
        };
        int head, tail;
        int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;

        scanf("%d %d", &n, &m);
        for ( i = 1; i <= n; i ++ )
        {
                for ( j = 1; j <= m; j ++ )
                {
                        scanf("%d", &a[i][j]);
                }
        }
        scanf("%d %d %d %d", &startx, &starty, &p, &q);

        // 初始化队列
        head = 1;
        tail = 1;
        // 往队列插入迷宫入口坐标
        que[tail].x = startx;
        que[tail].y = starty;
        que[tail].f = 0;
        que[tail].s = 0;
        tail ++;
        book[startx][starty] = 1;
        flag = 0; // 用来标记是否到达目标点，0 表示暂时没有到达，1 表示到达
        // 当队列不为空的时候循环
        while ( head < tail )
        {
                // 枚举 4 个方向
                for ( k = 0; k <= 3; k ++ )
                {
                        // 计算下一个点的坐标
                        tx = que[head].x + next[k][0];
                        ty = que[head].y + next[k][1];
                        // 判断是否越界
                        if ( tx < 1 || tx > n || ty < 1 || ty > m )
                        {
                                continue;
                        }
                        // 判断是否是障碍物或者已经在路径中
                        if ( a[tx][ty] == 0 && book[tx][ty] == 0 )
                        {
                                // 把这个点标记为已经走过
                                // 注意宽搜（广搜）每个点只入队一次，所以和深搜不同，不需要将book数组还原
                                book[tx][ty] = 1;
                                // 插入新的点到队列中
                                que[tail].x = tx;
                                que[tail].y = ty;
                                // 因为这个点是从 head 扩展出来的，所以它的父亲是 head，本题目不需要求路径，因此本句可以忽略
                                que[tail].f = head;
                                // 步数是父亲的步数 +1
                                que[tail].s = que[head].s + 1;
                                tail ++;
                        }

                        // 如果到目标点，停止扩展，任务结束，退出循环
                        if ( tx == p && ty == q )
                        {
                                // 这两句位置不用写颠倒了
                                flag = 1;
                                break;
                        }
                        
                }

                if ( flag == 1 )
                {
                        break;
                }

                // 这里千万不要忘记！！
                // 当一个点扩展结束后，head ++ 才能对后面的点进行扩展
                head ++;
        }

        // 打印队列中末尾最后一个点（目标点）的步数
        // 注意！！ tail 是指向队列队尾（即最后一位）的下一个位置，所以需要 -1
        printf("%d", que[tail - 1].s);
        
        return 0;
}
