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

   double arr[n];
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
    int _index=0;
    for (int i = 0; i < n; i++) {
        if ((arr[i] < P)) {
            swap(arr[i], arr[_index]);
            _index++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "; ";
    }
    return 0;
}
