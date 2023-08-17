#include <iostream>
#include <string>
#include <algorithm>

//CASE 1
class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
    }

    virtual ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};

class B : public A
{
public:
    B()
    {
        std::cout << "B()" << std::endl;
    }

    ~B()
    {
        std::cout << "~B()" << std::endl;
    }

    void print() const
    {
        std::cout << my_string << std::endl;
    }

    void print(const std::string& text) const
    {
        std::cout << text << std::endl;
    }

private:
    std::string my_string;
};

//CASE 2
class Base {
public:
    virtual void print() {
        std::cout << "Base" << std::endl;
    }
};

class Derived1 : public Base {
public:
    void print() {
        std::cout << "Derived1" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void print() {
        std::cout << "Derived2" << std::endl;
    }
};

//CASE 3
class Animal
{
public:
    virtual ~Animal() {};

    virtual void eat() {};

    virtual void sleep()
    {
        std::cout << "Animal sleep method\n";
    }
};

class Dog : public Animal
{
public:
    void eat() override
    {
        eatCallsCounter++;
        std::cout << "Dog eating\n" << eatCallsCounter;
    }

private:
    int eatCallsCounter = 0;
};

class Cat : public Animal
{
public:
    void eat() override
    {
        std::cout << "Cat eating\n";
    }
};

void toLower(std::string& str)
{
    //ranged-based for loop
    //read: iterate every char of the string from left to right and execute something inside with it
    //similar to for (int i = 0; i < str.size(); i++) { str[i]... }
    for (char& ch : str)
    {
        ch = std::tolower(ch);
    }
}

Animal* createAnimal(std::string pet)
{
    toLower(pet);

    if (pet == "dog")  return new Dog;
    if (pet == "cat") return new Cat;

    return new Animal;
}

int main()
{
    // CASE 1
    A* a = new A();
    B* b = dynamic_cast<B*>(a);

    if (b != nullptr) {
        b->print("sdf");
        b->print();
    }
    else {
        std::cout << "Failed cast A to B" << std::endl;
    }
    delete a;


    // CASE 2
    Derived1 d1;
    d1.print();

    Base* bp = dynamic_cast<Base*>(&d1);
    bp->print();

    Derived2* dp2 = dynamic_cast<Derived2*>(bp);
    if (dp2 != nullptr) {
        dp2->print();
    }
    else {
        std::cout << "Failed cast Derived2" << std::endl;
    }


    // CASE 3
    std::string petChoice;
    std::cout << "Choose your pet: (Dog/Cat): ";
    std::cin >> petChoice;

    Animal* animal = createAnimal(petChoice);
    Dog* dog = dynamic_cast<Dog*>(animal);
    Cat* cat = dynamic_cast<Cat*>(animal);
    if (dog != nullptr)
    {
        dog->eat();
    }
    if (cat != nullptr)
    {
        cat->eat();
    }
    delete animal;

    return 0;
}