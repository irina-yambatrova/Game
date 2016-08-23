#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
const int ground = 420;


class Player
{
private: float x, y;
public:
	float w, h, dx, dy, speed;
	int dir, playerScore;//новая переменная, хранящая очки игрока
	bool onGround;
	Sprite sprite;
	FloatRect rect;
	float currentFrame;

	Player(Texture &image) {
		dx = dy = 0.01;
		playerScore = 0;
		rect = FloatRect(0, 0, 40, 60);
		sprite.setTexture(image);
		currentFrame = 0;
	}
	void Player::Control();
	void Player::Update(float time);
	float getplayercoordinateX()
	{
		return x;
	}
	float getplayercoordinateY()
	{
		return y;
	}

};