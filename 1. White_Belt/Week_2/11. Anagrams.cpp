#include <iostream>
#include <string>
#include <map>

std::map <char, int> BuildCharCounters (std::string input)
{
    std::map <char, int> anag;
    for(auto letter : input)
    {
        ++anag[letter];
    }
    return anag;
}

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    if(BuildCharCounters(a) == BuildCharCounters(b))
    {
        std::cout << "YES";

    }
    else
    {
        std::cout << "NO";
    }   
}