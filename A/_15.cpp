#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>

bool isLetter(char c);

bool isVaild(std::string& str);

bool tryPush(std::stack<std::pair<std::string::iterator, std::string::iterator>>& st, std::string::iterator& begin, std::string::iterator end_border);

bool tryPop(std::stack<std::pair<std::string::iterator, std::string::iterator>>& st, std::string::iterator& begin, std::string::iterator end_border);

int main()
{
    std::string t;
    std::cin >> t;
    if(isVaild(t))
    {
        std::cout << t;
        return 0;
    }

    for(char i = 'a'; i <= 'z'; i++)
    {
        for(int j = 0; j < t.size(); j++)
        {
            char cache = t[j];
            t[j] = i;
            if(isVaild(t))
            {
                std::cout << t;
                return 0;
            }
            t[j] = cache;
        }
    }

    char i = '>';
    for(int j = 0; j < t.size(); j++)
    {
        char cache = t[j];
        t[j] = i;
        if(isVaild(t))
        {
            std::cout << t;
            return 0;
        }
        t[j] = cache;
    }

    i = '<';
    for(int j = 0; j < t.size(); j++)
    {
        char cache = t[j];
        t[j] = i;
        if(isVaild(t))
        {
            std::cout << t;
            return 0;
        }
        t[j] = cache;
    }

    i = '/';
    for(int j = 0; j < t.size(); j++)
    {
        char cache = t[j];
        t[j] = i;
        if(isVaild(t))
        {
            std::cout << t;
            return 0;
        }
        t[j] = cache;
    }

    return 0;
}

bool isVaild(std::string& str)
{
    if (str.size() < 7)
    {
        return false;
    }

    std::stack<std::pair<std::string::iterator, std::string::iterator>> st;
    std::string::iterator temp = str.begin();
    while(temp != str.end())
    {
        if(*temp == '<' && (temp + 1) != str.end() && *(temp + 1) == '/')
        {
            temp += 2;
            if(!tryPop(st, temp, str.end()))
            {
                return false;
            }
        }
        else if(*temp == '<')
        {
            temp++;
            if(!tryPush(st, temp, str.end()))
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        temp++;
    }

    return st.size() == 0;
}

bool tryPop(std::stack<std::pair<std::string::iterator, std::string::iterator>>& st, std::string::iterator& begin, std::string::iterator end_border)
{
    if(st.size() == 0)
    {
        return false;
    }

    auto a = st.top().first;
    auto b = st.top().second;
    
    while(a != b)
    {
        if (begin == end_border || *a != *begin)
        {
            return false;
        }
        begin++;
        a++;
    }

    if (*begin != '>')
    {
        return false;
    }

    st.pop();
    return true;
}

bool tryPush(std::stack<std::pair<std::string::iterator, std::string::iterator>>& st, std::string::iterator& begin, std::string::iterator end_border)
{
    auto start = begin;
    while(*begin != '>')
    {
        if (begin == end_border || !isLetter(*begin))
        {
            return false;
        }

        begin++;
    }

    st.push(std::pair<std::string::iterator, std::string::iterator>(start, begin));
    return true;
}


bool isLetter(char c)
{
    return c >= 'a' && c <= 'z';
}