#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

long long toSec(std::string& time);

int max(int a, int b);

int main()
{
    int N;
    std::string shit;
    int H9 = 32400;
    int H13 = 46800;
    int H14 = 50400;
    int H18 = 64800;
    int current_time = 32400;
    int result = 0;
    int result1 = 0;
    std::vector<std::pair<int, int>> tv;
    int* moments = (int*)malloc(sizeof(int) * (H13 - H9 + 1));
    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        std::string time;
        int stamp;
        std::cin >> time;
        std::cin >> stamp;
        tv.push_back(std::pair<int, int>(toSec(time), stamp));
    }


    for(int i = 0; i < H13 - H9 + 1; i++)
    {
        moments[i] = 0;
    }

    int current_stamp = (*tv.begin()).second;
    auto temp = ++tv.begin();
    for(int i = 0; i < H13 - H9 + 1; i++)
    {
        if (i != 0)
        {
            moments[i] = max(moments[i - 1], moments[i]);
        }

        if(temp != tv.end() && i + H9 >= (*temp).first)
        {
            current_stamp = (*temp).second;
            temp++;
        }

        if(i + H9 + current_stamp <= H13)
        {
            moments[i + current_stamp] = max(moments[i] + 1, moments[i + current_stamp]);
        }

        result = max(result, moments[i]);
    }

    for(int i = 0; i < H18 - H14 + 1; i++)
    {
        moments[i] = result;
    }

    while(temp != tv.end() && (*temp).first <= H14)
    {
        temp++;
    }
    temp--;
    current_stamp = (*temp).second;
    temp++;

    for(int i = 0; i < H18 - H14 + 1; i++)
    {
        if (i != 0)
        {
            moments[i] = max(moments[i - 1], moments[i]);
        }

        if(temp != tv.end() && i + H14 >= (*temp).first)
        {
            current_stamp = (*temp).second;
            temp++;
        }

        if(i + H14 + current_stamp <= H18)
        {
            moments[i + current_stamp] = max(moments[i] + 1, moments[i + current_stamp]);
        }

        result = max(result, moments[i]);
    }

    std::cout << result << std::endl;


    return 0;

}

char* xx = (char*)malloc(sizeof(char) * 2);

long long toSec(std::string& time)
{
    long long sec;
    xx[0] = time[0];
    xx[1] = time[1];
    sec = std::stoi(xx) * 3600;
    xx[0] = time[3];
    xx[1] = time[4];
    sec += std::stoi(xx) * 60;
    xx[0] = time[6];
    xx[1] = time[7];
    sec += std::stoi(xx);
    return sec;
}

int max(int a, int b)
{
    return a > b ? a : b;
}