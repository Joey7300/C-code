/*
输入1个比较大的正数x，找到[1, x]范围内的所有素数并打印出来.
*/
#include<stdio.h>
#include<stdbool.h>
//用于判断一个数是否为素数的函数
bool isPrime(int n)
{
	if(n<=1){
		return false;
	}
	for(int i=2; i<n; ++i){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

int main()
{
	int x;
	printf("请输入一个比较大的正数：\n");
	scanf("%d",&x);
	printf("[1, %d]范围内的所有素数:\n",x);
	//找到[1, x]范围内的所有素数
	for(int i=2; i<=x; ++i){
		if(isPrime(i)){
			printf("%d  ",i);
		}
	}
	printf("\n");
	return 0;
}
/*int main()
{
	int x;
	int flag = 1;
	printf("请输入一个比较大的正数：\n");
	scanf("%d",&x);
	if(x == 1){
		printf("none.\n");
	}else{
		//找到[1, x]范围内的所有素数
		for(int i=2; i<=x; i++){
			for(int j=2; j<i; j++){
				if(i % j ==0){
					flag = 0;	//不是素数
					break;	
				}
			}
			//将所有素数打印出来
			if(flag == 1){
				printf("素数%d\n",i);
			}
		}
	}
	return 0;
}*/
