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
    setText(txt, L"Règles du jeu\nTour à tour, lancer le dé,\npuis sélectionner la case où\navancer. Un duel a lieu tous les\n3 tours ou en allant sur une\ncase VS. Changer alors de\npièce pour atteindre la case\ndu roi en 1er. Chaque pièce\npossède un pouvoir spécifique\nen fonction de la valeur du dé.\nCliquer sur les pièces à\ndroite pour les connaître.");
    txtButton.setFont(font);
    txtButton.setString(L"Lancer le dé");
    txtButton.setCharacterSize(25);
    txtButton.setFillColor(sf::Color::Black);
    txtButton.setPosition(625,625);
    
    // Créer une texture à partir de l'image
    texture_Screen.loadFromFile("Pictures/Screen.jpeg");
    texture_Back.loadFromFile("Pictures/Back.jpeg");
    texture_Back2.loadFromFile("Pictures/Back2.jpg");
    //Button
    texture_Button.loadFromFile("Pictures/Button2.png");
    //Cell
    texture_Rock.loadFromFile("Pictures/Rock.png");
    texture_VS.loadFromFile("Pictures/VS.png");
    //Wooden pieces textures
    texture_WPawn.loadFromFile("Pictures/WoodenPieces/Pawn.png");
    texture_WKnight.loadFromFile("Pictures/WoodenPieces/Knight.png");
    texture_WBishop.loadFromFile("Pictures/WoodenPieces/Bishop.png");
    texture_WRook.loadFromFile("Pictures/WoodenPieces/Rook.png");
    texture_WQueen.loadFromFile("Pictures/WoodenPieces/Queen.png");
    texture_WKing.loadFromFile("Pictures/WoodenPieces/King.png");
    //White pieces textures
    texture_Pawn.loadFromFile("Pictures/WhitePieces/Pawn.png");
    texture_Knight.loadFromFile("Pictures/WhitePieces/Knight.png");
    texture_Bishop.loadFromFile("Pictures/WhitePieces/Bishop.png");
    texture_Rook.loadFromFile("Pictures/WhitePieces/Rook.png");
    texture_Queen.loadFromFile("Pictures/WhitePieces/Queen.png");
    //Black pieces textures
    texture_BPawn.loadFromFile("Pictures/BlackPieces/Pawn.png");
    texture_BKnight.loadFromFile("Pictures/BlackPieces/Knight.png");
    texture_BBishop.loadFromFile("Pictures/BlackPieces/Bishop.png");
    texture_BRook.loadFromFile("Pictures/BlackPieces/Rook.png");
    texture_BQueen.loadFromFile("Pictures/BlackPieces/Queen.png");

    // Créer un sprite avec la texture
    sprite_Screen.setTexture(texture_Screen);
    sprite_Back.setTexture(texture_Back);
    sprite_Back2L.setTexture(texture_Back2);
    sprite_Back2R.setTexture(texture_Back2);
    //Button
    sprite_Button.setTexture(texture_Button);
    //Cell
    sprite_Rock.setTexture(texture_Rock);
    sprite_VS.setTexture(texture_VS);
    //Wooden pieces sprites
    sprite_WPawn.setTexture(texture_WPawn);
    sprite_WKnight.setTexture(texture_WKnight);
    sprite_WBishop.setTexture(texture_WBishop);
    sprite_WRook.setTexture(texture_WRook);
    sprite_WQueen.setTexture(texture_WQueen);
    sprite_WKing.setTexture(texture_WKing);
    sprite_WKingCell.setTexture(texture_WKing);
    //White pieces sprites
    sprite_Pawn.setTexture(texture_Pawn);
    sprite_Knight.setTexture(texture_Knight);
    sprite_Bishop.setTexture(texture_Bishop);
    sprite_Rook.setTexture(texture_Rook);
    sprite_Queen.setTexture(texture_Queen);
    //Black pieces sprites
    sprite_BPawn.setTexture(texture_BPawn);
    sprite_BKnight.setTexture(texture_BKnight);
    sprite_BBishop.setTexture(texture_BBishop);
    sprite_BRook.setTexture(texture_BRook);
    sprite_BQueen.setTexture(texture_BQueen);

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

    //Button
    sprite_Button.setScale(1.02,1.19);
    sprite_Button.setPosition(600,600);

    //Rock
    sprite_Rock.setScale(0.52,0.54);

    //VS
    sprite_VS.setScale(0.033,0.033);

    //Wooden Pieces
    sprite_WPawn.setScale(3.1,3.1);
    sprite_WKnight.setScale(3.1,3.1);
    sprite_WBishop.setScale(3.1,3.1);
    sprite_WRook.setScale(3.1,3.1);
    sprite_WQueen.setScale(3.1,3.1);
    sprite_WKing.setScale(3.1,3.1);
    sprite_WKingCell.setScale(1.56,1.56);

    sprite_WPawn.setPosition(900,100);
    sprite_WKnight.setPosition(900,200);
    sprite_WBishop.setPosition(900,300);
    sprite_WRook.setPosition(900,400);
    sprite_WQueen.setPosition(900,500);
    sprite_WKing.setPosition(900,600);

    //White Pieces
    sprite_Pawn.setScale(1.56,1.56);
    sprite_Knight.setScale(1.56,1.56);
    sprite_Bishop.setScale(1.56,1.56);
    sprite_Rook.setScale(1.56,1.56);
    sprite_Queen.setScale(1.56,1.56);

    //Black Pieces
    sprite_BPawn.setScale(1.56,1.56);
    sprite_BKnight.setScale(1.56,1.56);
    sprite_BBishop.setScale(1.56,1.56);
    sprite_BRook.setScale(1.56,1.56);
    sprite_BQueen.setScale(1.56,1.56);
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

