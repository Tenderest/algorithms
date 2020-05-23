#include <stdio.h>
int book[10] = {0}, e[20][20] = {0};
int main(void)
{
        int i, j, head, tail;
        int n, m, a, b;
        int que[6];
        scanf("%d %d", &n, &m);

        for ( i = 1; i <= m; i ++ )
        {
                scanf("%d %d", &a, &b);
                e[a][b] = 1;
                e[b][a] = 1;
        }
        

        head = tail = 1;
        // 数组的值存储的是顶点的编号
        que[tail] = 1;
        book[tail] = 1;
        tail ++;

        while ( head < tail )
        {
                printf("%d ", que[head]);
                for ( i = 1; i <= n; i ++ )
                {
                        if ( e[head][i] == 1 && book[i] == 0 )
                        {
                                que[tail] = i;
                                book[i] = 1;
                                tail ++;
                        }
                }
                head ++;
        }
        
        return 0;
}
