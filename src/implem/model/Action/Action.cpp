//
// Created by anthony on 12/12/2021.
//
#include "../../../header/model/Action/Action.h"

Action::Action(Personnage* lanceurArg, Personnage* receveurArg, std::string nomArg, int dommageArg, Type typeArg)
: type(typeArg), lanceur(lanceurArg), receveur(receveurArg), nom(nomArg), dommage(dommageArg) {}

void Action::utilisation(){
    if (type == Offensive) {
        std::cout << "L'action " << nom << " a été utiliser sur " << receveur->getNom() << std::endl;
        receveur->setSante(receveur->getSante() - dommage);
        std::cout << receveur->getNom() << " recoit " << dommage << " de dommage" << std::endl << std::endl;
    }
    if (type == Defensive) {
        std::cout << "L'action " << nom << " a été utiliser sur " << lanceur->getNom() << std::endl;
        lanceur->setSante(lanceur->getSante() + dommage);
        std::cout << receveur->getNom() << " recoit " << dommage << " de soin" << std::endl << std::endl;
    }

}