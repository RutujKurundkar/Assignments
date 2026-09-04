#include <iostream>

// 1. Custom template to handle move semantics without <utility>
template <typename T> struct RemoveReference { typedef T Type; };
template <typename T> struct RemoveReference<T&> { typedef T Type; };
template <typename T> struct RemoveReference<T&&> { typedef T Type; };

template <typename T>
typename RemoveReference<T>::Type&& move(T&& arg) {
    return static_cast<typename RemoveReference<T>::Type&&>(arg);
}

// 2. Custom string class replacing <string> completely without global collisions
class string {
private:
    char* data;
    int len;
public:
    string() {
        data = new char[1];
        data[0] = '\0';
        len = 0;
    }
    string(const char* s) {
        len = 0;
        while (s[len] != '\0') len++;
        data = new char[len + 1];
        for (int i = 0; i <= len; i++) data[i] = s[i];
    }
    string(const string& other) {
        len = other.len;
        data = new char[len + 1];
        for (int i = 0; i <= len; i++) data[i] = other.data[i];
    }
    string(string&& other) noexcept {
        data = other.data;
        len = other.len;
        other.data = nullptr;
        other.len = 0;
    }
    string& operator=(const string& other) {
        if (this != &other) {
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            for (int i = 0; i <= len; i++) data[i] = other.data[i];
        }
        return *this;
    }
    string& operator=(string&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            len = other.len;
            other.data = nullptr;
            other.len = 0;
        }
        return *this;
    }
    ~string() {
        delete[] data;
    }
    int length() const { return len; }
    const char* c_str() const { return data; }
    friend std::ostream& operator<<(std::ostream& out, const string& s) {
        if (s.data) out << s.data;
        return out;
    }
};

// 3. Custom exception class to avoid including <stdexcept>
class out_of_range {
private:
    const char* message;
public:
    out_of_range(const char* msg) : message(msg) {}
    const char* what() const { return message; }
};

// 4. LedgerEntry Class Implementation
class LedgerEntry {
private:
    string description; // Perfectly matches required data member type
    double* amounts;
    int days;

public:
    static int totalEntries;

    // Constructor
    LedgerEntry(const string& desc, int days) : description(desc), days(days) {
        amounts = new double[days];
        for (int i = 0; i < days; ++i) {
            amounts[i] = 0.0;
        }
        totalEntries++;
        std::cout << "[LedgerEntry Created] " << description << " (" << days << " days)" << std::endl;
    }

    // Copy Constructor (Deep Copy)
    LedgerEntry(const LedgerEntry& other) : description(other.description), days(other.days) {
        amounts = new double[days];
        for (int i = 0; i < days; ++i) {
            amounts[i] = other.amounts[i];
        }
        totalEntries++;
    }

    // Move Constructor
    LedgerEntry(LedgerEntry&& other) noexcept
        : description(move(other.description)), amounts(other.amounts), days(other.days) {

        std::cout << "[Move Constructor] Ownership transferred from: " << description << std::endl;
        other.amounts = nullptr;
        other.days = 0;
        totalEntries++;
    }

    // Move Assignment Operator
    LedgerEntry& operator=(LedgerEntry&& other) noexcept {
        std::cout << "[Move Assignment] Ownership transferred from: " << other.description << std::endl;
        if (this != &other) {
            delete[] amounts;
            description = move(other.description);
            amounts = other.amounts;
            days = other.days;

            other.amounts = nullptr;
            other.days = 0;
        }
        return *this;
    }

    // Copy Assignment Operator
    LedgerEntry& operator=(const LedgerEntry& other) {
        if (this != &other) {
            delete[] amounts;
            description = other.description;
            days = other.days;
            amounts = new double[days];
            for (int i = 0; i < days; ++i) {
                amounts[i] = other.amounts[i];
            }
        }
        return *this;
    }

    // Destructor
    ~LedgerEntry() {
        if (amounts != nullptr) {
            std::cout << "[Destructor] " << description << " destroyed" << std::endl;
            delete[] amounts;
        }
        totalEntries--;
    }

    // Subscript Operators
    double& operator[](int index) {
        if (index < 0 || index >= days) {
            throw out_of_range("Index out of bounds");
        }
        return amounts[index];
    }

    const double& operator[](int index) const {
        if (index < 0 || index >= days) {
            throw out_of_range("Index out of bounds");
        }
        return amounts[index];
    }

    double getTotal() const {
        double total = 0.0;
        if (amounts != nullptr) {
            for (int i = 0; i < days; ++i) {
                total += amounts[i];
            }
        }
        return total;
    }

    // Operator +
    LedgerEntry operator+(const LedgerEntry& other) const {
        int maxDays = (this->days > other.days) ? this->days : other.days;
        LedgerEntry result("Combined", maxDays);
        for (int i = 0; i < maxDays; ++i) {
            double val1 = (this->amounts != nullptr && i < this->days) ? this->amounts[i] : 0.0;
            double val2 = (other.amounts != nullptr && i < other.days) ? other.amounts[i] : 0.0;
            result.amounts[i] = val1 + val2;
        }
        return result;
    }

    bool operator==(const LedgerEntry& other) const {
        return this->getTotal() == other.getTotal();
    }

    bool operator>(const LedgerEntry& other) const {
        return this->getTotal() > other.getTotal();
    }

    // Friend stream insertion function using native formatting flags
    friend std::ostream& operator<<(std::ostream& out, const LedgerEntry& entry) {
        out << entry.description;

        int padding = 15 - entry.description.length();
        for (int i = 0; i < padding; ++i) {
            out << " ";
        }

        out << " : [";

        out.setf(std::ios::fixed);
        out.precision(2);

        if (entry.amounts != nullptr) {
            for (int i = 0; i < entry.days; ++i) {
                out << entry.amounts[i];
                if (i < entry.days - 1) out << ", ";
            }
        } else {
            out << "...";
        }
        out << "] Total: " << entry.getTotal();
        return out;
    }
};

int LedgerEntry::totalEntries = 0;

int main() {
    // Objective 1 - Constructor & deep copy (With corrected brackets from screenshot)
    LedgerEntry jan("January Sales", 5);
    jan[0] = 1200.50;  jan[1] = 3400.00;  jan[2] = 800.75;
    jan[3] = 2100.00;  jan[4] = 650.25;

    LedgerEntry feb("February Sales", 5);
    feb[0] = 900.00;   feb[1] = 2200.50;  feb[2] = 1750.00;
    feb[3] = 3000.00;  feb[4] = 475.50;

    std::cout << jan << std::endl;
    std::cout << feb << std::endl;

    // Objective 2 - Operator +
    LedgerEntry combined = jan + feb;
    std::cout << "Combined        : " << combined << std::endl;

    // Objective 3 - Relational operators
    std::cout << "Jan == Feb : " << (jan == feb ? "Yes" : "No") << std::endl;
    std::cout << "Jan  > Feb : " << (jan > feb ? "Yes" : "No") << std::endl;

    // Objective 4 - Move constructor
    LedgerEntry moved = move(jan);
    std::cout << "After move, jan.amounts is null: " << (jan.getTotal() == 0 ? "YES" : "NO") << std::endl;
    std::cout << "Moved entry: " << moved << std::endl;

    // Objective 5 - Move assignment
    LedgerEntry q1("Q1 Total", 5);
    q1 = move(feb);
    std::cout << "Q1 (moved from feb): " << q1 << std::endl;

    // Objective 6 - Static member
    std::cout << "Live LedgerEntry objects: " << LedgerEntry::totalEntries << std::endl;

    return 0;
}
