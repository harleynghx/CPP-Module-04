#include "dog.hpp"

Dog::Dog() {
    _type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        brain = new Brain(*other.brain);
        delete brain; //? delete old brain
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "what da dog doin" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}

void Dog::setIdea(unsigned int index, const std::string& idea) {
    if (brain) 
        brain->setIdea(index, idea);
}