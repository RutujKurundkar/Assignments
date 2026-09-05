#ifndef CONTAINER_H
#define CONTAINER_H

#include <stdexcept>
#include <string>

namespace LibrarySystem {

    template <typename T>
    class Container {
    private:
        T* data;
        int currentSize;
        int maxCapacity;

        void resize() {
            maxCapacity *= 2;
            T* newData = new T[maxCapacity];
            for (int i = 0; i < currentSize; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

    public:
        Container(int initCap = 4) : currentSize(0), maxCapacity(initCap) {
            data = new T[maxCapacity];
        }

        ~Container() {
            delete[] data;
        }

        // Copy Constructor for Deep Copies
        Container(const Container& other) : currentSize(other.currentSize), maxCapacity(other.maxCapacity) {
            data = new T[maxCapacity];
            for (int i = 0; i < currentSize; ++i) {
                data[i] = other.data[i];
            }
        }

        // Copy Assignment Operator
        Container& operator=(const Container& other) {
            if (this != &other) {
                delete[] data;
                currentSize = other.currentSize;
                maxCapacity = other.maxCapacity;
                data = new T[maxCapacity];
                for (int i = 0; i < currentSize; ++i) {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        void push_back(const T& item) {
            if (currentSize >= maxCapacity) {
                resize();
            }
            data[currentSize++] = item;
        }

        void removeAt(int index) {
            if (index < 0 || index >= currentSize) return;
            for (int i = index; i < currentSize - 1; ++i) {
                data[i] = data[i + 1];
            }
            currentSize--;
        }

        int size() const { return currentSize; }

        T& operator[](int index) {
            return data[index];
        }

        const T& operator[](int index) const {
            return data[index];
        }

        // Overloaded Find Method 1: Find by numerical identifier
        T* findById(int id) {
            for (int i = 0; i < currentSize; ++i) {
                // Works since both Book and Member have getId / getBookId checked via integer casting
                if (data[i].getBookId() == id) {
                    return &data[i];
                }
            }
            return nullptr;
        }

        // Overloaded Find Method 2: Find by string matching pattern
        T* findByName(const std::string& query) {
            for (int i = 0; i < currentSize; ++i) {
                if (data[i].getTitle() == query || data[i].getName() == query) {
                    return &data[i];
                }
            }
            return nullptr;
        }
    };
}

#endif
