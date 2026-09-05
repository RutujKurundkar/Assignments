#include "Library.h"
#include "Librarian.h"
#include "Exceptions.h"
#include <iostream>

using namespace LibrarySystem;

void printApplicationMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "      ADVANCED LIBRARY MANAGEMENT SYSTEM \n";
    std::cout << "=========================================\n";
    std::cout << "1. Add New Book\n";
    std::cout << "2. Remove Book\n";
    std::cout << "3. Search Book\n";
    std::cout << "4. Display All Books\n";
    std::cout << "5. Register Member\n";
    std::cout << "6. Remove Member\n";
    std::cout << "7. Search Member\n";
    std::cout << "8. Display All Members\n";
    std::cout << "9. Issue Book\n";
    std::cout << "10. Return Book\n";
    std::cout << "11. View Overdue Books\n";
    std::cout << "12. Save Data\n";
    std::cout << "13. Load Data\n";
    std::cout << "0. Exit\n";
    std::cout << "=========================================\n";
    std::cout << "Enter selection selection (0-13): ";
}

int main() {
    Library lib;
    std::string booksFile = "data/books.txt";
    std::string membersFile = "data/members.txt";

    // --- Mandatory Late Binding/Runtime Polymorphism Verification Requirement ---
    std::cout << "Running baseline dynamic type late-binding confirmation tracer...\n";
    Person* testPolymorphismPointer = new Member(999, "Dynamic Polymorphism Test User", "000-0000");
    testPolymorphismPointer->displayInfo(); // Safely executes the overriden child version trace
    delete testPolymorphismPointer;
    std::cout << "Polymorphic validation trace verified successfully.\n\n";

    // Auto-load data at application start
    lib.loadFromFile(booksFile, membersFile);

    int choice = -1;
    while (choice != 0) {
        printApplicationMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid structural choice token type. Flushing system streams.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        try {
            switch (choice) {
                case 1: {
                    Book b;
                    std::cin >> b;
                    lib.addBook(b);
                    std::cout << "Book allocated successfully inside custom structural container.\n";
                    break;
                }
                case 2: {
                    int bId;
                    std::cout << "Enter target Book ID to drop: "; std::cin >> bId;
                    lib.removeBook(bId);
                    break;
                }
                case 3: {
                    int searchType;
                    std::cout << "Search options: 1 by ID, 2 by Title matching: "; std::cin >> searchType;
                    std::cin.ignore();
                    if (searchType == 1) {
                        int id; std::cout << "Enter Book ID: "; std::cin >> id;
                        Book* found = lib.searchBookById(id);
                        if (found) std::cout << "Match Found: " << *found << "\n";
                        else std::cout << "No matching ID located inside index registry.\n";
                    } else {
                        std::string title; std::cout << "Enter Book Title: "; std::getline(std::cin, title);
                        Book* found = lib.searchBookByTitle(title);
                        if (found) std::cout << "Match Found: " << *found << "\n";
                        else std::cout << "No matching Title string variant tracked.\n";
                    }
                    break;
                }
                case 4:
                    lib.listAllBooks();
                    break;
                case 5: {
                    int id; std::string name, phone;
                    std::cout << "Enter Member ID: "; std::cin >> id; std::cin.ignore();
                    std::cout << "Enter Name string: "; std::getline(std::cin, name);
                    std::cout << "Enter Phone number string: "; std::getline(std::cin, phone);
                    lib.registerMember(Member(id, name, phone));
                    std::cout << "Member data logged into custom template stack.\n";
                    break;
                }
                case 6: {
                    int mId;
                    std::cout << "Enter target Member ID to wipe: "; std::cin >> mId;
                    lib.removeMember(mId);
                    break;
                }
                case 7: {
                    int mId; std::cout << "Enter target Member ID: "; std::cin >> mId;
                    Member* found = lib.searchMemberById(mId);
                    if (found) found->displayInfo();
                    else std::cout << "No member entry found matching specific parameter bounds.\n";
                    break;
                }
                case 8:
                    lib.listAllMembers();
                    break;
                case 9: {
                    int mId, bId;
                    std::cout << "Enter borrower Member ID: "; std::cin >> mId;
                    std::cout << "Enter target Book ID: "; std::cin >> bId;
                    lib.issueBook(mId, bId);
                    std::cout << "Transaction processed cleanly.\n";
                    break;
                }
                case 10: {
                    int mId, bId, overDays;
                    std::cout << "Enter processing Member ID: "; std::cin >> mId;
                    std::cout << "Enter returning Book ID: "; std::cin >> bId;
                    std::cout << "Enter days overdue (0 if back on time context): "; std::cin >> overDays;
                    lib.returnBook(mId, bId, overDays);
                    break;
                }
                case 11:
                    lib.viewOverdueBooks();
                    break;
                case 12:
                    lib.saveToFile(booksFile, membersFile);
                    std::cout << "Memory structural entities mapped and saved out onto physical storage blocks.\n";
                    break;
                case 13:
                    lib.loadFromFile(booksFile, membersFile);
                    std::cout << "File parsing execution sequence finished loading up data maps safely.\n";
                    break;
                case 0:
                    lib.saveToFile(booksFile, membersFile);
                    std::cout << "Application data serialized safely to disk. Termination clean. Goodbye!\n";
                    break;
                default:
                    std::cout << "Selection out of valid indexing constraints.\n";
            }
        }
        catch (const LibraryException& e) {
            std::cerr << "\n>>> GRACEFUL RECOVERY TRACE: EXCEPTION CAUGHT <<<\n" << e.what() << "\n-------------------------------------------------\n";
        }
        catch (const std::exception& e) {
            std::cerr << "\n>>> Generic standard runtime crash: " << e.what() << "\n";
        }
    }
    return 0;
}
