#include <stdio.h>

int finfMin(int a[], int n)
{
    int min = a[0];
    int mark = 0;
    for (int i = 1; i < n; i++)
    {
        if (min > a[i])
        {
            mark = i;
            min = a[i];
        }
    }
    return mark;
}
void selectSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = finfMin(a + i, n - i);
        int tmp = a[i];
        a[i] = a[min + i];
        a[min + i] = tmp;
    }
}

int main()
{
    int n, i, num[10010];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    selectSort(num, n);
    return 0;
}
