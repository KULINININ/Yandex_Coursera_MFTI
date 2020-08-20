#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector <int> vec;
    int len, input;
    std::cin >> len;
    for (size_t i = 0; i < len; i++)
    {
        std::cin >> input;
        vec.push_back(input);
    }

    sort(begin(vec), end(vec), [](const int& x, const int& y) {
        return abs(x) < abs(y);
        });

    for (auto x : vec)
    {
        std::cout << x << " ";
    }
}