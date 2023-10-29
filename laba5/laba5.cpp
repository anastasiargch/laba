#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    ifstream input;
    ofstream output;

    input.open("input_file.txt");
    output.open("output_file.txt");

    if (!input.is_open()) {
        cout << "Failed to open input file";
        return 1;
    }

    if (!output.is_open()) {
        cout << "Failed to open output file";
        return 1;
    }

    string line;
    int count = 0;
    int startLine = 0; // ����� ������ ������ ������ ����������
    int emptyLineCount = 0; // ���������� ���������� ������ ����� � ������
    int i = 0; // ����� ������

    while (getline(input, line)) {
        if (line.empty() || line.find_first_not_of(' ') == string::npos) {
            if (emptyLineCount == 0) {
                startLine = count;
            }
            emptyLineCount++;
        }
        else {
            if (emptyLineCount > 1) {
                output << "������ " << ++i << ":" << endl;
                output << "��������� ���������� " << emptyLineCount << ":" << endl;
                output << "����� ������ ������ ������: " << startLine + 1 << endl << endl;
            }
            emptyLineCount = 0;
        }
        count++;
    }

    input.close();
    output.close();

    cout << "Programma vypolnena";
    return 0;
}