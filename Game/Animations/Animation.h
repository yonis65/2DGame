#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Animation{
public:

	Animation(string base_path, int frames_for_imgs, int total_imgs);

	void Update(sf::Sprite &sprite);

	sf::Texture GetTexture();

	void Update(sf::Sprite& sprite, bool mirrored);

	int frames_for_imgs;
	string base_path;
	int total_imgs;
	sf::Texture texture;

private:
	void LoadTexture();

	int img;
	int frame;
};

