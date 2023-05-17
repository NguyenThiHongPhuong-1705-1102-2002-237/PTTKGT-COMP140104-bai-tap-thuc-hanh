#include <iostream>
using namespace std;


int* aWeight, * aValue, * b, * maxBool;
int weight, limitWeight, maxValue, value;
int n;
void Try(int j) {
    if (j == n) {
        weight = value = 0;
        for (int i = 0; i < n; i++) {
            if (b[i]) {
                weight += aWeight[i];
                value += aValue[i];
            }
        }
        if (weight < limitWeight) {
            if (value > maxValue) {
                maxValue = value;
                for (int i = 0; i < n; i++) {
                    maxBool[i] = b[i];
                }
            }
        }

    }
    else {
        b[j] = 0;
        Try(j + 1);
        b[j] = 1;
        Try(j + 1);
    }
}

int main() {
    cin >> n >> limitWeight;
    aWeight = new int[n];
    aValue = new int[n];
    b = new int[n];
    maxBool = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> aWeight[i] >> aValue[i];
    }

    Try(0);

    cout << maxValue << endl;
    for (int i = 0; i < n; i++) {
        cout << maxBool[i] << ' ';
    }
}
