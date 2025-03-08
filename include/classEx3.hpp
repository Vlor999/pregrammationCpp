#include <string>

class CompteBancaire{
    /*
    Un attribut solde
    Une méthode deposer(double montant)
    Une méthode retirer(double montant) (refuse si solde insuffisant)
    Une méthode afficherSolde()
    */

    double solde;

    public :
        CompteBancaire(){
            this->solde = 0;
        };

        void deposer(double montant){
            if (montant < 0){
                std::cout << "You must input some positive amount for a deposit\n";
                return;
            }
            
            this->solde += montant;
        }

        void retirer(double montant){
            if (montant < 0){
                std::cout << "You must input some positive amount for a withdraw\n";
                return;
            }
            if (this->solde >= montant){
                this->solde -= montant;
            }
            else{
                std::cout << "You must have enough money to withdraw the amout. You only have : " << this->solde << "\n";
                return;
            }
        }

        void afficherSolde(){
            std::cout <<  "The amount of money that you have is : " << this->solde << "\n";
        }
};

class Livre{
    private:
        std::string titre;
        std::string auteur;
        int annee;

    public:
        int getAnnee(){
            return this->annee;
        }

        void show(){
            std::cout << "Titre du livre : " << this->titre << "\nAuteur du livre : " << this->auteur << "\nAnnee du livre : " << this->annee << "\n\n";
        }

        Livre(const std::string titre, const std::string auteur, const int annee){
            this->titre = titre;
            this->auteur = auteur;
            this->annee = annee;
        };
};

struct Personne {
    std::string nom;
    int age;

    private:
        static std::string randomNom(){
            int tailleNom = rand() % 10;
            std::string lettre = "abcdefghijklmopqrstuvwxyz";
            std::string currentName = "";

            while(tailleNom > 0){
                currentName += lettre[rand()%27];
            }
            return currentName;
        }
    
    public : 
        Personne(std::string nom, int age){
            this->nom = nom;
            this->age = age;
        }

        Personne(){
            this->nom = randomNom();
            this->age = rand() % 101;
        }

        void show(){
            std::cout << "Nom : " << nom << "\nAge : " << age << "\n";
        }
};
