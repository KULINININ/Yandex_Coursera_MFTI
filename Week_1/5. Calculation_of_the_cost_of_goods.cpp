#include <iostream>

int main()
{
    double n,a,b,x,y;
    std::cin >> n >> a >> b >> x >> y;
    if(n>b)
    {
        std::cout << n*((100-y)/100);
    }
    else if(n>a)
    {
        std::cout << n*((100-x)/100);
    }
    else
    {
        std::cout << n;    
    }
}