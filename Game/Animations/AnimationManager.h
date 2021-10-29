#pragma once
#include <vector>

using namespace std;

//#include "../ImGui/Gui.hpp"
//#include "Animation.h"

struct Animation {
	string base_path;
	int frames_for_imgs;
	int total_imgs;
};

class AnimationManager
{
public:
	AnimationManager();
	void AddAnimations(string name, Animation* animation);
	void AddAnimations(string name, string base_path, int frames_for_imgs, int total_imgs);
	void SwitchAnimation(string name);
	void Update(sf::Sprite& sprite);
	void Update(sf::Sprite& sprite, bool mirrored);

	sf::Texture texture;

private:
	//map<string, int> animations_map;
	//vector<Animation*> animations;
	int currentAnimation;
	int frame = 0;
	int frames_for_imgs = 0;

};