#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include "math.h"

int main()
{
    int common;
    int size;
    std::map<int, int> os;

    std::cin >> common;
    std::cin >> size;

    int first;
    int second;
    for(int i = 0; i < size; i++)
    {

        std::cin >> first;
        std::cin >> second;
        bool flag = false;

        std::map<int, int>::iterator temp = os.upper_bound(first);
        std::map<int, int>::iterator temp1;
        if (temp != os.begin())
        {
            temp1 = --temp;
            temp++;
            flag = true;
        }
        while((*temp).first <= second && temp != os.end())
        {
            os.erase(temp++);
        }

        if (flag && (*temp1).second >= first)
        {
            os.erase(temp1);
        }

        os.emplace(first, second);
    }

    std::cout << os.size() << std::endl;

}



