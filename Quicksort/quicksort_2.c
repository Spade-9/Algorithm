// 使用Partition函数的版本

// 注：没有写主函数，仅给出快速排序的算法实现
int partition(int a[], int low, int high)
{
    int pivotkey = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivotkey)
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivotkey)
            low++;
        a[high] = a[low];
    }
    a[low] = pivotkey;
    return low;
} // Partition

void quick_sort(int a[], int low, int high)
{
    int pivotloc;
    if (low < high)
    {
        pivotloc = partition(a, low, high);
        quick_sort(a, low, pivotloc - 1);
        quick_sort(a, pivotloc + 1, high);
    }
} // 递归的快速排序算法
