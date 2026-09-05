#ifndef LIBRARY_H
#define LIBRARY_H

#include "Container.h"
#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include <vector>

namespace LibrarySystem {

    class Library {
    private:
        Container<Book> books;      // Swapped out to utilize your template custom arrays
        Container<Member> members;  // Swapped out to utilize your template custom arrays
        std::vector<Transaction> transactions; // STL integration metric specification

    public:
        void addBook(const Book& book);
        void removeBook(int bookId);
        Book* searchBookById(int bookId);
        Book* searchBookByTitle(const std::string& title);
        void listAllBooks() const;

        void registerMember(const Member& member);
        void removeMember(int memberId);
        Member* searchMemberById(int memberId);
        void listAllMembers() const;

        void issueBook(int memberId, int bookId);
        void returnBook(int memberId, int bookId, int overdueDays = 0);
        void viewOverdueBooks() const;

        void saveToFile(const std::string& booksFile, const std::string& membersFile) const;
        void loadFromFile(const std::string& booksFile, const std::string& membersFile);
    };
}

#endif
