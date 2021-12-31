//
// Created by kevin on 18/12/2021.
//

#include "../header/Partie.h"

void Partie::startToPlay() {
    std::cout << "Partie Lancée" << std::endl;
    int count = 0;
    for(auto personnage: persoEnJeu){
        if(count == 0) {
            personnage->setPiece(chateau->getMap()[0][0]);
            chateau->getMap()[0][0]->pushPerso(personnage);
        }
        else if (count == 1) {
            personnage->setPiece(chateau->getMap()[0][3]);
            chateau->getMap()[0][3]->pushPerso(personnage);
        }
        else if (count == 2) {
            personnage->setPiece(chateau->getMap()[3][0]);
            chateau->getMap()[3][0]->pushPerso(personnage);
        }
        else if (count == 3) {
            personnage->setPiece(chateau->getMap()[3][3]);
            chateau->getMap()[3][3]->pushPerso(personnage);
        }
        count++;
    }
    routine();
}

void Partie::routine() {
    for(auto personnage: persoEnJeu){
        Piece * pieceArrive = nullptr;
        if(personnage == joueur->getPerso()){
            std::cout << "Tour du joueur: " << joueur->getPerso()->getNom() << std::endl;
            pieceArrive = joueur->interactionHorsCombat();
        } else {
            std::cout << "Tour de l'IA: " << personnage->getNom() << std::endl;
            pieceArrive = personnage->deplacementIA();
        }
        if(pieceArrive->combatPossible()) {
            if(personnage == joueur->getPerso()) {
                std::cout << "Combat entre : " << personnage->getNom() << "et"
                          << pieceArrive->getVecPerso()[0]->getNom() << std::endl;
            }
            Personnage * persoMort = deathBattle(personnage, pieceArrive->getVecPerso()[0]);
            //TODO: remove from la piece arrive
            retraitPersonnageMort(persoMort);
            if(finDePartie()){
                return;
            }
        }
    }
    routine();
}

std::vector<Personnage *> Partie::getPersoEnJeu() const {
    return persoEnJeu;
}

const Joueur* Partie::getJoueur() const {
    return joueur;
}

const Map* Partie::getChateau() const {
    return chateau;
}

Partie::Partie(std::vector<Personnage*> persoEnJeuArg, const Joueur* joueurArg, const Map* mapArg) : persoEnJeu(std::move(persoEnJeuArg)), joueur(joueurArg), chateau{mapArg}
{}

Personnage* Partie::deathBattle(Personnage *a, Personnage *b) const {
    std::cout << "Combat contre " << a->getNom() << " et " << b->getNom() << std::endl;
    while(!a->estMort() || !b->estMort()){
        if(a == joueur->getPerso()) {
            auto etat = a->updateStatut();
            etat = b->updateStatut();
            if (b->estMort()) {
                std::cout << "Victoire de " << a->getNom() << std::endl;
                std::cout << a << std::endl;
                a->reset();
                return b;
            }
            if (!etat) {
                b->actionIa(a);
            }
            if (a->estMort()) {
                std::cout << "Victoire de " << b->getNom() << std::endl;
                std::cout << a << std::endl;
                b->reset();
                return a;
            }
            if (!etat) {
                joueur->interactionEnCombat(b);
            }

        }
        else if(b == joueur->getPerso()) {
            auto etat = b->updateStatut();
            if (b->estMort()) {
                std::cout << "Victoire de " << b->getNom() << std::endl;
                std::cout << a << std::endl;
                b->reset();
                return a;
            }
            if (!etat) {
                b->actionIa(a);
            }
            etat = a->updateStatut();
            if (a->estMort()) {
                std::cout << "Victoire de " << a->getNom() << std::endl;
                std::cout << a << std::endl;
                a->reset();
                return b;
            }
            if (!etat) {
                joueur->interactionEnCombat(a);
            }
        }
        else {
            auto etat = a->updateStatut();
            etat = b->updateStatut();
            b->updateStatut();
            if (b->estMort()) {
                a->setSante(a->getSanteMax());
                std::cout << "Victoire de " << a->getNom() << std::endl;
                return b;
            }
            if (!etat) {
                b->actionIa(a);
            }
            etat = a->updateStatut();
            if (a->estMort()) {
                b->setSante(b->getSanteMax());
                std::cout << "Victoire de " << b->getNom() << std::endl;
                return a;
            }
            if (!etat) {
                a->actionIa(b);
            }

        }
    }
    return nullptr;
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

void Partie::retraitPersonnageMort(Personnage* personnageMort) {
    persoEnJeu.erase(std::remove(persoEnJeu.begin(), persoEnJeu.end(), personnageMort), persoEnJeu.end());
}