void SFMLRenderer::drawInterface(){
    //Sprite draw
    window->draw(sprite_Screen);
    window->draw(sprite_Back);
    window->draw(sprite_Back2L);
    window->draw(sprite_Back2R);
    window->draw(sprite_Button);
    window->draw(sprite_WPawn);
    window->draw(sprite_WKnight);
    window->draw(sprite_WBishop);
    window->draw(sprite_WRook);
    window->draw(sprite_WQueen);
    window->draw(sprite_WKing);
    window->draw(txt);
    window->draw(txtButton);
}

void SFMLRenderer::drawPlayboard(Playboard &playboard){
    //Plateau    
    int i, j;
    for(i = 0; i < playboard.getRows(); i++){
        for(j = 0 ; j < playboard.getCols(); j++){
            sf::RectangleShape shape(sf::Vector2f(CELL_SIZE,CELL_SIZE));
            if((i+j)%2 == 0){
                shape.setFillColor(sf::Color::White);
                shape.setPosition(i*CELL_SIZE,j*CELL_SIZE);
                window->draw(shape);
            }else if((i+j)%2 ==1 ){
                shape.setFillColor(sf::Color::Black);
                shape.setPosition(i*CELL_SIZE,j*CELL_SIZE);
                window->draw(shape);
            }
            if(playboard.getCell(i,j).getStatus() == 2){
                sprite_VS.setPosition(i*CELL_SIZE,j*CELL_SIZE);
                window->draw(sprite_VS);
            }else if(playboard.getCell(i,j).getStatus() == 0){
                sprite_Rock.setPosition(i*CELL_SIZE,j*CELL_SIZE);
                window->draw(sprite_Rock);
            }else if(playboard.getCell(i,j).getStatus() == 4){
                sprite_WKingCell.setPosition(i*CELL_SIZE,j*CELL_SIZE);
                window->draw(sprite_WKingCell);
            }
        }
    }

}

