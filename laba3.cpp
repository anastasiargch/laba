#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

int main() {
    srand(time(NULL)); //генератор случайных чисел
    int n, m, i, j, count = 0;
    cout << "Enter the number of rows and columns:" << endl;
    cin >> n >> m;
    vector <vector <int> > a(n, vector <int>(m, 0));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = rand() % 19 - 9;
            }
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }

    for (i = 0; i < n; i++) {
        int sum = 0;
        for (j = 0; j < m; j++)
            if (a[i][j] == 0) {
                for (j = 0; j < m; j++) {
                    sum += a[i][j];
                }
                cout << endl;
                cout << "Sum of elements in the line "<< i + 1 << " with zero = " << sum << endl;
            }
    }

    int min[i], max[j], maxofmin, minofmax;

    for (i = 0; i < n; i++) {
        min[i] = a[i][0];
        for (j = 0; j < m; j++) {
            if (min[i] > a[i][j]) {
                min[i] = a[i][j];
            }
        }
    }
    cout << endl;
    cout << "Minimum elements in rows:" << endl;
    for (i = 0; i < n; i++)
    cout << min[i] << endl;


    for (j = 0; j < m; j++) {
        max[j] = a[0][j];
        for (i = 0; i < n; i++) {
            if (max[j] < a[i][j]) {
                max[j] = a[i][j];
            }
        }
    }
    cout << endl;
    cout << "Maximum elements in columns:" << endl;
    for (j = 0; j < m; j++)
        cout << max[j] << setw(3);

    maxofmin = min[0];
    for (i = 0; i < n; i++)
        if (maxofmin < min[i]) {
            maxofmin = min[i];
        }

    minofmax = max[0];
    for (i = 0; i < m; i++)
        if (minofmax > max[i]) {
            minofmax = max[i];
        }

    if (minofmax > maxofmin) {
        cout << "\n\nSedlovih tochek net" << endl;
    }

    else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (min[i] == maxofmin && max[j] == minofmax) {
                    count++;
                    cout << "\n\nSedlovaya tochka: stroka " << i + 1 << ", stolbec " << j + 1 << endl;
                    cout << "The number of sedlovih tochek = " << count << endl;
                }
            }
        }
    }


    return 0;
}
