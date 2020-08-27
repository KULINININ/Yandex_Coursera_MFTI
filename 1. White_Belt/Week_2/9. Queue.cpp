#include <iostream>
#include <string>
#include <vector>

void WORRY(int i, std::vector <bool>& queue)
{
    queue[i - 1] = true;
}

void QUIET(int i, std::vector <bool>& queue)
{
    queue[i - 1] = false;
}

void COME(int i, std::vector <bool>& queue)
{
    if (i < 0)
    {
        for (size_t j = 0; j < abs(i); j++)
        {
            queue.pop_back();
        }
    }
    else
    {
        for (size_t j = 0; j < i; j++)
        {
            queue.push_back(false);
        }
    }
}

void WORRY_COUNT(std::vector <bool>& queue)
{
    int num = 0;
    for (auto item : queue)
    {
        if (item == true)
        {
            num++;
        }
    }
    std::cout << num;
}

int main()
{
    std::vector <bool> queue;
    std::string input;
    int i;
    while (true)
    {
        std::cin >> input;
        if (input == "WORRY")
        {
            std::cin >> i;
            WORRY(i, queue);
        }
        else if (input == "QUIET")
        {
            std::cin >> i;
            WORRY(i, queue);
        }
        else if (input == "COME")
        {
            std::cin >> i;
            COME(i, queue);
        }
        else if (input == "WORRY_COUNT")
        {
            WORRY_COUNT(queue);
        }
        else if (input == "0")
        {
            break;
        }
    }
}