#pragma once
#include <SFML/Graphics.hpp>
#include "ImGui/Gui.hpp"
#include "Animations/AnimationManager.h"

class Player{
public:
    Player(sf::Vector2f initial_pos);
    
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;

    AnimationManager animManager = AnimationManager();

    void Up();
    void Down();
    void Left();
    void Right();
    void AnimationCallback(EventType event, string animation);

    void Stop();

    void UpdateAnimation();
    float vel = 7;

private:

    int dir = 0;

};

