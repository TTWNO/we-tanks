#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include "tank.hpp"
#include "bullet.hpp"
#include "collision.cpp"

#define PI 3.1415926535

int main()
{
	std::vector<Bullet> bullets = {};
	sf::Texture bullet_texture;
	sf::Texture white_square_texture;
	bullet_texture.loadFromFile("bullet.png");
	white_square_texture.loadFromFile("ws.jpg");
	
    float velocity = 8;
    
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    const sf::Vector2f size(50.f, 50.f);
    const sf::Vector2f gun_size(50.f, 10.f);
	const sf::Vector2f midbox_size(100.f, 100.f);
    sf::RectangleShape shape(size);
    sf::RectangleShape gun_shape(gun_size);
	sf::Sprite midbox;
	midbox.setTexture(white_square_texture);
	midbox.setPosition(300, 300);
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
		// set variables for loop
        sf::Vector2i mp = sf::Mouse::getPosition(window);
		float ydiff = (float)mp.y - t1.gun.getPosition().y;
		float xdiff = (float)mp.x - t1.gun.getPosition().x;
	
        float gun_radeons = atan2((float)mp.y - t1.gun.getPosition().y,
                            (float)mp.x - t1.gun.getPosition().x);
		float gun_angle = gun_radeons * 180 / PI;
        t1.gun.setRotation(gun_angle);
		for (Bullet b : bullets){
			b.update();
			if (Collision::BoundingBoxTest(midbox, *b.bullet)){
				b.angle = -b.angle;
				b.update_velocity();
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
				bullets.push_back(Bullet(gun_radeons, t1.gun.getPosition(), bullet_texture));
            }
        } else if (enter_pressed) {
            enter_pressed = false;
        }


        window.clear();
        window.draw(t1);
		for (Bullet b : bullets){
			window.draw(b);
		}
		window.draw(midbox);
        window.display();
    }
    return 0;
}
