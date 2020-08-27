#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart {
public:

    FunctionPart(char operation_, double value_)
    {
        operation = operation_;
        value = value_;
    }

    double Apply(double value_)
    {
        if (operation == '+')
        {
            return value + value_;
        }
        else
        {
            return value - value_;
        }
    }

    void Invert()
    {
        if (operation == '+')
        {
            operation = '-';
        }
        else
        {
            operation = '+';
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

    double Apply(double value)
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
    vector<FunctionPart> parts;
};

int main()
{
    Function func;
    func.AddPart('+', 3);
    func.Invert();
    cout << func.Apply(2);
}