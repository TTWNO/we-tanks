#ifndef TANK_H
#define TANK_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Tank : public sf::Drawable {
    public:
    sf::RectangleShape tank;
    sf::RectangleShape gun;
    
    Tank(sf::RectangleShape& new_tank, sf::RectangleShape& new_gun);
    void move(float by_x, float by_y);
    
    private:
    virtual void draw(sf::RenderTarget &rt, sf::RenderStates render_states) const;
};
#endif
