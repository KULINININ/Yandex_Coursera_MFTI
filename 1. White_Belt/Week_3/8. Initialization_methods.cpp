#include <iostream>
#include <string>
#include <algorithm>

class Incognizable
{
private:
public:
    int x;
    int y;
};

int main()
{
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}