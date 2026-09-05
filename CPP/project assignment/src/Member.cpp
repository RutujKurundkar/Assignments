#include "Member.h"
#include "Exceptions.h"
#include <iostream>

namespace LibrarySystem {

    // Constructor
    Member::Member(int id, const std::string& name, const std::string& phone, int maxCap)
        : Person(id, name, phone), currentBookCount(0), maxCapacity(maxCap) {
        issuedBookIds = new int[maxCapacity];
    }

    // Destructor (Rule of Three)
    Member::~Member() {
        delete[] issuedBookIds;
    }

    // Copy Constructor (Rule of Three - Deep Copy)
    Member::Member(const Member& other)
        : Person(other.id, other.name, other.phone),
          currentBookCount(other.currentBookCount),
          maxCapacity(other.maxCapacity) {

        this->issuedBookIds = new int[this->maxCapacity];
        for (int i = 0; i < this->currentBookCount; ++i) {
            this->issuedBookIds[i] = other.issuedBookIds[i];
        }
    }

    // Copy Assignment Operator (Rule of Three - Safe Deep Copy)
    Member& Member::operator=(const Member& other) {
        if (this != &other) {
            // Copy data using Person's members
            this->id = other.id;
            this->name = other.name;
            this->phone = other.phone;
            this->currentBookCount = other.currentBookCount;
            this->maxCapacity = other.maxCapacity;

            // Free old memory and allocate new deep-copied array
            delete[] this->issuedBookIds;
            this->issuedBookIds = new int[this->maxCapacity];
            for (int i = 0; i < this->currentBookCount; ++i) {
                this->issuedBookIds[i] = other.issuedBookIds[i];
            }
        }
        return *this;
    }

    // Borrow a book
    void Member::borrowBook(int bookId) {
        if (currentBookCount >= maxCapacity) {
            throw MaxBooksExceededException("Borrow limit reached for this member.", __FUNCTION__, __LINE__);
        }
        issuedBookIds[currentBookCount++] = bookId;
    }

    // Return a book
    void Member::returnBook(int bookId) {
        int index = -1;
        for (int i = 0; i < currentBookCount; ++i) {
            if (issuedBookIds[i] == bookId) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            throw BookNotFoundException("This book was not borrowed by this member.", __FUNCTION__, __LINE__);
        }

        // Shift remaining IDs left to maintain a continuous array
        for (int i = index; i < currentBookCount - 1; ++i) {
            issuedBookIds[i] = issuedBookIds[i + 1];
        }
        currentBookCount--;
    }

    int Member::getCurrentBookCount() const { return currentBookCount; }
    int Member::getMaxCapacity() const { return maxCapacity; }
    const int* Member::getIssuedBookIds() const { return issuedBookIds; }

    // Implementation of overridden pure virtual display function
    void Member::displayInfo() const {
        std::cout << "Member ID: " << id << "\nName: " << name << "\nPhone: " << phone
                  << "\nBooks Borrowed: " << currentBookCount << "/" << maxCapacity << "\nBorrowed Book IDs: ";
        if (currentBookCount == 0) {
            std::cout << "None";
        } else {
            for (int i = 0; i < currentBookCount; ++i) {
                std::cout << issuedBookIds[i] << " ";
            }
        }
        std::cout << "\n-----------------------------------\n";
    }
}
