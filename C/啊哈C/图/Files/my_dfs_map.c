#include <stdio.h>
int e[51][51] = {0}, book[51] = {0};
int min = 9999999;
int n, m;
void dfs (int cur, int dis)
{
        int i; // 局部变量，尽量不冲突


        // 如果 dis 已经大于之前最短的，就不用尝试了

        if ( dis > min )
        {
                return ;
        }


        if ( cur == n )
        {
                if ( dis < min )
                {
                        min = dis;
                }
                return ;
        }
        
        for ( i = 1; i <= n; i ++ )
        {
                if ( e[cur][i] != 999999 && book[i] == 0)
                {
                        book[i] = 1;
                        dfs(i, dis + e[cur][i]);
                        book[i] = 0;
                }
        }
        return ;
}

int main(void)
{
        int i, j, a, b, c;
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

        book[1] = 1;
        dfs(1, 0);

        printf("min = %d", min);
        return 0;
}
