#include "Transaction.h"

namespace LibrarySystem {

    // Initializing static members outside class boundaries
    int Transaction::nextTransactionId = 1000;
    const double Transaction::FINE_RATE_PER_DAY = 10.0; // 10 INR per day fine rate bounds

    Transaction::Transaction(int mId, int bId, int overdueDays)
        : memberId(mId), bookId(bId), daysOverdue(overdueDays), fineAmount(0.0) {
        transactionId = nextTransactionId++;
        calculateFine();
    }

    int Transaction::getTransactionId() const { return transactionId; }
    int Transaction::getMemberId() const { return memberId; }
    int Transaction::getBookId() const { return bookId; }
    int Transaction::getDaysOverdue() const { return daysOverdue; }
    double Transaction::getFineAmount() const { return fineAmount; }

    void Transaction::calculateFine() {
        if (daysOverdue > 0) {
            fineAmount = daysOverdue * FINE_RATE_PER_DAY;
        } else {
            fineAmount = 0.0;
        }
    }

    void Transaction::displayTransaction() const {
        std::cout << "Transaction ID: " << transactionId << " | Member ID: " << memberId
                  << " | Book ID: " << bookId << " | Overdue: " << daysOverdue
                  << " Days | Fine Assessed: INR " << fineAmount << "\n";
    }
}
