#include <string>

class operations{
    private:
        int v1;
        int v2;

    public:
        int sum() 
        {
            return this->v1 + this->v2;
        };
        
        int prod(){
            return this->v1 * this->v2;
        };

        int diff(){
            return this->v1 - this->v2;
        };

        int divide(){
            return this->v1 / this->v2;
        };

        int getV1(){
            return this->v1;
        };

        int getV2(){
            return this->v2;
        };

    operations(int v1, int v2){
        this->v1 = v1;
        this->v2 = v2;
    };
};

class lettreCompte {
    private:
        std::string lettre;
        int count;
    
    public:
        void ajouteLettre() {
            this->count++;
        }
    
        int getCompte() const {
            return this->count;
        }
    
        std::string getLettre() const {
            return this->lettre;
        }
    
        lettreCompte(std::string lettre) : lettre(lettre), count(0) {}
};