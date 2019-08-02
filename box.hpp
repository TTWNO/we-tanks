#ifndef BOX_H
#define BOX_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Box : public sf::Drawable {
 public:
  sf::Vector2f* pos;
  sf::Vector2f* size;
  sf::Sprite* left_wall;
  sf::Sprite* right_wall;
  sf::Sprite* top_wall;
  sf::Sprite* bottom_wall;
  int thickness;

  bool collides_on_left(sf::Sprite& sp);
  bool collides_on_top(sf::Sprite& sp);
  bool collides_on_right(sf::Sprite& sp);
  bool collides_on_bottom(sf::Sprite& sp);

  Box(const sf::Vector2f& pos, const sf::Vector2f& size, sf::Texture& texture, int thickness);
 private:
  virtual void draw(sf::RenderTarget& rt, sf::RenderStates rss) const;
};

#endif
