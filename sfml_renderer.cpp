#include "sfml_renderer.hpp"
#include <iostream>

//Prototypes des fonctions
void inputHandler(sf::Event event, sf::RenderWindow &window);

//Création de la fenêtre
SFMLRenderer::SFMLRenderer()
{
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Jeu MMV");
    
}

SFMLRenderer::~SFMLRenderer()
{
    delete window;
}


void SFMLRenderer::waitForExit()
{
    sf::RectangleShape shape(sf::Vector2f(100,100));
    shape.setFillColor(sf::Color::White);
    shape.setPosition(100,100);

    //Boucle fenêtre graphique
    while (window->isOpen())
    {
        sf::Event event;    //Variable pour gérer l'évènement
        while (window->pollEvent(event))
        {
            inputHandler(event, *window);
        }

        //Couleur de la fenêtre
        window->clear(sf::Color::Black);

        window->draw(shape);

        //Dessiner à l'écran tous les évènements
        window->display();
    }  
}

void SFMLRenderer::drawPlayboard(Playboard &playboard){
    /*
    // Declare and load a texture
    sf::Texture texture_BandLeft, texture_BandRight;
    texture_BandLeft.loadFromFile("Pictures/BandLeft.jpeg");
    texture_BandRight.loadFromFile("Pictures/BandRight.jpeg");

    // Create a sprite
    sf::Sprite sprite_BandLeft;
    sf::Sprite sprite_BandRight;
    sprite_BandLeft.setTexture(texture_BandLeft);
    sprite_BandRight.setTexture(texture_BandRight);
    sprite_BandLeft.setScale(0.26,0.32);
    sprite_BandRight.setScale(0.36,0.43);
    //sprite.setColor(sf::Color(255, 255, 255, 200));
    sprite_BandLeft.setPosition(400, 0);
    sprite_BandRight.setPosition(700, 0);
    // Draw it
    window->draw(sprite_BandLeft);
    window->draw(sprite_BandRight);
    */
    
    // Créer une texture à partir de l'image
    sf::Texture texture_Screen, texture_Back, texture_Back2, texture_WPawn, texture_WKnight, texture_WBishop, texture_WRook, texture_WQueen, texture_WKing;
    texture_Screen.loadFromFile("Pictures/Screen.jpeg");
    texture_Back.loadFromFile("Pictures/Back.jpeg");
    texture_Back2.loadFromFile("Pictures/Back2.jpg");
    texture_WPawn.loadFromFile("Pictures/WoodenPieces/Pawn.png");
    texture_WKnight.loadFromFile("Pictures/WoodenPieces/Knight.png");
    texture_WBishop.loadFromFile("Pictures/WoodenPieces/Bishop.png");
    texture_WRook.loadFromFile("Pictures/WoodenPieces/Rook.png");
    texture_WQueen.loadFromFile("Pictures/WoodenPieces/Queen.png");
    texture_WKing.loadFromFile("Pictures/WoodenPieces/King.png");

    // Créer un sprite avec la texture
    sf::Sprite sprite_Screen, sprite_Back, sprite_Back2L, sprite_Back2R, sprite_WPawn, sprite_WKnight, sprite_WBishop, sprite_WRook, sprite_WQueen, sprite_WKing;
    sprite_Screen.setTexture(texture_Screen);
    sprite_Back.setTexture(texture_Back);
    sprite_Back2L.setTexture(texture_Back2);
    sprite_Back2R.setTexture(texture_Back2);
    sprite_WPawn.setTexture(texture_WPawn);
    sprite_WKnight.setTexture(texture_WKnight);
    sprite_WBishop.setTexture(texture_WBishop);
    sprite_WRook.setTexture(texture_WRook);
    sprite_WQueen.setTexture(texture_WQueen);
    sprite_WKing.setTexture(texture_WKing);

    //Screen
    sprite_Screen.setScale(0.45,0.62);
    sprite_Screen.setPosition(500,0);

    //Back
    sprite_Back.setScale(0.41,0.41);
    sprite_Back.setPosition(500,400);

    //Back 2
    sprite_Back2L.setScale(0.51,0.82);
    sprite_Back2L.setPosition(400,0);
    sprite_Back2R.setScale(0.51,0.82);
    sprite_Back2R.setPosition(900,0);

    //Wooden Pieces
    sprite_WPawn.setScale(3.1,3.1);
    sprite_WKnight.setScale(3.1,3.1);
    sprite_WBishop.setScale(3.1,3.1);
    sprite_WRook.setScale(3.1,3.1);
    sprite_WQueen.setScale(3.1,3.1);
    sprite_WKing.setScale(3.1,3.1);

    sprite_WPawn.setPosition(900,100);
    sprite_WKnight.setPosition(900,200);
    sprite_WBishop.setPosition(900,300);
    sprite_WRook.setPosition(900,400);
    sprite_WQueen.setPosition(900,500);
    sprite_WKing.setPosition(900,600);

    //Sprite draw
    window->draw(sprite_Screen);
    window->draw(sprite_Back);
    window->draw(sprite_Back2L);
    window->draw(sprite_Back2R);
    window->draw(sprite_WPawn);
    window->draw(sprite_WKnight);
    window->draw(sprite_WBishop);
    window->draw(sprite_WRook);
    window->draw(sprite_WQueen);
    window->draw(sprite_WKing);


    
    int i, j;
    for(i = 0; i < playboard.getRows(); i++){
        for(j = 0 ; j < playboard.getCols(); j++){
            sf::RectangleShape shape(sf::Vector2f(50,50));
            if((i+j)%2 == 0){
                shape.setFillColor(sf::Color::White);
            }else if((i+j)%2 ==1 ){
                shape.setFillColor(sf::Color::Black);
            }
            if(playboard.getCell(i,j).getStatus() == 2){
                shape.setFillColor(sf::Color::Blue);
            }else if(playboard.getCell(i,j).getStatus() == 0){
                shape.setFillColor(sf::Color::Red);
            }
            shape.setPosition(i*50,j*50);
            window->draw(shape);
        }
    }
}

//Gestion des events et des inputs
void inputHandler(sf::Event event, sf::RenderWindow &window){
    // Fermer le fenêtre
    if (event.type == sf::Event::Closed){
        window.close();
    }

    //Gestion des input clavier
        //Touche Echap
        if(event.key.code == sf::Keyboard::Escape){
            window.close();
        }

    //Gestion des inputs souris
    if (event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Right){
            std::cout << "click droit " << std::endl;
        }
        if(event.mouseButton.button == sf::Mouse::Left){
            std::cout << "click gauche " << std::endl;
        }
    }
    
    /*
    //Gestion des input clavier
    //Touche Echap
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window.close();
    }

    //Gestion des inputs souris
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        std::cout << "click droit " << std::endl;
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        std::cout << "click gauche " << std::endl;
    }


    // Declare and load a texture
    sf::Texture texture;
    texture.loadFromFile("Pictures/BandLeft.jpeg");
    // Create a sprite
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
    sprite.setColor(sf::Color(255, 255, 255, 200));
    sprite.setPosition(100, 25);
    // Draw it
    window.draw(sprite);
    */
}

