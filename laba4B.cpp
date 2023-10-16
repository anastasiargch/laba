#include <iostream>
using namespace std;

int my_strlen(char n) {
    int count = 0;
    while (n++) {
       ++count;
    }
    return count;
}

int main() {
    char str[300];
    int len = my_strlen(*str);
        cout << "Enter the string:" << endl;
        cin.getline(str, 300);
        for (int i = 0; i < len/2; i++) {
            if (str[i] != str[len - i - 1]) {
                cout << "Word is not palindrom" << endl;
                break;
            }
            else {
            cout << "Word is palindrom" << endl;
            }
        }   
    return 0;
}
