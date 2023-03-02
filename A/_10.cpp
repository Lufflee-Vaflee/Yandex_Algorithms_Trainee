#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<char, long long int> symbols;

    std::string str;

    std::cin >> str;

    long long int num;

    for (long long int i = 0; i < str.size(); i++)
    {
        auto t = symbols.find(str[i]);
        num = (i + 1) * (str.size() - i);
        if (t == symbols.end())
        {
            symbols.emplace(str[i], num);
        }
        else
        {
            (*t).second += num;
        }
    }

    for(auto i = symbols.begin(); i != symbols.end(); i++)
    {
        std::cout << (*i).first << ": " << (*i).second << std::endl;
    }

    return 0;
}