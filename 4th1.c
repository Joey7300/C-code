/*请补全这段程序，使得printf语句运行后可以输出字符串 C!YYDS!*/
#include<stdio.h>
int main()
{
    long x = 1;
    for ( x = 1; x < 8; x++)
    {
        switch (x)
        {
        case 1:
            printf("%s","C");
            break;
        case 2:
            printf("%s","!");
            break;
        case 3:
            printf("%s","Y");
            break;
        case 4:
            printf("%s","Y");
            break;
        case 5:
            printf("%s","D");
            break;
        case 6:
            printf("%s","S");
            break;
        case 7:
            printf("%s","!");
            break;
        }
    }
    
    return 0;
}