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

   int arr[n];

    cout << "Your array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (right - left + 1) + left;
        cout << arr[i] << "; ";
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < P) {
            count++;
        }
    }
    cout << endl;
    cout << "Number of elements < P: " << count << endl; //1 punct

    int i, index = -1;
    for (i = n - 1; i > 0; i--)
        if (arr[i] < 0) {
            index = i;
            break;
        }
        if (index == -1)
            cout << "There are no negative elements in the array" << endl;
        else {
             int sum = 0;

        for (i = index + 1; i < n; i++)
            sum = sum + arr[i];
        cout << "Sum of elements located after the negative one: " << sum << endl;
    }

    cout << "Converted array:" << endl;
    for (i = 0; i < n; i++)
        if ((arr[i] < P))
        {
            cout << arr[i] << "; ";
        }
    for(i = 0; i < n; i++)
        if (arr[i] >= P)
        {
            cout << arr[i] << ("; ");
        }
    return 0;
}