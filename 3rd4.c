/*试着增强一下之前作业中的程序。输入为不确定个数的字符（字符数少于5个），输出为这些字符的图案表示。*/
//因为实在是太麻烦了，所以就用了很笨的直接打印的方法，能支持输入的字母也只有简单的几个
#include<stdio.h>
void Print(char c[],int num)
{
    for (int i = 0; i < num; i++)
    {
        if (c[i]=='B')
        {
            printf("\n****\n*   *\n*   *\n****\n*   *\n*   *\n***\n");
        }else if (c[i]=='E')
        {
            printf("\n*****\n*\n*\n*****\n*\n*\n*****\n");
        }else if (c[i]=='F')
        {
            printf("\n*****\n*\n*\n****\n*\n*\n*\n");
        }else if (c[i]=='H')
        {
            printf("\n*   *\n*   *\n*   *\n*****\n*   *\n*   *\n*   *\n");
        }else if (c[i]=='L')
        {
            printf("\n*\n*\n*\n*\n*\n*\n*****\n");
        }else if (c[i]=='O')
        {
            printf("\n *** \n*   *\n*   *\n*   *\n*   *\n*   *\n *** \n");
        }else if (c[i]=='T')
        {
            printf("\n*****\n  *\n  *\n  *\n  *\n  *\n  *\n");
        }else{
            printf("抱歉，您查找的字符暂时还没有。\n");
        }   
    }
    
}

int main()
{
    char input[5];
    int num;
    //提示用户输入：
    printf("请输入不超过5个字符（大写字母）：\n");
    scanf("%s",input);
    // 计算输入字符的个数
    for (num = 0; input[num] != '\0'; num++);
    //打印字符图案
    Print(input, num);

    return 0;
}