#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector <int> vec;
    int num;
    int rem = 0;
    std::cin >> num;
    while (num != 0)
    {
        rem = num % 2;
        num /= 2;
        vec.push_back(rem);
    }

    for (int i = vec.size(); i > 0; i--)
    {
        std::cout << vec[i - 1];
    }
}