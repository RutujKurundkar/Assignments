#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

namespace LibrarySystem {

    enum class BookStatus {
        AVAILABLE,
        ISSUED,
        RESERVED
    };

    enum class BookGenre {
        FICTION,
        NON_FICTION,
        SCIENCE,
        HISTORY,
        TECHNOLOGY
    };

    class Book {
    private:
        int bookId;
        std::string title;
        std::string author;
        std::string isbn;
        BookStatus status;
        int quantity;
        int availableCopies;

    public:
        Book(int id = 0, const std::string& title = "", const std::string& author = "",
             const std::string& isbn = "", int qty = 1, BookStatus status = BookStatus::AVAILABLE);

        // Getters & Setters
        int getBookId() const;
        std::string getTitle() const;
        std::string getName() const { return title; } // Added helper for template uniformity
        std::string getAuthor() const;
        BookStatus getStatus() const;
        void setStatus(BookStatus newStatus);
        int getAvailableCopies() const;

        // --- Required Operator Overloads ---
        bool operator==(const Book& other) const;
        bool operator<(const Book& other) const; // Search/sort helper

        // Prefix & Postfix Increment/Decrement tracking quantities
        Book& operator++();    // Prefix ++
        Book operator++(int);  // Postfix ++
        Book& operator--();    // Prefix --
        Book operator--(int);  // Postfix --

        // Subscript indexing operator to fetch distinct textual properties
        std::string operator[](int index) const;

        // Stream IO overloads
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
        friend std::istream& operator>>(std::istream& is, Book& book);
    };
}

#endif
