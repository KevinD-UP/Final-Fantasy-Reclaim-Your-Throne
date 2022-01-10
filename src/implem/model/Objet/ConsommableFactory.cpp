//
// Created by kevin on 19/12/2021.
//

#include "../../../header/model/Objet/ConsommableFactory.h"

Consommable* ConsommableFactory::initConsommable(ConsommableType & consommableType){
    if(consommableType == CT_POTIONSOIN) {
        return (new PotionSoinFactory)->FactoryMethod();
    } else if (consommableType == CT_POTIONBRULURE){
        return (new PotionBrulureFactory)->FactoryMethod();
    } else if (consommableType == CT_POTIONPOISON){
        return (new PotionPoisonFactory)->FactoryMethod();
    } else if (consommableType == CT_POTIONSOMNOLENCE){
        return (new PotionSomnolenceFactory)->FactoryMethod();
    } else if (consommableType == CT_POTIONBERSERK){
        return (new PotionBerserkFactory)->FactoryMethod();
    } else if (consommableType == CT_POTIONAFFAIBLIE){
        return (new PotionAffaiblieFactory)->FactoryMethod();
    } else if (consommableType == CT_POTIONPROTEGER){
        return (new PotionProtegerFactory)->FactoryMethod();
    } else if (consommableType == CT_POTIONECORCHER){
        return (new PotionEcorcherFactory)->FactoryMethod();
    }
    else {
        throw std::invalid_argument( "Consommable inexistant");
    }
}

Consommable *PotionSoinFactory::FactoryMethod() const {
    return new PotionSoin("Potion de soin", OT_Consommable, "Regenère 25% de la vie max", CT_POTIONSOIN, CC_SELF);
}

Consommable *PotionBrulureFactory::FactoryMethod() const {
    return new PotionBrulure("Potion de brulure", OT_Consommable, "Brule l'ennemie pendant 3 tour", CT_POTIONBRULURE, CC_OTHER);
}

Consommable *PotionPoisonFactory::FactoryMethod() const {
    return new PotionPoison("Potion de poison", OT_Consommable, "Empoisonne l'ennemie pendant 3 tour", CT_POTIONPOISON, CC_OTHER);
}

Consommable *PotionSomnolenceFactory::FactoryMethod() const {
    return new PotionSomnolence("Potion de somnolence", OT_Consommable, "Endort l'ennemie pendant 2 tour", CT_POTIONSOMNOLENCE, CC_OTHER);
}

Consommable *PotionBerserkFactory::FactoryMethod() const {
    return new PotionBerserk("Potion de berserk", OT_Consommable, "Rend la cible Berserk pendant 3 tour",CT_POTIONBERSERK, CC_SELF);
}

Consommable *PotionAffaiblieFactory::FactoryMethod() const {
    return new PotionAffaiblie("Potion de fatigue", OT_Consommable, "Rend la cible Affaiblie pendant 3 tour",CT_POTIONAFFAIBLIE, CC_OTHER);
}

Consommable *PotionEcorcherFactory::FactoryMethod() const {
    return new PotionEcorcher("Potion de ecorchage", OT_Consommable, "Rend la cible Ecorcher pendant 3 tour",CT_POTIONECORCHER, CC_OTHER);
}

Consommable *PotionProtegerFactory::FactoryMethod() const {
    return new PotionProteger("Potion de protection", OT_Consommable, "Rend la cible Protéger pendant 3 tour",CT_POTIONPROTEGER, CC_SELF);
}