#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <set>
#include <deque>

int N;
void count_visited(int x, int y);
bool isValid(int x, int y);

struct pairhash 
{
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first * N + x.second);
    }
};

std::vector<std::vector<bool>> maze;
std::unordered_set<std::pair<int, int>, pairhash> visited;

int main()
{

    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        maze.push_back(std::vector<bool>());
        for(int j = 0; j < N; j++)
        {
            char symbol;
            std::cin >> symbol;
            maze[i].push_back(symbol == '.');
        }
    }

    int x, y;
    std::cin >> x;
    std::cin >> y;

    count_visited(x - 1, y - 1);

    std::cout << visited.size() << std::endl;

    return 0;
}

void count_visited(int x, int y)
{
    int temp_x, temp_y;

    if(!maze[x][y])
    {
        return;
    }

    visited.emplace(std::pair<int, int>(x, y));

    temp_x = x + 1;
    temp_y = y;
    bool isVisited = visited.find(std::pair<int, int>(temp_x, temp_y)) != visited.end();
    if (isValid(temp_x, temp_y) && !isVisited)
    {
        count_visited(temp_x, temp_y);
    } 

    temp_x = x - 1;
    temp_y = y;
    isVisited = visited.find(std::pair<int, int>(temp_x, temp_y)) != visited.end();
    if (isValid(temp_x, temp_y) && !isVisited)
    {
        count_visited(temp_x, temp_y);
    } 

    temp_x = x;
    temp_y = y + 1;
    isVisited = visited.find(std::pair<int, int>(temp_x, temp_y)) != visited.end();
    if (isValid(temp_x, temp_y) && !isVisited)
    {
        count_visited(temp_x, temp_y);
    } 

    temp_x = x;
    temp_y = y - 1;
    isVisited = visited.find(std::pair<int, int>(temp_x, temp_y)) != visited.end();
    if (isValid(temp_x, temp_y) && !isVisited)
    {
        count_visited(temp_x, temp_y);
    } 

    return;
}

bool isValid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}