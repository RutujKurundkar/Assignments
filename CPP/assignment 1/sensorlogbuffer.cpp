#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter number of readings: " << endl;
    cin >> size;

    if (size >= 1 && size <= 100){

        double arr[size];
        int count = 0;
        int Normal = 0;
        int Warning = 0;
        int Critical = 0;
        int Shutdown = 0;
        int skipped = 0;
        bool criticalFound = false;

        cout << "Enter the readings: " << endl;

        for (int i = 0; i < size; i++){
            double input;
            cin >> input;

            if (input < 0){
                skipped++;
                continue;
            }

            arr[count] = input;

            if (input >= 45 && criticalFound == false){
                printf("First CRITICAL: Index %d -> %.1f C\n", count + 1, input);
                criticalFound = true;
            }

            count++;
        }

        cout << "Readings entered: " << size << endl;
        cout << "Skipped readings: " << skipped << endl;

        cout << "Valid readings: ";
        for (int i = 0; i < count; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        double min = arr[0];
        double max = arr[0];
        double sum = 0;

        for (int i = 0; i < count; i++){

            if (arr[i] < min){
                min = arr[i];
            }

            if (arr[i] > max){
                max = arr[i];
            }

            sum = sum + arr[i];
        }

        double Avg = sum / count;

        for (int i = 0; i < count; i++){
            if (arr[i] < 25){
                Normal++;
            }
            else if (arr[i] < 40){
                Warning++;
            }
            else if (arr[i] < 60){
                Critical++;
            }
            else{
                Shutdown++;
            }
        }

        printf("Min: %.1f C\n", min);
        printf("Max: %.1f C\n", max);
        printf("Avg: %.2f C\n", Avg);

        cout << "Normal: " << Normal << endl;
        cout << "Warning: " << Warning << endl;
        cout << "Critical: " << Critical << endl;
        cout << "Shutdown: " << Shutdown << endl;

    }
    else {
        cout << "Invalid size. Size must be between 1 and 100." << endl;
    }

    return 0;
}
