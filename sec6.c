/*
输入1个字符，输出代表该字符字节每一位的值
*/
#include<stdio.h>
//用于从高到低查找字符字节每一位的值的函数
void PrintBit(char ch)
{
	if(ch & 0x80){
		printf("The eighth bit is 1,\n");
	}else{
		printf("The eighth bit is 0,\n");
	}
	if(ch & 0x40){
		printf("The seventh bit is 1,\n");
	}else{
		printf("The seventh bit is 0,\n");
	}
	if(ch & 0x20){
		printf("The sixth bit is 1,\n");
	}else{
		printf("The sixth bit is 0,\n");
	}
	if(ch & 0x10){
		printf("The fifth bit is 1,\n");
	}else{
		printf("The fifth bit is 0,\n");
	}
	if(ch & 0x08){
		printf("The forth bit is 1,\n");
	}else{
		printf("The forth bit is 0,\n");
	}
	if(ch & 0x04){
		printf("The third bit is 1,\n");
	}else{
		printf("The third bit is 0,\n");
	}
	if(ch & 0x02){
		printf("The second bit is 1,\n");
	}else{
		printf("The second bit is 0,\n");
	}
	if(ch & 0x01){
		printf("The first bit is 1.\n");
	}else{
		printf("The first bit is 0.\n");
	}
}

int main()
{
	char c;
	printf("请输入一个字符：\n");
	scanf("%c",&c);
	printf("字符'%c'的字节表示为：\n",c);
	PrintBit(c);
	return 0;
}
