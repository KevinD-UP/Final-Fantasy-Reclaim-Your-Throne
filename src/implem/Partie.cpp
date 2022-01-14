//
// Created by kevin on 18/12/2021.
//

#include "../header/Partie.h"

int Partie::tour = 0;

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
    tour++;
    std::vector < Personnage * > persosMort;
    for (auto personnage: persoEnJeu) {
        if (!personnage->estMort()) {
            Piece *pieceArrive = nullptr;
            if (personnage == joueur->getPerso()) {
                std::cout << "Tour du joueur: " << joueur->getPerso()->getNom() << std::endl;
                pieceArrive = joueur->interactionHorsCombat();
            } else {
                std::cout << "Tour de l'IA: " << personnage->getNom() << std::endl;
                pieceArrive = personnage->deplacementIA();
            }
            if (pieceArrive->combatPossible()) {
                Personnage *persoMort = deathBattle(pieceArrive->getVecPerso()[0], personnage);
                pieceArrive->removePerso(persoMort);
                persosMort.push_back(persoMort);
                if (finDePartie()) {
                    return;
                }
            } else {
                std::random_device seeder;
                std::mt19937 engine(seeder());
                std::uniform_int_distribution<int> dist(0, 10);
                int combatAleatoire = dist(engine);
                if (combatAleatoire > 8 && tour >= 10) {
                    PersonnageType TYPE_Mob = PT_Dragon;
                    Personnage *Dragon = PersonnageFactory::initPersonnage(TYPE_Mob, "Dragon",chateau);
                    Dragon->setPiece(pieceArrive);
                    Personnage *persoMort = deathBattle(Dragon, personnage);
                    if (persoMort->getPersonnageType() != PT_Dragon) {
                        pieceArrive->removePerso(persoMort);
                        retraitPersonnageMort(persoMort);
                        persosMort.push_back(persoMort);
                    }
                    delete Dragon;
                    Dragon = nullptr;
                    if (finDePartie()) {
                        return;
                    }
                } else if (combatAleatoire > 5 && tour >= 5) {
                    PersonnageType TYPE_Mob = PT_Loup;
                    Personnage *Loup = PersonnageFactory::initPersonnage(TYPE_Mob, "Loup",chateau);
                    Loup->setPiece(pieceArrive);
                    Personnage *persoMort = deathBattle(Loup, personnage);
                    if (persoMort->getPersonnageType() != PT_Loup) {
                        pieceArrive->removePerso(persoMort);
                        retraitPersonnageMort(persoMort);
                        persosMort.push_back(persoMort);
                    }
                    delete Loup;
                    Loup = nullptr;
                    if (finDePartie()) {
                        return;
                    }
                } else if (combatAleatoire >= 2) {
                    PersonnageType TYPE_Mob = PT_Gobelin;
                    Personnage *Gobelin = PersonnageFactory::initPersonnage(TYPE_Mob, "Gobelin",chateau);
                    Gobelin->setPiece(pieceArrive);
                    Personnage *persoMort = deathBattle(Gobelin, personnage);
                    if (persoMort->getPersonnageType() != PT_Gobelin) {
                        pieceArrive->removePerso(persoMort);
                        retraitPersonnageMort(persoMort);
                        persosMort.push_back(persoMort);
                    }
                    delete Gobelin;
                    Gobelin = nullptr;
                    if (finDePartie()) {
                        return;
                    }
                }
            }
        }
    }
    if (finDePartie()) {
        return;
    }
    for (auto persoMort: persosMort) {
        retraitPersonnageMort(persoMort);
        delete persoMort;
        persoMort = nullptr;
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

Partie::Partie(std::vector<Personnage*> persoEnJeuArg, const Joueur* joueurArg, const Map* mapArg)
    : persoEnJeu(std::move(persoEnJeuArg)),
        joueur(joueurArg),
        chateau(mapArg)
{}

Personnage* Partie::deathBattle(Personnage *a, Personnage *b) const {
    if(a == joueur->getPerso() || b == joueur->getPerso()){
        std::cout << "/!\\ Combat entre : " << a->getNom() << " et "
                  << b->getNom() << " /!\\ " << std::endl;
    }
    while(!a->estMort() || !b->estMort()){
        if(a == joueur->getPerso()) {
            auto etat = b->updateStatut();
            if (b->estMort()) {
                std::cout << "Victoire de " << a->getNom() << std::endl;
                std::cout << a->getNom() << " reçoit " << b->getLevel()*25  <<"EXP" << std::endl;
                a->victoire(b);
                std::cout << std::endl;
                return b;
            }
            if (!etat) {
                b->actionIa(a,joueur);
            }
            etat = a->updateStatut();
            if (a->estMort()) {
                std::cout << "Victoire de " << b->getNom() << std::endl;
                b->victoire(a);
                return a;
            }
            if (!etat) {
                joueur->interactionEnCombat(b);
            }

        }
        else if(b == joueur->getPerso()) {
            auto etat = b->updateStatut();
            if (b->estMort()) {
                std::cout << "Victoire de " << a->getNom() << std::endl;
                a->victoire(b);
                return b;
            }
            if (!etat) {
                joueur->interactionEnCombat(a);
            }
            etat = a->updateStatut();
            if (a->estMort()) {
                std::cout << "Victoire de " << b->getNom() << std::endl;
                std::cout << b->getNom() << " reçoit " << a->getLevel()*25  <<"EXP" << std::endl;
                b->victoire(a);
                std::cout << std::endl;
                return a;
            }
            if (!etat) {
               a->actionIa(b,joueur);
            }
        }
        else {
            auto etat = b->updateStatut();
            if (b->estMort()) {
                a->victoire(b);
                //std::cout << "Victoire de " << a->getNom() << std::endl;
                return b;
            }
            if (!etat) {
                b->actionIa(a,joueur);
            }
            etat = a->updateStatut();
            if (a->estMort()) {
                b->victoire(a);
                //std::cout << "Victoire de " << b->getNom() << std::endl;
                return a;
            }
            if (!etat) {
                a->actionIa(b,joueur);
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