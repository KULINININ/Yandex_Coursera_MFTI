#include <iostream>

int main()
{
    int a,b;
    std::cin >> a >> b;

    if((a%2) == 1)
    {
        a++;
    }
    if((b%2) == 1)
    {
        b--;
    }
    for (size_t i = a; i <= b; i+=2)
    {
        std::cout << a << " ";
        a+=2;
    }
}