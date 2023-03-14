#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <set>
#include <deque>

void view(std::vector<std::vector<long long>>& dp);

int main()
{
    int N;
    int M;

    std::cin >> M;
    std::cin >> N;

    std::vector<std::vector<long long>> dp;

    for(int i = 0; i < N; i++)
    {
        dp.push_back(std::vector<long long>());
        dp[i].push_back(1);
        for(int j = 1; j < M; j++)
        {
            if (i == 0)
            {
                dp[i].push_back(1);
            }
            else
            {
                dp[i].push_back(dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]);
            }
        }
    }

    view(dp);

    std::cout << dp[N - 1][M - 1] << std::endl;

    return 0;
}

void view(std::vector<std::vector<long long>>& dp)
{
    for(int i = 0; i < dp.size(); i++)
    {
        for(int j = 0; j < dp[i].size(); j++)
        {
            std::cout << std::setw(4) << dp[i][j];
        }

        std::cout << std:: endl;
    }
}
