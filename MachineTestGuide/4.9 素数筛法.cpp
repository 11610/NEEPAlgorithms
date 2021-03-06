#include <stdio.h>

int prime[10000]; //保存筛得的素数
int primeSize; //保存的素数的个数
bool mark[10001]; //若mark[x]为true，则表示该数x已被标记成非素数

//素数筛法
void init() {
    for (int i = 1; i <= 10000; i++) {
        mark[i] = false; //将所有数字初始化为未被标记
    }
    primeSize = 0; //得到的素数个数初始化为0
    for (int i = 2; i <= 10000; i++) {
        if (mark[i] == true)
            continue; //若该数字已经被标记则跳过
        prime[primeSize++] = i; //否则又新得到一个素数
        for (int j = i * i; j <= 10000; j += i)
            mark[j] = true; //并将该数的所有倍数均标记成非素数
    }
}

int main() {
    init(); //在程序一开始首先取得2到10000中所有素数
    int n;
    while (scanf("%d", &n) != EOF) {
        bool isOutput = false; //表示是否输出了符合条件的数字
        for (int i = 0; i < primeSize; i++) {
            //测试当前素数是否符合条件
            if (prime[i] < n && prime[i] % 10 == 1) {
                //若当前输出为第一个输出的数字
                if (isOutput == false) {
                    isOutput = true; //标记已经输出了符合条件的数字
                    printf("%d", prime[i]); //且该数字前不输出空格
                } else {
                    printf(" %d", prime[i]); //否则在输出这个数字前输出一个空格
                }
            }
        }
        //若始终不存在符合条件的数字
        if (isOutput == false)
            printf("-1\n"); //输出-1并换行
        else
            printf("\n"); //换行
    }
    return 0;
}
