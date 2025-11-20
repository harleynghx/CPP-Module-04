#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include <iostream>

int main() {
    std::cout << "=== EX01 TEST: Animals with Brains ===" << std::endl;
    std::cout << std::endl;

    // Test 1: Basic creation and destruction (from PDF example)
    std::cout << "1. Testing basic creation/destruction:" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    dog->makeSound();
    cat->makeSound();
    
    delete dog;  // Should not leak
    delete cat;  // Should not leak
    std::cout << std::endl;

    // Test 2: Array of animals (half Dog, half Cat)
    std::cout << "2. Testing array of animals:" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];
    
    // Create half dogs, half cats
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
            std::cout << "Created Dog at index " << i << std::endl;
        } else {
            animals[i] = new Cat();
            std::cout << "Created Cat at index " << i << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 3: Delete through Animal pointers
    std::cout << "3. Deleting through Animal pointers:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    std::cout << std::endl;

    // Test 4: Brain functionality
    std::cout << "4. Testing Brain ideas:" << std::endl;
    Dog smartDog;
    smartDog.setIdea(0, "I love bones!");
    smartDog.setIdea(1, "Where's my ball?");
    
    Cat cleverCat;
    cleverCat.setIdea(0, "I love naps!");
    cleverCat.setIdea(1, "Mouse hunting time!");
    
    std::cout << "Smart dog idea 0: " << smartDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Smart dog idea 1: " << smartDog.getBrain()->getIdea(1) << std::endl;
    std::cout << "Clever cat idea 0: " << cleverCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Clever cat idea 1: " << cleverCat.getBrain()->getIdea(1) << std::endl;
    std::cout << std::endl;

    // Test 5: Deep copy verification
    std::cout << "5. Testing deep copy (VERY IMPORTANT):" << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "Original idea");
    
    // Test copy constructor
    Dog copiedDog(originalDog);
    copiedDog.setIdea(0, "Copied and modified idea");
    
    std::cout << "Original dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    
    // Check if deep copy worked
    if (originalDog.getBrain()->getIdea(0) == "Original idea") {
        std::cout << "✅ SUCCESS: Deep copy works! Original not affected." << std::endl;
    } else {
        std::cout << "❌ FAIL: Shallow copy detected!" << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Assignment operator deep copy
    std::cout << "6. Testing assignment deep copy:" << std::endl;
    Cat cat1;
    cat1.setIdea(1, "First cat's idea");
    
    Cat cat2;
    cat2 = cat1;  // Assignment operator
    cat2.setIdea(1, "Second cat's different idea");
    
    std::cout << "Cat1 idea: " << cat1.getBrain()->getIdea(1) << std::endl;
    std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(1) << std::endl;
    
    if (cat1.getBrain()->getIdea(1) == "First cat's idea") {
        std::cout << "✅ SUCCESS: Assignment deep copy works!" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== All tests completed ===" << std::endl;
    std::cout << "Check for memory leaks with: leaks ./animals" << std::endl;

    return 0;
}