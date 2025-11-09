#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "../src/TodoList.hpp"

TEST_CASE("Add new task"){
    TodoList todo;
    std::map<std::string, std::vector<bool>>& tasks = todo.getTasks();
    todo.add("Go outside");
    REQUIRE(tasks["Go outside"][0] == false);
}
TEST_CASE("Complete a task"){
    TodoList todo;
    std::map<std::string, std::vector<bool>>& tasks = todo.getTasks();
    todo.add("Go outside");
    todo.complete("Go outside");
    REQUIRE(tasks["Go outside"][0] == true);
}
TEST_CASE("Cannot complete a non-existent task"){
    TodoList todo;
    std::map<std::string, std::vector<bool>>& tasks = todo.getTasks();
    todo.add("Go outside");
    todo.complete("Go inside");
    REQUIRE(tasks["Go inside"].size() == 0);
}
TEST_CASE("Cannot add multiple same uncompleted tasks"){
    TodoList todo;
    std::map<std::string, std::vector<bool>>& tasks = todo.getTasks();
    todo.add("Go outside");
    todo.add("Go outside");
    REQUIRE(tasks["Go outside"].size() == 1);
}
TEST_CASE("Can add multiple tasks when one is completed"){
    TodoList todo;
    std::map<std::string, std::vector<bool>>& tasks = todo.getTasks();
    todo.add("Go outside");
    todo.add("Go outside");
    REQUIRE(tasks["Go outside"].size() == 1);
    todo.complete("Go outside");
    todo.add("Go outside");
    REQUIRE(tasks["Go outside"].size() == 2);
}
TEST_CASE("Cannot enter blank task"){
    TodoList todo;
    std::map<std::string, std::vector<bool>>& tasks = todo.getTasks();
    todo.add("");
    REQUIRE(tasks[""].size() == 0);
}
TEST_CASE("Can add and clear tasks"){
    TodoList todo;
    std::map<std::string, std::vector<bool>>& tasks = todo.getTasks();
    todo.add("New task");
    REQUIRE(tasks["New task"].size() == 1);
    todo.clear();
    REQUIRE(tasks["New task"].size() == 0);
}
