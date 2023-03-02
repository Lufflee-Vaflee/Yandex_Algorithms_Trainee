#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>

bool foo(long long int K);


int main()
{
    long long int N;
    std::cin >> N;
    for(long long int i = 0; i < N; i++)
    {
        long long int K;
        std::cin >> K;
        std::cout << foo(K) << std::endl;
    }

}

bool foo(long long int K)
{
    double num;
    std::vector<double> cont2;
    std::map<double, std::pair<int, int>> cont1;
    for (int i = 0; i < K; i++)
    {
        std::cin >> num;
        cont2.push_back(num);
        auto d = cont1.try_emplace(num, -1, 1);
        if (d.second == false)
        {
            (*d.first).second.second++;
        }
    }

    int i = 0;
    for(auto t = cont1.begin(); t != cont1.end(); t++)
    {
        (*t).second.first = i;
        i++;
    }

    std::stack<int> st;
    int last = 0;
    for (int i = 0; i < K; i++)
    {
        auto temp = cont1.find(cont2[i]);
        st.push((*temp).second.first);
        while(st.size() != 0 && st.top() == last && (*temp).second.second)
        {
            (*temp).second.second--;
            if (!(*temp).second.second)
            {
                last++;
                temp++; 
            }
            st.pop();
        }
    }

    if(st.size() != 0)
    {
        return false;
    }

    return true;
}