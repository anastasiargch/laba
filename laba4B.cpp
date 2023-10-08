#include <iostream>
using namespace std;

bool polindrom(string str) {
    int len = str.length();
    for (int i = 0; i < len/2; ++i) {
        if (str[i] != str[len - i - 1])
            return false;

    }
    return true;
}
int main() {
    const int max_length = 10;
    char str[max_length];

    cout << "Enter the string:" << endl;
    cin.getline(str, max_length);
    if(polindrom(str))
    {
        cout << "Word is polindrom.";
    }
    else
    {
        cout << "Word is not polindrom";
    }

    return 0;
}
