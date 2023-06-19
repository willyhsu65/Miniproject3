#pragma once
#include "../state/state.hpp"


class Minimax
{
    public:
    static Move getmove(State* node,int depth);
};

int minimax(State *node,int depth,bool maximizing_player);
