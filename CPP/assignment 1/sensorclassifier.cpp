#include <iostream>
using namespace std;
int main() {
    double temperature;
    cout << "Enter temperature: " << endl;
    cin >> temperature;
    double temperature_F = ((9.0 / 5.0) * temperature) + 32;
    cout << "Temperature : " << temperature << " C" << " / " << temperature_F << " F" << endl;
    int statusCode;
    if (temperature < 0) {
        statusCode = -1;
    }
    else if (temperature >= 0 && temperature <= 29) {
        statusCode = 0;
    }
    else if (temperature >= 30 && temperature <= 44) {
        statusCode = 1;
    }
    else if (temperature >= 45 && temperature <= 59) {
        statusCode = 2;
    }
    else {
        statusCode = 3;
    }
    switch (statusCode) {
        case -1:
            cout << "Status      : SENSOR_ERROR" << endl;
            cout << "Action      : Sensor fault - check wiring" << endl;
            break;
        case 0:
            cout << "Status      : NORMAL" << endl;
            cout << "Action      : No action required" << endl;
            break;
        case 1:
            cout << "Status      : WARNING" << endl;
            cout << "Action      : Alert sent to supervisor" << endl;
            break;
        case 2:
            cout << "Status      : CRITICAL" << endl;
            cout << "Action      : Cooling system triggered" << endl;
            break;
        case 3:
            cout << "Status      : SHUTDOWN" << endl;
            cout << "Action      : Emergency shutdown initiated" << endl;
            break;
    }
    string display = (temperature > 25) ? "Above Average" : "Below Average";
    cout << "Reading     : " << display << endl;
    return 0;
}
