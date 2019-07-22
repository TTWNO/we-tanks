#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen()){
	sf::Vector2u size = window.getSize();
	shape.setPosition((float)size.x/2, (float)size.y/2);
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
    	    }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
