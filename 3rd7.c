/*7.现在有1个函数matrix_multi用于实现矩阵A和矩阵B相乘的功能，并将结果放在矩阵C中。该函数声明如下：
      void matrix_multi(double A[3][4], double B[4][5], double C[3][5]);
      请你编写该函数的函数体并测试其正确性。*/
#include<stdio.h>
void matrix_multi(double A[3][4],double B[4][5],double C[3][5])
{
    double multi;
    //i代表A矩阵的第几行
    for (int i = 0; i < 3; i++)
    {
        //multi = 0;
        //j代表B矩阵的第几列
        for (int j = 0; j < 5; j++)
        {
            multi = 0;
            //k代表A矩阵的第几列
            for (int k = 0; k < 4; k++)
            {
                multi+= A[i][k]*B[k][j];
                //C[i][k] = multi;
            }   
            C[i][j] = multi;
        }
    }
}

int main()
{
    double A[3][4];
    double B[4][5];
    double C[3][5];
    double a;
    double b;
    printf("请输入A[3][4]：\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%lf",&a);
            A[i][j] = a;
        }
    }
    printf("请输入B[4][5]：\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%lf",&b);
            B[i][j] = b;
        }
    }
    matrix_multi(A,B,C);
    printf("\nC[3][5]:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%.1f ",C[i][j]);
        }
        printf("\n");
    }
    
}