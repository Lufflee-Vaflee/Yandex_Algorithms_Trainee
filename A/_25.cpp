#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <deque>

int max(int a, int b);
int min(int a, int b);

int main()
{
    int N;
    int a, b;

    std::cin >> N;
    std::cin >> a;
    std::cin >> b;

    std::vector<int> dp;

    for(int i = 0; i <= N; i++)
    {
        dp.push_back(0);
    }

    if(N == 1)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    else if(N == 2)
    {
        std::cout << max(a, b) << std::endl;
        return 0;
    }

    dp[2] = max(a, b);

    int maximum;
    for (int i = 3; i <= N; i++)
    {
        int minimum = 2147483647;
        for (int k = 1; k < i; k++)
        {
            minimum = min(minimum, max(dp[k] + a, dp[i - k] + b));
        }
        dp[i] = minimum;
    }

    std::cout << dp.back() << std::endl;

    return 0;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}