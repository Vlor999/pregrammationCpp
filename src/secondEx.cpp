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
        std::string Phrase = "Ceci est un test. Ce test est simple." ;
        std::string Mot = "test";
        int tailleMot = Mot.length();
        int Resultat = 2;

        int compteur = 0;

        for (int i = 0; i < Phrase.length() - tailleMot + 1; i++){
            std::string currentString = getCurrent(Phrase, i, tailleMot);
            if (currentString == Mot){
                compteur++;
            }
        }

        if (Resultat == compteur){
            std::cout << "Tout est bon par ici";
        }

        return Resultat == compteur ? EXIT_SUCCESS : EXIT_FAILURE; 
    }
    static int ex2() { 
    std::cout << "TODO\n"; 
        return EXIT_SUCCESS; 
    }
    static int ex3() { 
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
