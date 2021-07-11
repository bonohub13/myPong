#ifndef __GAMEUTILS_BALL_HPP__
#define __GAMEUTILS_BALL_HPP__

#include "racket.hpp"
#include "windowProfile.hpp"
#include "score.hpp"

namespace GameUtils
{

    class Ball
    {
    public:
        Ball(int init_pos_x, int init_pos_y);
        ~Ball();
    private: // variables
        // position
        float ball_pos_x;
        float ball_pos_y;
        // direction (negative value for left, positive for right)
        // range(-1, 1)
        float ball_dir_x;
        float ball_dir_y;
        // radius of ball
        int ball_radius;
        // speed (velocity)
        int ball_speed;
    public: // functions
        /**
         * @brief Draws Ball onto screen
         * 
         */
        void draw();
        /**
         * @brief update position of ball
         * @param racket1 racket for player 1
         * @param racket2 racket for player 2
         * 
         */
        void updateBall(Racket &racket1, Racket &racket2,
                        WindowProfile &window_profile, Score &score);
    private: // functions
        /**
         * @brief keeps the value of direction to 1
         * 
         * @param x 
         * @param y 
         */
        void vec2_norm(float &x, float &y);
    };

}

#endif // __GAMEUTILS_BALL_HPP__