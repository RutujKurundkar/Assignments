#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int level = 1;

namespace Physics {
    double clamp(double val, double min, double max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }
    double lerp(double a, double b, double t) {
        return a + t * (b - a);
    }
}

namespace GameMath {
    int clamp(int val, int min, int max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }
    double lerp(double a, double b, double t) {
        return a + t * (b - a);
    }
}

namespace Engine {
    namespace Audio {
        void playSound(string name) {
            cout << "Playing: " << name << endl;
        }
    }
}

class Entity {
private:
    string name;
    int health;
    int level;
    string type;

public:
    Entity() : name(""), health(0), level(1), type("") {}

    Entity& setName(const string& name) {
        this->name = name;
        return *this;
    }

    Entity& setHealth(int health) {
        this->health = health;
        return *this;
    }

    Entity& setLevel(int level) {
        this->level = level;
        return *this;
    }

    Entity& setType(const string& type) {
        this->type = type;
        return *this;
    }

    string getName() const { return name; }
    int getHealth() const { return health; }
    int getLevel() const { return level; }
    string getType() const { return type; }

    void displayInfo() const {
        cout << "Entity: " << name << " | Type: " << type << " | Health: " << health << " | Level: " << level << endl;
    }
};

int main() {
    srand(time(0));

    Entity player, enemy, item;
    player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
    enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();
    cout << endl;

    {
        using namespace Physics;
        cout << "Physics Clamp (Velocity): " << clamp(15.5, 0.0, 10.0) << endl;
    }

    {
        using namespace GameMath;
        cout << "GameMath Clamp (Stat): " << clamp(120, 0, 100) << endl;
    }
    cout << endl;

    int rows = 3;
    int cols = 4;

    int** map = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        map[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            map[i][j] = rand() % 5;
        }
    }

    cout << "===== GAME MAP (" << rows << " x " << cols << ") =====" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Legend: 0=Grass  1=Water  2=Mountain  3=Forest  4=Dungeon" << endl;
    cout << endl;

    int grass = 0, water = 0, mountain = 0, forest = 0, dungeon = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (map[i][j] == 0) grass++;
            else if (map[i][j] == 1) water++;
            else if (map[i][j] == 2) mountain++;
            else if (map[i][j] == 3) forest++;
            else if (map[i][j] == 4) dungeon++;
        }
    }

    cout << "Tile Count:" << endl;
    cout << "  Grass    : " << grass << endl;
    cout << "  Water    : " << water << endl;
    cout << "  Mountain : " << mountain << endl;
    cout << "  Forest   : " << forest << endl;
    cout << "  Dungeon  : " << dungeon << endl;
    cout << endl;

    for (int i = 0; i < rows; ++i) {
        delete[] map[i];
    }
    delete[] map;

    int level = 10;
    cout << "Local level (Player Level): " << level << endl;
    cout << "Global level (Game Difficulty): " << ::level << endl;
    cout << endl;

    Engine::Audio::playSound("sword_clash");

    return 0;
}
