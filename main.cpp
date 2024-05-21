#include "cell.hpp"
#include "cavalier.hpp"
#include "reine.hpp"
#include "pion.hpp"
#include "fou.hpp"
#include "tour.hpp"
#include "joueur.hpp"
#include "emptycell.hpp"
#include "obstaclecell.hpp"
#include "duelcell.hpp"
#include "playboard.hpp"
#include "jeu.hpp"
#include "sfml_renderer.hpp"
#include <iostream>
#include <memory> // Pour std::shared_ptr

int main() {
    
//     // Création des objets nécessaires
//     Cell cellule;
//     Piece piece;
//     Fou fou(2, 2); // Crée un Fou avec une position (2, 2)
//     Playboard plateau(8, 8);

//     // Création d'un joueur avec une pièce (Fou) enveloppée dans std::shared_ptr
//     std::shared_ptr<Piece> fouPtr = std::make_shared<Fou>(2, 2); // Crée un Fou avec une position (2, 2)
//     Joueur joueur1("mathieu", fouPtr); // Déplace le Fou dans un std::shared_ptr et le passe au Joueur
//     std::shared_ptr<Piece> piPtr = std::make_shared<Pion>(0,0);
//     Joueur joueur2("victor", piPtr);
//     ObstacleCell cell;
//     plateau.setCell(0,1,cell);
//     plateau.setCell(1,1,cell);
//     joueur1.display(); // Affiche les détails du joueur et de sa pièce
//     // Ajouter des joueurs au vecteur
//     printf("est ce que 2 ,2 est occupée %d \n",plateau.isoccupied(2,2,joueur1));
//     plateau.printBoard(joueur1,joueur2);
//     // Déplacement de la pièce du joueur
//     if (joueur1.my_piece) {
//         joueur1.my_piece->deplacement(0, 1, plateau); // Appel de la méthode deplacement() sur la pièce du joueur
//         joueur1.display(); // Affiche les détails mis à jour du joueur et de sa pièce
//         plateau.printBoard(joueur1,joueur2);
//         std::shared_ptr<Piece> pionPtr = std::make_shared<Pion>(fouPtr->posx,fouPtr->posy);
//         joueur1.my_piece = pionPtr;

//         joueur1.my_piece->deplacement(0,0,plateau);
//         joueur1.display();
//         plateau.printBoard(joueur1,joueur2);

//         std::shared_ptr<Piece> cavalierPtr = std::make_shared<Cavalier>(joueur1.my_piece->posx,joueur1.my_piece->posy);
//         joueur1.my_piece = cavalierPtr;
//         std::shared_ptr<Piece> cavalierPtr2 = std::make_shared<Cavalier>(0,0);
//         joueur2.my_piece = cavalierPtr2;    
//         joueur2.my_piece->deplacement(3,0,plateau);

        
//         joueur1.my_piece->deplacement(3,0,plateau);
//         joueur1.display();
//         plateau.printBoard(joueur1,joueur2); // Affiche l'état du plateau après le déplacement
//     }
// /*
//     Playboard plateau(8,20);
//     plateau.initPlayboard();
//     plateau.printBoard();
//     */
//         plateau.printBoard(); // Affiche l'état du plateau après le déplacement
    
    //Rendu graphique SFML
    SFMLRenderer renderer;
    sf::RenderWindow &window = renderer.getWindow();
    window.setVerticalSyncEnabled(true);	


    //Test ratio + tour d'un joueur
    Jeu jeu(8,16);
    // int choice = 0;
    // int range= 0;
    // jeu.joueur1.print();
    // jeu.playboard.printBoard(jeu.joueur1,jeu.joueur2);
    // jeu.joueur1.my_piece->posx = 2;
    // jeu.joueur1.my_piece->posy = 1;
    // jeu.playboard.printBoard(jeu.joueur1,jeu.joueur2);
    // jeu.tour(1);
    // jeu.playboard.printBoard(jeu.joueur1,jeu.joueur2);
    // jeu.joueur1.print();
    // jeu.joueur1.changerpiece(2);
    // jeu.joueur2.changerpiece(2);
    // jeu.joueur1.print();
    // jeu.joueur2.print();

    // std::shared_ptr<Piece> reinePtr2 = std::make_shared<Reine>(jeu.joueur1.my_piece->posx,jeu.joueur1.my_piece->posy);
    
    // jeu.joueur1.my_piece = reinePtr2;  
    // jeu.joueur1.print();
    // jeu.joueur1.my_piece->convertXYtoChoiceRange(4,3,&choice, &range);
    
    // printf("choice %d range %d state %d \n",choice,range,jeu.joueur1.my_piece->deplacement(choice,range,jeu.playboard));
    // jeu.joueur1.print();
    // jeu.playboard.printBoard(jeu.joueur1,jeu.joueur2);
    // jeu.joueur1.changerpiece(1);
    // jeu.tour(1);
    // jeu.playboard.printBoard(jeu.joueur1,jeu.joueur2);
    jeu.playboard.printBoard(jeu.joueur1,jeu.joueur2);
    // jeu.joueur1.changerpiece(2);
    jeu.joueur1.print();

    //Boucle fenêtre graphique
    while (window.isOpen())
    {
        sf::Event event;    //Variable pour gérer l'évènement
        if(jeu.startGame){
            while (window.pollEvent(event))
            {
                // Fermer le fenêtre
                if (event.type == sf::Event::Closed){
                    window.close();
                    std::cout << "Game closed" << std::endl;
                }
                if (event.type == sf::Event::MouseButtonPressed){
                    if(event.mouseButton.button == sf::Mouse::Left){
                        jeu.startGame = false;
                    }
                }
            }

            //Couleur de la fenêtre
            window.clear(sf::Color::Black);
            window.draw(renderer.sprite_Start);

        }else if(!jeu.endGame){
            while (window.pollEvent(event))
            {
                inputHandler(event, renderer, jeu);
            }

            //Couleur de la fenêtre
            window.clear(sf::Color::Black);

            //Afficher les éléments de la fenêtre
            renderer.drawInterface();
            jeu.playboard.display(renderer);
            jeu.joueur1.my_piece->display(renderer, 1);
            jeu.joueur2.my_piece->display(renderer, 2);

        }else{
            while (window.pollEvent(event))
            {
                // Fermer le fenêtre
                if (event.type == sf::Event::Closed){
                    window.close();
                    std::cout << "Game closed" << std::endl;
                }
            }

            if(jeu.tourJ2){
                renderer.getVictoryText().setString("Victoire du Joueur 1");
            }else{
                renderer.getVictoryText().setString("Victoire du Joueur 2");
            }
            
            //Couleur de la fenêtre
            window.clear(sf::Color::Black);
            window.draw(renderer.sprite_End);
            window.draw(renderer.getVictoryText());
        }
            //Dessiner à l'écran tous les évènements
            window.display();
    }  

    /*
    while(1){
        printf("Tour N° %d \n",nb_tour);
        jeu.tour(1);
        jeu.joueur1.print();
        jeu.playboard.printBoard(jeu.joueur1,jeu.joueur2);
        nb_tour++;
        if (nb_tour%3==0){
            DuelCell cel;
            int res = cel.duel();
            jeu.recompense(res);
            jeu.joueur1.print();
        }
    }
    */

    
    return 0;
}

