#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <utility>
#include <cmath>

// Предварительное объявление шаблонных функций
template<typename Value> Value Sqr(Value x);

template<typename Value> std::vector<Value> Sqr(std::vector<Value>& value);

template<typename Key, typename Value> std::map<Key, Value> Sqr(
    const std::map<Key, Value>& value);

template<typename First, typename Second> std::pair<First, Second> Sqr(
    const std::pair<First, Second>& value);

template<typename Value> Value Sqr(Value x)
{
    return pow(x, 2);
}

template<typename Value> std::vector<Value> Sqr(std::vector<Value>& value)
{
    for (auto& item : value)
    {
        item = Sqr(item);
    }

    return value;
}

template<typename Key, typename Value> std::map<Key, Value> Sqr(
    const std::map<Key, Value>& value)
{
    std::map<Key, Value> result;

    for (const auto& item : value)
    {
        result[item.first] = Sqr(item.second);
    }

    return result;
}

template<typename First, typename Second> std::pair<First, Second> Sqr(
    const std::pair<First, Second>& value)
{
    return { Sqr(value.first), Sqr(value.second) };
}

int main()
{
    // Пример вызова функции
    std::vector<int> v = { 1, 2, 3 };
    std::cout << "vector:";
    for (int x : Sqr(v)) 
    {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;

    std::map<int, std::pair<int, int>> map_of_pairs = { {4, {2, 2} }, {7, {4, 3} } };
    std::cout << "map of pairs:" << std::endl;
    for (const auto& x : Sqr(map_of_pairs)) 
    {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
    }

    return 0;
}