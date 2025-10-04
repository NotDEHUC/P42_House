#include <iostream>

using namespace std;

class People
{
    char* fullName;
public:
    People(char* fullName): fullName{new char [strlen(fullName) + 1]} {
        strcpy_s(this->fullName, strlen(this->fullName), fullName);
    }
    People() : People(nullptr) {}

    ~People() {
        delete[] fullName;
    }

    People& operator= (People&& obj) {
        if (!(this == &obj))
        {
            delete[] fullName;

            fullName = obj.fullName;

            obj.fullName = nullptr;
        }

        return *this;
    }

    void setPeople(char* people) {
        fullName = new char[strlen(people) + 1];
        strcpy_s(fullName, strlen(fullName), people);
    }
};



class Apartment
{
public:
    People* residents;
    int amount;
    Apartment(int amount, People* arr) : amount{amount} {
        residents = (People*)malloc(sizeof(People) * amount);
        for (size_t i = 0; i < amount; i++)
        {
            residents[i] = arr[i];
        }
    }
    Apartment(int amount): amount{amount} {
        residents = (People*)malloc(sizeof(People) * amount);
    }
    Apartment() : Apartment(0) {}
    ~Apartment() {
        delete[] residents;
    }

    Apartment operator= (const People&& obj) {
        
    }

    void setResident(char* p, int i) {
        residents[i].setPeople(p);
    }
};



class House
{
    Apartment* apartments;
    int amount;
public:
    House(int amount, Apartment* apartments) : amount{ amount } {
        this->apartments = (Apartment*)malloc(sizeof(Apartment) * amount);
        for (size_t i = 0; i < amount; i++)
        {
            this->apartments[i] = apartments[i];
        }
    }
    House(int amount): amount{amount} {}
    House() : House(0) {}
    ~House() {
        delete[] apartments;
    }
};

People generatePeople() {
    People p;
    return p;
}

Apartment generateApartment(int amount) {
    Apartment a{amount};

    for (size_t i = 0; i < amount; i++)
    {
        a.residents[i] = generatePeople();
    }
    return a;
}


int main()
{
    People p1{ (char*)"I DONT KNOW1" };
    People p2{ (char*)"I DONT KNOW2" };
    People p3{ (char*)"I DONT KNOW3" };

    People* ppls;
    int amount = 3;
    ppls = (People*)malloc(sizeof(People) * amount);

    Apartment a1{ amount, ppls };
    Apartment a2{ amount, ppls };

    Apartment* apartments;
    int amount2 = 2;
    apartments = (Apartment*)malloc(sizeof(Apartment) * amount2);

    House h1{ 2, apartments };
}