void SFMLRenderer::drawPion(Pion& pion, int j){
    if(j == 1){
        sprite_Pawn.setPosition(pion.posx*CELL_SIZE, pion.posy*CELL_SIZE);
        window->draw(sprite_Pawn);
    }else if(j == 2){
        sprite_BPawn.setPosition(pion.posx*CELL_SIZE, pion.posy*CELL_SIZE);
        window->draw(sprite_BPawn);
    }else{
        std::cout << "Erreur : j dans drawPion(). Choix de joueur invalide" << std::endl;
    }
}

void SFMLRenderer::drawCavalier(Cavalier& cavalier, int j){
    if(j == 1){
        sprite_Knight.setPosition(cavalier.posx*CELL_SIZE, cavalier.posy*CELL_SIZE);
        window->draw(sprite_Knight);
    }else if(j == 2){
        sprite_BKnight.setPosition(cavalier.posx*CELL_SIZE, cavalier.posy*CELL_SIZE);
        window->draw(sprite_BKnight);
    }else{
        std::cout << "Erreur : j dans drawCavalier(). Choix de joueur invalide" << std::endl;
    }
}

void SFMLRenderer::drawFou(Fou &fou, int j){
    if(j == 1){
        sprite_Bishop.setPosition(fou.posx*CELL_SIZE, fou.posy*CELL_SIZE);
        window->draw(sprite_Bishop);
    }else if(j == 2){
        sprite_BBishop.setPosition(fou.posx*CELL_SIZE, fou.posy*CELL_SIZE);
        window->draw(sprite_BBishop);
    }else{
        std::cout << "Erreur : j dans drawFou(). Choix de joueur invalide" << std::endl;
    }
}

void SFMLRenderer::drawTour(Tour &tour, int j){
    if(j == 1){
        sprite_Rook.setPosition(tour.posx*CELL_SIZE, tour.posy*CELL_SIZE);
        window->draw(sprite_Rook);
    }else if(j == 2){
        sprite_BRook.setPosition(tour.posx*CELL_SIZE, tour.posy*CELL_SIZE);
        window->draw(sprite_BRook);
    }else{
        std::cout << "Erreur : j dans drawTour(). Choix de joueur invalide" << std::endl;
    }
}

void SFMLRenderer::drawReine(Reine &reine, int j){
    if(j == 1){
        sprite_Queen.setPosition(reine.posx*CELL_SIZE, reine.posy*CELL_SIZE);
        window->draw(sprite_Queen);
    }else if(j == 2){
        sprite_BQueen.setPosition(reine.posx*CELL_SIZE, reine.posy*CELL_SIZE);
        window->draw(sprite_BQueen);
    }else{
        std::cout << "Erreur : j dans drawReine(). Choix de joueur invalide" << std::endl;
    }
}

