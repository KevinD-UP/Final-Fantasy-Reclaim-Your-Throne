//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Objet/Equipement.h"

Equipement::Equipement
    (std::string nom_arg,
     ObjetType objetType_arg,
     std::string description_arg,
     PersonnageType personnageType_arg,
     EquipementType equipementType_arg,
     bool estEquipe_arg, int buffDeClasse_arg, int buffAutre_arg)
    : Objet(nom_arg, objetType_arg, description_arg),
    bonusClass(personnageType_arg),
    typeEquipement(equipementType_arg),
    estEquipe(estEquipe_arg),
    buffDeClasse(buffDeClasse_arg),
    buffAutre(buffAutre_arg)
{}

void Equipement::appliquerEffet(Personnage *cible) {
    if(!estEquipe) {
        if(typeEquipement == ET_ARME) {
            if (this->bonusClass == cible->getPersonnageType()) {
                cible->setAttaque(cible->getAttaque() + buffDeClasse);
            } else {
                cible->setAttaque(cible->getAttaque() + buffAutre);
            }
        }
        if(typeEquipement == ET_PROTECTION) {
            if (this->bonusClass == cible->getPersonnageType()) {
                cible->setDefense(cible->getDefense() + buffDeClasse);
            } else {
                cible->setDefense(cible->getDefense() + buffAutre);
            }
        }
        estEquipe = true;
    }
}

