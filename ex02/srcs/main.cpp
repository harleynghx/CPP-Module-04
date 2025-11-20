#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include <iostream>

int main() {
    std::cout << "=== EX02 TEST: Abstract Animal Class ===" << std::endl;
    
    // Test 1: Try to create Animal (should cause compile error)
    std::cout << "1. Testing that Animal cannot be instantiated..." << std::endl;

    // Animal animal;                    // Should NOT compile
    // Animal* animal = new Animal();    // Should NOT compile

    std::cout << "✅ Animal class is abstract - cannot instantiate directly" << std::endl;
    std::cout << std::endl;
    
    // Test 2: Everything else should work exactly as before
    std::cout << "2. Testing that Dog and Cat still work:" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    dog->makeSound();
    cat->makeSound();
    
    delete dog;
    delete cat;
    std::cout << std::endl;
    
    // Test 3: Polymorphism still works
    std::cout << "3. Testing polymorphism with array:" << std::endl;
    const int arraySize = 2;
    Animal* animals[arraySize];
    
    animals[0] = new Dog();
    animals[1] = new Cat();
    
    for (int i = 0; i < arraySize; i++) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    std::cout << std::endl;
    
    // Test 4: Brain functionality still works
    std::cout << "4. Testing Brain still works:" << std::endl;
    Dog smartDog;
    smartDog.setIdea(0, "I'm a smart doggo!");
    std::cout << "Dog idea: " << smartDog.getBrain()->getIdea(0) << std::endl;
    
    std::cout << std::endl;
    std::cout << "=== All tests completed successfully! ===" << std::endl;
    
    return 0;
}