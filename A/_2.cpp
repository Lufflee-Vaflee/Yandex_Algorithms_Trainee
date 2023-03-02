#include <iostream>
#include <string>
#include "string.h"
int count_beauty(std::string& str, char symbol, int insert_num);


int main()
{
    int insert_num, count, max = 0;
    std::string str;
    std::cin >> insert_num;
    std::cin >> str;

    for(char i = 'a'; i <= 'z'; i++)
        if ((count = count_beauty(str, i, insert_num)) > max)
            max = count;


    std::cout << max;
    return 0;
}

int count_beauty(std::string& str, char symbol, int insert_num)
{
    auto ltemp = str.begin();
    auto rtemp = ltemp;
    int max = 0;
    int temp;

    while(rtemp != str.end())
    {
        while((*rtemp == symbol || insert_num) && rtemp != str.end())
        {
            if (*rtemp != symbol)
                insert_num--;
            rtemp++;
        }

        if ((temp = rtemp - ltemp) > max)
            max = temp;

        if(rtemp == str.end())
            break;

        while(*ltemp == symbol)
            ltemp++;

        ltemp++;
        insert_num++;
    }

    return max;
}




