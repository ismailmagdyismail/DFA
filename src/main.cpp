#include <iostream>

#include "DFA.h"

bool test2(const std::string &p_strInput)
{
    State startingState = "A";
    std::set<std::string> finalStates = {"D"};
    std::map<State, Transitions> transitionTable = {
        {"A", {{"0", "DeadState"}, {"1", "B"}}},
        {"B", {{"0", "C"}, {"1", "C"}}},
        {"C", {{"0", "D"}, {"1", "D"}}},
        {"D", {{"0", "DeadState"}, {"1", "DeadState"}}},
        {"DeadState", {{"0", "DeadState"}, {"1", "DeadState"}}},
    };
    DFA dfa(startingState, transitionTable, finalStates);
    return dfa.Run(p_strInput);
}

int main()
{
    while (true)
    {
        std::string input;
        std::cout << "Enter Text to proccess: ";
        std::cin >> input;
        bool bResult = test2(input);
        if (bResult)
        {
            std::cout << "\033[32m[Success]: input is valid\033[0m\n";
        }
        else
        {
            std::cout << "\033[31m[Fail]: input is NOT valid\033[0m\n";
        }
    }
}
