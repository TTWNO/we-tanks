#include <stdio.h>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    float velocity = 8;
    
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    window.setVerticalSyncEnabled(true);
    const sf::Vector2f size(100.f, 100.f);
    sf::RectangleShape shape(size);
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = shape.getPosition();
    line[0].color = sf::Color::Cyan;
    sf::Vector2i mouse_pos = sf::Mouse::getPosition();
    line[1].position = sf::Vector2f((float)mouse_pos.x, (float)mouse_pos.y);
    line[1].color = sf::Color::Cyan;
    shape.setFillColor(sf::Color::Red);

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
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            shape.move(-velocity, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            shape.move(0, -velocity);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            shape.move(0, velocity);
        }

        auto sp = shape.getPosition();
        line[0].position = sf::Vector2f(sp.x + (shape.getSize().x/2), sp.y + (shape.getSize().y/2));
        mouse_pos = sf::Mouse::getPosition(window);
        line[1].position = sf::Vector2f((float)mouse_pos.x, (float)mouse_pos.y);

        window.clear();
        window.draw(shape);
        window.draw(line);
        window.display();
    }

    return 0;
}
