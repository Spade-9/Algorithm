#include<stdio.h>

// 约瑟夫环算法-1创建环
int create_joseph_cycle(int a[], int n)
{
    int i;
    for (i = 1; i <= n - 1; i++)
        a[i] = i + 1;
    a[n] = 1;
    return n;
}

// 约瑟夫环算法2-报数出圈
void josephCycle(int a[], int n, int m)
{
    int count, prei, i;
    count = 0;
    i = n; // 预备从1号开始的前编号
    while (a[i] != i)
    {
        count++; // 报数
        prei = i;
        i = a[i]; // 找下一个
        if (count % m == 0)
        { // 出圈
            a[prei] = a[i];
            printf("%d号出圈\n", i);
            i = prei; // 出圈后返回前结点
        }
    }
    printf("The last is No.%d !", i);
}

int main()
{
    int a[100] = {0}, n, m;
    printf("输入人数n:");
    scanf("%d", &n);
    create_joseph_cycle(a, n);
    printf("输入报数m:");
    scanf("%d", &m);
    josephCycle(a, n, m);
    return 0;
}