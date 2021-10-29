#include "Animation.h"

Animation::Animation(string base_path, int frames_for_imgs, int total_imgs){
	Animation::base_path = base_path;
	Animation::frames_for_imgs = frames_for_imgs;
	Animation::total_imgs = total_imgs;
	cout << "init";
}



void Animation::Update(sf::Sprite& sprite){
	LoadTexture();
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 363, 458));
}

sf::Texture Animation::GetTexture() {
	LoadTexture();
	return texture;
}

void Animation::Update(sf::Sprite& sprite, bool mirrored){
	cout << "Update";
	LoadTexture();
	sprite.setTexture(texture);
	if (mirrored){
		sprite.setTextureRect(sf::IntRect(363, 0, -363, 458));
	}
	else{
		sprite.setTextureRect(sf::IntRect(0, 0, 363, 458));
	}
}

void Animation::LoadTexture(){
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

