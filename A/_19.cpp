#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

double cost = 0;
long long add(long long a, long long b);

int main()
{
    std::multiset<long long> nums;
    long long N;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long num;
        std::cin >> num;
        nums.emplace(num);
    }

    while(nums.size() != 1)
    {
        auto temp = nums.begin();
        long long a = *temp;
        auto del = temp;
        temp++;
        nums.erase(del);
        long long b = *temp;
        nums.erase(temp);
        a = add(a, b);
        nums.emplace(a);
    }

    std::cout << std::setprecision(2) << std::fixed << cost;


    return 0;
}


long long add(long long a, long long b)
{
    long long result = a + b;
    cost += result * 0.05;
    return result;
}