#include "bullet.hpp"
#include <math.h>
#include <iostream>

void Bullet::draw(sf::RenderTarget& rt, sf::RenderStates render_states) const{
  rt.draw(*bullet, render_states);
}
void Bullet::update(){
  bullet->move(velocity.x, velocity.y);
}

Bullet::Bullet(float angle, const sf::Vector2f& starting_position){
	velocity = sf::Vector2f(10 * cos(angle), 10 * sin(angle));
	bullet = new sf::RectangleShape(sf::Vector2f(10.f, 3.f));	
	bullet->setPosition(starting_position);
	bullet->setFillColor(sf::Color::Red);
	bullet->setRotation(angle * 180 / 3.1415926);
}
