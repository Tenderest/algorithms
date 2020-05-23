// 第四节 数的全排列
#include <stdio.h>
// 123 和 1234
int main(void)
{
        int a, b, c;
        for ( a = 1; a <= 3; a ++ )
        {
                for ( b = 1; b <= 3; b ++ )
                {
                        for ( c = 1; c <= 3; c ++ )
                        {
                                if ( a != b && a != c && b != c )
                                {
                                        printf("%d%d%d\n", a, b, c);
                                }
                                
                        }
                        
                }
                
        }
        
        return 0;
}
