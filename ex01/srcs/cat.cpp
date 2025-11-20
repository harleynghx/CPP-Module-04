#include "cat.hpp"

Cat::Cat() {
    _type = "Cat";
    brain = new Brain();
    std::cout << "Cat defualt constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "OIIA OIIA" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}

void Cat::setIdea(unsigned int index, const std::string& idea) {
    if (brain) {
        brain->setIdea(index, idea);
    }
}
