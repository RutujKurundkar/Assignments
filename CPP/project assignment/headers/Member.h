#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include <iostream>

namespace LibrarySystem {

    class Member : public Person {
    private:
        int* issuedBookIds;
        int currentBookCount;
        int maxCapacity;

    public:
        // Constructor with explicit defaults for template array allocations
        Member(int id = 0, const std::string& name = "", const std::string& phone = "", int maxCap = 5);

        // --- Explicit Rule of Three Declarations matching Member.cpp ---
        virtual ~Member() override;
        Member(const Member& other);
        Member& operator=(const Member& other);

        // Methods
        void borrowBook(int bookId);
        void returnBook(int bookId);
        int getCurrentBookCount() const;
        int getMaxCapacity() const;
        const int* getIssuedBookIds() const;

        void displayInfo() const override;
    };
}

#endif
