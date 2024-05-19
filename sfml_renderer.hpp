#ifndef SFML_RENDERER_HPP
#define SFML_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include "playboard.hpp"
#include "pion.hpp"
#include "cavalier.hpp"
#include "fou.hpp"
#include "tour.hpp"
#include "reine.hpp"

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
    void drawPion(Pion &pion, int j);
    void drawFou(Fou &fou, int j);
    void drawCavalier(Cavalier &cavalier, int j);
    void drawTour(Tour &tour, int j);
    void drawReine(Reine &reine, int j);
     
    sf::Sprite sprite_Screen, sprite_Back, sprite_Back2L, sprite_Back2R, sprite_WPawn, sprite_WKnight, sprite_WBishop, sprite_WRook, sprite_WQueen, sprite_WKing, sprite_Pawn, sprite_Knight, sprite_Bishop, sprite_Rook, sprite_Queen, sprite_BPawn, sprite_BKnight, sprite_BBishop, sprite_BRook, sprite_BQueen;

    
private:
     sf::RenderWindow* window;
     sf::Font font;
     sf::Text txt;
     sf::Texture texture_Screen, texture_Back, texture_Back2, texture_WPawn, texture_WKnight, texture_WBishop, texture_WRook, texture_WQueen, texture_WKing, texture_Pawn, texture_Knight, texture_Bishop, texture_Rook, texture_Queen, texture_BPawn, texture_BKnight, texture_BBishop, texture_BRook, texture_BQueen;
};

void inputHandler(sf::Event event, SFMLRenderer &renderer, Playboard &playboard);
void handleMouseClick(sf::Vector2i mousePosition, SFMLRenderer &renderer, Playboard &playboard);
void setText(sf::Text &text, const sf::String &string);

#endif // SFML_RENDERER_HPP

