#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testBasicFunctionality() {
    std::cout << "=== Testing Basic Functionality ===" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // Should not create a leak
    delete i; // Should not create a leak
}

void testAnimalArray() {
    std::cout << "\n=== Testing Animal Array ===" << std::endl;
    
    const int arraySize = 6;
    Animal* animals[arraySize];
    
    // Create half dogs, half cats
    for (int i = 0; i < arraySize; ++i) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
            // Set some ideas for dogs
            Dog* dog = dynamic_cast<Dog*>(animals[i]);
            if (dog) {
                dog->setIdea(0, "I love bones");
                dog->setIdea(1, "Where's my ball?");
            }
        } else {
            animals[i] = new Cat();
            // Set some ideas for cats
            Cat* cat = dynamic_cast<Cat*>(animals[i]);
            if (cat) {
                cat->setIdea(0, "I love naps");
                cat->setIdea(1, "Where's the laser pointer?");
            }
        }
    }
    
    // Test polymorphism and display types
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Animal " << i << " type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    
    // Delete every Animal (proper destructors must be called)
    std::cout << "\nDeleting animals..." << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];
    }
}

void testDeepCopy() {
    std::cout << "\n=== Testing Deep Copy ===" << std::endl;
    
    // Create original dog with ideas
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "Original idea");
    originalDog->setIdea(1, "Chase cats");
    
    // Test copy constructor
    Dog* copiedDog = new Dog(*originalDog);
    copiedDog->setIdea(0, "Modified idea"); // Should not affect original
    
    // Test assignment operator
    Dog assignedDog;
    assignedDog = *originalDog;
    assignedDog->setIdea(1, "Different idea"); // Should not affect original
    
    std::cout << "Original dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned dog idea 1: " << assignedDog.getBrain()->getIdea(1) << std::endl;
    
    delete originalDog;
    delete copiedDog;
    // assignedDog destructor called automatically
}

void testBrainIdeas() {
    std::cout << "\n=== Testing Brain Ideas ===" << std::endl;
    
    Cat smartCat;
    smartCat.setIdea(0, "I'm a smart cat");
    smartCat.setIdea(1, "Fish is delicious");
    smartCat.setIdea(2, "Nap time soon");
    
    Dog cleverDog;
    cleverDog.setIdea(0, "I'm a clever dog");
    cleverDog.setIdea(1, "Walk time!");
    cleverDog.setIdea(2, "Where's my toy?");
    
    std::cout << "Smart cat ideas: " << std::endl;
    if (smartCat.getBrain()) {
        for (int i = 0; i < 3; ++i) {
            std::cout << "  " << i << ": " << smartCat.getBrain()->getIdea(i) << std::endl;
        }
    }
}

int main() {
    testBasicFunctionality();
    testAnimalArray();
    testDeepCopy();
    testBrainIdeas();
    
    // Additional test: Verify no memory leaks
    std::cout << "\n=== Program finished ===" << std::endl;
    std::cout << "Check for memory leaks with: leaks ./animals" << std::endl;
    
    return 0;
}