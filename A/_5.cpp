#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include "math.h"

long long int recursus(long long int* arr, int size);

int main()
{
    long long int* arr;
    int size;


    std::cin >> size;

    arr = (long long int*)malloc(sizeof(long long int) * size);

    for(int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << recursus(arr, size);


}

long long int recursus(long long int* arr, int size)
{
    if (size <= 1)
    {
        return 0;
    }
    long long int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min  = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] -= min;
    }

    long long int* temp1 = arr;
    long long int* temp2 = arr;
    long long int* end = arr + size;
    long long int result = 0;
    while(temp2 != end)
    {
        while(*temp1 == 0 && temp1 != end)
        {
            temp1++;
        }
        temp2 = temp1;
        while(*temp2 != 0 && temp2 != end)
        {
            temp2++;
        }

        result += recursus(temp1, temp2 - temp1);
        temp1 = temp2;
    }

    return result + (size - 1) * min;
}



