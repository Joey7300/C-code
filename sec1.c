/*
在你的机器上获取不同基本数据类型所占的字节数
*/
#include<stdio.h>
int main()
{
	printf("The size of int is %zd bytes.\n",sizeof(int));
	printf("The size of short is %zd bytes.\n",sizeof(short));
	printf("The size of long is %zd bytes.\n",sizeof(long));
	printf("The size of char is %zd bytes.\n",sizeof(char));
	printf("The size of float is %zd bytes.\n",sizeof(float));
	printf("The size of double is %zd bytes.\n",sizeof(double));
	return 0;
}
