#include <iostream>
#include <string>
#include <algorithm>
#include "math.h"
#include <iomanip>
#include <ctime>
#include <sstream>

int main()
{
    tm* TM = (tm*)malloc(sizeof(tm));
    std::cin >> std::get_time(TM, "%H:%M:%S");
    (*TM).tm_year = 2020-1900; // 2020
    (*TM).tm_mon = 2-1; // February
    (*TM).tm_mday = 15; // 15th
    time_t time1 = mktime(TM);

    std::cin >> std::get_time(TM, "%H:%M:%S");
    (*TM).tm_year = 2020-1900; // 2020
    (*TM).tm_mon = 2-1; // February
    (*TM).tm_mday = 15; // 15th
    time_t time2 = mktime(TM);

    TM = gmtime(&time2);

    std::cin >> std::get_time(TM, "%H:%M:%S");
    (*TM).tm_year = 2020-1900; // 2020
    (*TM).tm_mon = 2-1; // February
    (*TM).tm_mday = 15; // 15th
    time_t time3 = mktime(TM);

    auto t = round(((time3 - time1) / 2));
    time2 += t;

    TM = gmtime(&time2);
    if (TM->tm_sec < 10)
        std:: cout << TM->tm_hour << ":" << TM->tm_min << ":0" << TM->tm_sec << std::endl;
    else
        std:: cout << TM->tm_hour << ":" << TM->tm_min << ":" << TM->tm_sec << std::endl;
}



