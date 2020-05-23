// 炸弹人
// 用二维数组存储地图
/* 13 x 13     G 敌人 . 空地
 # # # # # # # # # # # # #
 # G G . G G G # G G G . #
 # # # . # G # G # G # G #
 # . . . . . . . # . . G #
 # G # . # # # . # G # G #
 # G G . G G G . # . G G #
 # G # . # G # . # . # . #
 # # G . . . G . . . . . #
 # G # . # G # # # . # G #
 # . . . G # G G G . G G #
 # G # . # G # G # . # G #
 # G G . G G G # G . G G #
 # # # # # # # # # # # # #
*/

#include <stdio.h>
char a[20][21]; // 用来存储地图
int book[20][20] = {0}; // 定义一个标记数组并全部初始化为0
int max, mx, my, n, m;

int getnum (int i, int j)
{
        int sum, x, y;
        sum = 0; // sum 用来计数（可以消灭的敌人）所以需要初始化为 0
        // 将坐标 i，j 复制到两个新变量 x，y 中，以便之后向上下左右四个方向统计可以消灭的敌人数
        // 向上统计
        x = i;
        y = j;
        while ( a[x][y] != '#' ) // 判断点是不是墙，如果不是墙就继续
        {
                // 如果当前的点是敌人，则进行计数
                if ( a[x][y] == 'G' )
                {
                        sum ++;
                }
                // x-- 的作用是继续向上统计
                x --;
        }

        // 向下统计
        x = i;
        y = j;
        while ( a[x][y] != '#' ) // 判断点是不是墙，如果不是墙就继续
        {
                // 如果当前的点是敌人，则进行计数
                if ( a[x][y] == 'G' )
                {
                        sum ++;
                }
                // x++ 的作用是继续向下统计
                x ++;
        }
        
        // 向左统计
        x = i;
        y = j;
        while ( a[x][y] != '#' ) // 判断点是不是墙，如果不是墙就继续
        {
                // 如果当前的点是敌人，则进行计数
                if ( a[x][y] == 'G' )
                {
                        sum ++;
                }
                // y-- 的作用是继续向左统计
                y --;
        }

        // 向右统计
        x = i;
        y = j;
        while ( a[x][y] != '#' ) // 判断点是不是墙，如果不是墙就继续
        {
                // 如果当前的点是敌人，则进行计数
                if ( a[x][y] == 'G' )
                {
                        sum ++;
                }
                // y++ 的作用是继续向右统计
                y ++;
        }

        return sum;
}

void dfs(int x, int y)
{

        // 定义一个用于表示走的方向的数组
        int next[4][2] = {
                {0, 1},  // 向右走
                {1, 0},  // 向下走
                {0, -1}, // 向左走
                {-1, 0}  // 向上走
        };
        int k, sum, tx, ty;

        // 统计当前扩展的点可以消灭的敌人总数
        sum = getnum(x, y);

        // 更新 max 的值
        if ( sum > max )
        {
                // 如果当前统计出所能消灭敌人数大于 max，则更新 max 并用 mx 和 my 记录该点坐标
                max = sum;
                mx = x;
                my = y;
        }

        // 枚举 4 个方向
        for ( k = 0; k <= 3; k ++ )
        {
                // 尝试走的下一个点的坐标
                tx = x + next[k][0];
                ty = y + next[k][1];

                // 判断是否越界
                if ( tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1 )
                /* if ( tx < 0 || tx > n || ty < 0 || ty > m ) */
                {
                        continue;
                }
                
                // 判断是否为平地或者曾经走过
                if ( a[tx][ty] == '.' && book[tx][ty] == 0 )
                {
                        // 需要标记这个点已经走过
                        book[tx][ty] = 1;
                        dfs(tx, ty);
                }
        }
        return ;
}
int main(void)
{
        int i, startx, starty;
        // 读入n和m，n表示有多少行字符，m表示每行有多少列
        scanf("%d %d %d %d", &n, &m, &startx, &starty);

        // 读入n行字符
        for ( i = 0; i <= n - 1; i ++ )
        {
                scanf("%s", a[i]);
        }

        book[startx][starty] = 1;
        max = getnum(startx, starty);
        mx = startx;
        my = starty;

        dfs(startx, starty);
        
        printf("将炸弹放置在(%d, %d), 最多可以消灭%d个敌人\n", mx, my, max);
        return 0;
}
