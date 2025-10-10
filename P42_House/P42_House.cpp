#include <iostream>

using namespace std;

class People
{
    char* fullName;
public:
    People(char* fullName) {
        if (fullName != nullptr)
        {
            this->fullName = new char[strlen(fullName) + 1];
            strcpy_s(this->fullName, strlen(this->fullName), fullName);
        }
    }
    People() : People(nullptr) {}

    People(const People& obj) {
        fullName = new char[strlen(obj.fullName) + 1];
        strcpy_s(fullName, strlen(fullName), obj.fullName);
    }

    ~People() {
        delete[] fullName;
    }

    People operator= (People& obj) {
        fullName = obj.fullName;
    }

    People& operator= (People&& obj) {
        if (!(this == &obj))
        {
            if (obj.fullName != nullptr)
            {
                fullName = new char[strlen(obj.fullName) + 1];
            }
            
            fullName = obj.fullName;

            obj.fullName = nullptr;
        }

        return *this;
    }

    char* getPeople() {
        return fullName;
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
            residents[i].setPeople(arr[i].getPeople());
        }
    }
    Apartment(int amount): amount{amount} {
        residents = (People*)malloc(sizeof(People) * amount);
    }
    Apartment() : Apartment(0) {}
    ~Apartment() {
        delete[] residents;
    }

    void setResident(People& p, int i) {
        residents[i] = p;
    }

    People getResident(int i) {
        return residents[i];
    }
};



class House
{
public:
    Apartment* apartments;
    int amount;

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

    void setApartment(Apartment& a, int i) {
        apartments[i] = a;
    }

    Apartment getApartment(int i) {
        return apartments[i];
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

House generateHouse(int amount) {
    House h{ amount };

    for (size_t i = 0; i < amount; i++)
    {
        h.apartments[i] = generateApartment(0);
    }
}


int main()
{
    People p1{ (char*)"I DONT KNOW1" };
    People p2{ (char*)"I DONT KNOW2" };
    People p3{ (char*)"I DONT KNOW3" };

    People* ppls;
    int amount = 3;
    ppls = (People*)malloc(sizeof(People) * amount);

    ppls[0].setPeople(p1.getPeople());
    ppls[1].setPeople(p2.getPeople());
    ppls[2].setPeople(p3.getPeople());

    Apartment a1{ amount, ppls };
    Apartment a2{ amount, ppls };
    Apartment a3 = generateApartment(5);

    Apartment* apartments;
    int amount2 = 2;
    apartments = (Apartment*)malloc(sizeof(Apartment) * amount2);

    House h1{ 2, apartments };
}