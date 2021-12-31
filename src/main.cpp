//
// Created by kevin on 11/12/2021.
//

#include "header/model/Personnage/Personnage.h"
#include "header/model/Personnage/PersonnageFactory.h"
#include "header/model/Joueur/Joueur.h"
#include "header/Partie.h"

#include  <random>
#include  <iterator>

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

PersonnageType TYPE_Guerrier = PT_Guerrier;
PersonnageType TYPE_Amazone = PT_Amazone;
PersonnageType TYPE_Moine = PT_Moine;
PersonnageType TYPE_Sorcier = PT_Sorcier;

static vector<std::string> names = {
        "Aien Xilcan",
        "Gorwin Fenroris",
        "Sinaht Zinnorin",
        "Raeran Mirasatra",
        "Volodar Petwraek",
        "Khatar Lorabella",
        "Fenian Naezumin",
        "Hagmar Xyrneiros",
        "Folduin Triszeiros",
        "Alas Keaynore",
        "Gaeleath Valrona",
        "Elen Shastina",
        "Cithrel Glynceran",
        "Faelyn Helewarin",
        "Khyrmin Jokian",
        "Ilphas Gilmaer",
        "Elauthin Adric",
        "Eldaerenth Roceran",
        "Artin Zylra",
        "Nym Morcaryn",
        "Ynaselle Waesdi",
        "Ilyana Caihice",
        "Nephinae Zumfaren",
        "Liluth Herlee",
        "Gwynnestri Qizana",
        "Nabeora Caivalur",
        "Saria Iarnelis",
        "Tehlarissa Miraren",
        "Shanyrria Yinkian",
        "Daethie Xyrran",
        "Aegnor",
        "Amras",
        "Amrod",
        "Anairë",
        "Angrod",
        "Aranwë",
        "Aredhel",
        "Caranthir",
        "Celebrimbor",
        "Celegorm",
        "Curufin",
        "Ecthelion",
        "Edrahil",
        "Elemmakil",
        "Elenwë",
        "Enerdhil",
        "Erestor",
        "Fëanor",
        "Finarfin",
        "Findis",
        "Finduilas",
        "Fingolfin",
        "Fingon",
        "Finrod",
        "Finwë",
        "Galadriel",
        "Gelmir",
        "Gildor",
        "Gil-galad",
        "Glorfindel",
        "Guilin",
        "Gwindor",
        "Idril",
        "Maedhros",
        "Maeglin",
        "Maglor",
        "Mahtan",
        "Míriel",
        "Nerdanel",
        "Orodreth",
        "Rúmil",
        "Turgon",
        "Voronwë",
        "Aldor",
        "Baldor",
        "Brego",
        "Brytta",
        "Ceorl",
        "Déor",
        "Déorwine",
        "Dúnhere",
        "Elfhelm",
        "Éofor",
        "Éomer",
        "Éomund",
        "Eorl le Jeune",
        "Éowyn",
        "Erkenbrand",
        "Fastred",
        "Folca",
        "Folcwine",
        "Folcred",
        "Fréa",
        "Fréaláf",
        "Fréawine",
        "Freca",
        "Gálmód",
        "Gléowine",
        "Goldwine",
        "Gram",
        "Gríma",
        "Grimbold",
        "Guthláf",
        "Háma",
        "Helm",
        "Herefara",
        "Herubrand",
        "Horn",
        "Thengel",
        "Théoden",
        "Théodred",
        "Théodwyn",
        "Walda",
        "Wídfara"
};

