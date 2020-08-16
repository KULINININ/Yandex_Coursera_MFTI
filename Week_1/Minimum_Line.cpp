#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string buff;
    vector<string> vec(3);
    cin >> vec[0];
    cin >> vec[1];
    cin >> vec[2];
    sort(vec.begin(), vec.end());
    cout << vec[0];
}