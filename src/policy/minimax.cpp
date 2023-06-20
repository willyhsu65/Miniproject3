#include <cstdlib>
#include <algorithm>
#include <climits>

#include "../state/state.hpp"
#include "./minimax.hpp"

int heuristic_value = INT_MIN;
Move Minimax::getmove(State *node,int depth)
{
    if (node->legal_actions.empty())
        node->get_legal_actions();
    heuristic_value = INT_MIN;
    auto actions = node->legal_actions;
    Move next;
    for (auto move : actions)
    {
        int heuristic = minimax(node->next_state(move),depth - 1,false);
        if (heuristic_value <= heuristic)
        {
            heuristic_value = heuristic;
            next = move;
        }
    }
    return next;
}
int minimax(State *node,int depth,bool maximizing_player)
{
    if (depth == 0)
    {
        if (maximizing_player)
            return node->evaluate()*(-1);
        else
            return node->evaluate();
    }

    if (maximizing_player)
    {
        int value = INT_MIN;
        node->get_legal_actions();
        auto actions = node->legal_actions;
        for (auto move : actions)
        {
            value = std::max(value,minimax(node->next_state(move),depth - 1,false));
        }
        return value;
    }
    else
    {
        int value = INT_MAX;
        node->get_legal_actions();
        auto actions = node->legal_actions;
        for (auto move : actions)
        {
            value = std::min(value,minimax(node->next_state(move),depth - 1,true));
        }
        return value;
    }
}