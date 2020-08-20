#include <iostream>
#include <string>
#include <set>

int main()
{
    std::set <std::string> str;
    int input;
    std::cin >> input;

    for (size_t i = 0; i < input; i++)
    {   
        std::string input_;
        std::cin >> input_;
        str.insert(input_);
    }
    
    std::cout << str.size();
}