#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>

bool isDigit(char c);

bool isOperation(char c);

bool isBracket(char c);


int getPriority(char c);

class token
{
    public:
    bool type;
};

class num : public token
{
    public:

    num(long long int number)
    {
        this->type = true;
        this->number = number;
    }

    long long int number;
};

class operation : public token
{
    public:

    operation(char op)
    {
        this->type = false;
        this->op = op;
    }

    char op;
};

int main()
{
    std::string str;
    std::string input;
    std::getline(std::cin, input);
    std::vector<token*> inflex;

    //if (get == 0)
    //{
    //    std::cout << "WRONG" << std::endl;
    //    return 0;
    //}

    for (int i = 0; i < input.size(); i++)
    {
        if (i == 0 && input[i] == ' ')
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
        else if (input[i] == ' ' && (input[i + 1] == ' ' || input[i - 1] == ' '))
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
        else if (input[i] == ' ' && isDigit(input[i - 1]) && isDigit(input[i + 1]))
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != ' ')
        {
            str += input[i];
        }
    }

    input = str;    

    for (int i = 0; i < input.size(); i++)
    {
        if (isDigit(input[i]))
        {
            int _i = i;
            while(isDigit(input[i]))
            {
                i++;
            }
            std::size_t size = i - _i;
            inflex.push_back(new num(std::stoll(input.substr(_i, i - _i))));
            i--;
            continue;
        }
        else if (isOperation(input[i]) && isOperation(input[i + 1]))
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
        //else if (input[i] == '-' && i == 0 || !(isDigit(input[i - 1] || input[i - 1] == ')')))  //checking for unary minus
        //{
        //    inflex.push_back(operation('_'));
        //}
        //else if (input[i] == '+' && i == 0 || !(isDigit(input[i - 1] || input[i - 1] == ')')))  //checking for unary plus
        //{
        //    continue;
        //}
        else if (input[i] == '(' && isDigit(input[i - 1]))
        {
            inflex.push_back(new operation('*'));
            inflex.push_back(new operation('('));
        }
        else if (input[i] == ')' && isDigit(input[i + 1]))
        {
            inflex.push_back(new operation(')'));
            inflex.push_back(new operation('*'));
        }
        else if (input[i] == '(' && input[i + 1] == ')')
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
        else if(isOperation(input[i]) || isBracket(input[i]))
        {
            inflex.push_back(new operation(input[i]));
        }
        else
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
    }

    std::stack<token*> st;
    std::vector<token*> postfix;

    for (auto i = inflex.begin(); i != inflex.end(); i++)
    {
        if((*i)->type)
        {
            postfix.push_back(*i);
        }
        else if(((operation*)(*i))->op == '(')
        {
            st.push(*i);
        }
        else if(((operation*)(*i))->op == ')')
        {
            if (st.size() == 0)
            {
                std::cout << "WRONG" << std::endl;
                return 0;
            }

            while(((operation*)(st.top()))->op != '(')
            {
                if (st.size() == 0)
                {
                    std::cout << "WRONG" << std::endl;
                    return 0;
                }
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if(isOperation(((operation*)(*i))->op))
        {
            while(st.size() != 0 && ((operation*)st.top())->op != '(' && getPriority(((operation*)st.top())->op) >= getPriority(((operation*)(*i))->op))
            {
                postfix.push_back(st.top());
                st.pop();
            }

            st.push(*i);
        }
        else
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
    }

    while(st.size() != 0)
    {
        postfix.push_back(st.top());
        st.pop();
    }

    std::stack<long long int> st1;
    for (auto i = postfix.begin(); i != postfix.end(); i++)
    {
        if((*i)->type)
        {
            st1.push(((num*)(*i))->number);
        }
        else if(isBracket(((operation*)(*i))->op))
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
        else
        {
            if (st.size() == 0)
            {
                std::cout << "WRONG" << std::endl;
                return 0;
            }
            long long int operand2 = st1.top();
            st1.pop();
            if (st.size() == 0)
            {
                std::cout << "WRONG" << std::endl;
                return 0;
            }
            long long int operand1 = st1.top();
            long long int result;
            switch (((operation*)(*i))->op)
            {
            case '*':
                result = operand1 * operand2;
                break;
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            default:
                std::cout << "WRONG" << std::endl;
                return 0;
            }

            st1.pop();
            st1.push(result);
        }
    }

    if(st1.size() != 1)
    {
        std::cout << "WRONG" << std::endl;
        return 0;
    }

    std::cout << st1.top();
    return 0;
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isOperation(char c)
{
    return c == '+' || c == '-' || c == '*';// || c == '_';
}

bool isBracket(char c)
{
    return c == '(' || c == ')';
}


int getPriority(char c)
{
    if (c == '*')
        return 2;
    else 
        return 1;
}