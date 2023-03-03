#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>

struct A
{
    A(long long int height, int right_border, int left_border)
    {
        this->height = height;
        this->left_border = left_border;
        this->right_border = right_border;
    }
    long long int height;
    int right_border;
    int left_border;
};

int main()
{
    int size;
    std::vector<A*> in;
    std::cin >> size;

    long long int num;
    for(int i = 0; i < size; i++)
    {
        std::cin >> num;
        in.push_back(new A(num, -1, -1));
    }

    std::stack<A*> st;
    for(auto i = in.begin(); i != in.end(); i++)
    {
        while(st.size() != 0 && st.top()->height > (*i)->height)
        {
            st.top()->right_border = i - in.begin();
            st.pop();
        }
        st.push(*i);
    }

    while(st.size() != 0)
    {
        st.top()->right_border = in.size();
        st.pop();
    }

    for(auto i = in.rbegin(); i != in.rend(); i++)
    {
        while(st.size() != 0 && st.top()->height > (*i)->height)
        {
            st.top()->left_border = in.rend() - i - 1;
            st.pop();
        }
        st.push(*i);
    }

    while(st.size() != 0)
    {
        st.top()->left_border = -1;
        st.pop();
    }

    long long int max = 0;
    for(int i = 0; i < in.size(); i++)
    {
        long long int temp = in[i]->height *(in[i]->right_border - in[i]->left_border - 1);
        if (temp > max)
        {
            max = temp;
        }
    }

    std::cout << max;

    return 0;
}