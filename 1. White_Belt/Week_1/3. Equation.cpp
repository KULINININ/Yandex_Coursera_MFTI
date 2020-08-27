#include <iostream>
#include <cmath>
#include <set>
int main()
{
    std::set<double> s;
    double a,b,c,D;
    std::cin >> a >> b >> c;
    D = sqrt(pow(b, 2) - 4 * a * c);
    if ((D >= 0) && (a!=0))
    {
        s.insert((-b + D) / (2 * a));
        s.insert((-b - D) / (2 * a));
        for (auto item : s)
        {
            std::cout << item << " ";
        }
    }
    else if (a == 0)
    {
        if(b!=0)
        {
        std::cout << c / b;
        }
    }
}