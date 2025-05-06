#include <iostream>
using namespace std;

class Instrument {
    string material;
    int volume;
    string sound;

public:
    int SetMaterial(string m) {
        material = m;
        return 1;
    }

    int SetVolume(int v) {
        volume = v;
        return 1;
    }

    int SetSound(string s) {
        sound = s;
        return 1;
    }

    int Play() {
        cout << "something is playing..." << endl;
        return 1;
    }

protected:
    int Describe() {
        cout << "Material: " << material << ", Volume: " << volume << ", Sound: " << sound << endl;
        return 1;
    }
};

class Guitar : public Instrument {
public:
    Guitar() {
        SetMaterial("wood");
        SetVolume(70);
        SetSound("strumming");
        Describe();
        Play();
    }

    int Play() {
        cout << "Strum-strum!" << endl;
        return 1;
    }
};

class Piano : public Instrument {
public:
    Piano() {
        SetMaterial("wood and metal");
        SetVolume(80);
        SetSound("classical chord");
        Describe();
        Play();
    }

    int Play() {
        cout << "Plink-plonk!" << endl;
        return 1;
    }
};

class ElectricGuitar : public Guitar {
protected:
    string brand;

public:
    int SetBrand(string b) {
        brand = b;
        return 1;
    }

    ElectricGuitar(string b) {
        SetBrand(b);
        cout << "Guitar brand: " << brand << endl;
    }

    ElectricGuitar() {}
};

class Player : public ElectricGuitar {
    string name;
    string style;

public:
    int SetName(string n) {
        name = n;
        return 1;
    }

    int SetStyle(string s) {
        style = s;
        return 1;
    }

    Player(string b, string n, string s) {
        SetBrand(b);
        SetName(n);
        SetStyle(s);
        cout << name << " plays in " << style << " style on a " << brand << " guitar." << endl;
    }
};

int main() {
    Player* rockstar = new Player("Yamaha", "Andrew", "rock");
}
