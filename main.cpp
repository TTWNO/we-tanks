#include <iostream>
#include <stdio.h>
#include <math.h>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

#define PI 3.14159265

int main()
{
    float velocity = 8;
    
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    window.setVerticalSyncEnabled(true);
    const sf::Vector2f size(100.f, 100.f);
    const sf::Vector2f gun_size(75.f, 25.f);
    sf::RectangleShape shape(size);
    sf::RectangleShape gun_shape(gun_size);

    shape.setFillColor(sf::Color::Blue);
    shape.setFillColor(sf::Color::Red);
    gun_shape.setPosition(50.f, 50.f);
    gun_shape.setOrigin(0.f, 12.5f);

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
            shape.move(velocity, 0);
            gun_shape.move(velocity, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            shape.move(-velocity, 0);
            gun_shape.move(-velocity, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            shape.move(0, -velocity);
            gun_shape.move(0, -velocity);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            shape.move(0, velocity);
            gun_shape.move(0, velocity);
        }

        sf::Vector2i mp = sf::Mouse::getPosition(window);
        float diff3 = atan2((float)mp.y - gun_shape.getPosition().y,
                            (float)mp.x - gun_shape.getPosition().x) * 180 / PI;
        gun_shape.setRotation(diff3);

        window.clear();
        window.draw(shape);
        window.draw(gun_shape);
        window.display();
    }

    return 0;
}
