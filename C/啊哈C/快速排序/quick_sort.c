#include <stdio.h>
/*注意：数组索引0不存放数据*/
int a[12], n;                      // 定义全局变量，这两个变量需要在子函数中使用
void eatline() { while (getchar() != '\n') {continue;} }
void quicksort (int left, int right) // left是左边的数，right是右边的数
{
        int i, j, t, tmp;
        if ( left > right )          // 左边基准数大于右边的数了
        {
                return;
        }

        tmp = a[left];               // tmp 中存的就是基准数
        i = left;
        j = right;
        while ( i != j )
        {
                // 顺序很重要，要先从右往左找
                while ( a[j] >= tmp && j > i ) // 书中i < j, a[j] >= tmp 此处 = 因为 3 1 2 5 4 这种情况，下同
                {
                        j --;
                }
                // 再从左往右找
                while ( a[i] <= tmp && i < j )
                {
                        i ++;
                }

                // 交换两个数在数组中的位置
                if ( i < j )
                {
                        t = a[i]; // 由于数组索引0没有存储数据，可以用来做临时变量
                        a[i] = a[j];
                        a[j] = t;
                }
        }

        // 最终将基准数归位
        // 找完以后 a[i] 已经是中间那个数了
        a[left] = a[i];
        a[i] = tmp;

        quicksort(left, i - 1);  // 继续处理左边的，这是一个递归过程
        quicksort(i + 1, right); // 继续处理右边的，这是一个递归过程
}

int main(void)
{
        int i, j, t;
        // 读取数据
        scanf("%d", &n);
        eatline();
        /*注意：数组索引0不存放数据*/
        for ( i = 1; i <= n; i ++ )
        {
                scanf("%d", &a[i]);
                eatline();
        }
        
        quicksort(1, n); // 调用

        // 输出
        for ( i = 1; i <= n; i ++ )
        {
                printf("%d ", a[i]);
        }
        
        return 0;
}
