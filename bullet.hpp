#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Bullet : public sf::Drawable {
public:
  float angle;
  sf::Sprite* bullet;
  sf::Vector2f* velocity;
  int ricoches_left;

  Bullet(float angle, const sf::Vector2f& position, sf::Texture& t, int richoches);
  void update();
  void update_velocity();
private:
  virtual void draw(sf::RenderTarget& rt, sf::RenderStates render_states) const;
};
#endif
