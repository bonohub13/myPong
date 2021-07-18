#include "../include/racket.hpp"
#include <cmath>
#include "GL/gl.h"

GameUtils::Racket::Racket(float pos_x, float pos_y)
    : racket_width(10), racket_height(80), racket_speed(30),
      racket_x(pos_x), racket_y(pos_y)
{
    racket_rotation = atan2(racket_height, racket_width);
    radius = sqrt(((racket_width / 2) * (racket_width / 2))
            + ((racket_height / 2) * (racket_height / 2)));
    // top left
    point_x[0] = radius * cos(M_PI - racket_rotation) + racket_x;
    point_y[0] = radius * sin(M_PI - racket_rotation) + racket_y;

    // top right
    point_x[1] = radius * cos(racket_rotation) + racket_x;
    point_y[1] = radius * sin(racket_rotation) + racket_y;

    // bottom right
    point_x[2] = radius * cos(-racket_rotation) + racket_x;
    point_y[2] = radius * sin(-racket_rotation) + racket_y;

    // bottom left
    point_x[3] = radius * cos(M_PI + racket_rotation) + racket_x;
    point_y[3] = radius * sin(M_PI + racket_rotation) + racket_y;

    // set the initial state of racket to 90 degrees
    racket_rotation = M_PI / 2;
}

GameUtils::Racket::Racket(int racket_width, int racket_height, int racket_speed,
                          float pos_x, float pos_y)
    : racket_width(racket_width), racket_height(racket_height), racket_speed(racket_speed),
      racket_rotation(0), racket_x(pos_x), racket_y(pos_y)
{}

GameUtils::Racket::~Racket()
{}

void GameUtils::Racket::drawRect()
{
    glBegin(GL_QUADS);
        for (uint i = 0; i < 4; i++)
        {
            glVertex2f(point_x[i], point_y[i]);
        }
    glEnd();
}

void GameUtils::Racket::rotate_racket(RotateMode rotation)
{
    float points_tmp_x[2];
    float points_tmp_y[2];

    if (rotation == 0)
    {
        if (racket_rotation - (5 * M_PI / 180) >= 0 && racket_rotation - (5 * M_PI / 180) <= M_PI)
        {
            racket_rotation -= 5 * M_PI / 180;
        }
    } else {
        if (racket_rotation + (5 * M_PI / 180) >= 0 && racket_rotation + (5 * M_PI / 180) <= M_PI)
        {
            racket_rotation += 5 * M_PI / 180;
        }
    }

    // temporary location calculation (pos_0, pos_1)
    points_tmp_x[0] = (racket_height / 2) * cos(racket_rotation) + racket_x;
    points_tmp_x[1] = (racket_height / 2) * cos(racket_rotation + M_PI) + racket_x;
    points_tmp_y[0] = (racket_height / 2) * sin(racket_rotation) + racket_y;
    points_tmp_y[1] = (racket_height / 2) * sin(racket_rotation + M_PI) + racket_y;
    
    // top left
    point_x[0] = (racket_width / 2) * cos(racket_rotation + M_PI / 2) + points_tmp_x[0];
    point_y[0] = (racket_width / 2) * sin(racket_rotation + M_PI / 2) + points_tmp_y[0];

    // top right
    point_x[1] = (racket_width / 2) * cos(racket_rotation - M_PI / 2) + points_tmp_x[0];
    point_y[1] = (racket_width / 2) * sin(racket_rotation - M_PI / 2) + points_tmp_y[0];

    // bottom right
    point_x[2] = (racket_width / 2) * cos(racket_rotation - M_PI / 2) + points_tmp_x[1];
    point_y[2] = (racket_width / 2) * sin(racket_rotation - M_PI / 2) + points_tmp_y[1];

    // bottom left
    point_x[3] = (racket_width / 2) * cos(racket_rotation + M_PI / 2) + points_tmp_x[1];
    point_y[3] = (racket_width / 2) * sin(racket_rotation + M_PI / 2) + points_tmp_y[1];
}

void GameUtils::Racket::move_racket(MoveMode move)
{
    if (move == MoveMode::UP)
    {
        for (uint i = 0; i < 4; i++)
        {
            point_y[i] += racket_speed;
        }
        racket_y += racket_speed;
    }
    else if (move == MoveMode::DOWN)
    {
        for (uint i = 0; i < 4; i++)
        {
            point_y[i] -= racket_speed;
        }
        racket_y -= racket_speed;
    }
    else if (move == MoveMode::RIGHT)
    {
        for (uint i = 0; i < 4; i++)
        {
            point_x[i] += racket_speed;
        }
        racket_x += racket_speed;
    } else {
        for (uint i = 0; i < 4; i++)
        {
            point_x[i] -= racket_speed;
        }
        racket_x -= racket_speed;
    }
}

void GameUtils::Racket::set_racket_x(float racket_x)
{
    this->racket_x = racket_x;
}

void GameUtils::Racket::set_racket_x(float &racket_x)
{
    this->racket_x = racket_x;
}

void GameUtils::Racket::set_racket_y(float racket_y)
{
    this->racket_y = racket_y;
}

void GameUtils::Racket::set_racket_y(float &racket_y)
{
    this->racket_y = racket_y;
}

int GameUtils::Racket::get_racket_speed()
{
    return racket_speed;
}

int GameUtils::Racket::get_racket_width()
{
    return racket_width;
}

int GameUtils::Racket::get_racket_height()
{
    return racket_height;
}

float GameUtils::Racket::get_racket_rotation()
{
    return racket_rotation;
}

float* GameUtils::Racket::get_points_x()
{
    return point_x;
}

float* GameUtils::Racket::get_points_y()
{
    return point_y;
}