#ifndef __GAMEUTILS_BALL_HPP__
#define __GAMEUTILS_BALL_HPP__

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
    public:
        /**
         * @brief Draws Ball onto screen
         * 
         */
        void draw();
        /**
         * @brief update position of ball
         * 
         */
        void updateBall();
    };

}

#endif // __GAMEUTILS_BALL_HPP__