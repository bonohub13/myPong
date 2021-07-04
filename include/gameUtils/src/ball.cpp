#include "../include/ball.hpp"

#include <cmath>
#include "GL/gl.h"

GameUtils::Ball::Ball(int init_pos_x, int init_pos_y)
    : ball_pos_x(init_pos_x), ball_pos_y(init_pos_y),
      ball_dir_x(-0.1f), ball_dir_y(0.0f), ball_radius(15),
      ball_speed(50)
{}

GameUtils::Ball::~Ball()
{}

void GameUtils::Ball::draw()
{
    float rad = 0;

    glBegin(GL_POLYGON);
    for (uint i = 0; i < 72; i++)
    {
        rad = i * M_PI / 36;
        glVertex2f((GLfloat)(ball_pos_x + ball_radius * cos(rad)),
                   (GLfloat)(ball_pos_y + ball_radius * sin(rad)));
    }
    glEnd();
}

void GameUtils::Ball::updateBall()
{
    ball_pos_x += ball_dir_x * ball_speed;
    ball_pos_y += ball_dir_y * ball_speed;
}