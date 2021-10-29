#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../ImGui/Gui.hpp"


using namespace std;


struct Animation {
	string base_path;
	int frames_for_imgs;
	int total_imgs;
	bool loop;

	Animation(string base_path, int frames_for_imgs, int total_imgs, bool loop) {
		Animation::base_path = base_path;
		Animation::frames_for_imgs = frames_for_imgs;
		Animation::total_imgs = total_imgs;
		Animation::loop = loop;
	}
};

class AnimationManager
{
public:
	void AddAnimation(string name, string base_path, int frames_for_imgs, int total_imgs, bool loop = true);
	void SwitchAnimation(string name);
	void Update(sf::Sprite& sprite);
	void Update(sf::Sprite& sprite, bool mirrored);

	int GetAnimationImages();
	int GetFrame() { return frame; };
	int GetImg() { return img; };
	string GetCurrentAnimation() { return currentAnimation; };

	sf::Texture texture;

private:
	map<string, Animation> animations_map;
	string currentAnimation;
	int frame = 0;
	int img = 0;
	bool playing = true;
};