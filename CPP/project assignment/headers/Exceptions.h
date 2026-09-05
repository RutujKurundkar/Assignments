#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

namespace LibrarySystem {

    class LibraryException : public std::exception {
    protected:
        std::string message;
        std::string functionName;
        int lineNumber;
        std::string fullMsg;

    public:
        LibraryException(const std::string& msg, const std::string& func, int line)
            : message(msg), functionName(func), lineNumber(line) {
            fullMsg = "[Error in " + functionName + " at line " + std::to_string(lineNumber) + "]: " + message;
        }

        virtual const char* what() const noexcept override {
            return fullMsg.c_str();
        }
    };

    class BookNotFoundException : public LibraryException {
    public:
        BookNotFoundException(const std::string& msg, const std::string& func, int line)
            : LibraryException(msg, func, line) {}
    };

    class MemberNotFoundException : public LibraryException {
    public:
        MemberNotFoundException(const std::string& msg, const std::string& func, int line)
            : LibraryException(msg, func, line) {}
    };

    class BookNotAvailableException : public LibraryException {
    public:
        BookNotAvailableException(const std::string& msg, const std::string& func, int line)
            : LibraryException(msg, func, line) {}
    };

    class MaxBooksExceededException : public LibraryException {
    public:
        MaxBooksExceededException(const std::string& msg, const std::string& func, int line)
            : LibraryException(msg, func, line) {}
    };
}

#endif
