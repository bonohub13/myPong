#include "../include/score.hpp"

GameUtils::Score::Score()
{
    this->score_player1 = 0;
    this->score_player2 = 0;
}

GameUtils::Score::~Score()
{}

int GameUtils::Score::get_score_player1()
{
    return score_player1;
}

void GameUtils::Score::set_score_player1(int score)
{
    score_player1 = score;
}

int GameUtils::Score::get_score_player2()
{
    return score_player2;
}

void GameUtils::Score::set_score_player2(int score)
{
    score_player2 = score;
}