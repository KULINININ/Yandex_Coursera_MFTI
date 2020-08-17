#include <iostream>
#include <string>

int main()
{
    std::string input;
    int a;
    int b = -2;
    std::cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if(input[i] == 'f')
        {
            a = i;
            b++;
        }
    }

    if(b >= 0)
    {
        std::cout << a;
    }
    else
    {
        std::cout << b;
    } 
}