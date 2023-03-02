#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include "math.h"

int get_table(int pos);

int main()
{
    long long int students_count;
    long long int variants_count;
    long long int line;
    int           side;

    std::cin >> students_count;
    std::cin >> variants_count;
    std::cin >> line;
    std::cin >> side;

    long long int P_pos;

    P_pos = ((line * 2 - 2) + side);

    long long int V_pos1 = -1;
    long long int V_pos2 = -1;
    long long int V_pos;

    if (P_pos - variants_count > 0)
    {
        V_pos2 = P_pos - variants_count;
        V_pos = V_pos2;
    }
    if (P_pos + variants_count <= students_count)
    {
        V_pos1 = P_pos + variants_count;
        V_pos = V_pos1;
    }
    if (V_pos1 == -1 && V_pos2 == -1)
    {
        std::cout << -1 << std::endl;
        return 0;
    }


    if (V_pos1 != -1 && V_pos2 != -1 && abs(get_table(V_pos2) - get_table(P_pos)) < abs(get_table(V_pos1) - get_table(P_pos)))
        V_pos = V_pos2;

    V_pos % 2 == 0 ? side = 2 : side = 1;
    std::cout << (int)((V_pos + 1) / 2) << " " << side << std::endl;

    return 0;
}

int get_table(int pos)
{
    return (int)((pos + 1) / 2);
}





