#include <string>
#include "TodoList.hpp"
void TodoList::pretty_print(std::string name, bool complete){
   std::string output = "";
   output += "Task: " + name;
   output += " | COMPLETE: ";
   std::cout << output << std::boolalpha << complete << " | " << std::endl;
}

void TodoList::add(std::string name){
   if(name == ""){
      std::cout << std::endl << "Cannot enter blank task." << std::endl;
      return;
   }
   if(taskList.count(name) > 0){
      for(const auto& complete : taskList[name]){
         if(!complete){
            std::cout << std::endl << "Cannot enter duplicate of incomplete task." << std::endl;
            return;
         }
      }
      taskList[name].push_back(false);
   }else{
      taskList[name] = {false};
   }
}
void TodoList::all(){
   if(taskList.size() == 0){
      std::cout << "\n| The To-Do List is Currently Empty |\n";
      return;
   }
   std::cout << "\nTOTAL TASK LIST:\n";
   for(const auto& task : taskList){
      for(const auto& complete : task.second){
         pretty_print(task.first, complete);
      }
   }
}
void TodoList::complete(std::string name){
   if(taskList.count(name) > 0){
      for(int i=0; i < taskList[name].size(); i++){
         taskList[name][i] = true;
      }
   }
}
void TodoList::complete(){
   std::cout << "\nCOMPLETED TASKS: \n";
   for(const auto& task : taskList){
      for(const auto& complete : task.second){
         if(complete){
            pretty_print(task.first, complete);
         }
      }
   }
}
void TodoList::incomplete(){
   std::cout << "\nUNCOMPLETED TASKS: \n";
   for(const auto& task : taskList){
      for(const auto& complete : task.second){
         if(!complete){
            pretty_print(task.first, complete);
         }
      }
   }
}
void TodoList::clear(){
   taskList.clear();
}
std::map<std::string, std::vector<bool>>& TodoList::getTasks(){
   return taskList;
}
