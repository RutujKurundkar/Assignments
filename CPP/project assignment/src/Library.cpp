#include "Library.h"
#include "Exceptions.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace LibrarySystem {

    void Library::addBook(const Book& book) {
        books.push_back(book);
    }

    void Library::removeBook(int bookId) {
        for (int i = 0; i < books.size(); ++i) {
            if (books[i].getBookId() == bookId) {
                books.removeAt(i);
                std::cout << "Book tracking record removed successfully.\n";
                return;
            }
        }
        throw BookNotFoundException("Cannot remove book. ID not found.", __FUNCTION__, __LINE__);
    }

    Book* Library::searchBookById(int bookId) {
        return books.findById(bookId);
    }

    Book* Library::searchBookByTitle(const std::string& title) {
        return books.findByName(title);
    }

    void Library::registerMember(const Member& member) {
        members.push_back(member);
    }

    void Library::removeMember(int memberId) {
        for (int i = 0; i < members.size(); ++i) {
            if (members[i].getId() == memberId) {
                members.removeAt(i);
                std::cout << "Member registration record dropped from database.\n";
                return;
            }
        }
        throw MemberNotFoundException("Cannot remove member. ID not found.", __FUNCTION__, __LINE__);
    }

    Member* Library::searchMemberById(int memberId) {
        return members.findById(memberId);
    }

    void Library::issueBook(int memberId, int bookId) {
        Member* member = searchMemberById(memberId);
        if (!member) throw MemberNotFoundException("Member reference mismatch error.", __FUNCTION__, __LINE__);

        Book* book = searchBookById(bookId);
        if (!book) throw BookNotFoundException("Book code identification error.", __FUNCTION__, __LINE__);

        if (book->getAvailableCopies() <= 0) {
            throw BookNotAvailableException("No copies available in stock.", __FUNCTION__, __LINE__);
        }

        member->borrowBook(bookId);
        book->setStatus(BookStatus::ISSUED);
        transactions.push_back(Transaction(memberId, bookId, 0));
    }

    void Library::returnBook(int memberId, int bookId, int overdueDays) {
        Member* member = searchMemberById(memberId);
        if (!member) throw MemberNotFoundException("Member reference mismatch error.", __FUNCTION__, __LINE__);

        Book* book = searchBookById(bookId);
        if (!book) throw BookNotFoundException("Book code identification error.", __FUNCTION__, __LINE__);

        member->returnBook(bookId);
        book->setStatus(BookStatus::AVAILABLE);

        if (overdueDays > 0) {
            Transaction trans(memberId, bookId, overdueDays);
            transactions.push_back(trans);
            std::cout << "Late return calculated fine balance: INR " << trans.getFineAmount() << "\n";
        } else {
            std::cout << "Book returned on time with no fine added.\n";
        }
    }

    void Library::viewOverdueBooks() const {
        std::cout << "\n--- Overdue Records / Late Return Slips ---\n";
        if (transactions.empty()) {
            std::cout << "Clean record state. No late return history stored currently.\n";
        } else {
            for (const auto& trans : transactions) {
                if (trans.getDaysOverdue() > 0) trans.displayTransaction();
            }
        }
    }

    void Library::listAllBooks() const {
        std::cout << "\n========== BOOK CATALOGUE ==========\n";
        for (int i = 0; i < books.size(); ++i) {
            std::cout << books[i] << "\n";
        }
    }

    void Library::listAllMembers() const {
        std::cout << "\n========= MEMBERS REGISTRY =========\n";
        for (int i = 0; i < members.size(); ++i) {
            members[i].displayInfo();
        }
    }

    void Library::saveToFile(const std::string& booksFile, const std::string& membersFile) const {
        std::ofstream bFile(booksFile);
        if (bFile.is_open()) {
            for (int i = 0; i < books.size(); ++i) {
                bFile << books[i].getBookId() << "," << books[i].getTitle() << ","
                      << books[i].getAuthor() << "," << static_cast<int>(books[i].getStatus()) << "\n";
            }
            bFile.close();
        }
        std::ofstream mFile(membersFile);
        if (mFile.is_open()) {
            for (int i = 0; i < members.size(); ++i) {
                mFile << members[i].getId() << "," << members[i].getName() << "," << members[i].getPhone() << ",0\n";
            }
            mFile.close();
        }
    }

    void Library::loadFromFile(const std::string& booksFile, const std::string& membersFile) {
        std::ifstream bFile(booksFile);
        std::string line;
        if (bFile.is_open()) {
            while (std::getline(bFile, line)) {
                if (line.empty()) continue;
                std::stringstream ss(line);
                std::string idStr, title, author, statusStr;
                std::getline(ss, idStr, ',');
                std::getline(ss, title, ',');
                std::getline(ss, author, ',');
                std::getline(ss, statusStr, ',');
                if (!idStr.empty()) {
                    books.push_back(Book(std::stoi(idStr), title, author, "978-X", 5, static_cast<BookStatus>(std::stoi(statusStr))));
                }
            }
            bFile.close();
        }
        std::ifstream mFile(membersFile);
        if (mFile.is_open()) {
            while (std::getline(mFile, line)) {
                if (line.empty()) continue;
                std::stringstream ss(line);
                std::string idStr, name, phone;
                std::getline(ss, idStr, ',');
                std::getline(ss, name, ',');
                std::getline(ss, phone, ',');
                if (!idStr.empty()) {
                    members.push_back(Member(std::stoi(idStr), name, phone));
                }
            }
            mFile.close();
        }
    }
}
