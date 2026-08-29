#include <iostream>
using namespace std;
int main() {
    double temp[3][3];
    cout << "Enter temperatures for 9 rooms: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> temp[i][j];
        }
    }
    cout << "\t\tRoom1\tRoom2\tRoom3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Floor " << (i + 1) << "\t:\t";
        for (int j = 0; j < 3; j++) {
            if (temp[i][j] == (int)temp[i][j]) {
                cout << temp[i][j] << ".0\t";
            } else {
                cout << temp[i][j] << "\t";
            }
        }
        cout << endl;
    }

    double maxTemp = temp[0][0];
    int maxFloor = 0;
    int maxRoom = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (temp[i][j] > maxTemp) {
                maxTemp = temp[i][j];
                maxFloor = i;
                maxRoom = j;
            }
        }
    }
    cout << "Hottest Room  : Floor " << (maxFloor + 1) << ", Room " << (maxRoom + 1) << " -> " << maxTemp << "°C" << endl;

    double maxAvg = 0.0;
    int hottestFloor = 0;
    for (int i = 0; i < 3; i++) {
        double sum = 0.0;
        for (int j = 0; j < 3; j++) {
            sum += temp[i][j];
        }
        double avg = sum / 3.0;
        if (avg > maxAvg) {
            maxAvg = avg;
            hottestFloor = i;
        }
    }
    maxAvg = (int)(maxAvg * 100 + 0.5) / 100.0;
    cout << "Hottest Floor : Floor " << (hottestFloor + 1) << " (avg " << maxAvg << "°C)" << endl;

    int warningCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (temp[i][j] >= 30.0) {
                warningCount++;
            }
        }
    }
    cout << "Rooms at WARNING or above : " << warningCount << endl;

    return 0;
}
