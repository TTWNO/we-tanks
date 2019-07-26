#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Bullet : public sf::Drawable {
public:
  sf::RectangleShape* bullet;
  sf::Vector2f velocity;

  Bullet(float angle, const sf::Vector2f& position);
  void update();
private:
  virtual void draw(sf::RenderTarget& rt, sf::RenderStates render_states) const;
};
#endif
