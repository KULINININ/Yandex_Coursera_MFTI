#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::string buff;
    std::vector<std::string> vec(3);
    std::cin >> vec[0];
    std::cin >> vec[1];
    std::cin >> vec[2];
    sort(vec.begin(), vec.end());
    std::cout << vec[0];
}