#include "bullet.hpp"
#include <math.h>
#include <iostream>

void Bullet::draw(sf::RenderTarget& rt, sf::RenderStates render_states) const{
  rt.draw(*bullet, render_states);
}
void Bullet::update(){
  bullet->move(velocity->x, velocity->y);
}
void Bullet::update_velocity(){
	velocity->x = 10 * cos(angle);
	velocity->y = 10 * sin(angle);
	bullet->setRotation(angle * 180 / 3.14159265);
	//bullet->rotate(90);
	this->ricoches_left--;
}

Bullet::Bullet(float new_angle, const sf::Vector2f& starting_position, sf::Texture& texture, int ricoches){
	angle = new_angle;
	velocity = new sf::Vector2f(10 * cos(new_angle), 10 * sin(new_angle));

	ricoches_left = ricoches;	

	bullet = new sf::Sprite();
    bullet->setOrigin(1024 /4.f, 768/2.f);
	bullet->setTexture(texture);
	bullet->setPosition(starting_position);
	//bullet->setFillColor(sf::Color::Red);
	bullet->setRotation(angle * 180 / 3.1415926);
	//bullet->rotate(90);
	bullet->scale(sf::Vector2f(0.025f, 0.025f));
}