//Gestion des events et des inputs
void inputHandler(sf::Event event, SFMLRenderer &renderer, Jeu& jeu){
    sf::RenderWindow &window = renderer.getWindow();

    // Fermer le fenêtre
    if (event.type == sf::Event::Closed){
        window.close();
        std::cout << "Game closed" << std::endl;
    }

    //Gestion des inputs souris
    if (event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Right){
            setText(renderer.getText(), L"Si vous cherchez des\ninformations cliquez sur les\npièces à droite.\nLe roi donne les règles du jeu.");
        }
        if(event.mouseButton.button == sf::Mouse::Left){
            renderer.drawGameStatut(jeu);

            //On récupère la position de la souris
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if(!jeu.joueur1.choosePiece && !jeu.joueur2.choosePiece){
                //Clique sur le plateau
                handleMouseClick(mousePosition, renderer, jeu);

                //On ne peut lancer le dé qu'une fois par tour
                if(!jeu.clickButton){
                    //Clique sur le bouton pour lancer le dé
                    if(renderer.sprite_Button.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                        jeu.clickButton = true;
                        jeu.dice = std::rand() % 6 + 1;
                        renderer.drawGameStatut(jeu);
                    }
                }
            }

            //Clique sur les Wooden Pieces
            //WPawn
            if(renderer.sprite_WPawn.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                if(jeu.joueur1.choosePiece){
                    setText(renderer.getText(), L"Le joueur 1 à choisi un Pawn");
                    jeu.joueur1.changerpiece(1);
                    jeu.joueur1.choosePiece = false;
                }else if(jeu.joueur2.choosePiece){
                    setText(renderer.getText(), L"Le joueur 2 à choisi un Pawn");
                    jeu.joueur2.changerpiece(1);
                    jeu.joueur2.choosePiece = false;
                }else{
                    setText(renderer.getText(), L"Pawn\n\nSi le dé tombe sur :\n- 1, 3 ou 5 : Avancez de 1 case,\nl'adversaire recule de 1 case\n- 2 ou 4 : Avancez de 1 case,\nl'adversaire recule de 3 cases\n- 6 : Avancez de 1 case,\nl'adversaire recule de 5 cases");
                }
            }

            //WKnight
            if(renderer.sprite_WKnight.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                if(jeu.joueur1.choosePiece){
                    setText(renderer.getText(), L"Le joueur 1 à choisi un Knight");
                    jeu.joueur1.changerpiece(2);
                    jeu.joueur1.choosePiece = false;
                }else if(jeu.joueur2.choosePiece){
                    setText(renderer.getText(), L"Le joueur 2 à choisi un Knight");
                    jeu.joueur2.changerpiece(2);
                    jeu.joueur2.choosePiece = false;
                }else{
                    setText(renderer.getText(), L"Knight\n\nSi le dé tombe sur :\n- 1, 3 ou 5 : Avancez en L\n- 2 ou 4 : Avancez en L,\nl'adversaire recule de 1 case\n- 6 : Avancez en L,\nl'adversaire recule de 3 cases");
                }
            }

            //WBishop
            if(renderer.sprite_WBishop.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                if(jeu.joueur1.choosePiece){
                    setText(renderer.getText(), L"Le joueur 1 à choisi un Bishop");
                    jeu.joueur1.changerpiece(3);
                    jeu.joueur1.choosePiece = false;
                }else if(jeu.joueur2.choosePiece){
                    setText(renderer.getText(), L"Le joueur 2 à choisi un Bishop");
                    jeu.joueur2.changerpiece(3);
                    jeu.joueur2.choosePiece = false;
                }else{
                    setText(renderer.getText(), L"Bishop\n\nSi le dé tombe sur :\n- 1, 3 ou 5 : Avancez jusqu'à 3\ncases\n- 2 ou 4 : Avancez jusqu'à 3\ncases, l'adversaire recule de\n1 case\n- 6 : Avancez jusqu'à 3 cases,\nl'adversaire recule de 3 cases\n");
                }
            }

            //WRook
            if(renderer.sprite_WRook.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                if(jeu.joueur1.choosePiece){
                    setText(renderer.getText(), L"Le joueur 1 à choisi une Rook");
                    jeu.joueur1.changerpiece(4);
                    jeu.joueur1.choosePiece = false;
                }else if(jeu.joueur2.choosePiece){
                    setText(renderer.getText(), L"Le joueur 2 à choisi une Rook");
                    jeu.joueur2.changerpiece(4);
                    jeu.joueur2.choosePiece = false;
                }else{
                    setText(renderer.getText(), L"Rook\n\nSi le dé tombe sur :\n- 1, 3 ou 5 : Avancez jusqu'à 3\ncases\n- 2 ou 4 : Avancez jusqu'à 4\ncases\n- 6 : Avancez jusqu'à 5 cases");
                }
            }

            //WQueen
            if(renderer.sprite_WQueen.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                if(jeu.joueur1.choosePiece && jeu.joueur1.point >= 3){
                    setText(renderer.getText(), L"Le joueur 1 à choisi une Queen");
                    jeu.joueur1.changerpiece(5);
                    jeu.joueur1.choosePiece = false;
                }else if(jeu.joueur2.choosePiece && jeu.joueur2.point >= 3){
                    setText(renderer.getText(), L"Le joueur 2 à choisi une Queen");
                    jeu.joueur2.changerpiece(5);
                    jeu.joueur2.choosePiece = false;
                }else{
                    setText(renderer.getText(), L"Queen\n\nSi le dé tombe sur :\n- 1, 3 ou 5 : Avancez jusqu'à 4\ncases, l'adversaire recule de\n1 case\n- 2 ou 4 : Avancez jusqu'à 4\ncases, l'adversaire recule de\n3 cases\n- 6 : Avancez jusqu'à 4 cases,\nl'adversaire recule de 4 cases\n");
                }
            }

            //WKing
            if(renderer.sprite_WKing.getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                setText(renderer.getText(), L"Règles du jeu\nTour à tour, lancer le dé,\npuis sélectionner la case où\navancer. Un duel a lieu tous les\n3 tours ou en allant sur une\ncase VS. Changer alors de\npièce pour atteindre la case\ndu roi en 1er. Chaque pièce\npossède un pouvoir spécifique\nen fonction de la valeur du dé.\nCliquer sur les pièces à\ndroite pour les connaître.");
            }
        }
    }
}

