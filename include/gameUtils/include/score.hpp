#ifndef __GAMEUTILS_SCORE_HPP__
#define __GAMEUTILS_SCORE_HPP__

namespace GameUtils
{

    /**
     * @brief Class to store scores for individual players
     * (2 players in total)
     */
    class Score
    {
    public:
        Score();
        ~Score();
    private:
        int score_player1; // left
        int score_player2; // right
    public:
        int get_score_player1();
        void set_score_player1(int score);
        int get_score_player2();
        void set_score_player2(int score);
    };

} // namespace GameUtils

#endif