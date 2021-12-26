//
// Created by kevin on 18/12/2021.
//

#include "../header/Partie.h"

void Partie::startToPlay() {
    std::cout << "Partie Lancée" << std::endl;
    /*for (auto & personnage: persoEnJeu) {
        personnage->print();
    }*/
}

const std::vector<Personnage *> Partie::getPersoEnJeu() const {
    return persoEnJeu;
}

const Joueur *Partie::getJoueur() const {
    return joueur;
}

Partie::Partie(const std::vector<Personnage*> persoEnJeuArg, const Joueur* joueurArg) : persoEnJeu(persoEnJeuArg), joueur(joueurArg)
{}

void Partie::deathBattle(Personnage *a, Personnage *b) const{
    while(!a->estMort() || !b->estMort()){
        if(a == getJoueur()->personnageJoueur) {
            auto etat = a->updateStatut();
            if (a->estMort()) {
                std::cout << "Victoire de " << b->getNom() << std::endl;
                std::cout << a << std::endl;
                b->reset();
                return;
            }
            if (etat == false) {
                Partie::getJoueur()->interagir(b);
            }

            etat = b->updateStatut();
            if (b->estMort()) {
                std::cout << "Victoire de " << a->getNom() << std::endl;
                std::cout << a << std::endl;
                a->reset();
                return;
            }
            if (etat == false) {
                b->actionIa(a);
            }

        }
        else{
            a->checkStatut();
            if (a->estMort()){
                b->setSante(b->getSanteMax());
                return;
            }
            a->actionIa(b);
            b->checkStatut();
            if(b->estMort()){
                a->setSante(a->getSanteMax());
                return;
            }
            b->actionIa(a);
        }
    }
}