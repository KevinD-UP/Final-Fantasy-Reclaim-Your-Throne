//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_CONSOMMABLE_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_CONSOMMABLE_H

#include "Objet.h"
#include "../Personnage/Personnage.h"

enum ConsommableType {
    CT_POTIONSOIN,
    CT_POTIONBRULURE,
    CT_POTIONPOISON,
    CT_POTIONSOMNOLENCE
};

class Consommable : public Objet {

private:
    Consommable(const std::string, const ObjetType, std::string, ConsommableType);
    ConsommableType typeConsommable;

public:
    __attribute__((unused)) ConsommableType getTypeConsommable() const;
    void appliquerEffet(Personnage *) override;
    void enleverEffet(Personnage *) override;
    virtual void appliquerConsommable(Personnage *) = 0;
    friend class PotionSoin;
    friend class PotionBrulure;
    friend class PotionPoison;
    friend class PotionSomnolence;
};

class PotionSoin : public Consommable {

private:
    PotionSoin(const std::string&, const ObjetType, std::string, ConsommableType, int);
    const int pouvoirDeSoin = 10;

public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionSoinFactory;
};

class PotionBrulure : public Consommable{
private:
    PotionBrulure(const std::string&, const ObjetType, std::string, ConsommableType);

public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionBrulureFactory;
};

class PotionPoison : public Consommable{
private:
    PotionPoison(const std::string&, const ObjetType, std::string, ConsommableType);

public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionPoisonFactory;
};

class PotionSomnolence : public Consommable{
private:
    PotionSomnolence(const std::string&, const ObjetType, std::string, ConsommableType);
public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionSomnolenceFactory;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_CONSOMMABLE_H
