#include <iostream>
#include <string>
#include <vector>;

void MoveStrings(std::vector <std::string>& first, std::vector <std::string>& second)
{
    for (size_t i = 0; i < first.size(); i++)
    {
        second.push_back(first[i]);
    }
    first.clear();
}

int main()
{
    std::vector <std::string> first{ "a", "b", "c" };
    std::vector <std::string> second;

    MoveStrings(first, second);

    for (size_t i = 0; i < second.size(); i++)
    {
        std::cout << second[i];
    }
}