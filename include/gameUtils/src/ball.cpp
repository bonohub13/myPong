#include "../include/ball.hpp"

#include <cmath>
#include "GL/gl.h"

GameUtils::Ball::Ball(int init_pos_x, int init_pos_y)
    : ball_pos_x(init_pos_x), ball_pos_y(init_pos_y),
      ball_dir_x(-0.1f), ball_dir_y(0.0f), ball_radius(15),
      ball_speed(10)
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

void GameUtils::Ball::updateBall(Racket &racket1, Racket &racket2,
                                 WindowProfile &window_profile, Score &score)
{
    u_short ball_hit_racket;
    // angle is set angle 0.5 if ball hits top of racket
    // 0 if ball hits the sides of racket
    // -0.5 if ball hits the bottom of racket
    float angle = 0;

    // ball movement
    ball_pos_x += ball_dir_x * ball_speed;
    ball_pos_y += ball_dir_y * ball_speed;

    // ball hit detection for racket1 and racket2
    // 0 -> did not hit any racket
    // 1 -> hit racket1
    // 2 -> hit racket2
    ball_hit_racket = (ball_pos_x - 15.0f < racket1.get_points_x()[1]
                       && racket1.get_points_x()[0] < ball_pos_x + 15.0f
                       && ball_pos_y + 15.0f > racket1.get_points_y()[3]
                       && racket1.get_points_y()[0] > ball_pos_y - 15.0f) ? 1
                    : (ball_pos_x + 15.0f > racket2.get_points_x()[1]
                       && racket2.get_points_x()[0] > ball_pos_x - 15.0f
                       && ball_pos_y + 15.0f > racket2.get_points_y()[3]
                       && racket2.get_points_y()[0] > ball_pos_y) ? 2
                    : 0;

    // check for hit detection with racket
    switch (ball_hit_racket)
    {
        case 1:
            angle = ((ball_pos_y - racket1.get_points_y()[3]) / racket1.get_racket_height()) - 0.5f;
            ball_dir_x = fabs(ball_dir_x); // force it to be negative
            ball_dir_y = angle;
            break;

        case 2:
            angle = ((ball_pos_y - racket2.get_points_y()[3]) / racket2.get_racket_height()) - 0.5f;
            ball_dir_x = -fabs(ball_dir_x); // force it to be negative
            ball_dir_y = angle;
            break;

        case 0:
            break;
        
        default:
            break;
    }
    
    if (ball_pos_x < 15)
    {
        score.set_score_player1(score.get_score_player1() + 1);
        ball_pos_x = window_profile.WIDTH / 2;
        ball_pos_y = window_profile.HEIGHT / 2;
        ball_dir_x = -fabs(ball_dir_x);
        ball_dir_y = 0;
    }
    else if (window_profile.WIDTH - 15 < ball_pos_x)
    {
        score.set_score_player2(score.get_score_player2() + 1);
        ball_pos_x = window_profile.WIDTH / 2;
        ball_pos_y = window_profile.HEIGHT / 2;
        ball_dir_x = -fabs(ball_dir_x);
        ball_dir_y = 0;
    }

    if (ball_pos_y - 15.0f < 0)
    {
        ball_dir_y = fabs(ball_dir_y);
    }
    else if (window_profile.HEIGHT < ball_pos_y + 15.0f)
    {
        ball_dir_y = -fabs(ball_dir_y);
    }

    vec2_norm(ball_dir_x, ball_dir_y);
}

void GameUtils::Ball::vec2_norm(float &x, float &y)
{
    float length = sqrt((x * x) + (y * y));

    if (length != 0.0f)
    {
        length = 1.0f / length;

        x *= length;
        y *= length;
    }
}