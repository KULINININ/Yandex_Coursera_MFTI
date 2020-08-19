#include <iostream>
#include <string>
#include <map>
#include <vector>

void NEW_BUS(std::map <std::string, std::vector<std::string>>& bus_stops)
{
    std::string input;
    std::cin >> input;
    std::string name = input;
    std::vector <std::string> stops;

    while (true)
    {
        std::cin >> input;

        if (input != "0")
        {
            stops.push_back(input);
        }
        else
        {
            break;
        }
    }

    bus_stops[name] = stops;
}

void BUSES_FOR_STOP(std::map <std::string, std::vector<std::string>>& bus_stops)
{
    bool check = false;
    std::string stopName;
    std::cin >> stopName;

    for (const auto& busStops : bus_stops)
    {
        for (const auto& stops : busStops.second)
        {
            if (stops == stopName)
            {
                check = true;
                std::cout << busStops.first << " ";
            }
        }
    }

    if (check == false)
    {
        std::cout << "No stop";
    }
}

void STOPS_FOR_BUS(std::map <std::string, std::vector<std::string>>& bus_stops)
{
    bool check = false;
    bool checkBus = false;
    std::string busName;
    std::cin >> busName;

    for (const auto& stops : bus_stops[busName])
    {
        std::cout << "\n" <<stops;

        for (const auto& busStops : bus_stops)
        {
            for (const auto& stops_ : busStops.second)
            {
                if ((stops_ == stops) && (busStops.first != busName))
                {
                    if (check == true)
                    {
                        std::cout << "Stop " << busStops.first << " ";
                    }
                    else
                    {
                        check = true;
                        checkBus = true;
                        std::cout << ": " <<busStops.first << " ";
                    }
                }
            }
        }

        if (check == false)
        {
            std::cout << ": no interchange";
        }
        check = false;
    }

    if (checkBus == false)
    {
        std::cout << "No bus";
    }
}

void ALL_BUSES(std::map <std::string, std::vector<std::string>>& bus_stops)
{
    for (const auto& bus : bus_stops)
    {
        std::cout << "Bus " << bus.first << ": ";
        for  (const auto& stop : bus.second)
        {
            std::cout << stop << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::map <std::string, std::vector<std::string>> bus_stops;
    std::string input;

    while (true)
    {
        std::cin >> input;

        if (input == "NEW_BUS")
        {
            NEW_BUS(bus_stops);
        }
        else if (input == "BUSES_FOR_STOP")
        {
            BUSES_FOR_STOP(bus_stops);
        }
        else if (input == "STOPS_FOR_BUS")
        {
            STOPS_FOR_BUS(bus_stops);
        }
        else if (input == "ALL_BUSES")
        {
            ALL_BUSES(bus_stops);
        }
        else if (input == "0")
        {
            break;
        }
    }
}