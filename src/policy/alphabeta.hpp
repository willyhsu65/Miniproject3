#pragma once
#include "../state/state.hpp"


class Alphabeta
{
    public:
    static Move getmove(State* node,int depth);
};

int alphabeta(State *node,int depth,bool maximizing_player,int alpha, int beta);
