// 利用栈的数据结构，将二进制数转换为十进制数
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct {
        ElemType * base;
        ElemType * top;
        int stacksize;
} sqStack;

int ipow(int a, int b)
{
        int re = 1;
        for ( int i = 0; i < b; i ++ )
        {
                re = re * a;
        }
        return re;
}

void initStack (sqStack * s)
{
        // 内存中开辟一段连续空间作为栈空间
        // 首地址赋值给 s->base
        s->base = (ElemType *) malloc (STACK_INIT_SIZE * sizeof(ElemType));
        // 分配空间失败
        if ( s->base == NULL ) // !s->base
        {
                exit(0);
        }
        // 最开始，栈顶就是栈底
        s->top = s->base;
        // 最大容量为 STACK_INIT_SIZE
        s->stacksize = STACK_INIT_SIZE;
}

void Push (sqStack * s, ElemType e)
{
        if ( s->top - s->base >= s->stacksize )
        {
                // 栈满，追加空间
                s->base = (ElemType *) realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(ElemType));
                // 存储分配失败
                if ( !s->base )
                {
                        exit(0);
                }
                s->top = s->base + s->stacksize;
                // 设置栈的最大容量
                s->stacksize = s->stacksize + STACKINCREMENT;
        }
        // 放入数据
        *(s->top) = e;
        s->top ++;
}

void Pop (sqStack * s, ElemType * e)
{
        // 栈为空程序返回
        if ( s->top == s->base )
        {
                return;
        }
        // 将栈顶元素取出， 同时 top 指针自减 1
        *e = *-- (s->top);
        // *e = s->top; s->top --;
}

int StackLen (sqStack s)
{
        return (s.top - s.base);
}

void DestroyStack (sqStack * s)
{
        free(s->base);           // 释放内存空间
        s->base = s->top = NULL; // 栈底 栈顶指针设为 NULL
        s->stacksize = 0;        // 设置栈的最大容量为 0
}

int main(void)
{
        ElemType c;
        sqStack s;
        int len, i, sum = 0;
        printf("please input a Binary digit\n");
        initStack(&s); // 创建一个栈用来存放二进制字符串
        // 输入 0/1 表示的二进制字符，# 结束
        scanf("%c", &c);
        while ( c != '#' )
        {
                Push(&s, c);
                scanf("%c", &c);
        }
        len = StackLen(s); // 得到栈中元素的个数，即二进制数的长度
        for ( i = 0; i < len; i ++ )
        {
                Pop(&s, &c);
                sum = sum + (c - 48) * ipow(2, i); // 转换为十进制
        }
        printf("Decimal is %d\n", sum);
        // 释放栈空间
        DestroyStack(&s);
        return 0;
}
