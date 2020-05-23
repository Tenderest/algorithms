// 用深度优先搜索遍历图
#include <stdio.h>


int main(void)
{
        int i, j, n, m, a, b, cur, book[101] = {0}, e[101][101]; // e 是存储图的边（邻接矩阵）
        int que[10001], head, tail;
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
        
        // 队列初始化
        head = 1;
        tail = 1;

        // 从 1 号顶点出发，将 1 号顶点加入队列
        que[tail] = 1;
        tail ++;
        // 标记 1 号顶点已经访问
        book[1] = 1;

        // 当队列不为空时循环
        while ( head < tail )
        {
                // 当前正在访问的顶点的编号
                cur = que[head];
                // 从 1 ～ n 依次尝试
                for ( i = 1; i <= n; i ++ )
                {
                        // 判断从顶点 cur 到顶点 i 是否有边，并判断顶点 i 是否已经访问过
                        if ( e[cur][i] == 1 && book[i] == 0 )
                        {
                                // 如果顶点 cur 到顶点 i 有边，并且顶点 i 没有被访问过，则将顶点 i 入队
                                que[tail] = i;
                                tail ++;
                                // 标记已经访问过
                                book[i] = 1;
                        }

                        // 如果 tail 大于 n，则表明所有的顶点都已经被访问过
                        if ( tail > n )
                        {
                                break;
                        }
                }
                // 注意不能忘记，当一个扩展点结束后，必须要 head++ 才能对后面的点进行扩展
                head ++;
        }
        
        for ( i = 1; i < tail; i ++ )
        {
                printf("%d ", que[i]);
        }
        
        return 0;
}
