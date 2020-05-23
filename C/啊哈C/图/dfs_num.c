// 用深度优先搜索遍历图
#include <stdio.h>
int book[101], sum, n, e[101][101]; // e 是存储图的边（邻接矩阵）
void dfs (int cur) // cur 是当前所在的顶点的编号
{
        int i;
        printf("%d ", cur);
        sum ++; // 每访问一个点 sum 就加 1
        if ( sum == n )
        {
                return ; // 所有的顶点都已经访问过则退出
        }

        // 从 1 号顶点到 n 号顶点依次尝试，看哪些顶点与当前顶点 cur 有边相连
        for ( i = 1; i <= n; i ++ )
        {
                // 判断当前顶点 cur 到顶点 i 是否有边，并判断顶点 i 是否已经访问过
                if ( e[cur][i] == 1 && book[i] == 0 )
                {
                        // 标记顶点 i 已经访问过
                        book[i] = 1;
                        // 从顶点 i 再出发继续遍历
                        dfs(i);
                }
        }
        return ;
}

int main(void)
{
        int i, j, m, a, b;
        scanf("%d %d", &n, &m);
        
        // 初始化二维矩阵
        for ( i = 1; i <= n; i ++ )
        {
                for ( j = 1; j <= m; j ++ )
                {
                        if ( i == j )
                        {
                                e[i][j] = 0;
                        }
                        else
                        {
                                e[i][j] = 99999999; // 我们这里假设99999999为正无穷
                        }
                }
        }
        
        // 读入顶点之间的边
        for ( i = 1; i <= m; i ++ )
        {
                scanf("%d %d", &a, &b);
                e[a][b] = 1;
                e[b][a] = 1; // 这里是无向图，所以需要将 e[b][a] 也赋为 1
        }
        
        // 从 1 出发
        // 标记 1 号顶点已经走过
        book[1] = 1;
        // 从 1 号顶点开始遍历
        dfs(1);
        return 0;
}
