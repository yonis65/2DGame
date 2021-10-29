#include "AnimationManager.h"

void AnimationManager::AddAnimation(string name, string base_path, int frames_for_imgs, int total_imgs, bool loop) {
	Animation animation = Animation(base_path, frames_for_imgs, total_imgs, loop);
	animations_map.insert(pair<string, Animation>(name, animation));
}


void AnimationManager::SwitchAnimation(string name)
{
	currentAnimation = name;
	frame = 0;
	img = 0;
	playing = true;
}

void AnimationManager::Update(sf::Sprite& sprite)
{
	auto pos = animations_map.find(currentAnimation);
	if (pos == animations_map.end()) {
		Logger.Log("Can't find animation" + currentAnimation);
	}
	else {
		Animation animation = pos->second;
		if (playing) {
			if (frame == animation.frames_for_imgs) {
				texture.loadFromFile(animation.base_path + std::to_string(img) + ".png", sf::IntRect(0, 0, 363, 458));

				if (img >= animation.total_imgs - 1) {
					img = 0;
					if (!animation.loop) {
						playing = false;
					}
				}
				else {
					img++;
				}

				frame = 0;
			}

			frame++;
		}
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 363, 458));

}

void AnimationManager::Update(sf::Sprite& sprite, bool mirrored)
{
	sprite.setTexture(texture);

}

int AnimationManager::GetAnimationImages()
{
	auto pos = animations_map.find(currentAnimation);
	if (pos == animations_map.end()) {
		Logger.Log("Can't find animation" + currentAnimation);
		return -1;
	}
	else {
		Animation animation = pos->second;
		return animation.total_imgs;
	}
}


