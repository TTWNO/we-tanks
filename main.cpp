#include <iostream>
#include <stdio.h>
#include <math.h>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include "tank.hpp"

#define PI 3.14159265

int main()
{
    float velocity = 8;
    
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    const sf::Vector2f size(50.f, 50.f);
    const sf::Vector2f gun_size(50.f, 10.f);
    sf::RectangleShape shape(size);
    sf::RectangleShape gun_shape(gun_size);

    bool enter_pressed = false;

    gun_shape.setFillColor(sf::Color::Cyan);
    shape.setFillColor(sf::Color::Blue);
    gun_shape.setPosition(25.f, 25.f);
    gun_shape.setOrigin(0.f, 5.0f);

    Tank t1(shape, gun_shape);

    while (window.isOpen()){
        sf::Vector2u size = window.getSize();
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        // Keyboard events
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            t1.move(velocity, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            t1.move(-velocity, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            t1.move(0, -velocity);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            t1.move(0, velocity);
        }
        // only activate 2nd if {}s once per key press, not constantly.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            if (!enter_pressed){
                enter_pressed = true;
                std::cout << "Bullet!" << std::endl;
            }
        } else if (enter_pressed) {
            enter_pressed = false;
        }

        sf::Vector2i mp = sf::Mouse::getPosition(window);
        float diff3 = atan2((float)mp.y - t1.gun.getPosition().y,
                            (float)mp.x - t1.gun.getPosition().x) * 180 / PI;
        t1.gun.setRotation(diff3);

        window.clear();
        window.draw(t1);
        window.display();
    }
    return 0;
}
