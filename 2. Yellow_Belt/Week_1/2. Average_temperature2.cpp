#include <iostream>
#include <vector>

int main() 
{
    int length;
    std::cin >> length;

    std::vector<int> temps(length);
    int64_t avg_temp = 0;

    for (int& temp : temps) 
    {
        std::cin >> temp;
        avg_temp += temp;
    }

    avg_temp /= length;

    std::vector<int> over {0};

    for (size_t i = 0; i < length; i++)
    {
        if (temps[i] > avg_temp)
        {
            over[0]++;
            over.push_back(i + 1);
        }
    }

    for (auto temp : over)
    {
        std::cout << temp << " ";
    }

    return 0;
}