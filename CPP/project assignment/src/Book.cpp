#include "Book.h"

namespace LibrarySystem {

    Book::Book(int id, const std::string& title, const std::string& author, const std::string& isbn, int qty, BookStatus status)
        : bookId(id), title(title), author(author), isbn(isbn), status(status), quantity(qty), availableCopies(qty) {}

    int Book::getBookId() const { return bookId; }
    std::string Book::getTitle() const { return title; }
    std::string Book::getAuthor() const { return author; }
    BookStatus Book::getStatus() const { return status; }
    void Book::setStatus(BookStatus newStatus) {
        status = newStatus;
        if (status == BookStatus::ISSUED && availableCopies > 0) {
            availableCopies--;
        } else if (status == BookStatus::AVAILABLE && availableCopies < quantity) {
            availableCopies++;
        }
    }
    int Book::getAvailableCopies() const { return availableCopies; }

    bool Book::operator==(const Book& other) const {
        return this->bookId == other.bookId;
    }

    bool Book::operator<(const Book& other) const {
        return this->bookId < other.bookId;
    }

    // Prefix increment
    Book& Book::operator++() {
        quantity++;
        availableCopies++;
        return *this;
    }

    // Postfix increment
    Book Book::operator++(int) {
        Book temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix decrement
    Book& Book::operator--() {
        if (quantity > 0) {
            quantity--;
            if (availableCopies > 0) availableCopies--;
        }
        return *this;
    }

    // Postfix decrement
    Book Book::operator--(int) {
        Book temp = *this;
        --(*this);
        return temp;
    }

    // Subscript indicator matching the requested indexing map layout
    std::string Book::operator[](int index) const {
        switch (index) {
            case 0: return std::to_string(bookId);
            case 1: return title;
            case 2: return author;
            case 3: return isbn;
            default: return "Out of range bound query";
        }
    }

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        std::string statusStr = (book.status == BookStatus::AVAILABLE) ? "Available" : "Issued";
        os << "ID: " << book.bookId << " | Title: " << book.title << " | Author: " << book.author
           << " | ISBN: " << book.isbn << " | Available: " << book.availableCopies << "/" << book.quantity;
        return os;
    }

    std::istream& operator>>(std::istream& is, Book& book) {
        std::cout << "Enter Book ID: "; is >> book.bookId; is.ignore();
        std::cout << "Enter Title: "; std::getline(is, book.title);
        std::cout << "Enter Author: "; std::getline(is, book.author);
        std::cout << "Enter ISBN Code: "; std::getline(is, book.isbn);
        std::cout << "Enter Total Initial Quantity: "; is >> book.quantity;
        book.availableCopies = book.quantity;
        book.status = BookStatus::AVAILABLE;
        return is;
    }
}
