#include <iostream>
using namespace std;
int my_strlen(char n) {
    int count = 0;
    while (n++) ++count;
    return count;
}
void my_strncat (char* s1, const char* s2, int count) {
    while (*s1) s1++;
    if (count == 0) {
        count = my_strlen(*s2);
    }
    while (*s2 && count) {
        *s1 = *s2;
        s1++;
        s2++;
        count--;
    }
    *s1 = '\0';
}

int main() {
    char s1[] = "Hello, ";
    char s2[] = "World!";
    my_strncat(s1, s2, 9);
    cout << s1 << endl;
    system("pause");
    return 0;
}