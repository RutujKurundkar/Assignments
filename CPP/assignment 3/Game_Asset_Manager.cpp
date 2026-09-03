#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Texture {
private:
    string name;
    int width;
    int height;

public:
    Texture(string n, int w, int h) : name(n), width(w), height(h) {
        cout << "[Texture Loaded]" << endl;
    }

    ~Texture() {
        cout << "[Texture Released]" << endl;
    }

    void display() const {
        cout << "Texture: " << name << " (" << width << "x" << height << ")" << endl;
    }
};

class Shader {
private:
    string name;
    string type;

public:
    Shader(string n, string t) : name(n), type(t) {
        cout << "[Shader Compiled]" << endl;
    }

    ~Shader() {
        cout << "[Shader Destroyed]" << endl;
    }
};

int getReferenceCount(const shared_ptr<Shader>& shaderPtr) {
    return shaderPtr.use_count();
}

class AudioClip {
private:
    string name;
    double duration;

public:
    AudioClip(string n, double d) : name(n), duration(d) {}

    string getName() const {
        return name;
    }
};

int main() {
    auto texture1 = make_unique<Texture>("player_sprite", 512, 512);
    texture1->display();

    // auto attemptCopy = texture1; // Error: unique_ptr copy constructor is deleted to enforce single exclusive ownership and prevent double-deletion crashes.

    auto texture2 = move(texture1);

    if (texture1 == nullptr) {
        cout << "Verification: First unique_ptr is now safely nullptr." << endl;
    }

    if (texture2 != nullptr) {
        cout << "Verification: Second unique_ptr now holds ownership." << endl;
    }

    texture2.reset();

    cout << endl;

    auto shader = make_shared<Shader>("main_vert", "vertex");
    cout << "Ref count: " << shader.use_count() << endl;
    {
        auto rendererRef = shader;
        cout << "Ref count: " << shader.use_count() << endl;

        auto editorRef = shader;
        cout << "Ref count: " << shader.use_count() << endl;
    }
    cout << "Ref count: " << shader.use_count() << endl;

    cout << endl;

    auto audio = make_shared<AudioClip>("explosion", 3.5);
    weak_ptr<AudioClip> observer = audio;

    if (auto clip = observer.lock()) {
        cout << "Clip alive: " << clip->getName() << endl;
    }

    audio.reset();

    if (observer.expired()) {
        cout << "Clip already unloaded." << endl;
    }

    return 0;
}
