#include <string>
#include <map>
#include <iostream>
#include <vector>
#pragma once
class TodoList{
    private:
        // key is task name
        // vector value represents all tasks under that task name
        // vector to hold if each task is complete or not (bool)
        std::map<std::string, std::vector<bool>> taskList;
    public:
        void add(std::string name);
        void all();
        void complete(std::string name);
        void complete();
        void incomplete();
        void clear();
        void pretty_print(std::string name, bool complete);
        std::map<std::string, std::vector<bool>>& getTasks();

};