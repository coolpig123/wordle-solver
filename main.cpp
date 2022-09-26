#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"
#include <fstream>
#include <string>
#include <map>
using namespace std;
bool isValid(string word, vector<char> blackLetters, map<int, char> yellowLetters, map <int, char> greenLetters) {
    if (checkGreenLetters(word,greenLetters) && checkYellowLetters(word,yellowLetters) && checkBlankLetters(word,blackLetters,yellowLetters,greenLetters)) {
        return true;
    }
    else {
        return false;
    }
}
void getWords(vector<char> invalid, map<int, char> valid, map<int, char> inPlace) {
    string currentWord;
    ifstream data("data.txt");
    cout << "words available : " << endl;
    while (getline(data, currentWord)) {
        if (isValid(currentWord,invalid, valid, inPlace)) {
            cout << currentWord << endl;
        }
    }
}
int main() {
    vector<char> invalid = {};
    map<int, char> valid = {};
    map<int, char> inPlace = {};
    string word;
    string colors;
    for (int i = 0; i < 6; i++) {
        cout << "enter the word you entered : " << endl;
        cin >> word;
        if (word == "quit") {
            exit(1);
        }
        cout << "enter the colors you got : " << endl;
        cin >> colors;
        if (colors == "quit") {
            exit(1);
        }
        for (int j = 0; j < 5; j++) {
            if (colors.at(j) == 'b') {
                invalid.push_back(word.at(j));
            }
            else if (colors.at(j) == 'y') {
                valid.insert({ j, word.at(j) });
            }
            else if (colors.at(j) == 'g' && !inPlace.count(j)) {
                inPlace.insert({ j, word.at(j) });
            }
        }
        getWords(invalid, valid, inPlace);
    }
}