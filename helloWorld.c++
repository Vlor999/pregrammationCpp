#include <iostream>
#include <string>
#include <stdbool.h>
#include <list>

std::string sayHello(std::string name, int age)
{
    return "Hello : " + name + " you are aged of : " + std::to_string(age);
}

int calculSum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

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

void ex1()
{
    std::string name;
    int age;
    
    std::cout << "Type your age: ";
    std::cin >> age;
    
    std::cout << "Type your name: ";
    std::cin >> name;
    
    std::string str = sayHello(name, age);
    std::cout << str << std::endl;
}


void ex2(){
    int valeur1;
    int valeur2;

    std::cout << "Type the first value: ";
    std::cin >> valeur1;
    
    std::cout << "Type the second value: ";
    std::cin >> valeur2;
    operations op = operations(valeur1, valeur2);

    std::cout << "The sum of the 2 value is : " << op.sum() << std::endl;
    std::cout << "The prod of the 2 value is : " << op.prod() << std::endl;
    std::cout << "The diff of the 2 value is : " << op.diff() << std::endl;
    std::cout << "The divide of the 2 value is : " << op.divide() << std::endl;

    std:: cout << "The first value is : " << op.getV1() << std::endl;
    std:: cout << "The second value is : " << op.getV2() << std::endl;

}

void ex3(){
    int valeur1;

    std::cout << "Type the value: ";
    std::cin >> valeur1;

    bool isOdd = valeur1 % 2 == 0 ? false : true;
    std::cout << "The value is " << (isOdd ? "odd" : "even") << std::endl;
}

void ex4(){
    int n;

    std::cout << "Please enter a value: ";
    std::cin >> n;

    int sum = calculSum(n);
    std::cout << "The sum of the first " << n << " numbers is : " << sum << std::endl;
}

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
    
    void updateList(std::list<lettreCompte>& list, char lettre) {
        for (auto& l : list) {
            if (l.getLettre() == std::string(1, lettre)) {
                l.ajouteLettre();
                return;
            }
        }
    }
    
    void ex5() {
        std::list<lettreCompte> vowels = { lettreCompte("a"), lettreCompte("e"), lettreCompte("i"), lettreCompte("o"), lettreCompte("u"), lettreCompte("y") };
        std::string str;
    
        std::cout << "Please enter a string: ";
        std::cin >> str;
        // std::getline(std::cin, str);
        std::cout << "You entered: " << str << std::endl;
    
        for (char lettre : str) {
            updateList(vowels, lettre);
        }
        std::cout << std::endl;
    
        for (const auto& l : vowels) {
            std::cout << "The letter " << l.getLettre() << " appears " << l.getCompte() << " times" << std::endl;
        }
    }

void ex6(){

}

int main()
{
    std::cout << "ex 1 : " << std::endl;
    ex1();
    std::cout << "ex 2 : " << std::endl;
    ex2();
    std::cout << "ex 3 : " << std::endl;
    ex3();
    std::cout << "ex 4 : " << std::endl;
    ex4();
    std::cout << "ex 5 : " << std::endl;
    ex5();
    std::cout << "ex 6 : " << std::endl;
    ex6();

    return 0;
}
