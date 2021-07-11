#include "../include/racket.hpp"
#include "GL/gl.h"

GameUtils::Racket::Racket(float pos_x, float pos_y)
    : racket_width(10), racket_height(80), racket_speed(30),
      racket_x(pos_x), racket_y(pos_y)
{}

GameUtils::Racket::Racket(int racket_width, int racket_height, int racket_speed,
                          float pos_x, float pos_y)
    : racket_width(racket_width), racket_height(racket_height), racket_speed(racket_speed),
      racket_x(pos_x), racket_y(pos_y)
{}

GameUtils::Racket::~Racket()
{}

void GameUtils::Racket::drawRect()
{
    glBegin(GL_QUADS);
        glVertex2f(racket_x, racket_y);
        glVertex2f(racket_x + racket_width, racket_y);
        glVertex2f(racket_x + racket_width,
                   racket_y + racket_height);
        glVertex2f(racket_x, racket_y + racket_height);
    glEnd();
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

float GameUtils::Racket::get_racket_x()
{
    return racket_x;
}

float GameUtils::Racket::get_racket_y()
{
    return racket_y;
}