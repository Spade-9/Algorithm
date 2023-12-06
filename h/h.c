#include <stdio.h>
// 寻找行中最大元素的列索引
int findr(int a[][120], int rows, int cols, int i)
{
    int max = 0;
    for (int j = 0; j < cols; j++)
    {
        if (a[i][j] > a[i][max])
        {
            max = j;
        }
    }
    return max;
}

int main()
{
    int n, m, flag = 0;
    // 输入矩阵的行数和列数
    scanf("%d %d", &n, &m);
    int a[120][120];
    // 输入矩阵元素
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int rx, min = 0;
    for (int i = 0; i < n; i++)
    {
        rx = findr(a, n, m, i);
        // 获得当前行中最大元素的列索引
        for (int j = 0; j < n; j++)
        {
            if (a[j][rx] < a[min][rx])
            {
                // 找到列中最小元素的行索引
                min = j;
            }
        }
        if (min == i)
        {
            flag = 1;
            // 如果行中最大的元素同时也是列中最小的元素，标记为1
            break;
        }
    }

    if (flag == 1)
    {
        printf("The saddle point is (%d,%d)=%d.\n", min, rx, a[min][rx]);
    }
    else
    {
        printf("There is no saddle point in the matrix.\n");
    }
    return 0;
}