int main(){

    std::string nomPerso;
    int choixPerso;
    Joueur* joueur;
    Personnage* personnageJoueur;
    Personnage* Ennemie1;
    Personnage* Ennemie2;
    Personnage* Ennemie3;

    //TODO: INIT LES PERSO EN FONCTION DU JOUEUR

    std::cout << "Bienvenue sur FINAL FANTASY RECLAIM YOUR THRONE" << std::endl;
    std::cout << "Veuillez écrire le nom de votre personnage : " << std::endl;
    std::cin >> nomPerso;
    std::cout << "Veuillez choisir la classe de votre personnage : " << std::endl;
    std::cout << "1 - Guerrier " << std::endl;
    std::cout << "2 - Amazone" << std::endl;
    std::cout << "3 - Moine " << std::endl;
    std::cout << "4 - Sorcier " << std::endl;

    while (!(choixPerso <= 4 && choixPerso >= 1)) {
        std::cin >> choixPerso;
        if(!(choixPerso <= 4 && choixPerso >= 1)){
            std::cout << "Erreur personnage non existant" << std::endl;
        }
    }

    if(choixPerso == 1){
        personnageJoueur = PersonnageFactory::initPersonnage(TYPE_Guerrier, nomPerso);
        joueur = new Joueur(personnageJoueur);
        std::cout << "Votre personnage a été crée" << std::endl;
        std::cout << "Création des personnages non joueur..." << std::endl;
        ennemie1 = PersonnageFactory::initPersonnage(TYPE_Sorcier,*select_randomly(names.begin(), names.end()));
        ennemie2 = PersonnageFactory::initPersonnage(TYPE_Moine,*select_randomly(names.begin(), names.end()));
        ennemie3 = PersonnageFactory::initPersonnage(TYPE_Amazone,*select_randomly(names.begin(), names.end()));
    }else if (choixPerso == 2){
        personnageJoueur = PersonnageFactory::initPersonnage(TYPE_Amazone, nomPerso);
        joueur = new Joueur(personnageJoueur);
        std::cout << "Votre personnage a été crée" << std::endl;
        std::cout << "Création des personnages non joueur..." << std::endl;
        ennemie1 = PersonnageFactory::initPersonnage(TYPE_Guerrier,*select_randomly(names.begin(), names.end()));
        ennemie2 = PersonnageFactory::initPersonnage(TYPE_Moine,*select_randomly(names.begin(), names.end()));
        ennemie3 = PersonnageFactory::initPersonnage(TYPE_Amazone,*select_randomly(names.begin(), names.end()));
    }else if (choixPerso == 3){
        personnageJoueur = PersonnageFactory::initPersonnage(TYPE_Moine, nomPerso);
        joueur = new Joueur(personnageJoueur);
        std::cout << "Votre personnage a été crée" << std::endl;
        std::cout << "Création des personnages non joueur..." << std::endl;
        ennemie1 = PersonnageFactory::initPersonnage(TYPE_Sorcier,*select_randomly(names.begin(), names.end()));
        ennemie2 = PersonnageFactory::initPersonnage(TYPE_Guerrier,*select_randomly(names.begin(), names.end()));
        ennemie3 = PersonnageFactory::initPersonnage(TYPE_Amazone,*select_randomly(names.begin(), names.end()));
    }else if(choixPerso == 4){
        personnageJoueur = PersonnageFactory::initPersonnage(TYPE_Sorcier, nomPerso);
        joueur = new Joueur(personnageJoueur);
        std::cout << "Votre personnage a été crée" << std::endl;
        std::cout << "Création des personnages non joueur..." << std::endl;
        ennemie1 = PersonnageFactory::initPersonnage(TYPE_Sorcier,*select_randomly(names.begin(), names.end()));
        ennemie2 = PersonnageFactory::initPersonnage(TYPE_Moine,*select_randomly(names.begin(), names.end()));
        ennemie3 = PersonnageFactory::initPersonnage(TYPE_Guerrier,*select_randomly(names.begin(), names.end()));
    }

    Map* carte = new Map();

    Partie partie = Partie({personnageJoueur, ennemie1, ennemie2, ennemie3}, joueur , carte);
    partie.startToPlay();
    //partie.deathBattle(personnageJoueur,sorcier);
    /*Piece *test = new Piece();
    Piece *test2 = new Piece();

    std::cout<<"Piece 0"<<std::endl;
    test->print();
    std::cout<<"Piece 1"<<std::endl;
    test2->print();*/

   // std::cout << "Fin de la partie" << std::endl;
}

