#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int main() {
    srand(time(NULL)); //генератор случайных чисел
    int n, m, i, j;
    cin >> n >> m;
    vector <vector <int> > a(n, vector <int>(m, 0));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if ((i + j) % 2 == 0)
            {
                a[i][j] = 1;
            }
            else {
                a[i][j] = rand() % 10;
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < n; i++) {
        bool fl = false;
        int sum = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                fl = true;
                break;
            }
        }

        if (fl == true) {
            for (int j = 0; j < m; j++) {
                sum += a[i][j];
            } cout << "Sum of elements in the line "<< i << " with zero = " << sum << endl;
        }

        if (fl == false) {
            for (int j = 0; j < m; j++) {
                sum += a[i][j];
            } cout << "There is no zero in the line" << endl;
        }
    }




    int *min = new int[n]; //минимумы строк
    int *max = new int[m]; //максимумы столбцов

    //найти минимумы строк и максимумы столбцов
    min[0] = a[0][0];
    max[0] = a[0][0];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] < min[i]) {
                min[i] = a[i][j];
            }
            if (a[i][j] > max[j]) {
                max[j] = a[i][j];
            }
        }
    }

    //проверить какие элементы являются седловой точкой
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((a[i][j] == min[i]) && (a[i][j] == max[j])) {
                cout << "Sedlovaya tochka: stroka " << i << ", stolbec " << j << endl;
            }
        }
    }

    return 0;
}
