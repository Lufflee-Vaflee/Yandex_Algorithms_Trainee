#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <list>

int main()
{
    int N;
    std::list<long long> goblins;
    std::cin >> N;
    std::list<long long>::iterator midle = goblins.begin();
    int middle_count = 0;
    for(int i = 0; i < N; i++)
    {
        char s;
        std::cin >> s;

        switch (s)
        {
        case '+':
            long long goblin;
            std::cin >> goblin;
            goblins.push_back(goblin);
            if (goblins.size() % 2 == 1)
            {
                midle++;
            }
            break;
        case '*':
            std::cin >> goblin;
            midle = goblins.insert(++midle, goblin);
            if (goblins.size() % 2 == 0)
            {
                midle--;
            }
            break;
        case '-':
            std::cout << *goblins.begin() << std::endl;
            goblins.pop_front();
            if (goblins.size() % 2 == 1)
            {
                midle++;
            }
            break;
        }

        if(goblins.size() == 1 || goblins.size() == 2)
        {
            midle = goblins.begin();
        }
    }

    return 0;
}