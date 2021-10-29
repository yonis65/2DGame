#include "AnimationManager.h"
#include <iostream>

AnimationManager::AnimationManager(){}

void AnimationManager::AddAnimations(string name, Animation* animation){
	animations.push_back(animation);
	int index = int(animations.size())-1;
	if (index == 0) {
		currentAnimation = index;
	}
	animations_map.insert(pair<string, int>(name, index));
}

void AnimationManager::AddAnimations(string name, string base_path, int frames_for_imgs, int total_imgs) {
	Animation* animation = new Animation(base_path, frames_for_imgs, total_imgs);
	animations.push_back(animation);
	int index = int(animations.size()) - 1;
	animations_map.insert(pair<string, int>(name, index));
}


void AnimationManager::SwitchAnimation(string name)
{
	auto pos = animations_map.find(name);
	if (pos == animations_map.end()) {
		//Logger.Log("Can't find animation");
	}
	else {
		int value = pos->second;
		currentAnimation = value;
	}
}

void AnimationManager::Update(sf::Sprite& sprite)
{
	if (frame == frames_for_imgs) {
		texture.loadFromFile(base_path + std::to_string(img) + ".png", sf::IntRect(0, 0, 363, 458));

		if (img >= total_imgs - 1) {
			img = 0;
		}
		else {
			img++;
		}

		frame = 0;
	}

	frame++;
}

void AnimationManager::Update(sf::Sprite& sprite, bool mirrored)
{
	cout << "test";
}


