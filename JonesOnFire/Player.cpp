#include "Player.h"

void Player::Control()
{

}

void Player::Update(float time)
{
	rect.left += dx * time;
	if (!onGround) dy = dy + 0.0005 * time;
	rect.top += dy * time;
	onGround = false;
	if (rect.top > ground)
	{
		rect.top = ground;
		dy = 0;
		onGround = true;
	}
	currentFrame += 0.1 * time;
	if (currentFrame > 2) currentFrame -= 2;
	if (dx > 0)
	{
		sprite.setTextureRect(IntRect(100, 100 * int(currentFrame), 100, 100));
	}
	if (dx < 0)
	{
		sprite.setTextureRect(IntRect(0, 100 * int(currentFrame), 100, 100));
	}
	sprite.setPosition(rect.left, rect.top);
}
