#include "tank.hpp"


Tank::Tank(sf::RectangleShape& start_tank, sf::RectangleShape& start_gun){
	tank = start_tank;
	gun = start_gun;
}
void Tank::draw(sf::RenderTarget& rt, sf::RenderStates render_states) const{
	rt.draw(tank);
	rt.draw(gun);
}
void Tank::move(float by_x, float by_y){
	tank.move(by_x, by_y);
	gun.move(by_x, by_y); 
}
