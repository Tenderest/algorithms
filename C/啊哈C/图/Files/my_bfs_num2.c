#include <stdio.h>
struct note
{
        int num;
};
int main(void)
{
        struct note que[6];
        int head, tail;
        int e[10][10] = {0}, book[10] = {0};
        int n, m, a, b, i, j, cur;
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
                                e[i][j] = 9999999;
                        }
                }
        }
        
        for ( i = 1; i <= m; i ++ )
        {
                scanf("%d %d", &a, &b);
                e[a][b] = 1;
                e[b][a] = 1;
        }
        

        head = tail = 1;
        que[tail].num = 1;
        book[tail] = 1;
        tail ++;

        while ( head < tail )
        {
                printf("%d ", que[head].num);
                cur = que[head].num;
                for ( i = 1; i <= n; i ++ )
                {
                        if ( e[cur][i] == 1 && book[i] == 0 )
                        {
                                que[tail].num = i;
                                book[i] = 1;
                                tail ++;
                        }
                }
                head ++;
        }
        
        return 0;
}
