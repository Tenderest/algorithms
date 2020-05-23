// Heap 堆排序，从大到小输出
#include <stdio.h>
int h[101]; // 用来存放对的数组
int n;      // 用来存储堆中元素的个数，也就是堆的大小

// 交换函数，用来交换堆中的两个元素的值
void swap (int x, int y)
{
        int t;
        t = h[x];
        h[x] = h[y];
        h[y] = t;
}

// 向下调整函数
// 传入一个需要向下调整的结点编号 i，这里传入 1 即从堆的顶点开始向下调整
void siftdown (int i)
{
        // flag 用来标记是否需要继续向下调整
        int t, flag = 0;
        // 当结点 i 有子节点（至少有左节点）并且需要继续调整的时候循环执行
        while ( i * 2 <= n && flag == 0 )
        {
                // 首先判断它和左子节点的关系，并用 t 记录较小的节点的编号
                if ( h[i] > h[i * 2] )
                {
                        t = i * 2;
                }
                else
                {
                        t = i;
                }

                // 如果有右子节点
                if ( i * 2 + 1 <= n )
                {
                        // 如果右子节点的值更小，更新较小的节点编号
                        if ( h[t] > h[i * 2 + 1] )
                        {
                                t = i * 2 + 1;
                        }
                }
                
                // 如果发现最小的节点编号不是自己，说明子节点有比父节点更小的
                if ( t != i )
                {
                        // 交换他们，注意 swap 函数需要自己来写
                        swap(t, i);
                        // 更新 i 为刚才与它交换的子节点的编号，便于接下来继续向下调整
                        i = t;
                }
                else
                {
                        // 否则说明当前的父结点已经比两个子节点都要小了，不需要调整了
                        flag = 1;
                }
        }
}

// 建立堆函数
// 建立的是最小堆
void creat (void)
{
        int i;
        // 从最后一个非叶节点到第 1 个节点依次进行向上调整
        for ( i = n / 2; i >= 1; i -- )
        {
                siftdown(i);
        }
        
}

// 堆排序
void heapsort (void)
{
        while ( n > 1 )
        {
                swap(1, n);
                n --;
                siftdown(1);
        }
        
}

int main(void)
{
        int i, num;
        // 读入要排序的数字的个数
        scanf("%d", &num);

        for ( i = 1; i <= num; i ++ )
        {
                scanf("%d", &h[i]);
        }
        n = num;

        // 建堆
        creat();

        // 堆排序
        // 从大到小
        heapsort();

        // 输出
        for ( i = 1; i <= num; i ++ )
        {
                printf("%d ", h[i]);
        }
        
        return 0;
}
