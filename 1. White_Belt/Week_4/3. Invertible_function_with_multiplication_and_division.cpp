#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class FunctionPart {
public:

    FunctionPart(char operation_, double value_)
    {
        operation = operation_;
        value = value_;
    }

    double Apply(double value_) const
    {
        if (operation == '+')
        {
            return value_ + value;
        }
        else if (operation == '*')
        {
            return value_ * value;
        }
        else if (operation == '/')
        {
            return value_ / value;
        }
        else
        {
            return value_ - value;
        }
    }

    void Invert()
    {
        if (operation == '+') 
        {
            operation = '-';
        }
        else if (operation == '-') 
        {
            operation = '+';
        }
        else if (operation == '/') 
        {
            operation = '*';
        }
        else 
        {
            operation = '/';
        }
    }

private:
    char operation;
    double value;
};


class Function
{
public:

    void AddPart(char operation, double value)
    {
        parts.push_back(FunctionPart(operation, value));
    }

    double Apply(double value) const
    {
        for (auto& part : parts)
        {
            value = part.Apply(value);
        }
        return value;
    }

    void Invert()
    {
        for (auto& part : parts)
        {
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    }

private:
    std::vector<FunctionPart> parts;
};

int main()
{
    Function func;
    func.AddPart('/', 3);
    func.Invert();
    std::cout << func.Apply(9);
}