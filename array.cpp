#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n, P, right, left, count = 0;
    cout << "Enter the size of the array n = ";
    cin >> n;
    cout << "Enter P = ";
    cin >> P;
    cout << "Enter left border = ";
    cin >> left;
    cout << "Enter right border = ";
    cin >> right;

    double* arr = new double [n];
    int max_rand = 1000;

    cout << "Your array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = double(rand() % max_rand) / max_rand * (right - left) + left;
        cout << arr[i] << "  ";
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < P) {
            count++;
        }
    }
    cout << endl;
    cout << "Number of elements < P: " << count << endl; //1 punct

    int index = -1;
    for (int i = n - 1; i > 0; i--)
        if (arr[i] < 0) {
            index = i;
            break;
        }
    if (index == -1)
        cout << "There are no negative elements in the array" << endl;
    else {
        int sum = 0;
        for (int i = index + 1; i < n; i++)
            sum = sum + arr[i];
        cout << "Sum an integer part of the elements located after the last negative one: " << sum << endl;
    }

    cout << "Converted array:" << endl;
    double temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] >= P) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "; ";
    }
        return 0;
 }
