#include <iostream>
using namespace std;

int instrumentDestructorsCalled = 0;

class Instrument {
    string material;
    int volume;
    string sound;

public:
    Instrument() {
        cout << "Instrument constructor\n";
    }

    virtual ~Instrument() {
        instrumentDestructorsCalled++;
        cout << "Instrument destructor called. Count: " << instrumentDestructorsCalled << endl;
    }

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

// Віртуальне успадкування для уникнення дублювання Instrument
class Guitar : virtual public Instrument {
public:
    Guitar() {
        cout << "Guitar constructor\n";
        SetMaterial("wood");
        SetVolume(70);
        SetSound("strumming");
        Describe();
        Play();
    }

    virtual ~Guitar() {
        cout << "Guitar destructor\n";
    }

    int Play() {
        cout << "Strum-strum!" << endl;
        return 1;
    }
};

class Piano : virtual public Instrument {
public:
    Piano() {
        cout << "Piano constructor\n";
        SetMaterial("wood and metal");
        SetVolume(80);
        SetSound("classical chord");
        Describe();
        Play();
    }

    virtual ~Piano() {
        cout << "Piano destructor\n";
    }

    int Play() {
        cout << "Plink-plonk!" << endl;
        return 1;
    }
};

class Violin : virtual public Instrument {
public:
    Violin() {
        cout << "Violin constructor\n";
        SetMaterial("wood");
        SetVolume(50);
        SetSound("classical chord");
        Describe();
        Play();
    }

    virtual ~Violin() {
        cout << "Piano destructor\n";
    }

    int Play() {
        cout << "Wee-Wee-Wee!" << endl;
        return 1;
    }
};



// Множинне успадкування від Guitar і Piano і Violin
class MultiInstrument : public Guitar, public Piano, public Violin {
public:
    MultiInstrument() {
        cout << "MultiInstrument constructor\n";
    }

    ~MultiInstrument() {
        cout << "MultiInstrument destructor\n";
    }

    int PlayAll() {
        Guitar::Play();
        Piano::Play();
        Violin::Play();
        return 1;
    }
};

// Успадкування від трьох класів (для демонстрації порядку)
class Performer : public MultiInstrument {
    string name;
public:
    Performer(string n) {
        name = n;
        cout << "Performer constructor: " << name << endl;
    }

    ~Performer() {
        cout << "Performer destructor: " << name << endl;
    }

    void Show() {
        cout << name << " is performing with multiple instruments!\n";
        PlayAll();
    }
};

int main() {
    Performer* p = new Performer("Alex");
    p->Show();
    delete p;

    return 0;
}
