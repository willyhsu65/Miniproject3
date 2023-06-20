#include <cstdlib>
#include <algorithm>
#include <climits>

#include "../state/state.hpp"
#include "./alphabeta.hpp"


Move Alphabeta::getmove(State *node,int depth)
{
    int alpha_value = INT_MIN;
    int beta_value = INT_MAX;
    alpha_value = INT_MIN;
    beta_value = INT_MAX;
    if (node->legal_actions.empty())
        node->get_legal_actions();
    int heuristic_value = INT_MIN;
    auto actions = node->legal_actions;
    Move next;
    for (auto move : actions)
    {
        int heuristic = alphabeta(node->next_state(move),depth - 1,false,alpha_value,beta_value);
        if (heuristic_value <= heuristic)
        {
            heuristic_value = heuristic;
            next = move;
        }
    }
    return next;
}
int alphabeta(State *node,int depth,bool maximizing_player,int alpha,int beta)
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
            value = std::max(value,alphabeta(node->next_state(move),depth - 1,false,alpha,beta));
            alpha = std::max(value,alpha);
            if (alpha >= beta)
                break;
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
            value = std::min(value,alphabeta(node->next_state(move),depth - 1,true,alpha,beta));
            beta = std::min(beta,value);
            if (beta <= alpha)
                break;
        }
        return value;
    }
}