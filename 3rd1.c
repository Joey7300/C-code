//实现非递归版本的一维整数型数组的选择排序算法和冒泡排序算法
//也就是用循环的方法完成选择排序和冒泡排序
#include<stdio.h>
//交换函数
void Swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
//选择排序
void SelectSort(int arr[],int n){
	int i,j,min;
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
		//如果后面一个数更小，就将其赋给min，再交换顺序
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		Swap(&arr[i],&arr[min]);
	}
}
//冒泡排序
void BubbleSort(int arr[],int n){
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1;j++){
		//如果前一个数比后一个数大，就把后一个数冒泡上去
			if(arr[j] > arr[j+1]){
				Swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

//主函数
int main(){
	int arr[] = {4,5,6,7,1,2,9};
	int n = sizeof(arr) / sizeof(arr[0]);
	//选择排序
	SelectSort(arr,n);
	printf("选择排序结果:\n");
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	//重新初始化数组
	int arr2[] = {4,5,6,7,1,2,9};
	//冒泡排序
	BubbleSort(arr2,n);
	printf("冒泡排序结果:\n");
	for(int i=0; i<n; i++){
		printf("%d ",arr2[i]);
	}
	
	printf("\n");
	return 0;
}