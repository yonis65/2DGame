#include "Player.h"
#include <iostream>

using namespace std;

void Player::AnimationCallback(EventType event, string animation) {
	switch (event)
	{
	case EventType::ANIMATION_FINISH:
		if (animation == "Dead") {
			animManager.SwitchAnimation("Run");
		}
		break;
	}
}

Player::Player(sf::Vector2f initial_pos){
	dir = 0;
	sprite.setScale(sf::Vector2f(0.3f, 0.3f));
	auto callback = bind(&Player::AnimationCallback, this, std::placeholders::_1, std::placeholders::_2);
	animManager.SetCallBack(callback);
	animManager.AddAnimation("Run", "src/Run_", 3, 10);
	animManager.AddAnimation("Dead", "src/Dead_", 3, 10, false);
	animManager.SwitchAnimation("Run");
}

void Player::Update() {
	if (dir == 1) {
		animManager.Update(sprite, true);
	}
	else{
		animManager.Update(sprite, false);
	}
}

void Player::Right() {
	sprite.move(vel, 0.f);
	dir = 0;
}

void Player::Left() {
	sprite.move(-vel, 0.f);
	dir = 1;
}
