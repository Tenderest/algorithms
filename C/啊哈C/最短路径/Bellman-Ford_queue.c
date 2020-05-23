// 解决负权边
// Bellman-Ford 的队列优化
#include <stdio.h>
int main(void)
{
        int i, j, k, n, m;
        // u、v 和 w 的数组大小要根据实际情况来设置，要比 m 的最大值要大 1
        int u[8], v[8], w[8];
        int first[6], next[8];
        // book 数组用来记录哪些顶点已经在队列中
        int dis[6] = {0}, book[6] = {0};
        // 定义一个队列，并初始化队列
        int que[101] = {0}, head = 1, tail = 1;
        int inf = 9999999; // 用inf（infintity的缩写）存储一个正无穷

        // 读入 n 和 m ，n 表示顶点个数，m 表示边的条数
        scanf("%d %d", &n, &m);

        // 初始化 dis 数组，这里是 1 号顶点到其余各个顶点的初始路程
        for ( i = 1; i <= n; i ++ )
        {
                dis[i] = inf;
        }
        dis[1] = 0;
        
        // 初始化 book 数组，初始化为 0,刚开始都不在队列中
        for ( i = 1; i <= n; i ++ )
        {
                book[i] = 0;
        }
        
        // 初始化 first 数组下标 1 ～n 的值为 -1,表示 1 ～ n 顶点暂时都没有边
        for ( i = 1; i <= n; i ++ )
        {
                first[i] = -1;
        }

        for ( i = 1; i <= m; i ++ )
        {
                // 读入边
                scanf("%d %d %d", &u[i], &v[i], &w[i]);
                // 下面两句是建立邻接表的关键
                next[i] = first[u[i]];
                first[u[i]] = i;
        }
        
        // 1 号顶点入队
        que[tail] = 1;
        tail ++;
        // 标记 1 号顶点已经入队
        book[1] = 1;
        
        // 当队列不为空时循环
        while ( head < tail )
        {
                // 当前需要处理的队首顶点
                k = first[que[head]];
                // 扫描当前顶点所有的边
                while ( k != -1 )
                {
                        // 判断是否松弛成功
                        if ( dis[v[k]] > dis[u[k]] + w[k] )
                        {
                                dis[v[k]] = dis[u[k]] + w[k];
                                // 这里的 book 数组用来判断顶点 v[k] 是否在队列中
                                // 如果不使用一个数组来标记的话，判断一个顶点是否在队列中
                                // 每次都需要从队列的 head 到 tail 都扫一遍，很浪费时间
                                if ( book[v[k]] == 0 )
                                {
                                        // 下面两句是入队操作
                                        que[tail] = v[k];
                                        tail ++;
                                        // 同时标记顶点 v[k] 已经入队
                                        book[v[k]] = 1;
                                }
                        }
                        k = next[k];
                }
                // 出队
                book[que[head]] = 0;
                head ++;
        }
        
        // 输出最终结果
        // 输出 1 号顶点到其余各个顶点的最短路径
        for ( i = 1; i <= n; i ++ )
        {
                printf("%d ", dis[i]);
        }
        
        return 0;
}
