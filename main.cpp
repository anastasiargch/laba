#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    //0 < e < 10^-k
    double x, k, f;
    cout << "Enter x, (-1, 1)" << endl;
    cin >> x;
    cout << "Enter k>1" << endl;
    cin >> k;


    f = 1 / sqrt(1 + x);
    double sum = 1;
    int i = 0;
    double ai = 1;
    do
    {
        ai*=(-x) * (2*i +1) / (double)(2*i+2);
        sum+= ai;
        i++;
        cout << setprecision(k) << f << '=' << setprecision(k) << sum << endl;
    } while ((fabs(sum - f) > pow(10.0, -k)));

    return 0;
}