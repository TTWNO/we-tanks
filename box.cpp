#include "box.hpp"
#include <SFML/Graphics/Rect.hpp>

Box::Box(sf::Vector2f& top_left, sf::Vector2f& size, sf::Texture& texture, int thickness){

    sf::Rect<int> side_wall_sprite_split(0, 0, size.x, thickness);
    sf::Rect<int> top_wall_sprite_split(0, 0, thickness, size.y);

    left_wall = new sf::Sprite();
    left_wall->setTexture(texture);
    left_wall->setTextureRect(side_wall_sprite_split);
    right_wall = new sf::Sprite();
    right_wall->setTexture(texture);
    right_wall->setTextureRect(side_wall_sprite_split);
    top_wall = new sf::Sprite();
    top_wall->setTexture(texture);
    top_wall->setTextureRect(top_wall_sprite_split);
    bottom_wall = new sf::Sprite();
    bottom_wall->setTexture(texture);
    bottom_wall->setTextureRect(top_wall_sprite_split);
}

void Box::draw(sf::RenderTarget& rt, sf::RenderStates& rss) const {
    rt.draw(*top_wall);
    rt.draw(*left_wall);
    rt.draw(*right_wall);
    rt.draw(*bottom_wall);
}
