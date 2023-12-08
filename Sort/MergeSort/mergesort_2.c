// // 归并排序的非递归算法

// void merge(int L[], int low, int mid, int high)
// {
//     int k, begin1, begin2, end1, end2;
//     begin1 = low;
//     end1 = mid;
//     begin2 = mid + 1;
//     end2 = high;
//     // int temp[high-low+1];
//     int *temp = (int *)malloc((high - low + 1) * sizeof(int));

//     // 2.将左右两部分合并排序
//     for (k = 0; begin1 <= end1 && begin2 <= end2; k++)
//     {
//         if (L[begin1] <= L[begin2])
//             temp[k] = L[begin1++];
//         else
//             temp[k] = L[begin2++];
//     }
//     if (begin1 <= end1) // 左剩
//         memcpy(temp + k, L + begin1, (end1 - begin1 + 1) * sizeof(int));
//     // 注：
//     // 函数原型
//     //     void *memcpy(void*dest, const void *src, size_t n);
//     // 功能
//     //     由src指向地址为起始地址的连续n个字节的数据复制到以destin指向地址为起始地址的空间内。
//     // 头文件
//     //     #include<string.h>
//     // 返回值
//     //     函数返回一个指向dest的指针。

//     else // 右剩
//         memcpy(temp + k, L + begin2, (end2 - begin2 + 1) * sizeof(int));

//     // 3.排序后复制到原数组
//     memcpy(L + low, temp, (high - low + 1) * sizeof(int));
//     free(temp); // 释放空间
// }

// void mergesort(int L[], int last)
// {
//     int len, low, mid, high, i;
//     for (len = 1; len < last; len *= 2)
//     {
//         low = 1;
//         while (low + len <= L - last)
//         {
//             mid = low + len - 1;
//             high = mid + len;
//             if (high > last)
//                 high = last;
//             merge(L, low, mid, high);
//             low = high + 1;
//         }
//     }
// }
