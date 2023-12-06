// 归并排序的递归算法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int L[], int low, int mid, int high)
{
    int k, begin1, begin2, end1, end2;
    begin1 = low;
    end1 = mid;
    begin2 = mid + 1;
    end2 = high;
    // int temp[high-low+1];
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));

    // 2.将左右两部分合并排序
    for (k = 0; begin1 <= end1 && begin2 <= end2; k++)
    {
        if (L[begin1] <= L[begin2])
            temp[k] = L[begin1++];
        else
            temp[k] = L[begin2++];
    }
    if (begin1 <= end1) // 左剩
        memcpy(temp + k, L + begin1, (end1 - begin1 + 1) * sizeof(int));
    else // 右剩
        memcpy(temp + k, L + begin2, (end2 - begin2 + 1) * sizeof(int));

    // 3.排序后复制到原数组
    memcpy(L + low, temp, (high - low + 1) * sizeof(int));
    free(temp); // 释放空间
}

void merge_sort(int L[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(L, low, mid);
        merge_sort(L, mid + 1, high);
        merge(L, low, mid, high);
    }
}

int main()
{
    int a[20], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}