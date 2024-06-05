char f(char (*pp)[5]) {return pp[1][2];}//这个（*pp）[5]是数组指针
int main(){
    char *B[20];//这是一个指针数组
    f(B);
    return 0;
}