#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

namespace LibrarySystem {

    class Transaction {
    private:
        int transactionId;
        int memberId;
        int bookId;
        int daysOverdue; // Simplified tracking representation for calculation metrics
        double fineAmount;

        static int nextTransactionId; // Auto-incrementing counter tracking state

    public:
        static const double FINE_RATE_PER_DAY; // Static const specification

        Transaction(int mId = 0, int bId = 0, int overdueDays = 0);

        int getTransactionId() const;
        int getMemberId() const;
        int getBookId() const;
        int getDaysOverdue() const;
        double getFineAmount() const;

        void calculateFine();
        void displayTransaction() const;
    };
}

#endif
