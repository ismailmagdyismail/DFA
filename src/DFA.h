
#pragma once

#include <string>
#include <map>
#include <set>

typedef std::string State;                        //! State Symbol
typedef std::string InputSymbol;                  //! Symbol that causes transition of current state to next
typedef std::map<InputSymbol, State> Transitions; //! Input to output mapping for a certain state

/*
    - A better more robust solution is to make DFA input an array of states with configurations
        - with thier Transitions
        - wether they are final or not , etc...
        - And table get constructed in DFA internally
        - This makes it impossible to represent Invalid states by client
        - would remove validations required in cosnstructor
*/
class DFA
{
public:
    DFA(State &p_strStartState, std::map<State, Transitions> &p_oStateTransistionsTable, std::set<State> &p_oFinalStates)
    {
        //! Should validate states here
        //! Make sure start is among symbols
        //! Make sure finals is among symbols
        m_oStartState = p_strStartState;
        m_oStatesTransitionTable = p_oStateTransistionsTable;
        m_oFinalStates = p_oFinalStates;
    }

    bool Run(const std::string &input)
    {
        std::size_t sSize = input.size();
        State strCurrentState = m_oStartState;
        for (int i = 0; i < sSize; ++i)
        {
            std::string strCurrentSymbol = std::string(1, input[i]);
            Transitions oPossibleTransitionsForCurrentState = m_oStatesTransitionTable[strCurrentState];
            if (!isTransitionAvailable(oPossibleTransitionsForCurrentState, strCurrentSymbol))
            {
                std::cerr << "NO TransitionAvailable" << std::endl;
                return false;
            }
            strCurrentState = oPossibleTransitionsForCurrentState[strCurrentSymbol];
        }
        return isFinalStateReached(strCurrentState);
    }

private:
    bool isCurrentSymbolInAlphabet(const std::string &p_strSymbol) const
    {
        return m_oStatesTransitionTable.end() != m_oStatesTransitionTable.find(p_strSymbol);
    }

    bool isTransitionAvailable(const Transitions &p_oTransitions, const std::string &p_strSymbol)
    {
        return p_oTransitions.end() != p_oTransitions.find(p_strSymbol);
    }

    bool isFinalStateReached(const State &p_strState)
    {
        return m_oFinalStates.end() != m_oFinalStates.find(p_strState);
    }

    State m_oStartState;
    std::map<State, Transitions> m_oStatesTransitionTable;
    std::set<State> m_oFinalStates;
};