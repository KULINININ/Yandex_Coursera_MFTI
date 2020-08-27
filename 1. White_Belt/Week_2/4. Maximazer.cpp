#include <iostream>
#include <string>

void UpdateIfGreater(int& x, int& y)
{
    if(x > y)
    {
        y = x;
    }
}

int main()
{
    int x, y;
    std::cin >> x >> y;
    UpdateIfGreater(x, y);
    std::cout << x << " " << y;
}