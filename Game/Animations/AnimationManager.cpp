#include "AnimationManager.h"

void AnimationManager::AddAnimation(string name, string base_path, int frames_for_imgs, int total_imgs, bool loop) {
	Animation animation = Animation(base_path, frames_for_imgs, total_imgs, loop);
	animations_map.insert(pair<string, Animation>(name, animation));
	if (callback) {
		callback(EventType::ANIMATION_ADD, name);
	}
}

void AnimationManager::SetCallBack(function<void(EventType, string)> fn) {
	callback = std::bind(fn, std::placeholders::_1, std::placeholders::_2);
}

void AnimationManager::SwitchAnimation(string name)
{
	currentAnimation = name;
	frame = 0;
	img = 0;
	playing = true;


	Animation animation = GetAnimationFromName(name);
	current_base_path = animation.base_path;
	current_frames_for_imgs = animation.frames_for_imgs;
	current_total_imgs = animation.total_imgs;
	current_loop = animation.loop;

	if (callback) {
		callback(EventType::ANIMATION_CHANGE, name);
	}
}

Animation AnimationManager::GetAnimationFromName(string name) {
	auto pos = animations_map.find(currentAnimation);
	if (pos == animations_map.end()) {
		Logger.Log("Can't find animation" + currentAnimation);
		return Animation("", 0, 0, false);
	}
	else {
		return pos->second;
	}
}

void AnimationManager::Update(sf::Sprite& sprite, bool mirror)
{
	if (playing) {
		if (frame == current_frames_for_imgs) {
			texture.loadFromFile(current_base_path + std::to_string(img) + ".png", sf::IntRect(0, 0, 363, 458));

			if (img >= current_total_imgs - 1) {
				img = 0;
				if (!current_loop) {
					playing = false;
					if (callback) {
						callback(EventType::ANIMATION_FINISH, currentAnimation);
					}
				}
			}
			else {
				img++;
			}

			frame = 0;
		}

		frame++;
	}
	sprite.setTexture(texture);
	if (mirror) {
		sprite.setTextureRect(sf::IntRect(363, 0, -363, 458));
	}
	else {
		sprite.setTextureRect(sf::IntRect(0, 0, 363, 458));
	}

}

int AnimationManager::GetAnimationImages()
{
	return current_total_imgs;
}


