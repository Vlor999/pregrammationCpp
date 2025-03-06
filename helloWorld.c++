#include <iostream>
#include <string>
#include <stdbool.h>
#include <list>
#include <cstdlib>

#include "class.hpp"

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

void updateList(std::list<lettreCompte>& list, char lettre) {
    for (auto& l : list) {
        if (l.getLettre() == std::string(1, lettre)) {
            l.ajouteLettre();
            return;
        }
    }
}

int ex1()
{
    std::string name;
    int age;
    
    std::cout << "Type your age: ";
    std::cin >> age;
    
    std::cout << "Type your name: ";
    std::cin >> name;
    
    std::string str = sayHello(name, age);
    std::cout << str << std::endl;
    return EXIT_SUCCESS;
}


int ex2(){
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
    return EXIT_SUCCESS;
}

int ex3(){
    int valeur1;

    std::cout << "Type the value: ";
    std::cin >> valeur1;

    bool isOdd = valeur1 % 2 == 0 ? false : true;
    std::cout << "The value is " << (isOdd ? "odd" : "even") << std::endl;
    return EXIT_SUCCESS;
}

int ex4(){
    int n;

    std::cout << "Please enter a value: ";
    std::cin >> n;

    int sum = calculSum(n);
    std::cout << "The sum of the first " << n << " numbers is : " << sum << std::endl;
    return EXIT_SUCCESS;
}
    
int ex5() {
    std::list<lettreCompte> vowels = { lettreCompte("a"), lettreCompte("e"), lettreCompte("i"), lettreCompte("o"), lettreCompte("u"), lettreCompte("y") };
    std::string str;

    std::cout << "Please enter a string: ";
    
    if (!std::getline(std::cin, str)){
        return EXIT_FAILURE;
    }
    if (str.empty()){
        std::getline(std::cin, str);
    }
    std::cout << "You entered: " << str << std::endl;

    for (char lettre : str) {
        updateList(vowels, lettre);
    }
    std::cout << std::endl;

    for (const auto& l : vowels) {
        std::cout << "The letter " << l.getLettre() << " appears " << l.getCompte() << " times" << std::endl;
    }
    return EXIT_SUCCESS;
}

int ex6(){
    int n;
    std::cout << "Please enter the number of * that we must put per row and column : ";
    std::cin >> n;

    for (int l = 1; l <= n; l++){
        for (int c = 1; c <= n; c++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

int ex7(){

    int randomValue = rand() % 101;

    int currentValue = -1;

    while (randomValue != currentValue){
        std::cout << "Please enter a value : ";
        std::cin >> currentValue;

        if (currentValue > randomValue){
            std::cout << "Your value is too high" << std::endl;
        }
        else if (currentValue < randomValue){
            std::cout << "Your value is too low" << std::endl;
        }
        else {
            std::cout << currentValue << " was the correct value" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}

int main()
{
    int isSucces = 0;
    std::cout << "ex 1 : " << std::endl;
    isSucces = ex1() + isSucces;
    std::cout << "ex 2 : " << std::endl;
    isSucces = ex2() + isSucces;
    std::cout << "ex 3 : " << std::endl;
    isSucces = ex3() + isSucces;
    std::cout << "ex 4 : " << std::endl;
    isSucces = ex4() + isSucces;
    std::cout << "ex 5 : " << std::endl;
    isSucces = ex5() + isSucces;
    std::cout << "ex 6 : " << std::endl;
    isSucces = ex6() + isSucces;
    std::cout << "ex 7 : " << std::endl;
    isSucces = ex7() + isSucces;

    return isSucces > 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
