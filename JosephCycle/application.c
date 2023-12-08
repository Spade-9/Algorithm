// 猴子选大王：有N只猴子围成一圈，每只猴子从1到N依次编号。
// 打算从中选出一个大王，经过协商，决定出选大王的规则：从第一个猴子开始循环报数，数到M的猴子出圈，最后剩下来的就是大王

#include <stdio.h>

// 初始化每只猴子对应的下一只猴子的编号（创建环）
void LinUp(int init_position[], int n)
{
    for (int i = 0; i < n - 1; i++)
        init_position[i] = i + 1;
    init_position[n - 1] = 0;
}

// 选大王
int selectKing(int mark[], int m)
{
    int cnt;             // cnt:报数计数
    int i = 0, prei;     // i：表示当前报数猴子的编号，prei：报数猴子的上一只猴子的编号（这里的上一只指：该位对应的下一位猴子是报数的猴子）
    cnt = 1;             // 开始计数
    while (i != mark[i]) // 相等则说明这只猴子的下一位就是这只猴子，即只剩一只猴子了
    {
        // 再次报数
        prei = i;     // 记录上一次报数猴子的编号，之后有用
        i = mark[i];  // 猴子报数
        cnt++;        // 计数
        if (cnt == m) // 有猴子报数到m了，它要被踢出去啦！
        {
            mark[prei] = mark[i]; // 踢出猴子，即让它的上一只猴子对应的下一只猴子的编号，变成它对应的下一只猴子的编号
            printf("%d %d %d \n", i, prei, mark[prei]);
            i = mark[i]; // 下一只猴子开始报数
            cnt = 1;     // 开始新的计数
        }
    }
    return i;
}
int main()
{
    int n, m; // n:猴子的总数，m：报数的间隔
    scanf("%d%d", &n, &m);
    int mark[100] = {0};
    LinUp(mark, n);
    int king = selectKing(mark, m);
    printf("%d", king);
    return 0;
}