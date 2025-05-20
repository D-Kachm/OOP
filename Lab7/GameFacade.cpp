#include <iostream>
#include <string>

using namespace std;

// Підсистема 1 — Графіка
class GraphicsSystem {
public:
    void loadTextures() {
        cout << "[Graphics] Textures loaded.\n";
    }
    void initializeRenderer() {
        cout << "[Graphics] Renderer initialized.\n";
    }
};

// Підсистема 2 — Звук
class SoundSystem {
public:
    void loadSounds() {
        cout << "[Sound] Sound assets loaded.\n";
    }
    void initAudio() {
        cout << "[Sound] Audio system started.\n";
    }
};

// Підсистема 3 — Мережа
class NetworkSystem {
public:
    void connectToServer() {
        cout << "[Network] Connected to game server.\n";
    }
};

// Підсистема 4 — Авторизація
class LoginSystem {
public:
    void loginPlayer(string username) {
        cout << "[Login] Player " << username << " logged in.\n";
    }
};

// Підсистема 5 — Геймплей
class GameEngine {
public:
    void startGame() {
        cout << "[Game] Game has started!\n";
    }
};

// === ФАСАД ===
class GameFacade {
private:
    GraphicsSystem* graphics;
    SoundSystem* sound;
    NetworkSystem* network;
    LoginSystem* login;
    GameEngine* engine;

public:
    GameFacade() {
        graphics = new GraphicsSystem();
        sound = new SoundSystem();
        network = new NetworkSystem();
        login = new LoginSystem();
        engine = new GameEngine();
    }

    ~GameFacade() {
        delete graphics;
        delete sound;
        delete network;
        delete login;
        delete engine;
    }

    void launchGame(string username) {
        graphics->loadTextures();
        graphics->initializeRenderer();
        sound->loadSounds();
        sound->initAudio();
        network->connectToServer();
        login->loginPlayer(username);
        engine->startGame();
    }

    void playOffline(string username) {
        graphics->loadTextures();
        graphics->initializeRenderer();
        sound->loadSounds();
        sound->initAudio();
        login->loginPlayer(username);
        cout << "[Game] Offline mode.\n";
        engine->startGame();
    }
};

// === CLIENT CODE ===
int main() {
    GameFacade* game = new GameFacade();

    cout << "=== Starting Online Game ===\n";
    game->launchGame("Gamer007");

    cout << "\n=== Starting Offline Game ===\n";
    game->playOffline("SoloPlayer");

    delete game;
    return 0;
}
