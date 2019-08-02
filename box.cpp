#include "box.hpp"
#include "collision.h"
#include <SFML/Graphics/Rect.hpp>

void Box::draw(sf::RenderTarget& rt, sf::RenderStates rss) const {
    rt.draw(*top_wall, rss);
    rt.draw(*left_wall, rss);
    rt.draw(*right_wall, rss);
    rt.draw(*bottom_wall, rss);
}

bool Box::collides_on_left(sf::Sprite& sp){
	return Collision::BoundingBoxTest(*left_wall, sp);
}
bool Box::collides_on_right(sf::Sprite& sp){
	return Collision::BoundingBoxTest(*right_wall, sp);
}
bool Box::collides_on_top(sf::Sprite& sp){
	return Collision::BoundingBoxTest(*top_wall, sp);
}
bool Box::collides_on_bottom(sf::Sprite& sp){
	return Collision::BoundingBoxTest(*bottom_wall, sp);
}

Box::Box(const sf::Vector2f& top_left, const sf::Vector2f& size, sf::Texture& texture, int thickness){

    sf::Rect<int> side_wall_sprite_split(0, 0, thickness, size.y);
    sf::Rect<int> top_wall_sprite_split(0, 0, size.x, thickness);

    left_wall = new sf::Sprite();
    left_wall->setTexture(texture);
    left_wall->setTextureRect(side_wall_sprite_split);
	left_wall->setPosition(top_left.x, top_left.y);
    right_wall = new sf::Sprite();
    right_wall->setTexture(texture);
    right_wall->setTextureRect(side_wall_sprite_split);
	right_wall->setPosition(top_left.x + size.x - thickness, top_left.y);
    top_wall = new sf::Sprite();
    top_wall->setTexture(texture);
    top_wall->setTextureRect(top_wall_sprite_split);
	top_wall->setPosition(top_left.x, top_left.y);
    bottom_wall = new sf::Sprite();
    bottom_wall->setTexture(texture);
    bottom_wall->setTextureRect(top_wall_sprite_split);
	bottom_wall->setPosition(top_left.x, top_left.y + size.y - thickness);
}
