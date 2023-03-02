#include <stdio.h>
#include <iostream>
#include <map>

int main()
{
    std::map<char, int> symbols;

    char symb;
    int max = 1;
    while(!((std::cin >> symb).eof()))
    {
        if (symb == ' ' || symb == '\n')
            continue;

        auto pair = symbols.find(symb);
        if (pair == symbols.end())
        {
            symbols.emplace(symb, 1);
        }
        else
        {
            if(++(*pair).second > max)
                max = (*pair).second;
        }
    }

    do
    {
        for (auto i = symbols.begin(); i != symbols.end(); i++)
        {
            if ((*i).second >= max)
                std::cout << '#';
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
    while(--max);

    for (auto i = symbols.begin(); i != symbols.end(); i++)
    {
        std::cout << (*i).first;
    }

    std::cout << std::endl;

    return 0;
}