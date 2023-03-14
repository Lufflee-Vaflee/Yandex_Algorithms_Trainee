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

inline int min(int a, int b);
inline int min(int a, int b, int c);
inline int M(char a, char b);

int main()
{
    std::string str1;
    std::string str2;

    std::cin >> str1;
    std::cin >> str2;

    std::vector<std::vector<int>> pr;

    for(int i = 0; i <= str1.size(); i++)
    {
        pr.push_back(std::vector<int>());
        for(int j = 0; j <= str2.size(); j++)
        {
            pr[i].push_back(0);
        }
    }


    for(int i = 0; i <= str1.size(); i++)
    {
        for(int j = 0; j <= str2.size(); j++)
        {
            if(i == 0 && j == 0)
            {
                pr[i][j] = 0;
            }
            else if(i == 0 && j != 0)
            {
                pr[i][j] = j;
            }
            else if(j == 0 && i != 0)
            {
                pr[i][j] = i;
            }
            else
            {
                pr[i][j] = min(pr[i][j -1] + 1, pr[i - 1][j] + 1, pr[i - 1][j - 1] + M(str1[i - 1], str2[j - 1]));
            }
        }
    }

    std::cout << pr[str1.size()][str2.size()] << std::endl;

    return 0;
}


inline int M(char a, char b)
{
    return a == b ? 0 : 1;
}

inline int min(int a, int b)
{
    return a < b ? a : b;
}

inline int min(int a, int b, int c)
{
    return min(min(a, b), c);
}