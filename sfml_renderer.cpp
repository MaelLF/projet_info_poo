#include "sfml_renderer.hpp"
#include <iostream>

//Prototypes des fonctions
void inputHandler(sf::Event event, sf::RenderWindow &window);

//Création de la fenêtre
SFMLRenderer::SFMLRenderer()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Jeu MMV");
    
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

void SFMLRenderer::drawPlayboard( Playboard &playboard){
    int i, j;
    for(i = 0; i < playboard.getRows(); i++){
        for(j = 0 ; j < playboard.getCols(); j++){
            sf::RectangleShape shape(sf::Vector2f(100,100));
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
            shape.setPosition(j*100,i*100);
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
    */
}

