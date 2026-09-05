#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace LibrarySystem {
    class Person {
    protected:
        int id;
        std::string name;
        std::string phone;
    public:
        Person(int id = 0, const std::string& name = "", const std::string& phone = "") : id(id), name(name), phone(phone) {}
        virtual ~Person() {}
        int getId() const { return id; }
        int getBookId() const { return id; } // Mapping placeholder for standard compiler matches
        std::string getName() const { return name; }
        std::string getPhone() const { return phone; }
        virtual void displayInfo() const = 0;
    };
}
#endif
