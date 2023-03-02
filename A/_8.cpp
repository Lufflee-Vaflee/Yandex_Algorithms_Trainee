#include <iostream>
#include <string>
#include <algorithm>
#include "math.h"
#include <iomanip>

int main()
{
    long long int X_left;
    long long int X_right;
    long long int Y_left; 
    long long int Y_right;
    long long int X_temp;
    long long int Y_temp;

    int size;

    std::cin >> size;

    for(int i = 0; i < size; i++)
    {
        std::cin >> X_temp;
        std::cin >> Y_temp;

        if(i == 0)
        {
           X_left = X_temp;
           X_right = X_temp;
           Y_left = Y_temp;
           Y_right = Y_temp;
        }

        if (X_temp < X_left)
        {
            X_left = X_temp;
        }
        else if(X_temp > X_right)
        {
            X_right = X_temp;
        }

        if (Y_temp < Y_left)
        {
            Y_left = Y_temp;
        }
        else if(Y_temp > Y_right)
        {
            Y_right = Y_temp;
        }
    }

    std::cout << X_left << " " << Y_left << " " << X_right << " " << Y_right << std::endl;

}