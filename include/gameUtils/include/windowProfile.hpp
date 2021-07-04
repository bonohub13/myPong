#ifndef __GAMEUTILS_WINDOW_PROFILE_HPP__
#define __GAMEUTILS_WINDOW_PROFILE_HPP__

namespace GameUtils
{

    /**
     * @brief Profile for window for game
     *  contains window size (width, height) and interval (fps)
     *  for window
     */
    struct WindowProfile
    {
    public: // window size and update rate (60 fps)
        const int WIDTH = 1920;
        const int HEIGHT = 1080;
        const int INTERVAL = 1000 / 60;
    };

}

#endif // __GAMEUTILS_WINDOW_PROFILE_HPP__