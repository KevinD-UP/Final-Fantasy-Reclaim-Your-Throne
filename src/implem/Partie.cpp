//
// Created by kevin on 18/12/2021.
//

#include "../header/Partie.h"

void Partie::startToPlay() {
    std::cout << "Partie Lancée" << std::endl;
    routine();
}

void Partie::routine() {
    /*for(auto & personnage: persoEnJeu){
        if(personnage == joueur->getPerso()){
            //TODO: INTERACTION JOUEUR
        } else {
            //TODO: DEPLACEMENT ALEATOIRE
        }

        if(pieceArrive.combatPossible()) { //TODO:VERIFICATION PRESENCE
            deathBattle(personnage, );
            if(finDePartie()){
                return;
            }
        }
    }*/
}

const std::vector<Personnage *> Partie::getPersoEnJeu() const {
    return persoEnJeu;
}

const Joueur* Partie::getJoueur() const {
    return joueur;
}

const Map* Partie::getChateau() const {
    return chateau;
}

Partie::Partie(const std::vector<Personnage*> persoEnJeuArg, const Joueur* joueurArg) : persoEnJeu(persoEnJeuArg), joueur(joueurArg)
{}

void Partie::deathBattle(Personnage *a, Personnage *b) const{
    while(!a->estMort() || !b->estMort()){
        if(a == joueur->getPerso()) {
            auto etat = a->updateStatut();
            if (a->estMort()) {
                std::cout << "Victoire de " << b->getNom() << std::endl;
                std::cout << a << std::endl;
                b->reset();
                return;
            }
            if (!etat) {
                joueur->interactionEnCombat(b);
            }

            etat = b->updateStatut();
            if (b->estMort()) {
                std::cout << "Victoire de " << a->getNom() << std::endl;
                std::cout << a << std::endl;
                a->reset();
                return;
            }
            if (!etat) {
                b->actionIa(a);
            }

        }
        else{
            a->updateStatut();
            if (a->estMort()){
                b->setSante(b->getSanteMax());
                return;
            }
            a->actionIa(b);
            b->updateStatut();
            if(b->estMort()){
                a->setSante(a->getSanteMax());
                return;
            }
            b->actionIa(a);
        }
    }
}

bool Partie::finDePartie() const {
    if(joueur->getPerso()->estMort()){
        std::cout << "GAME OVER, VOUS N'AVEZ PAS SU RECONQUERIR VOTRE TRÔNE" << std::endl;
        return true;
    } else {
        for(long unsigned int i = 1; i < persoEnJeu.size(); i++){
            if(!persoEnJeu[i]->estMort()){
                return false;
            }
        }
        std::cout << "FÉLICITATION, VOUS AVEZ SU RECONQUERIR VOTRE TRÔNE, ET RAMENER LA PAIX DANS VOTRE ROYAUME" << std::endl;
        return true;
    }
}