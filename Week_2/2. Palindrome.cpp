#include <iostream>
#include <string>

int main()
{
    int mid;
    std::string input, left, right;
    std::cin >> input;

    if(((input.size())%2) == 1)
    {
        mid = (input.size())/2;

        for (size_t i = 0; i < mid; i++)
        {
            left += input[i];
        }

        for (size_t i = input.size() - 1; i > mid; i--)
        {
            right += input[i];
        }

        if(right == left)
        {
            std::cout << "true" ;
        }
        else
        {
            std::cout << "false" ;
        }
    }
    
    if(((input.size())%2) == 0)
    {
        mid = (input.size() - 1)/2;

        for (size_t i = 0; i <= mid; i++)
        {
            left += input[i];
        }

        for (size_t i = input.size() - 1; i > mid; i--)
        {
            right += input[i];
        }

        if(right == left)
        {
            std::cout << "true" ;
        }
        else
        {
            std::cout << "false" ;
        }  
    }
}