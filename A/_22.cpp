#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>



int main()
{
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> nums;
    long long* pr = (long long*)malloc(sizeof(long long) * N);

    for(int i = 0; i < N; i++)
    {
        int num;
        std::cin >> num;
        nums.push_back(std::pair<int, int>(num, -1));
    }


    long long total_max = 0;
    long long total_max_index = 0;
    for (int i = N - 1; i >=  0; i--)
    {
        long long max = 0;
        int max_index = -1;
        for(int j = i + 1; j < N; j++)
        {
            if(pr[j] > max && nums[i].first < nums[j].first)
            {
                max = pr[j];
                max_index = j;
            }
        }

        pr[i] = max + 1;
        nums[i].second = max_index;

        if (pr[i] > total_max)
        {
            total_max = pr[i];
            total_max_index = i;
        }
    }

    while(total_max_index != -1)
    {
        std::cout << nums[total_max_index].first << " ";
        total_max_index = nums[total_max_index].second;
    }

    std::cout << std::endl;

    return 0;
}