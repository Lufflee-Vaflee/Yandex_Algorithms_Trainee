#include <iostream>
#include <iomanip>
long long int N, M;

long long query(long long int**, long long int x1, long long int y1, long long int x2, long long int y2);
void pre(long long int**, long long int**);

int main() 
{
    long long int** matrix;
    long long int** prefix;
    long long int k;
    std::cin >> N;
    std::cin >> M;
    std::cin >> k;

    matrix = (long long int**)malloc(sizeof(long long int*) * N);
    prefix = (long long int**)malloc(sizeof(long long int*) * N);
    

    for (long long int i = 0; i < N; i++)
    {
        matrix[i] = (long long int*)malloc(sizeof(long long int) * M);
        prefix[i] = (long long int*)malloc(sizeof(long long int) * M);
        for (long long int j = 0; j < M; j++)   
            std::cin >> matrix[i][j];
    }

    pre(prefix, matrix);

    long long int x1, y1, x2, y2;
    for (long long int i = 0 ; i < k; i++)
    {
        std::cin >> x1;
        std::cin >> y1;
        std::cin >> x2;
        std::cin >> y2;

        std::cout << query(prefix, x1 - 1, y1 - 1, x2 - 1, y2 - 1) << std::endl;
    }

    return 0;
}

long long query(long long int** prefix, long long int x1, long long int y1, long long int x2, long long int y2) 
{
    long long int RGBO = prefix[x2][y2];
    long long int RG = x1 ? prefix[x1 - 1][y2] : 0;
    long long int RB = y1 ? prefix[x2][y1 - 1] : 0;
    long long int R = x1 && y1 ? prefix[x1 - 1][y1 - 1] : 0;

    return RGBO - RG - RB + R;
}

void pre(long long int** prefix, long long int** matrix) 
{
    prefix[0][0] = matrix[0][0];

    for (long long int i = 1; i < N; i++)
        prefix[i][0] = prefix[i - 1][0] + matrix[i][0];

    for (long long int i = 1; i < M; i++)
        prefix[0][i] = prefix[0][i - 1] + matrix[0][i];

    for (long long int i = 1; i < N; i++)
        for (long long int j = 1; j < M; j++)
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i][j];
}

