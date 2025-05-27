#include <iostream>
#include <string>
using namespace std;

// Базовий клас персонажа
class Character {
protected:
    string name;
public:
    Character(string n) : name(n) {}
    virtual void display() = 0;
};

// Конкретні персонажі
class Elf : public Character {
public:
    Elf() : Character("Elf") {}
    void display() {
        cout << "Created character: " << name << " " << endl;
    }
};

class Orc : public Character {
public:
    Orc() : Character("Orc") {}
    void display() {
        cout << "Created character: " << name << " " << endl;
    }
   
};

// Базовий клас зброї
class Weapon {
protected:
    string type;
public:
    Weapon(string t) : type(t) {}
    virtual void show() = 0;
};

class Bow : public Weapon {
public:
    Bow() : Weapon("Bow") {}
    void show() {
        cout << "Equipped weapon: " << type << " " << endl;
    }
};

class Axe : public Weapon {
public:
    Axe() : Weapon("Axe") {}
    void show() {
        cout << "Equipped weapon: " << type << " " << endl;
    }
};

// Абстрактна фабрика
class GameFactory {
public:
    virtual Character* createCharacter() = 0;
    virtual Weapon* createWeapon() = 0;
};

// Конкретні фабрики
class ElfFactory : public GameFactory {
public:
    Character* createCharacter() override {
        return new Elf();
    }
    Weapon* createWeapon() override {
        return new Bow();
    }
    if () {
        delete
        {
            /* code */
        }
        
    }
};

class OrcFactory : public GameFactory{
public:
    Character* createCharacter() override {
        return new Orc();
    }
    
    Weapon* createWeapon() override {
        return new Axe();
    }
    
    ~OrcFactory() {
        
    }
};

int main() {
    GameFactory* factory;

    // Вибір раси
    cout << "Choose race (1 - Elf, 2 - Orc): ";
    int choice;
    cin >> choice;

    if (choice == 1)
        factory = new ElfFactory();
    else
        factory = new OrcFactory();

    Character* player = factory->createCharacter();
    Weapon* weapon = factory->createWeapon();

    player->display();
    weapon->show();

    delete player;
    delete weapon;
    delete factory;
    return 0;
}
