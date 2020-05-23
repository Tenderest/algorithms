#include <stdio.h>
int e[51][51] = {0}, book[51] = {0};
struct note
{
        int cur; // 顶点编号
        int dis; // 路程
};
int main(void)
{
        int i, j, n, m, a, b, c, cur;
        int flag;
        int min = 999999;
        struct note que[51];
        int head, tail;

        scanf("%d %d", &n, &m);

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
                                e[i][j] = 999999;
                        }
                }
                
        }

        for ( i = 1; i <= m; i ++ )
        {
                scanf("%d %d %d", &a, &b, &c);
                e[a][b] = c;
        }
        

        head = tail = 1;
        que[tail].cur = 1;
        que[tail].dis = 0;
        /* book[tail] = 1; */
        tail ++;
        
        /* printf("head = %d, tail = %d", head, tail); */
        /* for ( i = 1; i <= n; i ++ ) */
        /* { */
        /*         for ( j = 1; j <= n; j ++ ) */
        /*         { */
        /*                 printf("%d ", e[i][j]); */
        /*         } */
        /*         putchar('\n'); */
        /* } */
        
        /* getchar(); */
        /* getchar(); */
        /* getchar(); */
        while ( head < tail )
        {
                cur = que[head].cur;
                for ( i = 1; i <= n; i ++ )
                {
                        if ( e[cur][i] != 999999 && e[cur][i] > 0)
                        {
                                que[tail].cur = i;
                                que[tail].dis = que[head].dis + e[cur][i];
                                tail ++;
                        }
                        if ( cur == 5 ) // 已经到 5 号了，不需要继续扩展了
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
        
        // 遍历队列

        head = 1;
        while ( head < tail )
        {
                cur = que[head].cur;
                if ( cur == 5 )
                {
                        if ( que[head].dis < min )
                        {
                                min = que[head].dis;
                        }
                }
                head ++;
        }
        


        printf("min = %d", min);
        return 0;
}
