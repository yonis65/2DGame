#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(sf::Vector2f initial_pos){
	dir = 0;
	sprite.setScale(sf::Vector2f(0.3f, 0.3f));
	animManager.AddAnimation("Run", "src/Run_", 3, 10);
	animManager.AddAnimation("Dead", "src/Dead_", 3, 10, false);
	animManager.SwitchAnimation("Run");
}

void Player::UpdateAnimation() {
	//if (dir == 1) {
	//	animManager.Update(sprite, true);
	//}
	//else{
	//	animManager.Update(sprite, false);
	//}
	animManager.Update(sprite);
}

void Player::Stop() {
}

void Player::Up(){
	sprite.move(0.f, -vel);
}

void Player::Down() {
	sprite.move(0.f, vel);
}

void Player::Right() {
	sprite.move(vel, 0.f);
	dir = 0;
}

void Player::Left() {
	sprite.move(-vel, 0.f);
	dir = 1;
}
