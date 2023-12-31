// 深度优先搜索Depth First Search

// 从含有n个元素的数组中任意取出k个元素，求和，打印子数组
//  版本二：cnt=排列数nCk

#include <stdio.h>
int arr[100];         // 给定的整数数组
int visit[100] = {0}; // visit[]表示某一个下标有没有被访问过
int n, k;
int cnt = 0;       // cnt用于计数，计数一共计算了几次sum，即取出了多少个数组
int subarray[100]; // 子数组
int ans[100000];   // ans[cnt]用来存储答案,ans数组的大小要开的足够大。
void dfs(int step, int sum, int start)
{
    // step表示搜索深度, sum记录当前搜索深度的总和, start表示i的起始位置
    if (step == k)
    {
        ans[cnt++] = sum;           // 记录答案
        for (int i = 0; i < k; i++) // 打印子数组
            printf("%d ", subarray[i]);
        printf("\n");
        return;
    }
    for (int i = start; i < n; i++)
    {
        if (!visit[i]) // 如果下标i没有访问过
        {
            visit[i] = 1;                       // 把下标i标记成访问过
            subarray[step] = arr[i];            // 将当前搜索深度搜到的数据存入子数组
            dfs(step + 1, sum + arr[i], i + 1); // 把arr[i]加到sum里，把start赋值为i+1，递归
            visit[i] = 0;                       // 恢复下标i为未访问的状态
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    dfs(0, 0, 0);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\ncnt = %d", cnt);
}