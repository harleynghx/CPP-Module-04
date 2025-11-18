#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal, public Brain{
private:
    //? Brain as a direct member instead of inheritent like animal cause Brain is small and simple (no polymorphism needed)
    //? Now Dog have brain (via pointers not through inheritance)
    Brain* brain; 
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    virtual void makeSound() const;

    Brain* getBrain() const;
    void setIdea(unsigned int index, const std::string& idea);
};

#endif