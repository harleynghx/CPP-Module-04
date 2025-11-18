#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testBasicPolymorphism() {
    std::cout << "=== Testing Basic Polymorphism ===" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Should output cat sound
    j->makeSound(); // Should output dog sound
    meta->makeSound(); // Should output animal sound
    
    delete meta;
    delete j;
    delete i;
}

void testWrongPolymorphism() {
    std::cout << "\n=== Testing Wrong Polymorphism ===" << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound(); // Will output WrongAnimal sound (no polymorphism)
    wrongMeta->makeSound(); // Will output WrongAnimal sound
    
    delete wrongMeta;
    delete wrongCat;
}

void testCopyAndAssignment() {
    std::cout << "\n=== Testing Copy and Assignment ===" << std::endl;
    
    Dog originalDog;
    Dog copiedDog(originalDog);
    Dog assignedDog;
    assignedDog = originalDog;
    
    Cat originalCat;
    Cat copiedCat(originalCat);
    Cat assignedCat;
    assignedCat = originalCat;
}

void testArrays() {
    std::cout << "\n=== Testing Animal Array ===" << std::endl;
    
    const int arraySize = 4;
    Animal* animals[arraySize];
    
    // Create half dogs, half cats
    for (int i = 0; i < arraySize; ++i) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    
    // Test polymorphism
    for (int i = 0; i < arraySize; ++i) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
    
    // Clean up
    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];
    }
}

int main() {
    testBasicPolymorphism();
    testWrongPolymorphism();
    testCopyAndAssignment();
    testArrays();
    
    return 0;
}