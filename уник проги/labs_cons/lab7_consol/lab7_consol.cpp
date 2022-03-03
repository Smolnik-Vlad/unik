

#include <iostream>
#include <string.h>
#include <sstream>

    using namespace std;

    int main() {
        setlocale(LC_ALL, "rus");

        string str;
        getline(cin, str);
        str += ' ';

        int biggestLineSize = 0;
        string biggestLine = "";

        int currentLineSize = 0;

        string currentLine = "";

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i]!=' ')
            {
                biggestLineSize++;
            }
            else break;

        }
        
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                currentLine += str[i];
                currentLineSize++;
            }
            else
            {
                if (currentLineSize <= biggestLineSize) {
                    biggestLine = currentLine;
                    biggestLineSize = currentLineSize;
                }
                currentLine = "";
                currentLineSize = 0;
            }
        }

        cout <<"Наименьшая строка: "<< biggestLine;
    }
    

    /*1 1111 11 1*/