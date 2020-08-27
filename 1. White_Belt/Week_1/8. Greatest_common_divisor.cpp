#include <iostream>
#include <string>

int main()
{
    int a, b;
    std::cin >> a >> b;

    for (size_t i = a; i > 0; i--)
    {
        if((a%i == 0) && (b%i == 0))
        {
            std::cout << i;
            break;
        }
    }
}