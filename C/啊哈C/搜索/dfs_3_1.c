// 使用深度优先搜索做的全排列
#include <stdio.h>
int a[10], book[10], total = 0;
void dfs (int step) // step 表示现在站在第几个盒子前面
{
        int i;
        if ( step == 10 ) // 如果站在第 10 个盒子面前，则表示前 9 个盒子已经放好扑克牌
        {
                if ( a[1]*100 + a[2]*10 + a[3] + a[4]*100 + a[5]*10 + a[6] == a[7]*100 + a[8]*10 + a[9] )
                {
                        total ++;
                        printf("%d%d%d + %d%d%d = %d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
                }
                return ;
        }

        // 此时站在第step个盒子面前，应该放哪张牌？
        // 按照1 2 3 n 的顺序一一尝试
        for ( i = 1; i <= 9; i ++ )
        {
                // 判断扑克牌 i 是否还在手上
                // book[i] 等于0表示 i 号扑克牌在手上
                if ( book[i] == 0 )
                {
                        // 开始尝试使用扑克牌 i
                        a[step] = i; // 将扑克牌 i 放到第 step 个盒子中
                        book[i] = 1; // 将 book[i] 设为 1 ，表示 i 号扑克牌已经不在手上
                        // 第 step 个盒子已经放好扑克牌，接下来需要走到下一个盒子前面
                        dfs(step + 1); // 通过递归实现
                        book[i] = 0; // 非常重要的一步，一定要将刚才尝试的扑克牌放回，才能进行下一次尝试
                }
        }
        return ;
}

int main(void)
{
        dfs(1); // 首先站在 1 号盒子面前
        printf("total = %d\n", total / 2);
        return 0;
}
