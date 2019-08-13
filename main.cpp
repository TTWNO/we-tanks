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
#include "box.hpp"

#define PI 3.1415926535

int main()
{
	std::vector<Bullet> bullets = {};
	std::vector<Box> boxes = {};
	sf::Texture bullet_texture;
	sf::Texture white_square_texture;
	bullet_texture.loadFromFile("bullet5.png");
	white_square_texture.loadFromFile("ws.jpg");
	
    float velocity = 8;
    
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    const sf::Vector2f size(50.f, 50.f);
    const sf::Vector2f gun_size(50.f, 10.f);
	const sf::Vector2f box_startpos(200.f, 200.f);
	const sf::Vector2f box_size(100.f, 100.f);
	const sf::Vector2f box2_startpos(400.f, 250.f);
	const sf::Vector2f box2_size(100.f, 100.f);
	
	Box box(box_startpos, box_size, white_square_texture, 1);
	Box box2(box2_startpos, box2_size, white_square_texture, 1);

	boxes.push_back(box);
	boxes.push_back(box2);

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
		// set variables for loop
        sf::Vector2i mp = sf::Mouse::getPosition(window);
		float ydiff = (float)mp.y - t1.gun.getPosition().y;
		float xdiff = (float)mp.x - t1.gun.getPosition().x;
	
        float gun_radeons = atan2((float)mp.y - t1.gun.getPosition().y,
                            (float)mp.x - t1.gun.getPosition().x);
		float gun_angle = gun_radeons * 180 / PI;
        t1.gun.setRotation(gun_angle);

		for (auto& b : bullets){
			sf::Sprite bs = *b.bullet;
			for (auto& bo : boxes){
				if (bo.collides_on_top(bs) || bo.collides_on_bottom(bs)){
					b.angle = -b.angle;
					b.update_velocity();
				} else if (bo.collides_on_left(bs) || bo.collides_on_right(bs)){
					b.angle = -b.angle;
					// reverses angle in radeons by adding pi
					b.angle += 3.141592;
					b.update_velocity();
				}
			}
			b.update();
		}

		// remove bullets when no ricoches are left
		bullets.erase(
			std::remove_if(
				bullets.begin(),
				bullets.end(),
				[](Bullet const& b){return b.ricoches_left <= 0;}
			),
			bullets.end()
		);

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
        // only activate inner if once per key press, not constantly.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            if (!enter_pressed){
                enter_pressed = true;
				bullets.push_back(Bullet(gun_radeons, t1.gun.getPosition(), bullet_texture, 2));
            }
        } else if (enter_pressed) {
            enter_pressed = false;
        }


        window.clear();
        window.draw(t1);
		for (Bullet b : bullets){
			window.draw(b);
		}
		for (Box b : boxes){
			window.draw(b);
		}
        window.display();
    }
    return 0;
}
