#ifndef SFML_RENDERER_HPP
#define SFML_RENDERER_HPP

#include <SFML/Graphics.hpp>

#include "playboard.hpp"

class SFMLRenderer {

public:
    SFMLRenderer();
    ~SFMLRenderer();

    void waitForExit();
    
    sf::RenderWindow& getWindow() {return *window;};

    void drawPlayboard( Playboard &playboard);

    
private:
     sf::RenderWindow* window;
};

void inputHandler(sf::Event event, sf::RenderWindow &window);

#endif // SFML_RENDERER_HPP

