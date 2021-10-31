#pragma once
#include <SFML/Graphics.hpp>
#include "ImGui/Gui.hpp"
#include "Animations/AnimationManager.h"

class Player{
public:
    Player();
    
    sf::Sprite sprite;
    sf::Texture texture;

    AnimationManager animManager = AnimationManager();

    void Left();
    void Right();
    void AnimationCallback(EventType event, string animation);

    void Update();
    void Jump();
    float vel = 7;

private:
    int dir = 0;
    float gravity = 0;
};

