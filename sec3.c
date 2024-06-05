/*
实现至少3个英文字符的图案输出
假定图案高7,以下代码将实现E、F、H三个英文字符的图案输出
*/
#include<stdio.h>
int main()
{
	char ch;
	printf("请输入E/F/H来查看对应的图案输出：\n");
	scanf("%c",&ch);
	//打印红色的E
	if (ch == 'E'){
		printf("\033[31m******\n*\n*\n******\n*\n*\n******\n\033[0m");
	}
	//打印黄色的F
	else if(ch == 'F'){
		printf("\033[33m******\n*\n*\n******\n*\n*\n*\n\033[0m");
	}
	//打印绿色的H
	else if(ch == 'H'){
		printf("\033[32m*     *\n*     *\n*     *\n*******\n*     *\n*     *\n*     *\n\033[0m");
	}
	return 0;
}
