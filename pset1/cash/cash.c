#include <cs50.h>
#include <stdio.h>

int calculate_num(int cents);

// 贪心算法找零钱，使其个数最少
int main(void)
{
    // 提示要找多少零钱
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // 打印该总数
    int num = calculate_num(cents);
    printf("%d\n", num);
}

// 计算各面值硬币所需数目
int calculate_num(int cents)
{
    int num = 0;

    while (cents > 1)
    {
        if (cents >= 25)
        {
            // 计算一下你应该给顾客多少个 25美分硬币。从零钱中减去这些 25美分硬币的价值。
            num += (int) cents / 25;
            cents = cents % 25;
            continue;
        }
        else if (cents >= 10)
        {
            // 计算一下你应该给顾客多少个 10美分硬币。从剩余的零钱中减去这些 10美分硬币的价值。
            num += (int) cents / 10;
            cents = cents % 10;
            continue;
        }
        else if (cents >= 5)
        {
            // 计算一下你应该给顾客多少个 5美分硬币。从剩余的零钱中减去这些 5美分硬币的价值。
            num += (int) cents / 5;
            cents = cents % 5;
            continue;
        }
        else
        {
            // 计算一下你应该给顾客多少个 1美分硬币。从剩余的零钱中减去这些 1美分硬币的价值。
            num += cents;
            cents = 0;
            continue;
        }
    }
    return num;
}
