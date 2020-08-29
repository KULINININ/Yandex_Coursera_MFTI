#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks {
public:

    void AddNewTask(const std::string& person)
    {
        ++personsTasks[person][TaskStatus::NEW];
    }

    const TasksInfo& GetPersonTasksInfo(const std::string& person) const
    {
        return personsTasks.at(person);
    }

    std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person, int task_count)
    {
        TasksInfo updatedTasks, untouchedTasks;
        TasksInfo& newPersonTasks = personsTasks[person];

        for (int i = 0; i < 3; i++)
        {
            updatedTasks[GetStatus(i + 1)] = std::min(task_count, newPersonTasks[GetStatus(i)]);
            task_count -= updatedTasks[GetStatus(i + 1)];
        }

        for (int i = 0; i < 3; i++)
        {
            untouchedTasks[GetStatus(i)] = newPersonTasks[GetStatus(i)] - updatedTasks[GetStatus(i+1)];
            newPersonTasks[GetStatus(i)] += updatedTasks[GetStatus(i)] - updatedTasks[GetStatus(i + 1)];
        }

        newPersonTasks[TaskStatus::DONE] += updatedTasks[TaskStatus::DONE];

        RemoveZeroStatus(updatedTasks);
        RemoveZeroStatus(untouchedTasks);
        RemoveZeroStatus(personsTasks.at(person));
        
        return std::make_pair(updatedTasks, untouchedTasks);
    }

private:
    std::map <std::string, TasksInfo> personsTasks;

    TaskStatus GetStatus(int i)
    {
        return static_cast<TaskStatus>(static_cast<int>(i));
    }

    void RemoveZeroStatus(TasksInfo& tasks) 
    {
        std::vector<TaskStatus> statusesToRemove;

        for (const auto& task : tasks) 
        {
            if (task.second == 0) 
            {
                statusesToRemove.push_back(task.first);
            }
        }

        for (const TaskStatus status : statusesToRemove) 
        {
            tasks.erase(status);
        }
    }
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}

int main() {
    TeamTasks tasks;

    tasks.AddNewTask("Ilia");

    for (int i = 0; i < 3; ++i) 
    {
        tasks.AddNewTask("Ivan");
    }

    std::cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    std::cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updatedTasks, untouchedTasks;

    tie (updatedTasks, untouchedTasks) = tasks.PerformPersonTasks("Ivan", 2);
    
    std::cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updatedTasks);
    std::cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouchedTasks);

    tie(updatedTasks, untouchedTasks) = tasks.PerformPersonTasks("Ivan", 2);

    std::cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updatedTasks);
    std::cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouchedTasks);

    return 0;
}