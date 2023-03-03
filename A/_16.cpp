#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>


int main()
{
    int N;
    int K;
    std::vector<long long> nums;
    std::multiset<long long> ms;
    std::cin >> N;
    std::cin >> K;

    for(int i = 0; i < N; i++)
    {
        long long num;
        std::cin >> num;
        nums.push_back(num);
        if(i < K)
        {
            ms.emplace(num);
        }
    }

    std::vector<long long>::iterator left_border = nums.begin();
    std::vector<long long>::iterator right_border = left_border + K - 1;  //including 

    while(right_border != nums.end())
    {
        std::cout << *ms.begin() << std::endl;

        ms.erase(ms.find(*left_border));
        left_border++;
        right_border++;
        ms.emplace(*right_border);
    }

    return 0;
}
