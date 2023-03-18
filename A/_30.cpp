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

int recursus(std::vector<int>::iterator start, std::vector<int>::iterator end);
std::vector<int> cuts;
std::unordered_map<long, long long> pr;
int length;

int main()
{
    int N;

    std::cin >> length;
    std::cin >> N;

    cuts.push_back(0);

    for(int i = 0; i < N; i++)
    {
        int pos;
        std::cin >> pos;
        cuts.push_back(pos);
    }

    cuts.push_back(length);

    std::cout << recursus(cuts.begin(), cuts.end() - 1) << std::endl;

    return 0;
}


int recursus(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if(end == start + 1 || end == start)
    {
        return 0;
    }

    int min;
    int temp;
    for(auto i = start + 1; i != end; i++)
    {
        temp = 0;
        auto t = pr.find((*start * length) + *i);
        temp += t == pr.end() ? recursus(start, i) : (*t).second;
        t = pr.find((*i * length) + *end);
        temp += t == pr.end() ? recursus(i, end) : (*t).second;
        if(i == start + 1)
            min = temp;
        else
            min = temp < min ? temp : min;
    }

    pr.emplace((*start * length) + *end, min + *end - *start);
    return min + *end - *start;
}
