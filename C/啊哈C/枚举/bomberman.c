// 第二节 炸弹人
// 用二维数组存储地图
/* 13 x 13     T 敌人 . 空地
 # # # # # # # # # # # # #
 # G G . G G G # G G G . #
 # # # . # G # G # G # G #
 # . . . . . . . # . . G #
 # G # . # # # . # G # G #
 # G G . G G G . # . G G #
 # G # . # G # . # . # # #
 # # G . . . G . . . . . #
 # G # . # G # # # . # G #
 # . . . G # G G G . G G #
 # G # . # G # G # . # G #
 # G G . G G G # G . G G #
 # # # # # # # # # # # # #
*/

#include <stdio.h>
int main(void)
{
        char a[20][21]; // 假设这里的地图大小不超过20*20
        int i, j, sum, map = 0, p, q, x, y, n, m;
        // 读入n和m，n表示有多少行字符，m表示每行有多少列
        scanf("%d %d", &n, &m);

        // 读入n行字符
        for ( i = 0; i <= n - 1; i ++ )
        {
                scanf("%s", &a[i]);
        }
        
        for ( i = 0; i <= n - 1; i ++ )
        {
                for ( j = 0; j <= m - 1; j ++ )
                {
                        if ( a[i][j] == '.' )
                        {
                                sum = 0;

                                // 向上统计
                                x = i;
                                y = j;
                                while ( a[x][y] != '#' )
                                {
                                        if ( a[x][y] == 'G' )
                                        {
                                                sum ++;
                                        }
                                        x --; // x-- 作用是继续向上统计
                                }
                                // 向下统计
                                x = i;
                                y = j;
                                while ( a[x][y] != '#' )
                                {
                                        if ( a[x][y] == 'G' )
                                        {
                                                sum ++;
                                        }
                                        x ++;
                                }
                                // 向左统计
                                x = i;
                                y = j;
                                while ( a[x][y] != '#' )
                                {
                                        if ( a[x][y] == 'G' )
                                        {
                                                sum ++;
                                        }
                                        y --;
                                }
                                // 向右统计
                                x = i;
                                y = j;
                                while ( a[x][y] != '#' )
                                {
                                        if ( a[x][y] == 'G' )
                                        {
                                                sum ++;
                                        }
                                        y ++;
                                }
                                
                                // 更新map的值
                                if ( sum > map )
                                {
                                        // 如果当前点所能消灭的敌人总数大于map，则更新map
                                        map = sum;
                                        // 记录当前坐标
                                        p = i;
                                        q = j;
                                }
                                
                        }
                        
                }
                
        }
        
        printf("将炸弹放置在(%d, %d), 最多可以消灭%d个敌人\n", p, q, map);
        return 0;
}
