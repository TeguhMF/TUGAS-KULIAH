#include <iostream>
using namespace std;

int main() {
    int data[] = {24, 10, 11, 40, 13, 48};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Data awal: ";
    for(int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl << endl;

    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
            if(data[j] < data[minIndex])
                minIndex = j;
        }

        cout << "Step " << i + 1 << ": Tukar nilai " 
             << data[i] << " dengan " << data[minIndex] << endl;

        int temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;

        cout << "Hasil: ";
        for(int k = 0; k < n; k++)
            cout << data[k] << " ";
        cout << endl << endl;
    }

    cout << "Data akhir (Sorted): ";
    for(int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}
