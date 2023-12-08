// 不写partition函数版的
#include <iostream>
using namespace std;
void qsort(int a[], int left, int right)
{
    int i = left, j = right, flag = a[(left + right) / 2];
    int tmp;
    do
    {
        while (a[i] < flag)
            i++;
        while (a[j] > flag)
            j--;
        if (i <= j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        qsort(a, left, j);
    if (i < right)
        qsort(a, i, right);
}

int main()
{
    int n;
    int a[100010];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qsort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
