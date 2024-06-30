#include <cs50.h>
#include <stdio.h>

// 根据键入数值，输出对应层数的 “#金字塔”
int main(void)
{
    // 提示用户输入金字塔的高度
    int num;
    do
    {
        num = get_int("Height: ");
    }
    while (num < 1);

    // 输出金字塔的高度
    // 层数
    for (int i = 1; i <= num; i++)
    {
        // 输出空格，实现右对齐
        for (int j = 1; j <= num - i; j++)
        {
            printf(" ");
        }

        // 输出每行#
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
