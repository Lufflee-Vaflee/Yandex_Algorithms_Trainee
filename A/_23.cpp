#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    long long N;
    long long A;
    std::cin >> N;
    if (N % 2 == 0)
    {
        A = N >> 1;
        N = (A * (A + 1) * (4 * A + 1)) >> 1;
    }
    else
    {
        A = (N - 1) >> 1;
        N = ((A + 1) * (4 * A * A + 7 * A + 2)) >> 1;
    }

    std::cout << N << std:: endl;

    return 0;
}
