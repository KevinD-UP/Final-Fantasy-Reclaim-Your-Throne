//
// Created by anthony on 12/12/2021.
//
#include "../../../header/model/Action/Action.h"

Action::Action(Personnage* lanceur,Personnage* receveur,std::string nom,int dommage,std::string type){
    this->type = type;
    this->lanceur = lanceur;
    this->receveur = receveur;
    this->nom = nom;
    this->dommage = dommage;
    //this->effet = effet;
}

void Action::utilisation(){
    if (type == "offensive") {
        std::cout << "L'action " << nom << " a été utiliser sur " << receveur->getNom() << std::endl;
        receveur->setSante(receveur->getSante() - dommage);
        std::cout << receveur->getNom() << " recoit " << dommage << " de dommage" << std::endl;
    }
    /*if(effet != nullptr){
        receveur->pushStatut(effet);
        //std::cout << receveur->getNom() << " a été afflicté avec " << effet. << " de dommage" <<std::endl;
    }*/
}