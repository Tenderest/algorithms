// 最少转机 图的广度优先遍历
#include <stdio.h>
struct note
{
        int x;
        int s;
};
int main(void)
{
        struct note que[2501];
        // 二维矩阵，图的邻接矩阵表示法
        int book[51] = {0}, e[51][51] = {0};
        int head, tail;
        // 开始和结束点 start end 和一个到了的标志 flag
        int n, m, i, j, a, b, cur, start, end, flag = 0;
        scanf("%d %d %d %d", &n, &m, &start, &end);
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
                                e[i][j] = 9999999;
                        }
                }
        }
        
        // 读入城市之间的航班
        for ( i = 1; i <= m; i ++ )
        {
                scanf("%d %d", &a, &b);
                e[a][b] = 1;
                e[b][a] = 1;
        }

        head = tail = 1;
        que[tail].x = start;
        que[tail].s = 0;
        book[tail] = start;
        tail ++;

        while ( head < tail )
        {
                // 存储一下当前在的点，二维矩阵使用
                cur = que[head].x;
                for ( j = 1; j <= n; j ++ )
                {
                        // 用来判断是否有边，且没有访问过
                        if ( e[cur][j] == 1 && book[j] == 0 )
                        {
                                que[tail].x = j;
                                que[tail].s = que[head].s + 1;
                                book[j] = 1;
                                tail ++;
                        }

                        // 到了则设置 flag 为 1
                        if ( que[tail].x == end )
                        {
                                flag = 1;
                                break;
                        }
                }
                if ( flag == 1 )
                {
                        break;
                }
                head ++;
        }
        
        printf("%d", que[tail - 1].s);
        return 0;
}
