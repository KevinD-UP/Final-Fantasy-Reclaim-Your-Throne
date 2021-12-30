//
// Created by kevin on 11/12/2021.
//

#include "header/model/Personnage/Personnage.h"
#include "header/model/Personnage/PersonnageFactory.h"
#include "header/model/Joueur/Joueur.h"
#include "header/Partie.h"

int main(){

    PersonnageType TYPE_Guerrier = PT_Guerrier;
    PersonnageType TYPE_Amazone = PT_Amazone;
    PersonnageType TYPE_Moine = PT_Moine;
    PersonnageType TYPE_Sorcier = PT_Sorcier;

    std::string nomPerso;
    int choixPerso;
    Joueur *joueur;
    Personnage *personnageJoueur;

    //TODO: INIT LES PERSO EN FONCTION DU JOUEUR

    std::cout << "Bienvenue sur FINAL FANTASY RECLAIM YOUR THRONE" << std::endl;
    std::cout << "Veuillez écrire le nom de votre personnage : " << std::endl;
    std::cin >> nomPerso;
    std::cout << "Veuillez choisir la classe de votre personnage : " << std::endl;
    std::cout << "1 - Guerrier " << std::endl;
    std::cout << "2 - Amazone" << std::endl;
    std::cout << "3 - Moine " << std::endl;
    std::cout << "4 - Sorcier " << std::endl;

    while (!(choixPerso <= 4 && choixPerso >= 1)) {
        std::cin >> choixPerso;
        if(!(choixPerso <= 4 && choixPerso >= 1)){
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
    Personnage* sorcier = PersonnageFactory::initPersonnage(TYPE_Sorcier,"Test2");
    Personnage* moine = PersonnageFactory::initPersonnage(TYPE_Moine,"Test3");
    Personnage* amazone = PersonnageFactory::initPersonnage(TYPE_Amazone,"Test4");

    Map* carte = new Map();

    Partie partie = Partie({personnageJoueur, sorcier, moine, amazone}, joueur , carte);
    partie.startToPlay();
    //partie.deathBattle(personnageJoueur,sorcier);
    /*Piece *test = new Piece();
    Piece *test2 = new Piece();

    std::cout<<"Piece 0"<<std::endl;
    test->print();
    std::cout<<"Piece 1"<<std::endl;
    test2->print();*/

   // std::cout << "Fin de la partie" << std::endl;
}