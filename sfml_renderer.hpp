#ifndef SFML_RENDERER_HPP
#define SFML_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include "playboard.hpp"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

class SFMLRenderer {

public:
    SFMLRenderer();
    ~SFMLRenderer();

    void waitForExit();
    
    sf::RenderWindow& getWindow() {return *window;};

    void drawPlayboard(Playboard &playboard);
    void drawCell(Cell &cell);

    
private:
     sf::RenderWindow* window;
};

void inputHandler(sf::Event event, sf::RenderWindow &window);

#endif // SFML_RENDERER_HPP

