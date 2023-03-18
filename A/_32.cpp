#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <set>
#include <deque>

int N, M;

void walking(int x);

struct pairhash 
{
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first * N + x.second);
    }
};

std::vector<std::pair<bool, std::vector<bool>>> edges;

int main()
{

    std::cin >> N;
    std::cin >> M;

    for(int i = 0; i < N; i++)
    {
        edges.push_back(std::pair<bool, std::vector<bool>>(false, std::vector<bool>()));
        for(int j = 0; j < N; j++)
        {
            edges[i].second.push_back(i == j);
        }
    }

    for(int i = 0; i < M; i++)
    {
        int x, y;
        std::cin >> x;
        std::cin >> y;
        edges[y - 1].second[x - 1] = true;
    }

    walking(0);

    for(int i = 0; i < N; i++)
    {
        if(edges[i].first)
        {
            std::cout << i + 1 << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}

void walking(int x)
{
    edges[x].first = true;

    for(int i = 0; i < N; i++)
    {
        if(edges[x].second[i] && !edges[i].first)
        {
            walking(i);
        }
    }

    return;
}