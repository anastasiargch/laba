#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input;
    ofstream output;

    input.open("input_file.txt");
    if (!input.is_open()) {
        cout << "Failed to open input file";
        return 0;
    }
    
    output.open("output_file.txt");
    if (!output.is_open()) {
        cout << "Failed to open output file";
        return 0;
    }

    string line;
    int count = 1; // счетчик строк
    int startLine = 1; // номер строки начала группы повторений
    int emptyLineCount = 0; // количество повторений пустых строк в группе
    int i = 0; // номер группы

    while (getline(input, line)) {
        if (line.empty() || line.find_first_not_of(' ') == string::npos) {
            if (emptyLineCount == 0) {
                startLine = count;
            }
            emptyLineCount++;
        }
        else {
            if (emptyLineCount > 0) {
                output << "Группа " << ++i << ":" << endl;
                output << "Количество повторений " << emptyLineCount << ":" << endl;
                output << "Номер строки начала группы: " << startLine << endl << endl; 
                emptyLineCount = 0;
            }
        }
        count++;
    }

    // добавляем последнюю группу
    if (emptyLineCount > 0) {
        output << "Группа " << ++i << ":" << endl;
        output << "Количество повторений " << emptyLineCount << ":" << endl;
        output << "Номер строки начала группы: " << startLine;
    }

    input.close();
    output.close();

    cout << "Programma vypolnena";
    return 0;
}
