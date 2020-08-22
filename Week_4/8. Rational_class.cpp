#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <vector>

int GreatestCommonDivisor(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    }
    else 
    {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Rational 
{
public:
    Rational() 
    {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) 
    {
        int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        if (denominator < 0) 
        {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const 
    {
        return numerator;
    }

    int Denominator() const 
    {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs)
{
    if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    return  { lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator-(const Rational& lhs, const Rational& rhs) 
{
    return { lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return { lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator / (const Rational & lhs, const Rational & rhs) 
{
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

std::istream& operator >> (std::istream& stream, Rational& r) 
{
    int a, b;
    char c;

    if (stream) {
        stream >> a >> c >> b;
        if (stream && c == '/') {
            r = Rational(a, b);
        }
    }

    return stream;
}

std::ostream& operator << (std::ostream& stream, const Rational& r) {
    return stream << r.Numerator() << '/' << r.Denominator();
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}


int main() 
{
    using namespace std;
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };

        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
