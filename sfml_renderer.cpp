#include "sfml_renderer.hpp"
#include <iostream>

//Création de la fenêtre
SFMLRenderer::SFMLRenderer()
{
    // Création de la fenêtre
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Jeu MMV");

    //Load Font
    font.loadFromFile("Fonts/Poppins.ttf");

    //Création d'un texte
    txt.setFont(font);
    setText(txt, "Hello");

    
    // Créer une texture à partir de l'image
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
    sprite_Screen.setScale(0.63,0.56);
    sprite_Screen.setPosition(500,0);

    //Back
    sprite_Back.setScale(0.41,0.31);
    sprite_Back.setPosition(500,500);

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
    
        }

        //Couleur de la fenêtre
        window->clear(sf::Color::Black);

        window->draw(shape);

        //Dessiner à l'écran tous les évènements
        window->display();
    }  
}

void SFMLRenderer::drawPlayboard(Playboard &playboard){
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

    //Plateau    
    int i, j;
    for(i = 0; i < playboard.getRows(); i++){
        for(j = 0 ; j < playboard.getCols(); j++){
            sf::RectangleShape shape(sf::Vector2f(CELL_SIZE,CELL_SIZE));
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
            shape.setPosition(i*CELL_SIZE,j*CELL_SIZE);
            window->draw(shape);
        }
    }

    window->draw(txt);
}

//Gestion des events et des inputs
void inputHandler(sf::Event event, SFMLRenderer &renderer, Playboard &playboard){
    sf::RenderWindow &window = renderer.getWindow();

    // Fermer le fenêtre
    if (event.type == sf::Event::Closed){
        window.close();
        std::cout << "Game closed" << std::endl;
    }

    //Gestion des input clavier
        //Touche Echap
        /*
        if(event.key.code == sf::Keyboard::Escape){
            window.close();
            std::cout << "Fermeture par Echape" << std::endl;
        }
        */

    //Gestion des inputs souris
    if (event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Right){
            setText(renderer.getText(), "click droit");
        }
        if(event.mouseButton.button == sf::Mouse::Left){
            setText(renderer.getText(), "click gauche");
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            //Clique sur le plateau
            handleMouseClick(mousePosition, renderer, playboard);

            //Clique sur les Wooden Pieces
            //WPawn
            if(renderer.sprite_WPawn.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                setText(renderer.getText(), "Pawn");
            }

            //WKnight
            if(renderer.sprite_WKnight.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                setText(renderer.getText(), "Knight");
            }

            //WBishop
            if(renderer.sprite_WBishop.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                setText(renderer.getText(), "Bishop");
            }

            //WRook
            if(renderer.sprite_WRook.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                setText(renderer.getText(), "Rook");
            }

            //WQueen
            if(renderer.sprite_WQueen.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                setText(renderer.getText(), "Queen");
            }

            //WKing
            if(renderer.sprite_WKing.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                setText(renderer.getText(), "King");
            }
        }
    }
}

void handleMouseClick(sf::Vector2i mousePosition, SFMLRenderer &renderer, Playboard &playboard) {
    // Convertir les coordonnées de la souris en coordonnées de la grille
    int col = mousePosition.x / CELL_SIZE;
    int row = mousePosition.y / CELL_SIZE;

    ObstacleCell obs = ObstacleCell();

    // Vérifier que les coordonnées sont valides
    if (playboard.isValidCell(col,row)) {
        // Effectuer une action sur la case (row, col)
        std::cout << "Click sur la case (" << col << ", " << row << ")" << std::endl;
        playboard.setCell(col, row, obs);
    }
}

void setText(sf::Text &txt, const sf::String &string){
    txt.setString(string);
    txt.setCharacterSize(26);
    txt.setFillColor(sf::Color::Red);
    txt.setPosition(550,100);
}
