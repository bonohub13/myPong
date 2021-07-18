#ifndef __GAMEUTILS_RACKET_HPP__
#define __GAMEUTILS_RACKET_HPP__

#include <vector>
#include <array>

namespace GameUtils
{

    class Racket
    {
    public:
        /**
         * @brief Constructor for Racket
         * 
         * @param pos_x position (x)
         * @param pos_y position (y)
         */
        Racket(float pos_x, float pos_y);
        /**
         * @brief Constructor for Racket
         * 
         * @param racket_width width of racket
         * @param racket_height height of racket
         * @param racket_speed velocity for racket
         * @param pos_x position(x)
         * @param pos_y position(y)
         */
        Racket(int racket_width, int racket_height, int racket_speed,
               float pos_x, float pos_y);
        ~Racket();
    private: // variables
        // properties for racket
        // size
        int racket_width;
        int racket_height;
        // used to compute points of corners
        double radius;
        // speed
        int racket_speed;
        // rotation
        float racket_rotation;
        // position
        float racket_x;
        float racket_y;
        // points
        /**
         * @brief top-left, top-right, bottom-right, bottom-left
         * 
         */
        float point_x[4];
        float point_y[4];
    public:
        /**
         * @brief Sets the direction for rotation
         * 
         */
        enum RotateMode
        {
            CLOCKWISE,
            COUNTER_CLOCKWISE
        };
        /**
         * @brief Set if moving racket up, down, right, or left
         * 
         */
        enum MoveMode
        {
            UP,
            DOWN,
            RIGHT,
            LEFT
        };
    public: // functions
        /**
         * @brief Draw racket on screen
         * 
         */
        void drawRect();
        /**
         * @brief Rotates the racket
         * 
         * @param rotation 
         */
        void rotate_racket(RotateMode rotation);
        /**
         * @brief Move racket horizontally or vertically
         * 
         * @param move 
         */
        void move_racket(MoveMode move);
        
        /* setters */

        void set_racket_x(float racket_x);
        void set_racket_x(float &racket_x);
        void set_racket_y(float racket_y);
        void set_racket_y(float &racket_y);
        /* getters */
        
        int get_racket_speed();
        int get_racket_width();
        int get_racket_height();
        float get_racket_rotation();
        float* get_points_x();
        float* get_points_y();
    };

}

#endif // __GAMEUTILS_RACKET_HPP__