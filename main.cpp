#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    //0 < e < 10^-k
    double x, k, f;
    cout << "Enter x, -1<x<1" << endl;
    cin >> x;
    while ((x <= -1) || (x >= 1)) {
        cin >> x;
    }
    cout << "Enter k>1" << endl;
    cin >> k;


    f = 1 / sqrt(1 + x);
    long double s = 1;
    long double t = 1;
    int i;
        for (i = 1; i < 10; i = i + 2) {
            if (i % 2 == 0) {

                t = x * x * t / (i * 2);
                s += t;
            } else {
                t = -1 * x * x * t / (i * 2);
                s += t;
            }
        }
    cout << setprecision(k) << f << '=' << s << endl;
    return 0;
}