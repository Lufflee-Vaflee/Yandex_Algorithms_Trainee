#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <set>
#include <deque>

int N, M;

std::ostream& operator<<( std::ostream& dest, __int128_t value );

int main()
{
    std::cin >> N;
    std::cin >> M;

    std::unordered_map<long, std::pair<int, int>>* current = new std::unordered_map<long, std::pair<int, int>>();
    std::unordered_map<long, std::pair<int, int>>* next = new std::unordered_map<long, std::pair<int, int>>();

    std::vector<std::vector<__int128_t>> desk;
    
    for(int i = 0; i < N; i++)
    {
        desk.push_back(std::vector<__int128_t>());
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            desk[i].push_back(0);
        }
    }

    

    current->emplace(0, std::pair<int, int>(0, 0));
    desk[0][0] = 1;

    __int128_t result = 0;

    while(current->size() != 0)
    {
        for(auto temp = current->begin(); temp != current->end(); temp++)
        {

            int i = (*temp).second.first;
            int j = (*temp).second.second;

            int temp_j = j - 1;
            int temp_i = i + 2;

            if(temp_j >= 0 && temp_i < N)
            { 
                desk[temp_i][temp_j] += desk[i][j];
                next->emplace(temp_i * M + temp_j, std::pair<int, int>(temp_i, temp_j));
            }

            temp_j = j + 1;
            temp_i = i + 2;

            if(temp_j < M && temp_i < N)
            {
                desk[temp_i][temp_j] += desk[i][j];
                next->emplace(temp_i * M + temp_j, std::pair<int, int>(temp_i, temp_j));
            }

            temp_j = j + 2;
            temp_i = i + 1;

            if(temp_j < M && temp_i < N)
            {
                desk[temp_i][temp_j] += desk[i][j];
                next->emplace(temp_i * M + temp_j, std::pair<int, int>(temp_i, temp_j));
            }

            temp_j = j + 2;
            temp_i = i - 1;

            if(temp_j < M && temp_i >= 0)
            {
                desk[temp_i][temp_j] += desk[i][j];
                next->emplace(temp_i * M + temp_j, std::pair<int, int>(temp_i, temp_j));
            }
        }

        for(auto t = current->begin(); t != current->end(); t++)
        {
            if ((*t).second.first == N - 1 && (*t).second.second == M - 1)
            {
                result += desk[(*t).second.first][(*t).second.second];
            }
            
            desk[(*t).second.first][(*t).second.second] = 0;
        }

        free(current);
        current = next;
        next = new std::unordered_map<long, std::pair<int, int>>();
    }

    std::cout << result << std::endl;

    return 0;
}

std::ostream& operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

