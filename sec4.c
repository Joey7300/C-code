/*
设计一段程序，接收的输入为1个正数，判断它是否为素数并输出结果 (yes或者 no）
*/
#include<stdio.h>
int main()
{
	int n;	
	int flag = 1;	//用于记录是否为素数的结果
	printf("请输入一个正数：\n");
	scanf("%d",&n);
	if(n == 1){
	printf("no.\n");
	}else{
		for(int i=2; i<n; i++){
			//说明在1和它本身之外还有其他因数
			if(n % i == 0){
				flag = 0;	//不是素数
				break;
			}
		}
		if(flag == 0){
			printf("no.\n");
		}else{
			printf("yes.\n");
		}
	}
	return 0;
}
