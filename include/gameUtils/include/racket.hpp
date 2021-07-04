#ifndef __GAMEUTILS_RACKET_HPP__
#define __GAMEUTILS_RACKET_HPP__

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
        // speed
        int racket_speed;
        // position
        float racket_x;
        float racket_y;
    public: // functions
        /**
         * @brief Draw racket on screen
         * 
         */
        void drawRect();
        /* setters */

        void set_racket_x(float racket_x);
        void set_racket_x(float &racket_x);
        void set_racket_y(float racket_y);
        void set_racket_y(float &racket_y);
        /* getters */
        
        int get_racket_speed();
        float get_racket_x();
        float get_racket_y();
    };

}

#endif // __GAMEUTILS_RACKET_HPP__