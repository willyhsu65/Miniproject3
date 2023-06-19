#include <cstdlib>
#include <algorithm>
#include <climits>
#define MAX_DEPTH 5

#include "../state/state.hpp"
#include "./minimax.hpp"

Move Minimax::getmove(State *node,int depth)
{
    Move next;
    int maxheuristic = INT_MIN;
    if (!node->legal_actions.size())
        node->get_legal_actions();
    for (auto child : node->legal_actions)
    { 
        int cur_heuristic = minimax(node->next_state(child),depth,true);
        if (cur_heuristic > maxheuristic)
        {
            maxheuristic = cur_heuristic;
            next = child;
        }
    }
    return next;
}
int minimax(State *node,int depth,bool maximizing_player)
{
    if (depth == 0)
    {
        return node->evaluate();
    }

    if (maximizing_player == true)
    {
        int value = INT_MIN;
        node->get_legal_actions();
        for (auto child : node->legal_actions)
            value = std::max(value,minimax(node->next_state(child),depth-1,false));
        return value;
    }

    else if (maximizing_player == false)
    {
        int value = INT_MAX;
        node->get_legal_actions();
        for (auto child : node->legal_actions)
            value = std::min(value,minimax(node->next_state(child),depth - 1,true));
        return value;
    }
}