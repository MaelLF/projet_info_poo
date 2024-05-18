#ifndef SFML_RENDERER_HPP
#define SFML_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include "playboard.hpp"
#include "obstaclecell.hpp"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800
#define CELL_SIZE 50

class SFMLRenderer {

public:
    SFMLRenderer();
    ~SFMLRenderer();

    void waitForExit();
    
    sf::RenderWindow& getWindow() {return *window;};
    sf::Text& getText(){return txt;};

    void drawPlayboard(Playboard &playboard);
     
    sf::Sprite sprite_Screen, sprite_Back, sprite_Back2L, sprite_Back2R, sprite_WPawn, sprite_WKnight, sprite_WBishop, sprite_WRook, sprite_WQueen, sprite_WKing;

    
private:
     sf::RenderWindow* window;
     sf::Font font;
     sf::Text txt;
     sf::Texture texture_Screen, texture_Back, texture_Back2, texture_WPawn, texture_WKnight, texture_WBishop, texture_WRook, texture_WQueen, texture_WKing;
};

void inputHandler(sf::Event event, SFMLRenderer &renderer, Playboard &playboard);
void handleMouseClick(sf::Vector2i mousePosition, SFMLRenderer &renderer, Playboard &playboard);
void setText(sf::Text &text, const sf::String &string);

#endif // SFML_RENDERER_HPP

