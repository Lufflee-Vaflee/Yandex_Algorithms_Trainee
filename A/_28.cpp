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


int decode(char c);
std::vector<std::vector<int>> mas;
int recursus(int comand, int depth);

int main()
{
    std::string temp;
    for(int i = 0; i < 6; i++)
    {
        mas.push_back(std::vector<int>());
        for(int j = 0; j < 6; j++)
        {
            mas[i].push_back(0);
        }
    }

    for(int i = 0; i < 6; i++)
    {
        std::getline(std::cin, temp);
        for(int j = 0; j < temp.size(); j++)
        {
            mas[i][decode(temp[j])] += 1;
        }
    }

    int depth;
    std::cin >> temp;
    std::cin >> depth;

    std::cout << recursus(decode(temp[0]), depth) << std::endl;

    return 0;
}


int recursus(int comand, int depth)
{
    if(depth == 1)
    {
        return 1;
    }

    int result = 0;
    for(int i = 0; i < 6; i++)
    {
        if(mas[comand][i])
        {
            result += recursus(i, depth - 1) * mas[comand][i];
        }
    }

    result++;

    return result;
}


int decode(char c)
{
    switch(c)
    {
        case 'N':
        return 0;
        case 'S':
        return 1;
        case 'W':
        return 2;
        case 'E':
        return 3;
        case 'U':
        return 4;
        case 'D':
        return 5;
    }

    return -1;
}
