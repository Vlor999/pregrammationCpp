#include <iostream>
#include <vector>
#include <functional>

std::string getCurrent(std::string Phrase, int positionDebut, int tailleMot){
    std::string output = "";
    for (int i =0; i < tailleMot; i++){
        output += Phrase[positionDebut+i];
    }
    return output;
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
        std::cout << "TODO\n"; 
        int tailleTableau = 0;
        std::cout << "Quelle est la taille du tableau : ";
        std::cin >> tailleTableau;

        int* tableau = new int[tailleTableau];
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

        delete [] tableau;

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
        std::cout << "TODO\n"; 
        return EXIT_SUCCESS; 
    }

    static int ex4() { 
        std::cout << "TODO\n"; 
        return EXIT_SUCCESS; 
    }

    static int ex5() { 
        std::cout << "TODO\n"; 
        return EXIT_SUCCESS; 
    }

    static int ex6() { 
        std::cout << "TODO\n"; 
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
