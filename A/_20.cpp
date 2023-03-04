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
    std::vector<int> q;
    std::vector<std::pair<int, int>> queries;
    std::multimap<int, int> floor;


    int N, K, P;

    std::cin >> N;
    std::cin >> K;
    std::cin >> P;

    for (int i = 0; i < P ; i++)
    {
        int num;
        std::cin >> num;
        q.push_back(num);
    }

    int* last_in = (int*)malloc(sizeof(int) * P);
    for (int i = 0; i < N; i++)
    {
        last_in[i] = P;
    }

    int pos = P - 1;
    for (auto i = q.rbegin(); i != q.rend(); i++)
    {
        int last = last_in[*i];
        queries.push_back(std::pair<int, int>(*i, last));
        last_in[*i] = pos;

        pos--;
    }

    int result = 0;

    pos = 0;
    for(auto i = queries.rbegin(); i != queries.rend(); i++)
    {
        auto temp = floor.find(pos);
        if(temp != floor.end())
        {
            floor.erase(temp);
            floor.emplace((*i).second, (*i).first);
        }
        else
        {
            result++;
            if (floor.size() < K)
            {
                floor.emplace((*i).second, (*i).first);
            }
            else
            {
                floor.erase(--floor.end());
                floor.emplace((*i).second, (*i).first);
            }
        }

        pos++;
    }

    std::cout << result << std::endl;

    return 0;
}