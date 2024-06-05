//2.请编写程序对一个char型的二维数组A进行排序。排序之后的数组应该满足如下的要求：
//	(a)如果 i < j,那么第i行字符的ASCII码的和不大于第j行字符ASCII码的和。
//	(b)对于任意一行k，如果 i < j ，那么A[k][i] <= A[k][j] 
//1.计算字符asc码的和
//2.行内字符：比较大小，交换
//3.行间：比和的大小，交换
#include <stdio.h>
#include <stdbool.h>

// 比较两个字符大小
bool compareChars(char c1, char c2) {
    return c1 > c2;
}

// 交换两个字符
void swapChars(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// 冒泡排序算法对一行进行排序
void bubbleSort(char row[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareChars(row[j], row[j + 1])) {
                swapChars(&row[j], &row[j + 1]);
            }
        }
    }
}

// 计算字符串的ASCII码的和
int sumASCII(char str[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += str[i];
    }
    return sum;
}

// 比较两个字符串的ASCII码的和
bool compareSums(char str1[], int n1, char str2[], int n2) {
    int sum1 = sumASCII(str1, n1);
    int sum2 = sumASCII(str2, n2);
    return sum1 > sum2;
}

// 对二维数组A进行排序
void sortArray(char arr[][6], int rows) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (compareSums(arr[j], 6, arr[j + 1], 6)) {
                // 如果前一行的ASCII码和大于下一行的ASCII码和，则交换两行
                char temp[6];
                for (int k = 0; k < 6; k++) {
                    temp[k] = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp[k];
                }
            } else if (!compareSums(arr[j], 6, arr[j + 1], 6)) {
                // 如果前一行的ASCII码和等于下一行的ASCII码和，则按行内字符进行排序
                bubbleSort(arr[j], 6);
                bubbleSort(arr[j + 1], 6);
                if (compareSums(arr[j], 6, arr[j + 1], 6)) {
                    // 如果排序后前一行的ASCII码和大于下一行的ASCII码和，则交换两行
                    char temp[6];
                    for (int k = 0; k < 6; k++) {
                        temp[k] = arr[j][k];
                        arr[j][k] = arr[j + 1][k];
                        arr[j + 1][k] = temp[k];
                    }
                }
            }
        }
    }
}

// 打印二维数组
void printArray(char arr[][6], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char arr[5][6] = {
        {'S','D','U','Y','E','S'},
        {'C','H','I','N','A','!'},
        {'A','F','T','E','R','X'},
        {'h','e','r','o','a','b'},
        {'C','y','y','D','S','!'}
    };
    printf("排序前的数组：\n");
    printArray(arr, 5);
    // 对数组进行排序
    sortArray(arr, 5);
    printf("\n排序后的数组：\n");
    printArray(arr, 5);

    return 0;
}