#include <iostream>
#include <vector>
#include <functional>

#include "classEx3.hpp"

std::string getCurrent(std::string Phrase, int positionDebut, int tailleMot) {
    return Phrase.substr(positionDebut, tailleMot);
}

class Solution {
public:
    static int ex1() {
        // On cherche ici a compter le nombre de fois ou un mot se trouve dans une phrase
        std::string Phrase = "Ceci est un test. Ce test est simple." ;
        std::string Mot = "test";
        int tailleMot = Mot.length();
        int Resultat = 2;

        int compteur = 0;

        for (unsigned long i = 0; i <= Phrase.length() - tailleMot; i++){
            std::string currentString = getCurrent(Phrase, i, tailleMot);
            if (currentString == Mot){
                compteur++;
            }
        }

        if (Resultat == compteur){
            std::cout << "Tout est bon par ici\n";
        }

        return Resultat == compteur ? EXIT_SUCCESS : EXIT_FAILURE; 
    }

    static int ex2() { 
        /*
        Crée un programme qui :
            Demande un nombre n à l'utilisateur.
            Alloue dynamiquement un tableau de n entiers.
            Demande à l'utilisateur de remplir les n valeurs.
            Affiche la somme et la moyenne des valeurs.
            Libère la mémoire à la fin. 
        */
        int tailleTableau = 0;
        std::cout << "Quelle est la taille du tableau : ";
        std::cin >> tailleTableau;

        std::vector<int> tableau(tailleTableau);
        int valeurUtilisateur;
        float moyenne = 0;
        int somme = 0;
        
        for (int i=0; i < tailleTableau; i++){
            std::cout << "Quelle est la valeur du tableau en position " << i << " : ";
            std::cin >> valeurUtilisateur;
            tableau[i] = valeurUtilisateur;
            somme += valeurUtilisateur;
        }

        for (int i=0; i < tailleTableau; i++){
            std::cout << (i == 0 ? "[" : " ") << tableau[i] << (i == tailleTableau - 1 ? "]\n" :",");
        }

        std::cout << "La somme  : " << somme << "\n";
        moyenne = (float)somme / (float)tailleTableau;
        std::cout << "La moyenne  : " << moyenne << "\n";

        return EXIT_SUCCESS; 
    }

    static int ex3() { 
        /*
        Crée une classe CompteBancaire avec :
            Un attribut solde
            Une méthode deposer(double montant)
            Une méthode retirer(double montant) (refuse si solde insuffisant)
            Une méthode afficherSolde()
        */
        CompteBancaire compte = CompteBancaire();
        compte.afficherSolde();
        compte.retirer(50);
        compte.deposer(100);
        compte.afficherSolde();
        compte.retirer(10);
        compte.afficherSolde();
        compte.retirer(-10);
        compte.afficherSolde();
        return EXIT_SUCCESS; 
    }

    static bool comp(Livre l1, Livre l2){
        int annee1 = l1.getAnnee();
        int annee2 = l2.getAnnee();
        return annee1 < annee2;
    };
    
    static void afficheLivre(std::vector<Livre> listLivre){
        sort(listLivre.begin(), listLivre.end(), comp);
        for (Livre l :listLivre){
            l.show();
        }
    };

    static int ex4() { 
        /*
        Crée une classe Livre avec :
            titre (string)
            auteur (string)
            annee (int)
            Stocke plusieurs Livre dans un std::vector et ajoute une fonction pour afficher les livres triés par année.*/
        Livre livre1 = Livre("Les fleurs du mal", "Baudelaire", 1786);
        Livre livre2 = Livre("Alcool", "Voltaire", 1986);
        Livre livre3 = Livre("Les pleurs de l'homme", "willem", 2025);
        std::vector<Livre> listLivre = {livre1, livre2, livre3};
        afficheLivre(listLivre);
        return EXIT_SUCCESS; 
    }

    static int ex5() { 
        /*
        Stocke plusieurs Personne dans un std::vector.
        Trie la liste par âge en utilisant std::sort avec une fonction lambda.*/
        std::vector<Personne> listPersonne = {Personne("Papi", 85), Personne("willem", 22), Personne("chloe", 24)};

        /*
        Lambda format : [list of eleemnt ot use](args){function}*/
        sort(listPersonne.begin(), listPersonne.end(), [](const Personne& p1,const Personne& p2){return p1.age < p2.age;});
        for (Personne p : listPersonne){
            p.show();
        }

        return EXIT_SUCCESS; 
    }

    static int ex6() { 
        srand(time(0));
        int valeur = rand() % 101;
        int nombreEssai = 10;
        bool isSuccess = false;
        int currentValue;

        while(nombreEssai > 0 && !isSuccess){
            std::cout << "Quelle est votre valeur : ";
            std::cin >> currentValue;
            isSuccess = currentValue == valeur;
            if (!isSuccess){
                std::cout << "Vous êtes " << (std::abs(currentValue - valeur) > 10 ? "tres " : "") << (currentValue > valeur ? "au dessus" : "en dessous") << "\n";
            }
            else{
                std::cout << "Bravo la valeu etait  : " << valeur << std::endl;
            }
            nombreEssai--;
        }

        if(!isSuccess){
            std::cout << "Trop d'essaie, valeur etait : " << valeur << std::endl;
        }

        return EXIT_SUCCESS; 
    }
};

int main() {
    int isSuccess = 0;

    std::vector<std::function<int()>> functions = {
        {std::bind(&Solution::ex1)},
        {std::bind(&Solution::ex2)},
        {std::bind(&Solution::ex3)},
        {std::bind(&Solution::ex4)},
        {std::bind(&Solution::ex5)},
        {std::bind(&Solution::ex6)}
    };

    int count = 1;
    for (const auto& func : functions) {
        std::cout << "Executing: ex " << count << "\n";
        isSuccess += func();
        count++;
    }

    return isSuccess > 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
