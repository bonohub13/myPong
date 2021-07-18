#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/freeglut.h"

#include "../include/gameUtils/include/GameUtils.hpp"

const int RACKET_WIDTH = 10;
const int RACKET_HEIGHT = 80;

GameUtils::WindowProfile window_profile;
GameUtils::Score score = GameUtils::Score();
GameUtils::Racket racket_player1(10.0f + RACKET_WIDTH / 2,
                                 50.0f + RACKET_HEIGHT / 2 );
GameUtils::Racket racket_player2(
    (float)window_profile.WIDTH - RACKET_WIDTH / 2 - 10, 50.0f + RACKET_HEIGHT / 2);
GameUtils::Ball ball(window_profile.WIDTH/2, window_profile.HEIGHT/2);

/**
 * @brief Draws components onto display
 */
void draw();

/**
 * @brief Get keyboard input from user
 * 
 * @param Key 
 * @param x 
 * @param y 
 */
void keyboard(unsigned char Key, int x, int y);

/**
 * @brief Updates frame
 */
void update(int value);

/**
 * @brief Tell OpenGL that we want to draw 2D only
 */
void enable2D(int width, int height);

/**
 * @brief Draws text on screen
 * 
 * @param x 
 * @param y 
 * @param text 
 */
void drawText(float x, float y, std::string text);

int main(int argc, char** argv)
{
    // Initialize opengl (via glut)
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(window_profile.WIDTH, window_profile.HEIGHT);
    glutCreateWindow("My Pong");

    // Register callback function
    glutDisplayFunc(draw);
    glutTimerFunc(window_profile.INTERVAL, update, 0);
    
    // setup scene to 2d mode and set draw color to white
    enable2D(window_profile.WIDTH, window_profile.HEIGHT);
    glColor3f(1.0f, 1.0f, 1.0f);

    glutMainLoop();

    return 0;
}

void drawText(float x, float y, std::string text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void draw()
{
    // glClear has to be called at the beginning
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // todo
    // racket for p1
    racket_player1.drawRect();
    // racket for p2
    racket_player2.drawRect();
    // ball
    ball.draw();
    
    // draw score
    drawText(window_profile.WIDTH / 2 - 10, window_profile.HEIGHT - 15,
            GameUtils::int2str(score.get_score_player1()) + " : " +
            GameUtils::int2str(score.get_score_player2()));

    // swap buffers
    glutSwapBuffers();
}

void keyboard(unsigned char Key, int x, int y)
{
    switch(Key)
    {
        case 'w':
            racket_player1.move_racket(GameUtils::Racket::MoveMode::UP);
            break;
        case 's':
            racket_player1.move_racket(GameUtils::Racket::MoveMode::DOWN);
            break;
        case 'e':
            racket_player1.rotate_racket(GameUtils::Racket::RotateMode::CLOCKWISE);
            break;
        case 'q':
            racket_player1.rotate_racket(GameUtils::Racket::RotateMode::COUNTER_CLOCKWISE);
            break;
        case 'i':
            racket_player2.move_racket(GameUtils::Racket::MoveMode::UP);
            break;
        case 'k':
            racket_player2.move_racket(GameUtils::Racket::MoveMode::DOWN);
            break;
        case 'o':
            racket_player2.rotate_racket(GameUtils::Racket::RotateMode::CLOCKWISE);
            break;
        case 'u':
            racket_player2.rotate_racket(GameUtils::Racket::RotateMode::COUNTER_CLOCKWISE);
            break;
        default:
            std::cout << "Keypress: " << Key << std::endl;
    }
}

void update(int value)
{
    // Input handling
    glutKeyboardFunc(keyboard);

    // ball
    ball.updateBall(racket_player1, racket_player2, window_profile, score);

    // Call update() again in interval milliseconds
    glutTimerFunc(window_profile.INTERVAL, update, 0);

    // redisplay frame
    glutPostRedisplay();
}

void enable2D(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
