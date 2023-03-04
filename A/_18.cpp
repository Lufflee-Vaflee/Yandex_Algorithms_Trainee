#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    std::set<long long> free;     //свободные тупики
    std::multimap<long long, long long> occupied;      //занятые тупики отсроитрованные по времени освобождения
    long long K;
    long long N;

    std::vector<long long> result;

    std::cin >> K;
    std::cin >> N;

    for (long long i = 1; i <= K; i++)
    {
        free.insert(i);
    }

    for (long long i = 1; i <= N; i++)
    {
        long long arrive;
        long long departure;
        std::cin >> arrive;
        std::cin >> departure;

        auto temp = occupied.begin();
        while(occupied.size() > 0 && (*temp).first < arrive)
        {
            free.emplace((*temp).second);
            auto temp1 = temp;
            temp++;
            occupied.erase(temp1);
        }

        auto temp1 = free.begin();

        if (free.size() == 0)
        {
            std::cout << "0 " << i << std::endl;
            return 0;
        }
        else
        {
            result.push_back(*temp1);
        }

        occupied.emplace(departure, *temp1);
        free.erase(temp1);
    }

    for(auto i = result.begin(); i != result.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    return 0;

}