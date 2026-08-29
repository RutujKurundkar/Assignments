#include <iostream>
using namespace std;

// Calculates RMS
double computeRMS(double* signal, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + (*(signal + i)) * (*(signal + i));
    }
    double mean = sum / n;

    // Calculate square root without cmath
    double guess = mean / 2;
    for (int i = 0; i < 20; i++) {
        guess = (guess + mean / guess) / 2;
    }
    return guess;
}

// Normalises the signal
void normalise(double* signal, int n) {
    double maxValue = 0;
    // Find maximum absolute value
    for (int i = 0; i < n; i++) {
        double value = *(signal + i);
        if (value < 0) {
            value = -value;
        }
        if (value > maxValue) {
            maxValue = value;
        }
    }
    // Divide every element by maximum absolute value
    if (maxValue != 0) {
        for (int i = 0; i < n; i++) {
            *(signal + i) = *(signal + i) / maxValue;
        }
    }
}


// Counts zero crossings
int countZeroCrossings(double* signal, int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if ((*(signal + i) < 0 && *(signal + i + 1) > 0) ||
            (*(signal + i) > 0 && *(signal + i + 1) < 0)) {
            count++;
        }
    }
    return count;
}


// Applies gain to every element
void applyGain(double* signal, int n, double gainFactor) {
    for (int i = 0; i < n; i++) {
        *(signal + i) = *(signal + i) * gainFactor;
    }
}


// Prints the array
void printArray(double* signal, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(signal + i) << " ";
    }
    cout << endl;
}


int main() {
    double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
    int n = sizeof(signal) / sizeof(signal[0]);
    // Print original array
    cout << "Original signal: ";
    printArray(signal, n);

    // Calculate and print RMS
    double rms = computeRMS(signal, n);
    cout << "RMS: " << rms << endl;

    // Calculate and print zero crossings
    int zeroCrossings = countZeroCrossings(signal, n);
    cout << "Zero crossings: " << zeroCrossings << endl;

    // Print before normalisation
    cout << "Before normalise: ";
    printArray(signal, n);

    // Normalise
    normalise(signal, n);

    // Print after normalisation
    cout << "After normalise: ";
    printArray(signal, n);

    // Print before applying gain
    cout << "Before applyGain: ";
    printArray(signal, n);

    // Apply gain of 2
    double gainFactor = 2.0;
    applyGain(signal, n, gainFactor);

    // Print after applying gain
    cout << "After applyGain: ";
    printArray(signal, n);

    return 0;
}
