#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>



int main()
{
    int size;
    std::set<long long int> cards;
    std::cin >> size;
    for(int i = 0; i < size; i++)
    {
        long long int num;
        std::cin >> num;
        cards.emplace(num);
    }

    std::cin >> size;

    std::vector<std::pair<long long int, int>> col;
    std::map<int, int> result;

    for (int i = 0; i < size; i++)
    {
        long long int num;
        std::cin >> num;
        col.push_back(std::pair<long long int, int>(num, i));
    }

    std::sort(col.begin(), col.end());

    auto j = cards.begin();
    int res = 0;
    for (auto i = col.begin(); i != col.end(); i++)
    {
        while(*j < (*i).first && j != cards.end())
        {
            j++;
            res++;
        }

        result.emplace((*i).second, res);
    }

    for(auto i = result.begin(); i != result.end(); i++)
    {
        std::cout << (*i).second << std::endl;
    }

    return 0;
}





