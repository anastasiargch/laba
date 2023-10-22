#include <iostream>
using namespace std;

const int LENGTH = 300;
char* line = new char[LENGTH];
int k = 0;
int realLength = 0;

char* getWord(int& len) {
    len = 0;
    char* word = new char[LENGTH];
    while (k < realLength && line[k] != ' ') {
        word[len++] = line[k++];
    }
    k++;
    return word;
}

bool check_palindrom(char* word, int len) {
    for (int i = 0; i < len / 2; ++i) {
        if (word[i] != word[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char* answer;
    int answerLength = 0;
    cout << "Enter the string:";
    cin.getline(line, LENGTH);
    realLength = cin.gcount() - 1;
    cout << "Answer: ";
    while (k < realLength) {
        char* word;
        int length;
        word = getWord(length);
        if (check_palindrom(word, length)) {
            if (answerLength != 0) {
                cout << word;
                delete[] word;
                delete[] answer;
                delete[] line;

                return 0;
            }
            else {
                answer = word;
                answerLength = length;
            }
        }
        else {
            delete[] word;
        }
    }

    if (answerLength != 0) {
        cout << answer;
    }
    else {
        cout << "No palindromes";
    }

    delete[] answer;
    delete[] line;
    return 0;
}
