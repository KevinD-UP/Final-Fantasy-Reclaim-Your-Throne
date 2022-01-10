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
    CT_POTIONSOMNOLENCE,
    CT_POTIONBERSERK,
    CT_POTIONECORCHER,
    CT_POTIONAFFAIBLIE,
    CT_POTIONPROTEGER
};

enum ConsommableCible {
    CC_SELF,
    CC_OTHER
};
class Consommable : public Objet {

private:
    Consommable(const std::string, const ObjetType, std::string, ConsommableType, ConsommableCible);
    ConsommableType typeConsommable;
    ConsommableCible cibleConsommable;

public:
    __attribute__((unused)) ConsommableType getTypeConsommable() const;
    void appliquerEffet(Personnage *) override;
    void enleverEffet(Personnage *) override;
    bool checkCible() override;
    virtual void appliquerConsommable(Personnage *) = 0;
    friend class PotionSoin;
    friend class PotionBrulure;
    friend class PotionPoison;
    friend class PotionSomnolence;
    friend class PotionBerserk;
    friend class PotionAffaiblie;
    friend class PotionEcorcher;
    friend class PotionProteger;
    friend class PotionChallenge;
};

class PotionSoin : public Consommable {

private:
    PotionSoin(const std::string&, const ObjetType, std::string, ConsommableType, ConsommableCible);

public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionSoinFactory;
};

class PotionBrulure : public Consommable{
private:
    PotionBrulure(const std::string&, const ObjetType, std::string, ConsommableType ,ConsommableCible);

public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionBrulureFactory;
};

class PotionPoison : public Consommable{
private:
    PotionPoison(const std::string&, const ObjetType, std::string, ConsommableType, ConsommableCible);

public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionPoisonFactory;
};

class PotionSomnolence : public Consommable{
private:
    PotionSomnolence(const std::string&, const ObjetType, std::string, ConsommableType, ConsommableCible);
public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionSomnolenceFactory;
};

class PotionBerserk : public Consommable{
private:
    PotionBerserk(const std::string&, const ObjetType, std::string, ConsommableType, ConsommableCible);
public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionBerserkFactory;
};

class PotionAffaiblie: public Consommable{
private:
    PotionAffaiblie(const std::string&, const ObjetType, std::string, ConsommableType, ConsommableCible);
public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionAffaiblieFactory;
};

class PotionEcorcher : public Consommable{
private:
    PotionEcorcher(const std::string&, const ObjetType, std::string, ConsommableType, ConsommableCible);
public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionEcorcherFactory;
};

class PotionProteger : public Consommable{
private:
    PotionProteger(const std::string&, const ObjetType, std::string, ConsommableType, ConsommableCible);
public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionProtegerFactory;
};

class PotionChallenge : public Consommable{
private:
    PotionChallenge(const std::string&, const ObjetType, std::string, ConsommableType, ConsommableCible);
public:
    void appliquerConsommable(Personnage *) override;
    friend class PotionProtegerFactory;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_CONSOMMABLE_H
