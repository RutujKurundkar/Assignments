#include <iostream>

using namespace std;

class LogBuffer {
private:
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;
    mutable int accessCount;

public:
    LogBuffer(int cap) : capacity(cap), size(0), accessCount(0) {
        buffer = new char[capacity];
        buffer[0] = '\0';
        instanceCount++;
        cout << "[LogBuffer Created] capacity=" << capacity << endl;
    }

    LogBuffer(const LogBuffer& other) : capacity(other.capacity), size(other.size), accessCount(0) {
        buffer = new char[capacity];
        for (int i = 0; i <= size; i++) {
            buffer[i] = other.buffer[i];
        }
        instanceCount++;
        cout << "[LogBuffer Deep Copied] capacity=" << capacity << endl;
    }

    LogBuffer& operator=(const LogBuffer& other) {
        if (this == &other) {
            cout << "[Self-assignment detected - no operation]" << endl;
            return *this;
        }
        delete[] buffer;
        capacity = other.capacity;
        size = other.size;
        buffer = new char[capacity];
        for (int i = 0; i <= size; i++) {
            buffer[i] = other.buffer[i];
        }
        cout << "[LogBuffer Assigned]" << endl;
        return *this;
    }

    ~LogBuffer() {
        delete[] buffer;
        instanceCount--;
        cout << "[LogBuffer Destroyed]" << endl;
    }

    void append(const char* msg) {
        if (!msg) return;
        int len = 0;
        while (msg[len] != '\0') len++;

        int i = 0;
        while (size < capacity - 1 && i < len) {
            buffer[size] = msg[i];
            size++;
            i++;
        }
        buffer[size] = '\0';
    }

    void print() const {
        accessCount++;
        cout << buffer << endl;
    }

    void clear() {
        size = 0;
        buffer[0] = '\0';
    }

    static int getInstanceCount() {
        return instanceCount;
    }

    int getAccessCount() const {
        return accessCount;
    }
};

int LogBuffer::instanceCount = 0;

int main() {
    LogBuffer log1(256);
    log1.append("Server started on port 8080 | Request received from 192.168.1.10");
    log1.print();
    cout << endl;

    LogBuffer log2 = log1;
    cout << "log1 : "; log1.print();
    log2.append(" | Cached response sent");
    cout << "log2 : "; log2.print();
    cout << endl;

    LogBuffer log3(256);
    log3 = log1;
    cout << "log3 : "; log3.print();
    cout << endl;

   // log3 = log3; // Testing self-assignment
    cout << endl;

    cout << "Live LogBuffer objects : " << LogBuffer::getInstanceCount() << endl;
    cout << endl;

    const LogBuffer readOnly(log1);
    readOnly.print();
    readOnly.print();
    readOnly.print();
    cout << "Times printed: " << readOnly.getAccessCount() << endl;
    cout << endl;

    return 0;
}

/*
==========================================================================================
CONCEPTUAL EXPLANATION:
1. Why accessCount must be 'mutable':
   The print() function is explicitly marked as a 'const' member function, meaning it promises
   not to modify the logical state of the object. However, tracking metrics like an internal
   read counter (accessCount) modifies a physical member variable. Declaring the member variable
   as 'mutable' permits it to be modified even inside 'const' member functions or when called
   on a 'const LogBuffer' object.

2. What the 'const' keyword on a member function prevents:
   The 'const' keyword on a member function modifies the implicit 'this' pointer from
   'Class*' to 'const Class*'. This prevents the function from modifying any non-mutable
   member variables of the class and restricts the function from calling any other
   non-const member functions on that object, enforcing read-only safety at the compiler level.
==========================================================================================
*/
