#include <iostream>

#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>


#include "ImGui/Gui.hpp"
#include "Player.h"

using namespace std;

int main()
{
    Player player = Player(sf::Vector2f(300, 250));

    //sf::RenderWindow window(sf::VideoMode(600, 500), "GAME");
    sf::RenderWindow window(sf::VideoMode(600, 500), "GAME", sf::Style::Fullscreen);

    ImGui::SFML::Init(window);

	SetImGuiStyle();

    window.setFramerateLimit(10);

    sf::Clock deltaClock;
    while (window.isOpen()){
        player.UpdateAnimation();
        sf::Event event;
        while (window.pollEvent(event)){
            ImGui::SFML::ProcessEvent(event);
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    if (event.key.code == sf::Keyboard::P) {
                        player.animManager.SwitchAnimation("Dead");
                    }
                    break;
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());


        //ImGui GUI
        GuiWindow.Draw(&player);
        //GuiWindow.Log("TEST");

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            player.Up();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            player.Down();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.Left();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.Right();
        }

        window.clear();
        window.draw(player.sprite);

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}