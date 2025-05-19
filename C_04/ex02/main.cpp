#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int arraySize = 6;
    Animal *animals[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        if (i < arraySize / 2)
        {
            animals[i] = new Dog();
        }
        else
        {
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < arraySize; i++)
    {
        animals[i]->makeSound();
    }

    for (int i = 0; i < arraySize; i++)
    {
        delete animals[i];
    }

    return 0;
}
