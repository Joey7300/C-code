/*6.对于一个整数类型的二维数组A，请你补全如下函数实现对该二维数组任意元素A[m,n]的访问并验证其正确性（注：在该函数中不允许使用[][]操作符！）。*/
#include<stdio.h>
int two_dim_array_access(int *x,int i,int j,int m,int n,int C)
{
    //已知元素的索引
    int index = i*C + j;
    //目标元素的索引
    int add = m*C + n;
    //目标元素的地址
    int *adress = x-index+add-1;
    return *adress;
}

int main()
{
    int A[2][3] = {{1,2,3},{4,5,6}};
    //验证
    printf("结果1：%d\n",two_dim_array_access(&A[0][0],0,0,1,2,3));
    printf("结果2：%d\n",two_dim_array_access(&A[1][2],1,2,1,2,3));
    return 0;
}