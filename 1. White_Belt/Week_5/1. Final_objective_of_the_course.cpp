#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

class Date 
{
private:
    int year;
    int month;
    int day;

public:
    Date(int& year, int& month, int& day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    int GetYear() const
    {
        return year;
    }
    int GetMonth() const
    {
        return month;
    }
    int GetDay() const 
    {
        return day;
    }
};

Date parseDate(std::string& input)
{
    try
    {
        int year, month, day;
        std::stringstream ss;
        ss << input;

        ss >> year;
        if (ss.peek() != '-')
        {
            throw std::exception();
        }
        ss.ignore(1);

        ss >> month;
        if (ss.peek() != '-')
        {
            throw std::exception();
        }
        ss.ignore(1);

        ss >> day;

        if ((month < 1) || (month > 12))
        {
            throw std::invalid_argument("Month value is invalid: " + std::to_string(month));
        }
        if ((day < 1) || (day > 31))
        {
            throw std::invalid_argument("Day value is invalid: " + std::to_string(day));
        }

        Date date{ year, month, day };
        return date;
    }

    catch (std::invalid_argument& e) 
    {
        throw;
    }
    catch (std::exception&) 
    {
        throw std::invalid_argument("Wrong date format");
    }
}

class Database 
{
private:
    std::map<Date, std::set<std::string>> events;

public:
    void AddEvent(const Date& date, const std::string& event)
    {
        events[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const std::string& event)
    {
        if ((events[date].count(event) !=0) && (events.count(date) != 0))
        {
            events[date].erase(event);
            return true;
        }
        else
        {
            return false;
        }
    }

    int DeleteDate(const Date& date)
    {
        int eventsCount = events[date].size();

        if (events.count(date) != 0)
        {
            events.erase(date);
            return eventsCount;
        }
        else
        {
            return 0;
        }
    }

    void Find(const Date& date) const
    {
        std::cout << "Events: ";
        for (std::set<std::string>::iterator it = events.at(date).begin(); it != --events.at(date).end(); ++it)
        {
            std::cout << *it << ", ";
        }
        std::cout << *--(events.at(date).end());
        std::cout << std::endl;
    }

    void Print() const
    {
        for (const auto& event : events)
        {
            std::cout << event.first.GetYear() << "-"
                << event.first.GetMonth() << "-"
                << event.first.GetDay() << " Events: ";

            for (std::set<std::string>::iterator it = event.second.begin(); it != --event.second.end(); ++it)
            {
                std::cout << *it << ", ";
            }

            std::cout << *--(event.second.end()) << std::endl;
        }
    }
};

bool operator<(const Date& lhs, const Date& rhs) 
{
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} < std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

int main() 
{    
    Database db;
    std::string command;

    while (getline(std::cin, command))
    {
        std::stringstream ss(command);
        ss >> command;

        if (command == "Add")
        {
            try
            {
                ss >> command;
                Date date = parseDate(command);
                ss >> command;
                db.AddEvent(date, command);
            }
            catch (std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        else if (command == "Print")
        {
            db.Print();
        }

        else if (command == "Del")
        {
            ss >> command;
            Date date = parseDate(command);

            std::string event;
            ss >> event;

            if (event.empty())
            {
                const int count = db.DeleteDate(date);

                if (count)
                {
                    std::cout << "Delted " << count << " events";
                }

                else
                {
                    std::cout << "Date not found";
                }
            }

            else
            {
                if (db.DeleteEvent(date, event))
                {
                    std::cout << "Deleted successfully";
                }

                else
                {
                    std::cout << "Event not found";
                }
            }

            std::cout << std::endl;
        }

        else if (command == "Find")
        {
            ss >> command;
            const Date date = parseDate(command);
            db.Find(date);
        }

        else if (command.empty())
        {
            break;
        }

        else
        {
            std::cout << "Unknown command: " << command << std::endl;
        }
    }
}