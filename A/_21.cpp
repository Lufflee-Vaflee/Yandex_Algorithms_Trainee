#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

long long* pr;
long long notrec(long long num);
std::map<long long, long long> Pow;


int main()
{
    long long num;
    std::cin >> num;

    pr = (long long*)malloc(sizeof(long long) * (num + 1));
    pr[0] = 0;

    long long p = 0;
    long long n = 0;
    while(p < 1000000)
    {
        p = n * n * n;
        Pow.emplace(p, n);
        n++;
    }

    std::cout << notrec(num) << std::endl;

    return 0;
}

long long notrec(long long num)
{
    long long min = 1;
    for(long long i = 1; i <= num; i++)
    {
        min = 1;
        bool flag = true;
        if(i == num)
        {
            flag = true;
        }
        auto t = Pow.upper_bound(i);
        t--;
        long long temp = (*t).second;
        while (temp != 0)
        {
            long long count = pr[i - temp * temp * temp];
            count++;
            if (count < min || flag)
            {
                min = count;
            }
            temp--;
            flag = false;
        }

        pr[i] = min;
    }

    return min;
}