void handleMouseClick(sf::Vector2i mousePosition, SFMLRenderer &renderer, Jeu& jeu) {
    // Convertir les coordonnées de la souris en coordonnées de la grille
    sf::Vector2i posCell;
    posCell.x = mousePosition.x / CELL_SIZE;
    posCell.y = mousePosition.y / CELL_SIZE;

    // Vérifier que les coordonnées sont valides
    if (jeu.playboard.isValidCell(posCell.x, posCell.y)) {
        // Effectuer une action sur la case (row, col)
        std::cout << "Click sur la case (" << posCell.x << ", " << posCell.y << ")" << std::endl;
        //On doit d'abord lancer le dé avant de jouer
        if(jeu.clickButton){
            //On lance le tour de jeu
            jeu.tour(posCell);
        }
        //On affiche le statut du tour
        renderer.drawGameStatut(jeu);
    }
}

void setText(sf::Text &txt, const sf::String &string){
    txt.setString(string);
    txt.setCharacterSize(20);
    txt.setFillColor(sf::Color::Black);
    txt.setPosition(560,80);
}

void SFMLRenderer::drawGameStatut(Jeu& jeu){
    if(jeu.clickButton){
        //Numéro du dé
        std::wstring wdice = std::to_wstring(jeu.dice);

        if(jeu.tourJ1){
            std::wstring wpoints = std::to_wstring(jeu.joueur1.point);
            sf::String message = L"Tour du Joueur 1\n\nNombre de duels gagnés : " + wpoints + L"\n\nLe dé est tombé sur " + wdice + L"\n\nVous pouvez choisir une case";
            setText(txt, message);
        }
        else if(jeu.tourJ2){
            std::wstring wpoints = std::to_wstring(jeu.joueur2.point);
            sf::String message = L"Tour du Joueur 2\n\nNombre de duels gagnés : " + wpoints  + L"\n\nLe dé est tombé sur " + wdice + L"\n\nVous pouvez choisir une case";
            setText(txt, message);
        }
    }else if(!jeu.clickButton){
        if(jeu.tourJ1){
            std::wstring wpoints = std::to_wstring(jeu.joueur1.point);
            sf::String message = L"Tour du Joueur 1\n\nNombre de duels gagnés : " + wpoints + L"\n\nVeuillez lancer le dé";
            setText(txt, message);
        }
        else if(jeu.tourJ2){
            std::wstring wpoints = std::to_wstring(jeu.joueur2.point);
            sf::String message = L"Tour du Joueur 2\n\nNombre de duels gagnés : " + wpoints + L"\n\nVeuillez lancer le dé";
            setText(txt, message);
        }
    }
    if(jeu.joueur1.choosePiece){
        setText(txt, L"Duel : Le Joueur 1  a gagné\nChoisissez une une piece");
    }
    else if(jeu.joueur2.choosePiece){
        setText(txt, L"Duel : Le Joueur 2  a gagné\nChoisissez une une piece");
    }
}