/*请你编写程序实现如下功能：
程序从用户接收多行英文字符串。当用户结束输入后，
程序统计出在用户的输入中所出现过的单词，
以及这些单词在每一行出现的次数、
在用户输入中总共出现的次数。*/
//
/*也就是创建一个数据结构来实现存储每个单词以及
其出现的次数的统计，这里使用哈希表
要解决的问题就包括：1.接收用户输入，直到输入END
2.处理每行输入的单词，更新统计数据
3.输出每个单词在每行中的出现次数以及总出现次数*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 100
#define BUFFER_SIZE 1024
#define WORD 100
#define HASH_SIZE 101

//存储单词各行和总的次数统计
typedef struct WordCount {
    char word[WORD];
    int total_count;          // 总次数
    int line_counts[MAXLINES]; // 每行的计数
    struct WordCount *next;   // 指向下一个节点的指针
} WordCount;
//定义一个指针数组（哈希表）存储单词的统计信息
WordCount *hash_table[HASH_SIZE];
//哈希函数
unsigned int hash(char *str) {
    //初始哈希值为0
    unsigned int hash_val = 0;
    //循环遍历字符串，将字符串映射到一个哈希值
    while (*str != '\0') {
        hash_val = (hash_val * 31 + *str++) % HASH_SIZE;
    }
    return hash_val;
}

//在哈希表中查找单词的统计信息，找得到就返回，找不到就创建个新的
WordCount *find_word(char *word) {
    //先根据给定单词计算其哈希值，得到在表中的索引位置
    unsigned int index = hash(word);
    //把索引位置的链表头指针赋给wc
    WordCount *wc = hash_table[index];
    //循环查找统计信息
    while (wc != NULL) {
        //若当前节点的单词和给定单词相等，则返回当前节点的指针
        if (strcmp(wc->word, word) == 0)
            return wc;
        wc = wc->next;
    }

    //找不到的话就创建一个新的
    wc = (WordCount *)malloc(sizeof(WordCount));
    strcpy(wc->word, word);//将给定单词复制到新的结构体中
    //初始化总次数和每行计数
    wc->total_count = 0;
    memset(wc->line_counts, 0, sizeof(wc->line_counts));
    wc->next = hash_table[index];
    hash_table[index] = wc;

    return wc;
}

//更新给定单词的计数
void count_word(char *word, int line_number) {
    WordCount *wc = find_word(word);
    wc->total_count++; //总次数加1
    wc->line_counts[line_number]++; //特定行次数加1
}

void print(int lines_read) {
    printf("单词计数:\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        WordCount *wc = hash_table[i];
        //循环遍历打印每个单词的统计信息
        while (wc != NULL) {
            printf("%s: 总次数 = %d, 行的计数 = ", wc->word, wc->total_count);
            //遍历单词在每行上的出现次数，大于0就打印出来
            for (int j = 0; j < lines_read; j++) {
                if (wc->line_counts[j] > 0) {
                    printf("[行 %d: %d] ", j + 1, wc->line_counts[j]);
                }
            }
            printf("\n");
            wc = wc->next;
        }
    }
}

int main() {
    //储存用户输入的文本
    char buffer[BUFFER_SIZE];
    int line_number = 0;//文本行号

    printf("请输入文本 (输入END来结束输入):\n");
    //读入一行文本，储存到buffer中，进入循环
    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        //若为END则跳出循环
        if (strncmp(buffer, "END", 3) == 0)
            break;
        //用空格或制表符或换行符分割，把单词赋给token
        char *token = strtok(buffer, " \t\n");
        //循环统计出现次数
        while (token != NULL) {
            count_word(token, line_number);
            token = strtok(NULL, " \t\n");
        }
        line_number++;
    }

    print(line_number);
    return 0;
}
