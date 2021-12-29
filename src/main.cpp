//
// Created by kevin on 11/12/2021.
//

#include "header/model/Personnage/Personnage.h"
#include "header/model/Personnage/PersonnageFactory.h"
//#include "header/model/Objet/ConsommableFactory.h"
#include "header/model/Joueur/Joueur.h"
#include "header/Partie.h"

int main(){
    /*PersonnageType TYPE_Guerrier = PT_Guerrier;
    PersonnageType TYPE_Amazone = PT_Amazone;
    PersonnageType TYPE_Moine = PT_Moine;
    PersonnageType TYPE_Sorcier = PT_Sorcier;

    std::string nomPerso;
    int choixPerso{0};
    Joueur *joueur = nullptr;
    Personnage *personnageJoueur = nullptr;

    std::cout << "Bienvenue sur FINAL FANTASY RECLAIM YOUR THRONE" << std::endl;
    std::cout << "Veuillez écrire le nom de votre personnage : " << std::endl;
    std::cin >> nomPerso;
    std::cout << "Veuillez choisir la classe de votre personnage : " << std::endl;
    std::cout << "1 - Guerrier " << std::endl;
    std::cout << "2 - Amazone" << std::endl;
    std::cout << "3 - Moine " << std::endl;
    std::cout << "4 - Sorcier " << std::endl;
    while (choixPerso > 4 || choixPerso < 0) {
        std::cin >> choixPerso;
        if(choixPerso > 4 || choixPerso < 0){
            std::cout << "Erreur personnage non existant" << std::endl;
        }
    }

    if(choixPerso == 1){
        personnageJoueur = PersonnageFactory::initPersonnage(TYPE_Guerrier, nomPerso);
        joueur = new Joueur(personnageJoueur);
        std::cout << "Votre personnage a été crée" << std::endl;
    }else if (choixPerso == 2){
        personnageJoueur = PersonnageFactory::initPersonnage(TYPE_Amazone, nomPerso);
        joueur = new Joueur(personnageJoueur);
        std::cout << "Votre personnage a été crée" << std::endl;
    }else if (choixPerso == 3){
        personnageJoueur = PersonnageFactory::initPersonnage(TYPE_Moine, nomPerso);
        joueur = new Joueur(personnageJoueur);
        std::cout << "Votre personnage a été crée" << std::endl;
    }else if(choixPerso == 4){
        personnageJoueur = PersonnageFactory::initPersonnage(TYPE_Sorcier, nomPerso);
        joueur = new Joueur(personnageJoueur);
        std::cout << "Votre personnage a été crée" << std::endl;
    }

    std::cout << "Création des personnages non joueur..." << std::endl;
    Personnage* sorcier = PersonnageFactory::initPersonnage(TYPE_Sorcier,"Ennemie");
    Personnage* moine = PersonnageFactory::initPersonnage(TYPE_Moine,"Test3");
    Personnage* amazone = PersonnageFactory::initPersonnage(TYPE_Amazone,"Test4");

    Partie partie = Partie({personnageJoueur, sorcier, moine, amazone}, joueur);
    partie.startToPlay();*/
    //partie.deathBattle(personnageJoueur,sorcier);
    Piece *test = new Piece();
    Piece *test2 = new Piece();
    /*Piece *test3 = new Piece();
    Piece *test4 = new Piece();
    Piece *test5= new Piece();
    Piece *test6 = new Piece();
    Piece *test7= new Piece();
    Piece *test8 = new Piece();

    Piece *test9 = new Piece();
    Piece *test10 = new Piece();
    Piece *test11 = new Piece();
    Piece *test12 = new Piece();
    Piece *test13= new Piece();
    Piece *test14 = new Piece();
    Piece *test15= new Piece();
    Piece *test16= new Piece();


*/    //test->pushPerso(personnageJoueur);
    std::cout<<"0"<<std::endl;
    test->print();
    std::cout<<"1"<<std::endl;
    test2->print();
    /*test3->print();
    test4->print();
    test5->print();
    test6->print();
    test7->print();
    test8->print();

    test9->print();
    test10->print();
    test11->print();
    test12->print();
    test13->print();
    test14->print();
    test15->print();
    test16->print();
*/

   // std::cout << "Fin de la partie" << std::endl;
}