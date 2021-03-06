#include "Debug/ImGui/Gui.hpp"
#include "Core/Player.h"

#include <iostream>

#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>


using namespace std;


int main()
{
    Player player = Player();
    //sf::RenderWindow window(sf::VideoMode(600, 500), "GAME");
    sf::RenderWindow window(sf::VideoMode(600, 500), "GAME", sf::Style::Fullscreen);

    ImGui::SFML::Init(window);

	SetImGuiStyle();

    window.setFramerateLimit(60);

    sf::Clock deltaClock;
    while (window.isOpen()){
        player.Update();
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
                    if (event.key.code == sf::Keyboard::Space) {
                        player.Jump();
                    }
                    break;
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());


        //ImGui GUI
        GuiWindow.Draw(&player);

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