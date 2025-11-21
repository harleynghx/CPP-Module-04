#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

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

// void testWrongPolymorphism() {
//     std::cout << "\n=== Testing Wrong Polymorphism ===" << std::endl;
    
//     const WrongAnimal* wrongMeta = new WrongAnimal();
//     const WrongAnimal* wrongCat = new WrongCat();
    
//     std::cout << wrongCat->getType() << " " << std::endl;
    
//     wrongCat->makeSound(); // Will output WrongAnimal sound (no polymorphism)
//     wrongMeta->makeSound(); // Will output WrongAnimal sound
    
//     delete wrongMeta;
//     delete wrongCat;
// }




int main() {
    testBasicPolymorphism();
    // testWrongPolymorphism();
    
    return 0;
}