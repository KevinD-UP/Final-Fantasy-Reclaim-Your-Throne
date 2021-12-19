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
    } else {
        throw std::invalid_argument( "Consommable inexistant");
    }
}

Consommable *PotionSoinFactory::FactoryMethod() const {
    return new PotionSoin("Potion de soin", OT_Consommable, "C'est une potion de soin : Regenere 10HP", CT_POTIONSOIN, 10);
}

Consommable *PotionBrulureFactory::FactoryMethod() const {
    return new PotionBrulure("Potion de brulure", OT_Consommable, "C'est une potion de brulure : ", CT_POTIONBRULURE);
}

Consommable *PotionPoisonFactory::FactoryMethod() const {
    return new PotionPoison("Potion de poison", OT_Consommable, "C'est une potion de poison : ", CT_POTIONPOISON);
}

Consommable *PotionSomnolenceFactory::FactoryMethod() const {
    return new PotionSomnolence("Potion de somnolence", OT_Consommable, "C'est une potion de somnolence : ", CT_POTIONSOMNOLENCE);
}
