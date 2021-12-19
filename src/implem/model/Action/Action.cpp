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
        std::cout << receveur->getNom() << " recoit " << dommage << " de dommage" << std::endl;
    }
    /*if(effet != nullptr){
        receveur->pushStatut(effet);
        //std::cout << receveur->getNom() << " a été afflicté avec " << effet. << " de dommage" <<std::endl;
    }*/
}